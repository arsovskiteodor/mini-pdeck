#pragma once

// Compile the ChibiOS drivers we use. Defined BEFORE the include: QMK's base halconf.h
// only sets values that aren't defined yet.
#define HAL_USE_PWM TRUE // key LEDs D1-D4 on GP9-GP12
#define HAL_USE_I2C TRUE // OLED on GP0/GP1

#include_next <halconf.h>
