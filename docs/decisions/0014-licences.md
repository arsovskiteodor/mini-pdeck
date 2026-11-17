# ADR-0014: Licences: CERN-OHL-P for hardware, GPL-2.0-or-later for firmware, CC-BY for docs

- **Status:** Accepted
- **Date:** 2026-11-17
- **Step:** none (repository: before making the repo public)

## Context
The owner wants to make the repository public and link it from a master's application (2026-11-17).
Without a licence, a public repo grants nobody the right to copy, modify or build the work, only to view it.
The repo holds three kinds of work, and each kind has licences written for it:

- **Firmware** (`firmware/`): QMK keyboard files and Arduino bench sketches. QMK calls its own licence "GPL2+":
  it requires full source for any distributed binary, recommends GPL2/GPL3 for keyboard code, and accepts other
  licences only if they are GPL-compatible (QMK PR checklist). The `.uf2` we build contains QMK, so any binary
  we hand out is GPL whatever we choose for our own files.
- **Hardware** (`hardware/`, `case/`): KiCad schematic, board, project-local footprints. Software licences
  don't describe physical products made from design files; CERN-OHL v2 does.
- **Documentation** (`docs/`, READMEs, `STATUS.md`, `.claude/`, photos): prose and images.

Files copied from other projects keep their upstream licence (read 2026-11-17):
- `SW_Gateron_LowProfile_THT` comes from `siderakb/key-switches.pretty`: CERN-OHL-P-2.0 (GitHub licence API).
- `MODULE_RP2040-ZERO` and `third_party/snapmagic-RP2040-ZERO/` come from SnapMagic: CC BY-SA 4.0 with the
  SnapMagic Design Exception 1.0. Attribution is required when the files are shared; the exception lets a
  design that uses them be conveyed "under terms of your choice".
- The LED, resistor, pin-header and encoder footprints are KiCad 10 stock copies: CC BY-SA 4.0 with KiCad's
  exception, which waives the share-alike article for designs that use the library data.
- `third_party/bobu01-…/`: GPL-3.0, own `LICENSE` file. Kept as a candidate; not used on the board.
- Vendor 3D models (Gateron, Waveshare, SnapMagic, FreeCAD KS-33) are gitignored and not redistributed.

Much of the documentation and part of the firmware were drafted by Claude (README, "How I used AI").
The licence covers whatever rights the owner holds in that text; it doesn't change who wrote what.

## Options considered
**Hardware**

| Option | For | Against |
|---|---|---|
| **A. CERN-OHL-P-2.0 (permissive)** | Anyone may build, modify and sell it, keeping the notices; same licence as the switch footprint we copied; simplest to explain | Someone can make a closed derivative and not share improvements |
| B. CERN-OHL-W-2.0 (weakly reciprocal) | Changes to our files must stay open; others may combine them with closed parts | Extra obligations for little gain on a 4-key learning board; harder to explain |
| C. CERN-OHL-S-2.0 (strongly reciprocal) | Any product made from it must publish its full design; keeps everything downstream open | Strongest obligations; discourages reuse in other projects; more to get right with mixed upstream licences |
| D. CC BY-SA 4.0 | Same licence as the KiCad and SnapMagic footprints | Written for creative works, not hardware; doesn't address manufactured products |
| E. No licence (all rights reserved) | Keeps every right | Visitors may look but not reuse; contradicts sharing a learning project; GitHub still lets anyone fork the repo on GitHub |

**Firmware**

| Option | For | Against |
|---|---|---|
| **A. GPL-2.0-or-later** | QMK's own licence and its recommended header; binaries are GPL anyway | Copyleft: anyone redistributing modified firmware must publish the source (true of any QMK binary) |
| B. GPL-3.0-or-later | Also accepted by QMK; patent and anti-tivoisation clauses | Differs from the rest of QMK for no practical gain here |
| C. MIT | Permissive; GPL-compatible, so QMK accepts it | The built firmware is GPL anyway, so MIT on our few files changes nothing in practice and confuses readers |

**Documentation**

| Option | For | Against |
|---|---|---|
| **A. CC BY 4.0** | Reuse anywhere with attribution; matches the permissive hardware choice | Derivatives may be closed |
| B. CC BY-SA 4.0 | Derivatives stay open | Share-alike adds obligations to people quoting the docs; inconsistent with the hardware choice |
| C. CC0 | No conditions at all | No attribution, which a CV project wants |

**One licence for everything** (for example GPL or CC BY-SA for the whole repo): one file and simple, but each
licence fits only one of the three kinds of work, and the firmware is GPL-bound regardless.

## Decision
Hardware **CERN-OHL-P-2.0**, firmware **GPL-2.0-or-later**, documentation and images **CC BY 4.0**. Copied files
keep their upstream licence. Proposed by Claude at the owner's request; accepted by the owner (2026-11-17).

## Consequences
- Done 2026-11-17 (branch `publish`, uncommitted): `LICENSE.md` maps parts to licences; `LICENSES/` holds the
  four full texts (CERN-OHL-P-2.0, GPL-2.0-or-later, CC-BY-4.0, CC-BY-SA-4.0) from the SPDX licence list; SPDX
  headers on the 8 firmware source files; footprint licence table in `hardware/kicad/README.md`; SnapMagic
  attribution in `third_party/snapmagic-RP2040-ZERO/README.md`.
- New firmware source files need the SPDX header. `keyboard.json` can't hold comments; `LICENSE.md` covers it
  by folder.
- Every footprint copied into `minipad.pretty` gets a row in `hardware/kicad/README.md` with its upstream licence.
  A file with no stated licence stays out of the repo (as the 3D models do now).
- `MODULE_RP2040-ZERO` and the KiCad stock copies stay CC BY-SA 4.0, also after edits. Only the board design is
  CERN-OHL-P.
- Open: the SnapMagic part's original author is TBD (part page). Settles it: read the author on
  https://www.snapeda.com/parts/RP2040-ZERO/Waveshare+Electronics/view-part/.
- To verify: whether CERN-OHL v2 asks for a notice on the board or its documentation, and where (CERN-OHL v2
  user guide). Rev A carries no licence mark.
- The remapping PC app (ADR-0008) is separate software and needs its own licence decision when it exists.

## Revisit if
- The owner wants to sell boards or kits and keep competitors' derivatives open → consider CERN-OHL-S.
- The firmware moves off QMK (another framework or own code) → recheck the firmware licence.
- A third-party file is added whose licence conflicts with these (for example no licence, or non-commercial only).
- SnapMagic or KiCad change their library licence or exception text.

## Sources
- SPDX licence list texts: https://github.com/spdx/license-list-data (`text/*.txt`, downloaded 2026-11-17).
- CERN-OHL v2: https://ohwr.org/project/cernohl
- QMK PR checklist, licence requirements ("GPL2+", GPL-compatible): https://docs.qmk.fm/pr_checklist
- QMK licence violations (full source for distributed binaries): https://docs.qmk.fm/license_violations
- QMK licence file (GPL v2): https://github.com/qmk/qmk_firmware/blob/master/LICENSE
- SnapMagic, licence for symbols and footprints: https://support.snapmagic.com/en/articles/2957814-what-is-the-license-for-symbols-and-footprints
- SnapMagic, Design Exception 1.0: https://support.snapmagic.com/en/articles/2957815-what-is-the-design-exception-1-0
- KiCad library licence: https://www.kicad.org/libraries/license/
- `siderakb/key-switches.pretty` licence: GitHub API `repos/siderakb/key-switches.pretty/license` → CERN-OHL-P-2.0.
