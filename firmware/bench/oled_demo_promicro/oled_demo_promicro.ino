// Copyright 2026 Teodor Arsovski
// SPDX-License-Identifier: GPL-2.0-or-later

// OLED look-and-feel demo for the minipad (DISP1, HW-239, SSD1306 128x64) on a Pro Micro.
// Not part of the macropad firmware: QMK has its own OLED API. Same panel, so the look is similar.
// Wiring and libraries: see ../oled_test_promicro/oled_test_promicro.ino (SDA -> 2, SCL -> 3).
//
// Four scenes, 6 s each:
//   0  wavy "minipad" title
//   1  macropad UI mock-up: layer bar, two encoder dials, volume bar, visualiser, 4 keys
//   2  rotating wireframe cube
//   3  starfield
// Serial (115200) prints the scene and frames per second once a second.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const uint8_t W = 128;
const uint8_t H = 64;
const uint8_t OLED_ADDR = 0x3C;  // found by the I2C scan, 2026-11-04 (parts.md, DISP1)
const unsigned long SCENE_MS = 6000;
const uint8_t SCENES = 4;

Adafruit_SSD1306 d(W, H, &Wire, -1);

// ---------- scene 0: wavy title ----------
void sceneTitle(float t) {
  const char title[] = "minipad";
  d.setTextSize(2);
  d.setTextColor(SSD1306_WHITE);
  for (uint8_t i = 0; i < 7; i++) {
    int16_t y = 20 + (int16_t)(sin(t * 4.0 + i * 0.7) * 8.0);
    d.setCursor(22 + i * 12, y);
    d.write(title[i]);
  }
  d.setTextSize(1);
  d.setCursor(22, 54);
  d.print(F("4 keys . 2 knobs"));
}

// ---------- scene 1: macropad UI mock-up ----------
void dial(int16_t cx, int16_t cy, int16_t r, float a, const __FlashStringHelper *label) {
  d.drawCircle(cx, cy, r, SSD1306_WHITE);
  d.drawLine(cx, cy, cx + (int16_t)(cos(a) * (r - 2)), cy + (int16_t)(sin(a) * (r - 2)), SSD1306_WHITE);
  d.setTextSize(1);
  d.setTextColor(SSD1306_WHITE);
  d.setCursor(cx - 9, cy + r + 3);
  d.print(label);
}

void sceneUi(float t) {
  // Layer bar (inverted)
  d.fillRect(0, 0, W, 10, SSD1306_WHITE);
  d.setTextSize(1);
  d.setTextColor(SSD1306_BLACK);
  d.setCursor(2, 1);
  d.print(F("LAYER 1  MEDIA"));
  if (((unsigned long)(t * 2)) % 2) d.fillCircle(122, 4, 2, SSD1306_BLACK);  // blinking "alive" dot

  // Left encoder: volume, sweeping up and down
  uint8_t vol = 50 + (int8_t)(sin(t * 0.8) * 45.0);
  dial(16, 28, 10, -2.36 + vol * 0.0471, F("VOL"));  // 0..100 % maps to a 270 degree sweep

  // Right encoder: turns in 20 detent steps per turn, like the real EC11
  uint8_t step = ((unsigned long)(t * 5)) % 20;
  dial(112, 28, 10, step * (6.2832 / 20.0) - 1.5708, F("SCR"));

  // Volume bar in the middle
  d.setTextColor(SSD1306_WHITE);
  d.setCursor(40, 14);
  d.print(F("VOL "));
  d.print(vol);
  d.print('%');
  d.drawRect(34, 24, 60, 7, SSD1306_WHITE);
  d.fillRect(35, 25, (uint8_t)(vol * 58 / 100), 5, SSD1306_WHITE);

  // Little audio visualiser
  for (uint8_t i = 0; i < 10; i++) {
    uint8_t h = 1 + (uint8_t)(fabs(sin(t * 3.1 + i * 0.9) * cos(t * 1.7 + i * 0.4)) * 11.0);
    d.fillRect(35 + i * 6, 46 - h, 4, h, SSD1306_WHITE);
  }

  // Four keys, one "pressed" at a time
  static const char *const labels[4] = {"CUT", "CPY", "PST", "MUT"};
  uint8_t active = ((unsigned long)(t * 2)) % 4;
  for (uint8_t k = 0; k < 4; k++) {
    int16_t x = 7 + k * 30;
    if (k == active) {
      d.fillRoundRect(x, 51, 24, 13, 3, SSD1306_WHITE);
      d.setTextColor(SSD1306_BLACK);
    } else {
      d.drawRoundRect(x, 51, 24, 13, 3, SSD1306_WHITE);
      d.setTextColor(SSD1306_WHITE);
    }
    d.setCursor(x + 3, 54);
    d.print(labels[k]);
  }
}

// ---------- scene 2: rotating cube ----------
const int8_t CV[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
                         {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}};
const uint8_t CE[12][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6},
                           {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

void sceneCube(float t) {
  float sx = sin(t * 0.9), cx = cos(t * 0.9);
  float sy = sin(t * 1.3), cy = cos(t * 1.3);
  int16_t px[8], py[8];
  for (uint8_t i = 0; i < 8; i++) {
    float x = CV[i][0], y = CV[i][1], z = CV[i][2];
    float y1 = y * cx - z * sx, z1 = y * sx + z * cx;    // rotate around X
    float x2 = x * cy + z1 * sy, z2 = -x * sy + z1 * cy;  // rotate around Y
    float f = 40.0 / (z2 + 4.0);                          // perspective
    px[i] = 64 + (int16_t)(x2 * f);
    py[i] = 32 + (int16_t)(y1 * f);
  }
  for (uint8_t e = 0; e < 12; e++) {
    d.drawLine(px[CE[e][0]], py[CE[e][0]], px[CE[e][1]], py[CE[e][1]], SSD1306_WHITE);
  }
}

// ---------- scene 3: starfield ----------
const uint8_t NS = 40;
int16_t starX[NS], starY[NS];
uint8_t starZ[NS];

void respawn(uint8_t i) {
  starX[i] = random(-512, 512);
  starY[i] = random(-256, 256);
  starZ[i] = 63;
}

void sceneStars() {
  for (uint8_t i = 0; i < NS; i++) {
    if (starZ[i] <= 2) respawn(i);
    starZ[i] -= 2;
    int16_t x = 64 + starX[i] / starZ[i];
    int16_t y = 32 + starY[i] / starZ[i];
    if (x < 0 || x >= W || y < 0 || y >= H) {
      respawn(i);
      continue;
    }
    if (starZ[i] < 16) d.fillRect(x, y, 2, 2, SSD1306_WHITE);  // near stars look bigger
    else d.drawPixel(x, y, SSD1306_WHITE);
  }
}

void setup() {
  Serial.begin(115200);
  if (!d.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    while (true) {
      Serial.println(F("display.begin() failed"));
      delay(1000);
    }
  }
  randomSeed(analogRead(A0));
  for (uint8_t i = 0; i < NS; i++) {
    respawn(i);
    starZ[i] = random(3, 63);
  }
}

void loop() {
  static unsigned long lastReport = 0;
  static uint16_t frames = 0;

  unsigned long now = millis();
  uint8_t scene = (now / SCENE_MS) % SCENES;
  float t = now / 1000.0;

  d.clearDisplay();
  switch (scene) {
    case 0: sceneTitle(t); break;
    case 1: sceneUi(t); break;
    case 2: sceneCube(t); break;
    case 3: sceneStars(); break;
  }
  d.display();

  frames++;
  if (now - lastReport >= 1000) {
    Serial.print(F("scene "));
    Serial.print(scene);
    Serial.print(F("  fps "));
    Serial.println(frames);
    frames = 0;
    lastReport = now;
  }
}
