
@echo off
setlocal enabledelayedexpansion

set "iterations=1"
set "delay_seconds=1"

for /l %%i in (1, 1, %iterations%) do (
    start ""  cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
    timeout /nobreak /t %delay_seconds% >nul
)

endlocal