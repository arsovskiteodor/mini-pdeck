# ADR-0005: Firmware: QMK

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec

## Context
The firmware must do USB HID (keyboard plus media keys), handle encoders and drive the OLED.
The owner also wants to learn how firmware works.

## Options considered
| Option | For | Against |
|---|---|---|
| KMK (CircuitPython) | Edit a Python file on the USB drive and see the change instantly | Teaches less about compiled firmware; smaller ecosystem |
| **QMK (C)** | The standard for keyboards; teaches embedded C; supports VIA remapping | Toolchain setup; compile-and-flash cycle |

## Decision
QMK.

## Consequences
- Set up the toolchain (`qmk setup`) and prove it by compiling an existing RP2040 keyboard before writing our own.
- Keyboard definition in `firmware/qmk/minipad/`, linked into `qmk_firmware/keyboards/` (see `firmware/README.md`).
- The OLED needs the RP2040 I2C driver configured (QMK's RP2040 platform docs).
- Plan bootloader access in the case: the BOOT button stays reachable, or Bootmagic is enabled.

## Revisit if
- The QMK toolchain becomes the bottleneck for the PCB learning goal.
