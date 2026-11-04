# ADR-0010: Mounting holes: four M3, one per corner, plated and tied to GND

- **Status:** Accepted
- **Date:** 2026-10-31
- **Step:** 08 Place the parts (draft placement, running ahead)

## Context
The case approach is still open (STATUS Q7), and `mechanical.md` listed the mounting holes as "number, size (M2 or
M3) and position TBD". During a draft placement on the night of 2026-10-30 the owner added four mounting holes,
first as M2 (`MountingHole_2.2mm_M2_Pad`), then changed them to M3 on 2026-10-31. The board must stay within
100 × 100 mm, 2 layers (ADR-0009). The outline on the board is a rough box (about 70 × 69 mm), not a target size.

The holes are the one part of the case that the PCB fixes. Settling them now lets placement and routing keep
clear of them, while the case itself stays open.

KiCad stock footprint `MountingHole:MountingHole_3.2mm_M3_Pad`, as placed on the board: one plated through-hole
pad, drill Ø3.2 mm, pad Ø6.4 mm on both copper layers (read from `mini-pdeck.kicad_pcb`, 2026-10-31).

## Options considered
| Option | For | Against |
|---|---|---|
| A. M2 at the corners (first version placed) | Smaller pad, leaves more room next to the outer keys and encoders | Owner: harder to source, weaker |
| **B. M3 at the corners, plated pad on GND** | Owner: easier to source, stronger; gives GND a path through metal screws or standoffs to the case | Bigger keep-out in every corner (near DISP1, U1, SW3 and ENC1 in the draft placement); screws and standoffs are tied to GND whether wanted or not |
| C. M3 at the corners, unplated hole, no pad | No copper under the screw heads; simpler | No GND path |
| D. No holes until the case is decided (Q7) | Nothing to undo if the case wants something else | Placement and routing can't keep clear of holes that aren't there yet |

## Decision
Option B (owner, 2026-10-31): four M3 holes, one in each corner of the board, using
`MountingHole:MountingHole_3.2mm_M3_Pad` with the pad on the GND net. Exact positions follow the final outline.

## Consequences
- Partly answers Q7: whatever case is chosen must mount on these four M3 corner holes. The case approach and
  OLED support (options A–D in `mechanical.md`) stay open.
- The owner has a case design in mind but hasn't named it yet (assumption until it is written down under Q7).
- Clearance is unchecked (draft placement): H1 is near DISP1, H2 near U1, H3 near SW3 and H4 near ENC1. Check that
  the screw head or standoff diameter (TBD, depends on the hardware bought) clears the OLED module, the USB-C plug,
  the keycap (Q5, Q8) and the knob (Q6).
- The hole footprint's courtyard must cover the screw head or standoff of the chosen hardware; enlarge it if not.
- The ground pour will connect to the hole pads. Metal standoffs or a metal case then sit at GND.
- When the outline is final, place each hole at the centre of its corner arc, with coordinates, not by eye.
- Update `mechanical.md` (Board outline, Mounting holes) to point here.

## Revisit if
- The chosen case can't use four corner holes, e.g. it needs holes between the keys or a different size.
- Screw heads or standoffs collide with a keycap or knob once their sizes are known.
- The GND connection to the case causes a problem in testing (reported by owner).

## Sources
- `hardware/kicad/mini-pdeck.kicad_pcb`, footprints H1–H4, read 2026-10-31.
- Owner's reasons, this session (2026-10-31).
- `docs/hardware/mechanical.md`, "Board outline" and "Inputs for the case decision (Q7)".
