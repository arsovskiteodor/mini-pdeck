// Copyright 2026 Teodor Arsovski
// SPDX-License-Identifier: GPL-2.0-or-later

// EC11 encoder bench test for the minipad (ENC1-ENC2) on a Pro Micro, with the OLED as the display.
// Not part of the macropad firmware. It answers what QMK needs to know about our clone encoder:
//   - does A/B counting work, and which sign is clockwise (QMK: swap A and B if reversed),
//   - how many quadrature edges per detent (QMK encoder "resolution"),
//   - bounce: transitions that skip a state ("bad"),
//   - does the push switch work (no multimeter needed).
//
// Wiring (Pro Micro pin labels). Unplug USB while wiring.
//   OLED:    VCC -> VCC, GND -> GND, SCL -> 3, SDA -> 2   (as in ../oled_test_promicro)
//   Encoder, 3-pin side:  A -> RXI (D0),  C (middle) -> GND,  B -> TXO (D1)
//   Encoder, 2-pin side:  one pin -> 4,   other pin -> GND
// A-C-B with C in the middle follows the SR Passives drawing in docs/hardware/parts.md (ENC1-ENC2). Our encoder
// is a clone: if nothing counts, the common pin may be elsewhere.
// D0 and D1 are external-interrupt pins (INT2, INT3): ArduinoCore-avr variants/leonardo/pins_arduino.h,
// digitalPinToInterrupt. Interrupts catch every edge even while the OLED is being redrawn.
// All encoder pins use the AVR's internal pull-ups, like the RP2040 plan (docs/hardware/pinout.md).
//
// How to use:
//   1. Turn ONE detent clockwise, slowly. "last" shows the edges for that detent (expect +/-4 or +/-2).
//   2. Turn exactly ONE full turn (20 detents). "edges" should change by 20 x that number. "bad" should stay 0.
//   3. Press the knob: "btn" shows DOWN and the press count goes up.
// Serial (115200) logs every move and button press.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const uint8_t PIN_A = 0;    // RXI
const uint8_t PIN_B = 1;    // TXO
const uint8_t PIN_SW = 4;
const uint8_t OLED_ADDR = 0x3C;
const uint8_t DETENTS_PER_TURN = 20;  // counted by the owner, 2026-11-04 (parts.md)
const unsigned long REST_MS = 150;    // no edge for this long = the knob is resting in a detent

Adafruit_SSD1306 d(128, 64, &Wire, -1);

// Quadrature decoder: index = previous AB (2 bits) and new AB (2 bits). +1/-1 = valid step, 0 = no step.
const int8_t QDEC[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
volatile int16_t edges = 0;
volatile uint16_t bad = 0;
volatile uint8_t prevAB = 0;

void onEdge() {
  uint8_t ab = (digitalRead(PIN_A) << 1) | digitalRead(PIN_B);
  if (ab == prevAB) return;
  int8_t step = QDEC[(prevAB << 2) | ab];
  if (step) edges += step;
  else bad++;  // both bits changed at once: a skipped state, usually contact bounce
  prevAB = ab;
}

int16_t restEdges = 0;
int16_t lastMove = 0;
int16_t seenEdges = 0;
unsigned long lastChange = 0;
uint16_t presses = 0;
bool swDown = false;
unsigned long swChanged = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);
  pinMode(PIN_SW, INPUT_PULLUP);
  prevAB = (digitalRead(PIN_A) << 1) | digitalRead(PIN_B);
  attachInterrupt(digitalPinToInterrupt(PIN_A), onEdge, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_B), onEdge, CHANGE);

  if (!d.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    while (true) {
      Serial.println(F("display.begin() failed"));
      delay(1000);
    }
  }
}

void loop() {
  unsigned long now = millis();

  noInterrupts();
  int16_t e = edges;
  uint16_t b = bad;
  interrupts();
  uint8_t abNow = (digitalRead(PIN_A) << 1) | digitalRead(PIN_B);

  // Detect "moved, then came to rest in a detent"
  if (e != seenEdges) {
    seenEdges = e;
    lastChange = now;
  } else if (e != restEdges && now - lastChange > REST_MS) {
    lastMove = e - restEdges;
    restEdges = e;
    Serial.print(F("move "));
    if (lastMove > 0) Serial.print('+');
    Serial.print(lastMove);
    Serial.print(F(" edges, total "));
    Serial.print(e);
    Serial.print(F(", resting AB="));
    Serial.print(abNow >> 1);
    Serial.print(abNow & 1);
    Serial.print(F(", bad "));
    Serial.println(b);
  }

  // Push switch, 20 ms debounce
  bool down = digitalRead(PIN_SW) == LOW;
  if (down != swDown && now - swChanged > 20) {
    swDown = down;
    swChanged = now;
    if (down) presses++;
    Serial.println(down ? F("button DOWN") : F("button UP"));
  }

  // Display
  d.clearDisplay();
  d.fillRect(0, 0, 128, 10, SSD1306_WHITE);
  d.setTextSize(1);
  d.setTextColor(SSD1306_BLACK);
  d.setCursor(2, 1);
  d.print(F("EC11 TEST"));

  // Dial: assumes 4 edges per detent until we know better; one tick mark per detent
  const int16_t cx = 20, cy = 37, r = 15;
  d.drawCircle(cx, cy, r, SSD1306_WHITE);
  float a = (e / 4.0) * (6.2832 / DETENTS_PER_TURN) - 1.5708;
  d.drawLine(cx, cy, cx + (int16_t)(cos(a) * (r - 3)), cy + (int16_t)(sin(a) * (r - 3)), SSD1306_WHITE);
  if (swDown) d.fillCircle(cx, cy, 5, SSD1306_WHITE);

  d.setTextColor(SSD1306_WHITE);
  d.setCursor(42, 14);
  d.print(F("edges "));
  d.print(e);
  d.setCursor(42, 24);
  d.print(F("last  "));
  if (lastMove > 0) d.print('+');
  d.print(lastMove);
  d.setCursor(42, 34);
  d.print(F("AB    "));
  d.print(abNow >> 1);
  d.print(abNow & 1);
  d.setCursor(42, 44);
  d.print(F("bad   "));
  d.print(b);
  d.setCursor(42, 54);
  d.print(F("btn "));
  d.print(swDown ? F("DOWN ") : F("up   "));
  d.print(presses);
  d.display();
}
