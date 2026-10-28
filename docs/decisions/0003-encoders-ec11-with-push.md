# ADR-0003: Encoders: generic EC11 with push switch, 20 detents

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec

## Context
The two knobs should click once per step (detents) and press as buttons. They should also
use the footprint that most macropad guides and QMK examples assume.

## Options considered
| Option | For | Against |
|---|---|---|
| Alps EC12E2430 (Diotronic, €2.50) | Genuine Alps | **0 detents, no push switch** (Farnell, RS), EC12 footprint, shaft 20 or 25 mm |
| Diotronic EC11E2020SW (€4.54 each) | Right type: 20/20 with switch | About 3× the price; no datasheet |
| Bourns PEC11L, 15 mm shaft | "Low profile" series, shorter shaft | Separate distributor order; pin layout vs EC11 unconfirmed |
| Horizontal EC11B | Lies flat | Knob sticks out of the side; complicates the case |
| Panasonic EVQWGD001 roller | The classic low-profile scroll wheel | Discontinued |
| **Generic EC11, 5-pack with knobs (Xatgiouy, €7.99)** | Push switch, 20 steps per turn, knobs included, cheap, spares | Generic: no datasheet; 20 mm shaft is tall next to low-profile keys |

## Decision
Generic EC11 with push switch, 20 steps per turn, 6 mm knurled shaft 20 mm long; 5-pack with knobs
from Amazon. The product photo confirmed bare encoders (not KY-040 modules) with vertical legs and mounting tabs.

## Consequences
- Starting footprint: KiCad `RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm`. Verify the pin pitch,
  pin positions and mounting tab slots against the real part.
- The QMK default encoder resolution should give one step per detent with 20 pulses / 20 detents. Confirm on the breadboard.
- Knurled shaft: replacement knobs must be for a knurled (often "18 teeth") 6 mm shaft, not a D-shaft.
- Knob height vs keycap height is STATUS Q6. Options: shorten the shaft with a hacksaw, or use a lower knob.

## Revisit if
- Detents and pulses aren't 1:1 in testing, or the footprint doesn't match.

## Sources
- Farnell EC12E2430804 (0 detents, no push switch): https://uk.farnell.com/alps/ec12e2430804/encoder-vertical-12mm-0det-24ppr/dp/2065070
- RS EC12E2430803: https://befr.rs-online.com/web/p/mechanical-rotary-encoders/7295842
- TME, a similar generic EC11 (20/20 with switch) for reference: https://www.tme.eu/ee/details/ec11e20-20p20c-sw
- SparkFun (EVQWGD001 discontinued): https://www.sparkfun.com/sparkfun-roller-encoder-breakout.html
