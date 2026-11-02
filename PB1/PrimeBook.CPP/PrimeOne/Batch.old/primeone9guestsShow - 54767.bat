
@echo off
setlocal enabledelayedexpansion

set "iterations=3"
set "delay_seconds=1"

for /l %%i in (1, 1, %iterations%) do (
    start ""  cmd /c primeone.exe -m 9 -p 54767 -ip 170.83.9.10
    timeout /nobreak /t %delay_seconds% >nul
)

endlocal