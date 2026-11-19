# Phase 2: Prototype (steps 03–04)

**Goal:** prove every part works with QMK on a breadboard before any of it becomes copper.

## 03 Buy the parts 🔄
- **Ordered:** 2026-10-28 (see `docs/hardware/parts.md`).
- **Exit criterion:** all parts on the desk, and each part has gone through `/check-part` in arrived mode.
- **Evidence:** status `arrived` or `verified` for every row in `parts.md`.

## 04 Breadboard and flash firmware
**Tasks**
1. Solder headers to **one** RP2040-Zero. Keep the second one bare.
2. Flash any test UF2 (QMK or the official blink) to prove the board and cable work.
3. Create the keyboard with `qmk new-keyboard` (RP2040, direct pins) and move it into
   `firmware/qmk/minipad/` (see `firmware/README.md`).
4. Wire **one** switch, **one** encoder and the OLED using the candidate pins in
   `docs/hardware/pinout.md`.
5. Map the switch to a letter, the encoder to Volume Up/Down, the encoder push to Mute,
   and draw something on the OLED.
6. Test the second encoder and the other key pins too, so every assigned pin gets used once.

**Exit criterion:** the key types; the encoder turns the right way, one step per detent;
the encoder push works; the OLED shows text. All pins are marked "breadboard ✔" in `pinout.md`.

**Evidence:** a log entry with the owner's reported results, the updated `pinout.md`,
and the firmware committed.

## Pitfalls
- **Charge-only USB-C cables.** If the board never shows up as `RPI-RP2`, try another cable first.
- **EC11 on a breadboard.** The mounting tabs don't fit. Solder short wires to the legs, or bend the tabs flat.
- **OLED pin order.** It differs between sellers. Read the labels printed on *your* module.
- **I2C pins** must be a valid RP2040 I2C pair, and QMK needs the I2C driver enabled for RP2040.
- **Encoder direction reversed:** swap A and B in the config, not the wires.
- **Double or half steps per detent:** adjust the encoder `resolution` in QMK; don't rewire.
