# Licences

Copyright 2026 Teodor Arsovski.

This repository holds three kinds of work, so it uses three licences. Full texts are in [`LICENSES/`](LICENSES/).
Why these: [ADR-0014](docs/decisions/0014-licences.md).

| Part | Licence | Full text |
|---|---|---|
| Hardware: everything in `hardware/` and `case/`, unless a file or folder says otherwise | CERN Open Hardware Licence v2, Permissive | [`CERN-OHL-P-2.0.txt`](LICENSES/CERN-OHL-P-2.0.txt) |
| Firmware: everything in `firmware/` | GNU GPL v2 or (at your option) any later version | [`GPL-2.0-or-later.txt`](LICENSES/GPL-2.0-or-later.txt) |
| Documentation and images: everything else (`docs/`, `README.md`, `STATUS.md`, `.claude/`) | Creative Commons Attribution 4.0 International | [`CC-BY-4.0.txt`](LICENSES/CC-BY-4.0.txt) |

## Third-party files
Files copied from other projects keep their own licence. The full list is in
[`hardware/kicad/README.md`](hardware/kicad/README.md#licences-of-library-files). In short:

- KiCad stock footprints and the SnapMagic RP2040-ZERO symbol and footprint: CC BY-SA 4.0, each with an
  exception that leaves board designs using them free to use their own licence
  ([`CC-BY-SA-4.0.txt`](LICENSES/CC-BY-SA-4.0.txt)).
- The Gateron KS-33 switch footprint, from `siderakb/key-switches.pretty`: CERN-OHL-P-2.0.
- `hardware/kicad/lib/third_party/bobu01-RP2040-Zero-Kicad-Footprint-1mm/`: GPL-3.0, see its `LICENSE`.
- The firmware builds on QMK, which is "GPL2+" and asks that keyboard code be GPL-compatible
  (https://docs.qmk.fm/pr_checklist, read 2026-11-17).

Vendor 3D models (Gateron, Waveshare, SnapMagic, the FreeCAD KS-33 model) are not in this repository.
Download links are in [`docs/hardware/datasheets/README.md`](docs/hardware/datasheets/README.md).
