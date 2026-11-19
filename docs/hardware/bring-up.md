# Bring-up and test procedures

Physical results are always recorded as "reported by owner", with the date, in the log and in the tables below.

## A. Breadboard (step 04)
1. Flash a test UF2: hold BOOT, plug in USB, and the `RPI-RP2` drive appears. Drag the UF2 onto it.
2. Wire the OLED (VCC → 3V3, GND, SDA, SCL on the candidate pins). Show text.
3. Wire one switch (GPIO → switch → GND). It should type a letter.
4. Wire one encoder (C → GND, A/B → GPIO, push → GPIO and GND). Volume up/down and mute.
5. Move the switch and encoder across every assigned pin so each pin is tested once.

| Test | Expected | Result | Date |
|---|---|---|---|
| Board shows up as `RPI-RP2` | Drive appears | ✔ (owner) | 2026-11-11 |
| QMK firmware enumerates | Keyboard device appears | ✔ (owner) | 2026-11-11 |
| OLED | Text visible | ✔ on Rev A (owner) | 2026-11-14 |
| Key on each of K1–K4's pins | Correct keycode | ✔ on Rev A: a, b, c, d (owner) | 2026-11-14 |
| ENC1 clockwise / counter-clockwise | Volume up / down, 1 step per detent | ✔ on Rev A: 20 per turn, CW = up (owner) | 2026-11-19 |
| ENC1 push | Mute | ✔ on Rev A (owner) | 2026-11-19 |
| ENC2 clockwise / counter-clockwise / push | As mapped | ✔ on Rev A: → / ←, 20 per turn; push = Enter (owner) | 2026-11-19 |

## B. Bare PCB checks (before soldering anything)
1. Visual check: no bridges or missing copper; drill holes present.
2. Multimeter continuity: **5V ↔ GND and 3V3 ↔ GND must be open** (no short).
3. Spot-check a few nets against the schematic (e.g. K1 pad ↔ its GPIO pad).

## C. Staged assembly (step 13). Test after each stage.
| Stage | Solder | Then test |
|---|---|---|
| 1 | RP2040-Zero (flat, edge pads) | Shorts check again; plug in; `RPI-RP2` appears; flash firmware; the board enumerates |
| 2 | OLED header and OLED | Text visible |
| 3 | Encoders | Both directions plus push, both encoders |
| 4 | Switches (or hot-swap sockets first) | Every key |

Solder in this order because the lowest parts go first and the MCU is proven before anything else
depends on it.

## D. Final acceptance
| Input | Expected | Result | Date |
|---|---|---|---|
| K1–K4 | Mapped keycodes | ✔ a, b, c, d (owner) | 2026-11-14 |
| ENC1 / ENC2 rotate | One step per detent, correct direction | ✔ 20 per turn, CW = up, both (owner) | 2026-11-19 |
| ENC1 / ENC2 push | Mapped action | ✔ Mute / Enter (owner) | 2026-11-19 |
| OLED | Shows layer/status | ✔ status screen: last action, presses, encoder counts (owner) | 2026-11-19 |
| Bootmagic (if configured) | Enters bootloader | | |
| VIA (optional for v1) | Remap a key live; it survives unplugging | | |

## Troubleshooting
| Symptom | Check first |
|---|---|
| Board not detected at all | Charge-only USB-C cable; try another cable or port |
| No `RPI-RP2` drive | BOOT held *while* plugging in; USB solder joints (stage 1) |
| OLED blank | Pin order (VCC/GND swapped?), I2C pins are a valid pair, I2C driver enabled in QMK, address 0x3C vs 0x3D, pull-ups (Q3), powered from 3V3 |
| Encoder direction reversed | Swap A/B in `keyboard.json`, not on the board |
| Two steps or half a step per detent | Encoder `resolution` in QMK |
| Key does nothing | Continuity from switch pad to GPIO; cold solder joint; wrong pin in config |
| Keymap edits don't apply (VIA on) | Stored keymap overrides `keymap.c`: clear it with `EE_CLR` |
