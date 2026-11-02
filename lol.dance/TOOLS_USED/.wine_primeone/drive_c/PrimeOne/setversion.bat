@echo off
setlocal enabledelayedexpansion

set "signtool_path=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64\signtool.exe"
set "exe_path=C:\Users\Shark\Desktop\gyro.cpp.2023\PrimeOne\primeone.exe"
set "new_version=1.2.3.4"

REM Check if the file exists
if not exist "%exe_path%" (
    echo File not found: %exe_path%
    exit /b
)

REM Set the file version using signtool
"%signtool_path%" sign /f "path\to\your\certificate.pfx" /p YourPassword /d "Your Description" /du "Your URL" /t http://timestamp.digicert.com "%exe_path%"

echo File Version of %exe_path% set to %new_version%

endlocal
