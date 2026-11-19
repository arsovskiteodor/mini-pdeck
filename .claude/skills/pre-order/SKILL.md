---
name: pre-order
description: Step 10 pre-order check. Runs ERC and DRC with kicad-cli, generates JLCPCB fab files when clean, and walks through the fabrication checklist. Never places an order.
disable-model-invocation: true
allowed-tools: Bash(kicad-cli *)
---

Run the pre-order check for `hardware/kicad/minipad`.

1. `kicad-cli version`: note the version in the report. Flags differ between versions; if a
   command fails, check `kicad-cli <command> --help` and adapt instead of guessing.
   Make sure `hardware/kicad/production/` exists (it's gitignored, so a fresh clone won't have it).
2. ERC:
   `kicad-cli sch erc --severity-all --exit-code-violations -o hardware/kicad/production/erc.rpt hardware/kicad/mini-pdeck.kicad_sch`
3. DRC (with schematic parity):
   `kicad-cli pcb drc --schematic-parity --severity-all --exit-code-violations -o hardware/kicad/production/drc.rpt hardware/kicad/mini-pdeck.kicad_pcb`
4. For every violation, explain what it means, the likely cause, and whether it must be fixed or is
   acceptable (with the reason). The bar is zero unexplained violations.
5. Check that the board outline is at most 100 × 100 mm and that the design rules match
   `docs/hardware/fabrication.md`.
6. Only if ERC and DRC are clean: export Gerbers and drill files into
   `hardware/kicad/production/gerbers/` (`kicad-cli pcb export gerbers` and
   `kicad-cli pcb export drill`, using the board's saved plot settings if supported), then list
   the generated files.
7. Go through the pre-order checklist in `docs/hardware/fabrication.md` with the owner, item by item.
   Items that need the owner's eyes (paper print, 3D view, JLCPCB's Gerber viewer) stay open until
   they report back.
8. Verdict: **ready** or **not ready**, with the blocking items. The owner uploads and orders.
