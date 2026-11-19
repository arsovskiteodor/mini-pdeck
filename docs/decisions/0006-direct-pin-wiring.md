# ADR-0006: Wiring: direct pins, no key matrix

- **Status:** Accepted
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec

## Context
There are 6 buttons (4 keys and 2 encoder pushes) and plenty of spare GPIO.

## Options considered
| Option | For | Against |
|---|---|---|
| Key matrix with diodes | Scales to many keys | Adds diodes and scanning logic for no benefit at 6 buttons |
| **Direct pins** | One GPIO per button, internal pull-ups, no extra parts, simplest schematic | Uses more GPIO (not a problem here) |

## Decision
Wire each button from its own GPIO to GND and use the RP2040's internal pull-ups.
In QMK this is `matrix_pins.direct`.

## Consequences
- No diodes and no pull-up resistors for the buttons.
- Encoder common pin (C) → GND; A and B → GPIO with internal pull-ups.

## Revisit if
- A future board has more than about 12 buttons.
