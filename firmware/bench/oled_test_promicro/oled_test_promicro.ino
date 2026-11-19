// Copyright 2026 Teodor Arsovski
// SPDX-License-Identifier: GPL-2.0-or-later

// Bench test for the minipad OLED (DISP1, HW-239 module) on a Pro Micro (ATmega32U4).
// Not part of the macropad firmware. It answers three things before step 04:
//   - is the module alive (box + text on screen),
//   - its I2C address (STATUS Q10),
//   - a functional hint for on-board pull-ups (STATUS Q3), with DISABLE_INTERNAL_PULLUPS = 1.
//
// Wiring (Pro Micro pin labels):
//   OLED VCC -> VCC        OLED GND -> GND
//   OLED SCL -> 3          OLED SDA -> 2
// Source for SDA = D2 (PD1) and SCL = D3 (PD0): ArduinoCore-avr, variants/leonardo/pins_arduino.h
// (PIN_WIRE_SDA 2, PIN_WIRE_SCL 3).
//
// Libraries (Arduino IDE > Library Manager): "Adafruit SSD1306" (it also installs "Adafruit GFX Library").
// Board: "Arduino Leonardo" is right only for a 5 V / 16 MHz Pro Micro. A 3.3 V / 8 MHz one needs
// the SparkFun board package instead.
// Serial Monitor: 115200 baud.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 0 = keep the AVR's internal pull-ups on. Wire.begin() turns them on (ArduinoCore-avr twi.c,
//     twi_init: "activate internal pullups for twi").
// 1 = turn them off after init, so the bus relies only on pull-ups on the OLED module.
#define DISABLE_INTERNAL_PULLUPS 1

const uint8_t W = 128;
const uint8_t H = 64;
Adafruit_SSD1306 display(W, H, &Wire, -1);  // -1: the module has no reset pin on its header
uint8_t oledAddr = 0;

void setWireTimeout() {
#ifdef WIRE_HAS_TIMEOUT
  Wire.setWireTimeout(25000, true);  // 25 ms: a stuck bus reports an error instead of hanging
#endif
}

void scanBus() {
  Serial.println(F("I2C scan (7-bit addresses):"));
  uint8_t found = 0;
  for (uint8_t a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) {
      Serial.print(F("  device at 0x"));
      if (a < 16) Serial.print('0');
      Serial.println(a, HEX);
      if (a == 0x3C || a == 0x3D) oledAddr = a;
      found++;
    }
  }
  if (found == 0) Serial.println(F("  nothing found: check VCC/GND, and that SDA/SCL are not swapped"));
}

void setup() {
  Serial.begin(115200);
  unsigned long t0 = millis();
  while (!Serial && millis() - t0 < 4000) {}  // USB serial: wait up to 4 s for the monitor

  Wire.begin();
  setWireTimeout();
  // Keep scanning until the OLED answers, so the result is visible whenever the monitor opens.
  while (true) {
    scanBus();
    if (oledAddr != 0) break;
    Serial.println(F("No SSD1306 at 0x3C or 0x3D. Retrying in 2 s."));
    delay(2000);
  }

  // begin() calls Wire.begin() again, which turns the internal pull-ups back on.
  if (!display.begin(SSD1306_SWITCHCAPVCC, oledAddr)) {
    Serial.println(F("display.begin() failed (not enough RAM for the frame buffer?). Stopping."));
    while (true) {}
  }
  setWireTimeout();

#if DISABLE_INTERNAL_PULLUPS
  // With the TWI enabled, the PORT bit only controls the pull-up. Clearing it turns the pull-up off.
  digitalWrite(SDA, LOW);
  digitalWrite(SCL, LOW);
  Serial.println(F("AVR internal pull-ups: OFF"));
#else
  Serial.println(F("AVR internal pull-ups: ON"));
#endif
}

void loop() {
  static uint16_t count = 0;
  static uint16_t nacks = 0;

  Wire.beginTransmission(oledAddr);
  uint8_t err = Wire.endTransmission();  // 0 = the OLED answered (ACK)
  if (err != 0) nacks++;

  display.clearDisplay();
  display.drawRect(0, 0, W, H, SSD1306_WHITE);  // all four edges should be visible
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(4, 4);
  display.println(F("Minipad OLED test"));
  display.setCursor(4, 16);
  display.print(F("addr 0x"));
  display.println(oledAddr, HEX);
  display.setCursor(4, 28);
  display.println(DISABLE_INTERNAL_PULLUPS ? F("AVR pull-ups OFF") : F("AVR pull-ups ON"));
  display.setCursor(4, 40);
  display.print(F("count "));
  display.print(count);
  display.setCursor(4, 52);
  display.print(F("NACKs "));
  display.print(nacks);
  display.display();

  Serial.print(F("addr 0x"));
  Serial.print(oledAddr, HEX);
  Serial.print(DISABLE_INTERNAL_PULLUPS ? F("  AVR pull-ups OFF") : F("  AVR pull-ups ON"));
  Serial.print(F("  count "));
  Serial.print(count);
  Serial.print(F("  NACKs "));
  Serial.print(nacks);
  Serial.print(F("  ping "));
  Serial.print(err == 0 ? F("ACK") : F("FAIL, code "));
  if (err != 0) Serial.print(err);
  Serial.println();

  count++;
  delay(1000);
}
