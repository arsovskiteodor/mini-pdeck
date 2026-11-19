---
paths:
  - "firmware/**"
---

# Firmware rules (QMK)

- Pins come from `docs/hardware/pinout.md`. If firmware needs a different pin, change
  `pinout.md` first and flag the schematic.
- Prefer data-driven `keyboard.json`. Use `config.h`, `halconf.h` and `mcuconf.h` only for what
  JSON can't express (e.g. the RP2040 I2C driver for the OLED).
- RP2040 pin names are written `GP0`, `GP1`, … in QMK config.
- Buttons are direct pins (ADR-0006): `matrix_pins.direct`, no diodes, internal pull-ups.
- GP16 is the onboard WS2812 LED. Don't use it for anything else.
- Build with `qmk compile -kb minipad -km default`. Read compiler errors fully before changing things.
- Never claim firmware works on hardware. Compiling proves it builds; only the owner's test proves it works.
- The owner flashes the board. `qmk flash` needs the board in bootloader mode and always asks first.
- When VIA is enabled (ADR-0008): the stored keymap overrides `keymap.c` after first boot.
  Remind the owner about `EE_CLR` when keymap edits "don't apply".
- Explain what each config line does the first time it appears. The owner is learning QMK.
