# ADR-0012: Fab: PCBWay instead of JLCPCB (everything else as ADR-0009)

- **Status:** Accepted
- **Date:** 2026-11-01
- **Step:** 10 Run the pre-order checks (Rev A ordered early, ADR-0011)
- **Supersedes:** ADR-0009

## Context
ADR-0009 fixed the fab as JLCPCB bare boards. Before ordering Rev A, the owner compared the checkout totals of
JLCPCB and PCBWay for the same board (69.8 × 69.1 mm, 2 layers, FR-4, 1.6 mm, 5 pieces, no assembly) and found
PCBWay cheaper, mainly in shipping (owner, 2026-11-01; amounts not recorded here, the paid cost goes in
`fabrication.md`, "Order history").

PCBWay's capabilities page (checked 2026-11-01, values in `fabrication.md`) allows everything on the board: tracks
and spacing ≥ 0.1 mm, drills 0.15–6.0 mm (extra charge under 0.2 mm or over 6 mm; ours are 0.3–5.25 mm), annular ring
≥ 0.15 mm (ours ≥ 0.2 mm), silkscreen line ≥ 0.15 mm and text ≥ 0.8 mm. The page doesn't say whether PCBWay prints an
order number on the board, and gives no copper-to-edge value for standard boards.

## Options considered
| Option | For | Against |
|---|---|---|
| A. Stay with JLCPCB (ADR-0009) | Docs, checklist and rules already written for it; capabilities checked 2026-11-01 | Higher total for this order (owner's quote) |
| **B. PCBWay** | Cheaper total for this order (owner's quote); board within all published limits; tighter plated-hole tolerance (±0.08 mm vs JLCPCB's +0.13/−0.08 mm) | Docs and checklist need updating; order-number policy unknown; no copper-to-edge value published for standard boards |

## Decision
Option B (owner, 2026-11-01): Rev A bare boards from PCBWay. Everything else in ADR-0009's Decision and Consequences
carries over unchanged: 2 layers, FR-4, 1.6 mm, 5 pieces, at most 100 × 100 mm, everything hand-soldered by the
owner, through-hole only except the four 1206 LEDs D1–D4.

## Consequences
- `fabrication.md` becomes the PCBWay page: order settings, capabilities table, checklist.
- Ask PCBWay (service@pcbway.com or the order notes) whether they add an order number to the board and where, before
  ordering. Until then this item is TBD.
- Copper-to-edge: our 0.5 mm is more than JLCPCB's 0.2 mm and PCBWay's advanced-process 0.25 mm; assumption that it is
  fine for standard boards too, since PCBWay publishes no standard value.
- Files that name JLCPCB and are not docs Claude may edit alone: `CLAUDE.md` (intro, rule 5, commands), `README.md`,
  `.claude/skills/pre-order/SKILL.md`, `.claude/agents/design-reviewer.md`, and the phase files
  (`03-design.md` pitfall, `04-order-build.md` step 12). Owner to approve the changes.
- ADR-0011 mentions JLCPCB in its checks; read those as "the fab" (accepted ADRs aren't edited).

## Revisit if
- PCBWay's DFM check rejects the board or asks for changes.
- PCBWay prints an order number somewhere unacceptable and won't move it.
- A later revision wants assembly (PCBA): compare both fabs again then.

## Sources
- PCBWay capabilities page, https://www.pcbway.com/capabilities.html, checked 2026-11-01 (Claude, page text).
- JLCPCB capabilities page, https://jlcpcb.com/capabilities/pcb-capabilities, checked 2026-11-01.
- Owner's quote comparison, this session (2026-11-01).
- ADR-0009 (superseded), ADR-0011.
