#pragma once

// Compile ChibiOS's PWM driver (used by the backlight on GP9).
// Defined BEFORE the include: QMK's base halconf.h only sets values that aren't defined yet.
#define HAL_USE_PWM TRUE

#include_next <halconf.h>
