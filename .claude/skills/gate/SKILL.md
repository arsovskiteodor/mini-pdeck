---
name: gate
description: Strict gate review of the current step's exit criteria against evidence in the repo, before the step is marked done.
argument-hint: "[step number, defaults to the current step]"
disable-model-invocation: true
---

Gate review for step: $ARGUMENTS (if empty, use the current step in `STATUS.md`).

1. Read the step's exit criterion and tasks in `docs/phases/`.
2. For each criterion, find evidence in the repo: a log entry, a file, a check report
   (ERC/DRC), a measurement in `parts.md`, a ticked row in `pinout.md`.
3. Report a table: **criterion | evidence (file and line, or link) | pass / fail / unclear**.
4. Be strict. "Probably fine" is a fail. Missing evidence is a fail; say exactly what would
   provide it (a measurement, a test, a report).
5. For design steps (06–11), also ask the `design-reviewer` agent for an independent pass and
   include its findings.
6. Only if everything passes: propose the STATUS.md update (tick the step, set the next step and
   next actions). Wait for the owner's OK before editing anything.
