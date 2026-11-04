# Datasheets and references

PDFs saved in this folder are gitignored (copyright, and they bloat the repo). Keep the links here,
and note the page numbers you relied on in `parts.md`.

| Part | Document | Link | Notes |
|---|---|---|---|
| RP2040 | Datasheet (GPIO function table for I2C pairs) | https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf | Read from PDF text. Pull-up citations are in `parts.md` (DISP1). |
| I2C bus | NXP UM10204, I2C-bus specification and user manual, Rev 7.0 | https://www.nxp.com/docs/en/user-guide/UM10204.pdf | Read from PDF text. Pull-up citations are in `parts.md` (DISP1). |
| RP2040-Zero | Waveshare wiki: pinout, dimensions | https://www.waveshare.com/wiki/RP2040-Zero | For the original, not the clone |
| RP2040-Zero | Waveshare 3D model, `RP2040_Zero.stp` | Link TBD (owner) | No licence stated: gitignored, local copy in `lib/third_party/waveshare-RP2040-Zero-3d/`. Attached to `minipad.pretty/MODULE_RP2040-ZERO` (`parts.md`, U1). Tracked in commit `dfef7d8`, untracked 2026-10-31. |
| RP2040-Zero | SnapMagic symbol, footprint and 3D model (download zip) | Link TBD (owner) | No licence file in the download. Symbol and footprint stay tracked (the project loads the symbol); the zip and `models/RP2040-ZERO.step` are gitignored. Licence to check before the repo goes public. |
| Gateron KS-33 | Gateron 3D models | https://www.gateron.com/pages/3d | KS-33 Low Profile 2.0 model: https://www.gateron.com/u_file/2309/25/file/GateronKS-33LowProfile20KS33-20230109KS-33-Y313D.rar (RAR, one STEP). Local copy and checks in `parts.md` (SW1–SW4). |
| Gateron KS-33 | Drawing and product specification, KS-33H10B050NN-Y24 Rev 2 (DS-02-001-A0, SPEC-KS-33-002), 2023-01-03 | Owner's copy; link TBD | p. 1 is the drawing (footprint check in `parts.md`, SW1–SW4). No text layer; read from a rendered image. Red Switch 2.0 at 50 gf, not our 45 gf Silent. |
| Gateron low-profile footprint | KiCad library | https://github.com/siderakb/key-switches.pretty | KS-27 and KS-33 share a footprint |
| EC11 (generic) | Similar part for reference: SR Passives EC11E20-20P20C-SW | https://www.tme.eu/Document/f67c6eb1b15f4dd5809b64accc815a9a/EC11E20-20P20C-SW.pdf | Our part is generic; measure it. Drawings are images: read from a rendered page. p. 2 = dimensions and mounting holes (comparison in `parts.md`, ENC1–ENC2) |
| SSD1306 | Controller datasheet (owner's copy) | https://www.alldatasheet.com/datasheet-pdf/pdf/1179026/ETC2/SSD1306.html | Found by owner. Fetch blocked (HTTP 403). Owner pasted §8.1.5 (MCU I2C Interface); page TBD. Assumed to be the same copy. |
| SSD1306 | Controller datasheet, v1.1 (Crystalfontz) | https://www.crystalfontz.com/controllers/SSD1306 | Listing page with the PDF. Not read. Page numbers TBD. |
| SSD1306 | Controller datasheet, Rev 1.5 "Advance Information" (Radiolocman) | https://www.radiolocman.com/datasheet/data.html?di=615783 | Found in search, not read. Page numbers TBD. |
| SSD1306 | Controller datasheet (ChipDip copy) | https://static.chipdip.ru/lib/490/DOC001490735.pdf | Found in search. Revision and maker not checked. Not read. |
| PCBWay | PCB capabilities | https://www.pcbway.com/capabilities.html | Fab for Rev A (ADR-0012). Check before ordering |
| JLCPCB | PCB capabilities | https://jlcpcb.com/capabilities/pcb-capabilities | Previous fab (ADR-0009, superseded) |
| QMK | RP2040 platform, Encoders, OLED driver | https://docs.qmk.fm | |
| VIA | Configuring QMK for VIA | https://caniusevia.com/docs/configuring_qmk/ | |
