#!/usr/bin/env bash
# Copyright 2026 Teodor Arsovski
# SPDX-License-Identifier: GPL-2.0-or-later
#
# Build the minipad QMK firmware in WSL and copy the .uf2 into firmware/out/.
#
# From the repo root, in a Windows terminal (PowerShell):   wsl bash firmware/build.sh
# Or inside WSL:                                             bash firmware/build.sh
# Optional argument: keymap name (default: "default").
#
# Needs: QMK set up in WSL (qmk setup) and the minipad link in ~/qmk_firmware/keyboards
# (firmware/README.md). Build only: flashing stays manual (BOOT + drag the .uf2).

set -euo pipefail

KEYMAP="${1:-default}"
QMK_HOME="${QMK_HOME:-$HOME/qmk_firmware}"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
OUT_DIR="$SCRIPT_DIR/out"
UF2="minipad_${KEYMAP}.uf2"

# The QMK installer puts qmk in ~/.local/bin, which is only on PATH in a login shell.
export PATH="$HOME/.local/bin:$PATH"

if ! command -v qmk >/dev/null 2>&1; then
    echo "error: qmk not found. Install it in WSL (firmware/README.md)." >&2
    exit 1
fi
if [ ! -e "$QMK_HOME/keyboards/minipad" ]; then
    echo "error: $QMK_HOME/keyboards/minipad is missing. Create the link (firmware/README.md)." >&2
    exit 1
fi

# Remove the old copy first, so a failed build can't leave a stale .uf2 behind.
mkdir -p "$OUT_DIR"
rm -f "$OUT_DIR/$UF2"

(cd "$QMK_HOME" && qmk compile -kb minipad -km "$KEYMAP")

cp "$QMK_HOME/$UF2" "$OUT_DIR/$UF2"
echo
echo "OK: firmware/out/$UF2 ($(stat -c %s "$OUT_DIR/$UF2") bytes, $(date '+%Y-%m-%d %H:%M:%S'))"
