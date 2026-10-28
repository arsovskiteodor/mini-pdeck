# Mechanical

Every number here is either **measured** (with date) or **TBD**. Nothing comes from a listing photo.

## Stack-up (height above the PCB top surface)
| Item | Height (mm) | Source |
|---|---|---|
| PCB thickness | 1.6 | Fab setting (ADR-0007) |
| Keycap top, switch seated | TBD | Measure (parts.md) |
| Encoder shaft top | TBD (listing: 20 mm shaft) | Measure |
| Knob top | TBD | Measure |
| OLED glass top on its header | TBD | Measure |
| RP2040-Zero top incl. USB-C (flat mount) | TBD | Measure |
| Tallest thing on the underside (pin stubs after trimming) | TBD | Measure |

**Q6, knob vs keycap:** decide once the heights above are known. Options: shorten the shaft,
use a lower knob (6 mm knurled), or accept the difference.

## Spacing
- **Key pitch:** TBD (STATUS Q5). MX standard is 19.05 mm. Check the drawing or a measurement of the chosen keycaps.
- **Encoder clearance:** knob diameter (TBD) plus finger room next to the nearest keycap.
- **OLED:** module outline TBD; keep it clear of the knobs.
- **USB-C:** at the board edge, flush or slightly overhanging. The cable plug body needs clearance in the case.
- **BOOT button:** reachable through the case, or Bootmagic configured (ADR-0001, ADR-0005).

## Board outline
- At most 100 × 100 mm (ADR-0007). Target: as small as the parts and spacing allow.
- Mounting holes: number, size (M2 or M3) and position TBD; they depend on the case (STATUS Q7).
- Rounded corners: optional, cosmetic.

## Checks before step 10
- [ ] 1:1 paper print of the board with every real part placed on it
- [ ] Side-view sketch with the stack-up heights above
- [ ] No part overhangs another part's keep-out
