#!/bin/bash
# Run PrimeOne.exe with proper Wine setup

cd /workspace/app/.wine_primeone/drive_c/PrimeOne

# Try with fresh WINEPREFIX and console
export WINEPREFIX=/workspace/app/.wine_primeone
export WINEARCH=win64

# Run with Xvfb and 64-bit wine
xvfb-run -a /usr/lib/wine/wine64 PrimeOne.exe 2>&1
