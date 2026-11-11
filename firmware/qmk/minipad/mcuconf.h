#pragma once

// Include the base file FIRST: it sets every value unconditionally,
// so we override afterwards with #undef + #define.
#include_next <mcuconf.h>

// Turn on PWM slice 4 (GP9 = slice 4, channel B).
#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE
