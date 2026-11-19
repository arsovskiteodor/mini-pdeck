# Phases

The project runs as 13 steps in 4 phases. Step numbers match `STATUS.md` and the
web checklist, so they stay comparable.

| Phase | Steps | Gate: the phase is done when |
|---|---|---|
| [1. Decide](01-decide.md) | 01–02 | Every part and the footprint family are chosen, with ADRs |
| [2. Prototype](02-prototype.md) | 03–04 | Every input type works on the breadboard under QMK, and the pins are recorded |
| [3. Design](03-design.md) | 05–11 | ERC and DRC are clean, footprints are verified, and the review is addressed |
| [4. Order & build](04-order-build.md) | 12–13 | The assembled board passes every test in `bring-up.md` |

## Rules
- A step is done only when its exit criterion has **evidence**: a log entry, a file,
  a check report or a measurement. `/gate` checks this.
- Steps can overlap when they don't depend on each other. For example, step 05
  (KiCad tutorial) can run while parts are in transit.
- Never skip a gate to save time. The cheapest bug is the one caught before the order.
- Each phase file ends with **Pitfalls**: known ways this step goes wrong. Claude
  should raise them at the right moment, not all at once.
