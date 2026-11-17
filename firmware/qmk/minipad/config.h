// Copyright 2026 Teodor Arsovski
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// OLED (DISP1) on I2C0: SDA = GP0, SCL = GP1 (pinout.md).
// QMK's generic RP2040 board defaults to I2C1 on GP2/GP3 (docs/platformdev_rp2040.md), which are
// K1/K2 on this board, so all three must be overridden. QMK keeps the "I2C1_" names for the pins
// whichever peripheral is used.
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

// 0.96" module is 128 x 64 (parts.md, DISP1). QMK assumes 128 x 32 without this.
// Address: QMK default 0x3C, which matches the module's 0x78 pads (parts.md, DISP1).
#define OLED_DISPLAY_128X64
