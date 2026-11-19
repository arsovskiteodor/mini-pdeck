---
name: where-are-we
description: Start-of-session briefing for the macropad project. Use at the start of a session, or when the owner asks where the project stands or what to do next.
---

Give the owner a short briefing before any work starts.

1. Read `STATUS.md`, the newest file in `docs/log/`, and the phase file in `docs/phases/`
   that contains the current step.
2. Run `git status` and `git log --oneline -5` to spot uncommitted or unlogged work.
3. Reply briefly, in this order:
   - **Where:** phase and step, and the step's exit criterion quoted from the phase file.
   - **Last time:** 2–3 bullets from the newest log entry.
   - **Blocking:** open questions (Q-numbers) that block the current step.
   - **Next:** the single best next action, and why it comes before the others.
   - **Inconsistencies:** anything in STATUS.md that looks stale or contradicts the log,
     the git state or the docs. Say so plainly; don't quietly fix it.
4. Mention one pitfall from the current phase file if it's relevant to the next action.
5. Don't start the work until the owner confirms.
