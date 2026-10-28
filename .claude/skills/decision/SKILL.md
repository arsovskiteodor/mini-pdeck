---
name: decision
description: Record a design decision as a numbered ADR in docs/decisions, from the alternatives discussed in this session.
argument-hint: "<short title>"
disable-model-invocation: true
---

Create an ADR for: $ARGUMENTS

1. Find the highest number in `docs/decisions/` and use the next one (4 digits).
2. Copy `docs/decisions/0000-template.md` to `docs/decisions/NNNN-<kebab-case-title>.md` and fill it in:
   - **Context:** constraints and what we knew, with sources.
   - **Options:** every real alternative discussed, with honest pros and cons. Include the ones
     the owner leaned against. No straw men.
   - **Consequences:** follow-up tasks, risks, and things to verify.
   - **Revisit if:** concrete, checkable conditions.
3. Status is `Proposed` unless the owner has clearly decided; then `Accepted` with today's date.
4. If it replaces an earlier ADR, set the old one's status to `Superseded by ADR-NNNN`
   (the only edit allowed to an accepted ADR) and link both ways.
5. Add a row to the index in `docs/decisions/README.md`.
6. If it settles a STATUS open question, say which one, so `/log-session` can close it.
7. Show the owner the full ADR for review before finishing.
