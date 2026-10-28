---
paths:
  - "docs/log/**"
  - "docs/decisions/**"
  - "docs/phases/**"
  - "STATUS.md"
---

# Documentation rules

- **Log** (`docs/log/`): append-only. Never edit a past entry. Corrections go in today's entry,
  with a link back to the original.
- **ADRs** (`docs/decisions/`): once `Accepted`, the content is frozen. The only allowed change is
  the status line, to `Superseded by ADR-NNNN`. Keep the index in `README.md` in sync.
- **STATUS.md**: short, around 60 lines at most. It's loaded into every session through CLAUDE.md,
  so stale content costs context and misleads. It holds the present only; history goes in the log.
- **Phase files**: exit criteria change only with the owner's agreement, and the change is logged.
- Dates are ISO (`YYYY-MM-DD`). Step numbers are two digits (`04`). Open questions are `Q<n>`
  and never renumbered.
- Plain, direct sentences. A fact without a source is marked as an assumption.
