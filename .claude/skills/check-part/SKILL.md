---
name: check-part
description: Check a candidate part (product listing or link) against the macropad's requirements, or walk through verifying a part that has arrived, and record the result in docs/hardware/parts.md. Use when the owner shares a listing or says a part arrived.
argument-hint: "<part name, listing text or link>"
---

Part: $ARGUMENTS

First decide which mode applies, and say which.

## Candidate mode (a listing or link, not yet bought)
1. Identify the real part: manufacturer, part number, and whether it's a bare part or a module/breakout.
   Listings often contradict themselves; list every contradiction you find.
2. Check it against the project:
   - function and the ADR it would fill or change;
   - footprint and mounting (through-hole? matches the planned footprint?);
   - electrical: works at 3.3 V; pin count and order;
   - mechanical: fits the stack-up and spacing in `docs/hardware/mechanical.md`;
   - price vs alternatives (per unit, and including shipping if it's a separate order).
3. Check the "Rejected parts" table in `parts.md`. Don't re-suggest a rejected part without new information.
4. Verdict: **buy**, **buy with checks**, or **don't buy**, with reasons and a list of what to
   verify on arrival. If it changes an accepted ADR, propose `/decision`.

## Arrived mode (the part is on the desk)
1. Open the part's checklist in `docs/hardware/parts.md`.
2. Walk the owner through it **one measurement at a time**: say what to measure, how (calipers,
   multimeter mode, 1:1 print), and what value we'd expect and why.
3. Record each reported value in the Measurements table: value, method, date, "owner".
4. Set the status to `verified` only when every checklist item has evidence. Otherwise use `arrived`
   and list what's missing.
5. If a measurement contradicts a footprint, ADR or `pinout.md`, stop and flag it.

Never fill in a measurement the owner hasn't reported.
