# Phase 1: Decide (steps 01–02) ✅ complete

**Goal:** choose every part before designing anything, with the reasons written down.

## 01 Lock the spec ✅
- **Spec:** 4 keys, 2 encoders with push buttons, 1 OLED, USB-C, low-profile.
- **GPIO budget:** 4 keys + 2 × (A, B, push) + 2 (I2C) = **12**. The RP2040-Zero has about 20 on its edges.
- **Exit criterion:** pin count written down and module chosen.
- **Evidence:** this file; [ADR-0001](../decisions/0001-mcu-rp2040-zero-module.md); log 2026-10-28.

## 02 Pick switches and mounting ✅
- **Exit criterion:** footprint family decided.
- **Evidence:** [ADR-0002](../decisions/0002-switches-gateron-ks33-low-profile.md): Gateron low-profile (KS-27/KS-33) footprint.
- **Still open:** hot-swap or soldered (STATUS Q1). It must be settled before step 07.

## Pitfalls (for future boards)
- Picking parts one at a time without checking how they fit together, for example
  low-profile keys next to a 20 mm encoder shaft. Always sketch the side view
  (`docs/hardware/mechanical.md`).
- Trusting the spec table in an Amazon listing. Several listings in this project
  contradicted themselves (switches "for MX keyboards", OLED "blue" vs "white").
