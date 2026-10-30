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
| OLED SDA | GP0 | ☐ | ☑ | ☐ |
| OLED SCL | GP1 | ☐ | ☑ | ☐ |
| K1 | GP2 | ☐ | ☑ | ☐ |
| K2 | GP3 | ☐ | ☑ | ☐ |
| K3 | GP4 | ☐ | ☑ | ☐ |
| K4 | GP5 | ☐ | ☑ | ☐ |
| ENC1 A | GP6 | ☐ | ☑ | ☐ |
| ENC1 B | GP7 | ☐ | ☑ | ☐ |
| ENC1 push | GP8 | ☐ | ☑ | ☐ |
| ENC2 A | GP26 | ☐ | ☑ | ☐ |
| ENC2 B | GP27 | ☐ | ☑ | ☐ |
| ENC2 push | GP28 | ☐ | ☑ | ☐ |
| Onboard RGB LED | GP16 (fixed) | — | — | ☐ |
| LED1 (under K1) | GP9 | ☐ | ☑ | ☐ |
| LED2 (under K2) | GP10 | ☐ | ☑ | ☐ |
| LED3 (under K3) | GP11 | ☐ | ☑ | ☐ |
| LED4 (under K4) | GP12 | ☐ | ☑ | ☐ |

**Spare:** GP13–GP15, GP29.

**Per-key LEDs:** 1206 SMD in the switch's LED window, hand-soldered (ADR-0009). The LED part and the series
resistor value are TBD (LED datasheet and the RP2040 GPIO current limit; see `parts.md`, D1–D4).

**Edge pins only:** Waveshare's wiki says 20 of the 29 GPIOs come out on the edge pins and the rest only on
solder pads underneath. The `RP2040-ZERO` symbol in the schematic has exactly 20 GPIOs (GP0–GP15, GP26–GP29),
so every pin assigned above is an edge pin. Confirm on the received clone (`parts.md`, U1).

## Changelog
| Date | Change | Why |
|---|---|---|
| 2026-10-28 | Draft created | Breadboard starting point |
| 2026-10-30 | LED1–LED4 on GP9–GP12 (candidate) | Draft schematic has 4 per-key LEDs; owner asked for edge pins only |
| 2026-10-30 | Schematic ✔ ticked for all 16 assigned pins | Netlist exported with `kicad-cli` matches this table; ERC 0 errors. Schematic is a draft until step 04 |
