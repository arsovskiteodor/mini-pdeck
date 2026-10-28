# Pinout: RP2040-Zero

**Status: DRAFT.** These are candidate pins for breadboarding. A row is final only when all three
columns are ticked. The final assignment may change to make routing easier; any change must update
the schematic and `firmware/qmk/minipad/keyboard.json` together (CLAUDE.md, rule 4).

## Constraints
- **I2C:** SDA and SCL must be a valid RP2040 I2C pair, e.g. GP0/GP1 (I2C0), GP2/GP3 (I2C1),
  GP4/GP5 (I2C0). Confirm in the RP2040 datasheet's GPIO function table.
- **GP16** drives the onboard WS2812 RGB LED. Don't assign it.
- Use edge pins only (Waveshare: GP0–GP15 and GP26–GP29). Bottom pads are hard to reach once the
  board is soldered flat. *Confirm on the received clone.*
- **Buttons:** GPIO → switch → GND, using the internal pull-up (QMK direct pins, ADR-0006). No resistors.
- **Encoders:** C (common) → GND; A and B → GPIO with internal pull-ups.
- **OLED power:** VCC → 3V3 pin, not 5V. GND → GND.

## Assignment
| Signal | GPIO (candidate) | Breadboard ✔ | Schematic ✔ | Firmware ✔ |
|---|---|---|---|---|
| OLED SDA | GP0 | ☐ | ☐ | ☐ |
| OLED SCL | GP1 | ☐ | ☐ | ☐ |
| K1 | GP2 | ☐ | ☐ | ☐ |
| K2 | GP3 | ☐ | ☐ | ☐ |
| K3 | GP4 | ☐ | ☐ | ☐ |
| K4 | GP5 | ☐ | ☐ | ☐ |
| ENC1 A | GP6 | ☐ | ☐ | ☐ |
| ENC1 B | GP7 | ☐ | ☐ | ☐ |
| ENC1 push | GP8 | ☐ | ☐ | ☐ |
| ENC2 A | GP26 | ☐ | ☐ | ☐ |
| ENC2 B | GP27 | ☐ | ☐ | ☐ |
| ENC2 push | GP28 | ☐ | ☐ | ☐ |
| Onboard RGB LED | GP16 (fixed) | — | — | ☐ |

**Spare:** GP9–GP15, GP29.

## Changelog
| Date | Change | Why |
|---|---|---|
| 2026-10-28 | Draft created | Breadboard starting point |
