# Mechanical

Every number here is either **measured** (with date) or **TBD**. Nothing comes from a listing photo.

## Stack-up (height above the PCB top surface)
| Item | Height (mm) | Source |
|---|---|---|
| PCB thickness | 1.6 | Fab setting (ADR-0009) |
| Keycap top, switch seated | TBD | Measure (parts.md) |
| Encoder shaft top | TBD (listing: 20 mm shaft) | Measure |
| Knob top | TBD | Measure |
| OLED glass top, module header soldered into the board | TBD | Measure (header spacer + module) |
| RP2040-Zero top incl. USB-C (flat mount) | TBD | Measure |
| Tallest thing on the underside (pin stubs after trimming) | TBD | Measure |

**Q6, knob vs keycap:** decide once the heights above are known. Options: shorten the shaft,
use a lower knob (6 mm knurled), or accept the difference.

## Spacing
- **Key pitch:** 19.1 mm in both directions on the Rev A board (owner, 2026-11-01), provisional until the keycap
  model is known (STATUS Q8, Q5; ADR-0011). MX standard is 19.05 mm. Check the drawing or a measurement of the chosen keycaps.
- **Encoder clearance:** knob diameter (TBD) plus finger room next to the nearest keycap.
- **OLED:** module outline TBD; keep it clear of the knobs.
- **USB-C:** at the board edge, flush or slightly overhanging. The cable plug body needs clearance in the case.
- **BOOT button:** reachable through the case, or Bootmagic configured (ADR-0001, ADR-0005).

## Board outline
- At most 100 × 100 mm (ADR-0009). Target: as small as the parts and spacing allow.
- Outline on the board (2026-10-31): a rough box of about 70 × 69 mm around the draft placement, not a target size.
- Mounting holes: four M3, one per corner, plated pad on GND (`MountingHole_3.2mm_M3_Pad`, ADR-0010). Exact
  positions follow the final outline, at the centre of each corner arc. Screw head or standoff clearance to the
  keycaps, knobs, OLED and USB-C plug: TBD (ADR-0010, Consequences).
- Rounded corners: optional, cosmetic.

## Inputs for the case decision (Q7)
- **OLED mounting** (discussed 2026-10-30). The module's own header is soldered into the board (no socket), so the
  header holds one edge. Mounting holes are **undecided** (owner, 2026-10-30).
  - A. Module on the PCB, plus standoffs in its four holes; the case has a window over the display. Recommended: the
    PCB and display stay one testable unit.
  - B. Module screwed to the case, connected to the PCB by four wires instead of the header.
  - C. Module screwed to the case *and* soldered to the board: not recommended. Two parts fix its position, so any
    case-to-PCB mismatch bends the header and its joints.
  - D. No holes: header only, with a lip in the case lid resting on the module's far edge.
  - Standoffs (option A): nylon, height = the module's header spacer height (measure). Keep traces away from the
    standoff and screw-head area.

## Checks before step 10
- [ ] 1:1 paper print of the board with every real part placed on it
- [ ] Side-view sketch with the stack-up heights above
- [ ] No part overhangs another part's keep-out
