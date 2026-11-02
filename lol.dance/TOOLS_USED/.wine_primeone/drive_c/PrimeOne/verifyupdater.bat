@echo off
setlocal enabledelayedexpansion

set "app1=primeoneold.exe"
set "app2=primeone.exe"

:CheckNewer
REM Get creation dates
for %%A in ("%app1%") do set "app1_date=%%~tA"
for %%B in ("%app2%") do set "app2_date=%%~tB"

REM Compare creation dates
if "%app1_date%" gtr "%app2_date%" (
    echo %app1% is newer than %app2%
) else if "%app1_date%" lss "%app2_date%" (
    echo %app2% is newer than %app1%
    copy /y "%app2%" "%app1%"
    echo Overwritten %app1% with %app2%
timeout /T 1 /NOBREAK


    goto CheckNewer
) else (
    echo Both applications have the same creation date.
)




rem goto CheckNewer

endlocal
