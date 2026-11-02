#!/bin/bash
# Run PrimeOne3236.exe (console version) via Wine with pseudo-terminal

cd /workspace/app/.wine_primeone/drive_c/PrimeOne

export WINEPREFIX=/workspace/app/.wine_primeone
export WINEARCH=win64

# Use script to provide a pseudo-terminal for Wine console
# This allows GetConsoleWindow() to work properly
exec script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null
