# Datasheets and references

PDFs saved in this folder are gitignored (copyright, and they bloat the repo). Keep the links here,
and note the page numbers you relied on in `parts.md`.

| Part | Document | Link | Notes |
|---|---|---|---|
| RP2040 | Datasheet (GPIO function table for I2C pairs) | https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf | Read from PDF text. Pull-up citations are in `parts.md` (DISP1). |
| I2C bus | NXP UM10204, I2C-bus specification and user manual, Rev 7.0 | https://www.nxp.com/docs/en/user-guide/UM10204.pdf | Read from PDF text. Pull-up citations are in `parts.md` (DISP1). |
| RP2040-Zero | Waveshare wiki: pinout, dimensions | https://www.waveshare.com/wiki/RP2040-Zero | For the original, not the clone |
| Gateron KS-33 | Gateron 3D models | https://www.gateron.com/pages/3d | |
| Gateron low-profile footprint | KiCad library | https://github.com/siderakb/key-switches.pretty | KS-27 and KS-33 share a footprint |
| EC11 (generic) | Similar part for reference: SR Passives EC11E20-20P20C-SW | https://www.tme.eu/Document/f67c6eb1b15f4dd5809b64accc815a9a/EC11E20-20P20C-SW.pdf | Our part is generic; measure it |
| SSD1306 | Controller datasheet (owner's copy) | https://www.alldatasheet.com/datasheet-pdf/pdf/1179026/ETC2/SSD1306.html | Found by owner. Fetch blocked (HTTP 403). Owner pasted §8.1.5 (MCU I2C Interface); page TBD. Assumed to be the same copy. |
| SSD1306 | Controller datasheet, v1.1 (Crystalfontz) | https://www.crystalfontz.com/controllers/SSD1306 | Listing page with the PDF. Not read. Page numbers TBD. |
| SSD1306 | Controller datasheet, Rev 1.5 "Advance Information" (Radiolocman) | https://www.radiolocman.com/datasheet/data.html?di=615783 | Found in search, not read. Page numbers TBD. |
| SSD1306 | Controller datasheet (ChipDip copy) | https://static.chipdip.ru/lib/490/DOC001490735.pdf | Found in search. Revision and maker not checked. Not read. |
| JLCPCB | PCB capabilities | https://jlcpcb.com/capabilities/pcb-capabilities | Check before ordering |
| QMK | RP2040 platform, Encoders, OLED driver | https://docs.qmk.fm | |
| VIA | Configuring QMK for VIA | https://caniusevia.com/docs/configuring_qmk/ | |
