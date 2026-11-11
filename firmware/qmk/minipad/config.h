#pragma once

// LED1 on GP9 (pinout.md) is PWM slice 4, channel B on the RP2040
// (pico-sdk: slice = (9 >> 1) & 7 = 4, channel = 9 & 1 = B).
#define BACKLIGHT_PWM_DRIVER PWMD4
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_B
