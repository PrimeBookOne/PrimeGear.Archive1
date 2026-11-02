@echo off
setlocal enabledelayedexpansion

set "app1=primeone.exe"
set "app2=primeoneold.exe"

REM Get creation dates
for %%A in ("%app1%") do set "app1_date=%%~tA"
for %%B in ("%app2%") do set "app2_date=%%~tB"

REM Compare creation dates
if "%app1_date%" gtr "%app2_date%" (
    echo %app1% is newer than %app2%
) else if "%app1_date%" lss "%app2_date%" (
    echo %app2% is newer than %app1%
) else (
    echo Both applications have the same creation date.
)

endlocal
