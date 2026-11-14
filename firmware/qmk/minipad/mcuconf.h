#pragma once

// Include the base file FIRST: it sets every value unconditionally,
// so we override afterwards with #undef + #define.
#include_next <mcuconf.h>

// PWM slices for the key LEDs (slice = (pin >> 1) & 7, channel = pin & 1):
// GP9 = slice 4 B, GP10 = slice 5 A, GP11 = slice 5 B, GP12 = slice 6 A.
#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE
#undef RP_PWM_USE_PWM5
#define RP_PWM_USE_PWM5 TRUE
#undef RP_PWM_USE_PWM6
#define RP_PWM_USE_PWM6 TRUE

// I2C0 for the OLED (GP0 = I2C0 SDA, GP1 = I2C0 SCL).
#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE
