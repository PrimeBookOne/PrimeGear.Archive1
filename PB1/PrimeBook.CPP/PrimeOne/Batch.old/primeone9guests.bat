
@echo off
setlocal enabledelayedexpansion

set "iterations=16"
set "delay_seconds=1"

for /l %%i in (1, 1, %iterations%) do (
    start "" /min cmd /c primeone.exe -m 9
    timeout /nobreak /t %delay_seconds% >nul
)

endlocal