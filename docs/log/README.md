# Log

One file per day, `YYYY-MM-DD.md`. Several sessions on the same day become sections in that file.
`/log-session` writes these entries.

**Rules**
- Append-only. Never rewrite a past entry. To correct something, say so in today's entry and link back.
- Facts carry their source: a link, a datasheet page, or "measured by owner".
- Physical test results are written as "reported by owner".
- Decisions get an ADR; the log just links to it.

## Entry format
```markdown
# YYYY-MM-DD

## Session N: <short title>
**Phase/step:** <phase>, <step>

### Done
- 

### Found / learned
- 

### Decisions
- ADR-NNNN <title> (link)

### Problems
- 

### Next
- 
```
