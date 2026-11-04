# ADR-0009: Fab: JLCPCB, 2 layers, at most 100 × 100 mm, through-hole plus hand-soldered 1206 LEDs under the switches

- **Status:** Superseded by ADR-0012
- **Date:** 2026-10-30
- **Step:** 06 Draw the schematic
- **Supersedes:** ADR-0007

## Context
The owner wants a white LED under each key. Gateron's KS-33 drawing (KS-33H10B050NN-Y24 Rev 2, p. 1) reserves a
5.00 × 2.25 mm LED window behind the stem, and Gateron's product page says "LED Support: SMD". Outside the window
the housing base sits 0.30 mm above the PCB (Gateron 3D model, `parts.md` SW1–SW4), so the LED and its solder
joints must fit inside the window. ADR-0007 allowed through-hole parts only. Everything else in ADR-0007 still holds.

## Options considered
| Option | For | Against |
|---|---|---|
| A. No per-key LEDs on v1 | Keeps ADR-0007 as is; no resistor sizing, no SMD soldering | No key lighting |
| **B. 1206 SMD LEDs in the switch window, hand-soldered** | The window is designed for an SMD LED; 1206 (3.2 × 1.6 mm size code) fits 5.00 × 2.25 mm; no JLCPCB assembly fees | First SMD soldering; LED must be soldered before the switch and can't be reached afterwards |
| C. Rectangular through-hole LED | Stays through-hole | Not checked against a datasheet; round 3 mm and 5 mm LEDs are wider than 2.25 mm |
| JLCPCB assembly (PCBA) for the LEDs | No SMD hand-soldering | Setup and feeder fees for four LEDs (owner's question, 2026-10-30) |

## Decision
Option B (owner, 2026-10-30). Same fab as ADR-0007: JLCPCB bare boards, 2 layers, FR4, 1.6 mm, 5 pieces, at most
100 × 100 mm, everything hand-soldered by the owner. One exception to "through-hole only": the four per-key LEDs
(D1–D4) are 1206 SMD parts. Every other part stays through-hole.

## Consequences
- The exception covers D1–D4 only. Their series resistors (R3–R6) stay through-hole.
- Assembly order: LEDs first, test them, then solder the switches over them.
- The LED part must have a datasheet before it is bought: forward voltage at the chosen current decides whether a
  3.3 V GPIO can drive it and sets R3–R6 (with the RP2040 GPIO current limit, also TBD).
- Footprint: KiCad stock `LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder` as the starting point. Check in KiCad
  that both pads and the solder joints fall inside the switch footprint's LED window outline; if not, use the
  standard `LED_1206_3216Metric` pads.
- LED height must clear the inside of the switch above the window. Confirm with the LED datasheet and the real switch.
- Practise 1206 soldering on scrap before the real board.
- Update `fabrication.md`, `pinout.md` and the hardware rules where they say "through-hole only".

## Revisit if
- No white 1206 LED with a datasheet can be driven from a 3.3 V GPIO at a useful brightness.
- The LED or its joints don't fit the window, or the switch doesn't sit flat over it.
- Hand-soldering 1206 on scrap goes badly.

## Sources
- Gateron KS-33 drawing, KS-33H10B050NN-Y24 Rev 2, p. 1 (LED window); details in `parts.md` (SW1–SW4).
- Gateron product page, KS-33 Low Profile Red Silent 2.0 ("LED Support: SMD"):
  https://www.gateron.com/products/gateron-ks-33-low-profile-red-silent-20-mechanical-switches-set?VariantsId=11456
