
@echo off
setlocal enabledelayedexpansion

set "iterations=3"
set "delay_seconds=1"

for /l %%i in (1, 1, %iterations%) do (
    start ""  cmd /c primeone.exe -m 0 -p 54767 -ip 127.0.0.1 -c 1 -w g
    timeout /nobreak /t %delay_seconds% >nul
)

endlocal