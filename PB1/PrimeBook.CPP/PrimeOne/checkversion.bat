@echo off
setlocal enabledelayedexpansion

set "exe_path=primeone.exe"

REM Check if the file exists
if not exist "%exe_path%" (
    echo File not found: %exe_path%
    exit /b
)

REM Use wmic to get file version
for /f "tokens=2 delims==" %%v in ('wmic datafile where "name='%exe_path%'" get version /value ^| find "="') do (
    set "file_version=%%v"
)

echo File Version of %exe_path%: %file_version%

endlocal
