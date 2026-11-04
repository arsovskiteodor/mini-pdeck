# ADR-0011: Order Rev A before the parts are verified

- **Status:** Accepted
- **Date:** 2026-11-01
- **Step:** 10 Run the pre-order checks (brought forward from phase 3; step 03 still open)

## Context
The plan puts the order (step 12) after the breadboard (step 04), footprint verification against the real parts
(step 07) and a 1:1 paper print with the real parts (step 08). The pre-order checklist in `fabrication.md` repeats
this: "Every footprint `verified`", "1:1 paper print with the real parts", "OLED pin order matches the
**received** module".

On 2026-11-01 none of the parts was on the desk: the Amazon order (2026-10-28) is in transit, and the LEDs and
resistors are not ordered. The draft routing is complete: DRC 0 violations, 0 unconnected, schematic parity
clean; key pitch set to 19.1 mm in both directions (owner and Claude, this session). The boards are cheap
(`fabrication.md`: about $2 + shipping for 5). The owner wants the boards to arrive together with the parts.

What is unverified at the time of this decision:

| Item | If wrong | Known so far |
|---|---|---|
| RP2040-Zero footprint (clone) | Board unusable: every net goes to U1 | Three candidates in `lib/third_party/`, not yet compared with the Waveshare drawing (STATUS) |
| EC11 pin holes and tab slots | Encoders don't seat; tabs bent or cut, holes reamed | Footprint **differs** from the SR Passives drawing: pin drill 1.0 mm vs Ø1.2 mm, tab slots 11.2 mm vs about 10.4 mm centre to centre (`parts.md`, ENC1–ENC2) |
| OLED pin order | VCC/GND swap can kill the module; fallback is wires instead of the header | Schematic matches the listing photos (VCC, GND, SCL, SDA), not a received module (Q10) |
| Key pitch 19.1 mm | Keycaps rub | Keycap model unknown (Q8, Q5) |
| LED forward voltage | LEDs dim or dark from 3.3 V; keys unaffected | LEDs not ordered (Q12) |
| I2C pins and pull-ups | Low risk | GP0/GP1 is a valid pair; R1/R2 are fit-if-needed (Q2, Q3, Q9) |

## Options considered
| Option | For | Against |
|---|---|---|
| **A. Order Rev A now, as a fit-check board** | Boards arrive about when the parts do; a real board is a better 1:1 test than paper; low cost | The three worst risks above (U1, EC11, OLED) are unchecked; a likely Rev B means a second shipping fee and a second wait; skips the exit criteria of steps 04, 07 and part of 08 for this revision |
| B. Wait for the Amazon parts, do a short check (calipers, 1:1 print: U1, EC11, OLED), then order | Removes the three worst risks for a delay of probably a few days; Rev A could be the final board | Boards arrive a few days to a week later than with A; LEDs and resistors still not ordered either way |
| C. Follow the plan: steps 04 and 07 first, then order | Every pin and footprint confirmed before copper; matches the phase files | Slowest; the owner judged the board cost too low to justify the wait |

Claude recommended B. The owner chose A.

## Decision
Option A (owner, 2026-11-01): order Rev A before the parts arrive, accepting it as a fit-check board that may need
a Rev B. The checks that don't need the parts are still done before ordering.

## Consequences
- **Still required before ordering** (no parts needed):
  - Commit the board; tag the ordered commit `rev-a` (`04-order-build.md`, pitfall: ordering from an uncommitted copy).
  - ERC and DRC clean via `/pre-order`, or every remaining item explained in the log.
  - RP2040-Zero footprint compared with the Waveshare drawing (pin pitch, row spacing, pin 1, USB-C at the edge).
  - Silkscreen: K1–K4, ENC1/ENC2, OLED pin labels (VCC, GND, SCL, SDA), board name, `Rev A`, date, JLCPCB
    order-number marking. The OLED labels make a mismatched module obvious before soldering.
  - Design review by the `design-reviewer` agent (step 11), every comment fixed or rejected in the log.
  - JLCPCB capabilities page checked and its date recorded in `fabrication.md`; Gerbers checked in JLCPCB's viewer.
- **Waived for Rev A** in the `fabrication.md` checklist (mark them "waived, ADR-0011" in `/pre-order`, don't tick
  them): every footprint `verified`; 1:1 paper print with the real parts; OLED pin order vs the received module.
- **Open choice before ordering:** the EC11 footprint can be adjusted now to the SR Passives drawing (pin hole and
  tab slots, values in `parts.md`), or left as KiCad stock. Both are guesses until the clone is measured.
- Steps 04 and 07 still happen, on the received parts. Their results are checked against Rev A, and every mismatch
  goes on the Rev B list (`04-order-build.md`, "After v1: retrospective").
- Bring-up: check U1's footprint on the bare board against the received module **before** soldering anything
  (`04-order-build.md`, pitfall: soldering everything before testing the MCU).
- The phase files and their exit criteria don't change; this ADR records the exception for Rev A only.

## Revisit if
- The Amazon parts arrive before the order is placed: do the option B checks first, as they then cost about an hour.
- The RP2040-Zero comparison is ambiguous, or the three candidates disagree on pin positions.
- The design review finds a problem that needs a part in hand to settle.

## Sources
- `docs/phases/02-prototype.md`, `03-design.md` (steps 07, 08, 10), `04-order-build.md`.
- `docs/hardware/fabrication.md`, "Pre-order checklist".
- `docs/hardware/parts.md`, ENC1–ENC2 footprint comparison and DISP1 notes.
- DRC run by Claude on 2026-11-01: 0 violations, 0 unconnected, 0 parity issues (4 exclusions, ADR-0009).
- Owner's choice and reasons, this session (2026-11-01).
