---
name: log-session
description: End-of-session wrap-up. Appends today's log entry, updates STATUS.md, checks the hardware docs and suggests a commit message.
argument-hint: "[optional notes]"
disable-model-invocation: true
---

Wrap up this session. Owner's notes, if any: $ARGUMENTS

1. Work out what actually happened: review this conversation and run `git status` and `git diff --stat`.
2. Append a new `## Session N: <title>` section to `docs/log/<today YYYY-MM-DD>.md`. If the file
   doesn't exist, create it with the header from `docs/log/README.md`. **Never edit earlier entries.**
   - Facts carry their source (link, datasheet page, or "measured by owner").
   - Physical test results only as "reported by owner".
   - Decisions: link the ADR. If a real choice was made without an ADR, ask whether to run `/decision`.
3. Update `STATUS.md`:
   - date, phase and step, step checkboxes (`[~]` in progress, `[x]` only if `/gate` passed);
   - next actions: at most 5, concrete, in order;
   - blockers;
   - open questions: add new ones with the next free Q-number; for settled ones, note how they
     were settled (ADR link or measurement) in the log and remove them from the table.
4. If parts, pins, measurements or fab details changed, make sure their home files
   (`docs/hardware/parts.md`, `pinout.md`, `mechanical.md`, `fabrication.md`) reflect it.
   List anything you couldn't update and why.
5. Print a suggested commit message, `area: summary` (areas: hw, fw, docs, case, repo),
   with a short body if several areas changed. **Don't commit.**
