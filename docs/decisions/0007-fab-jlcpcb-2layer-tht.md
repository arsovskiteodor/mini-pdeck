# ADR-0007: Fab: JLCPCB, 2 layers, at most 100 × 100 mm, through-hole, hand-soldered

- **Status:** Superseded by ADR-0009
- **Date:** 2026-10-28
- **Step:** 01 Lock the spec

## Context
A cheap first order that the owner assembles by hand.

## Options considered
| Option | For | Against |
|---|---|---|
| **JLCPCB, bare boards** | Fixed low price for 2-layer boards up to 100 × 100 mm; very common, so there are lots of guides | Shipping costs more than the boards |
| JLCPCB with assembly (PCBA) | Allows SMD parts | Setup fees; not needed when every part is through-hole |
| Other fabs or coupon deals | Possibly cheaper | Less familiar; not worth the risk on a first board |

## Decision
JLCPCB bare boards: 2 layers, FR4, 1.6 mm, 5 pieces, at most 100 × 100 mm. Every part is
through-hole and hand-soldered.

## Consequences
- Above 100 × 100 mm the price jumps, so the outline must fit.
- No SMD parts on v1 (the RP2040-Zero module counts as hand-solderable through its edge pads or headers).
- Settings and rules: `docs/hardware/fabrication.md`.

## Sources
- Hack Club, JLCPCB cost optimizing: https://hwdocs.hackclub.dev/user-contrib-guides/jlc-cost-optimizing/
