#!/bin/bash
# Run PrimeOne.exe (GUI version) via Wine with Xvfb

cd /workspace/app/.wine_primeone/drive_c/PrimeOne

export WINEPREFIX=/workspace/app/.wine_primeone
export WINEARCH=win64

# Use Xvfb for GUI
exec xvfb-run -a /usr/lib/wine/wine64 PrimeOne.exe
