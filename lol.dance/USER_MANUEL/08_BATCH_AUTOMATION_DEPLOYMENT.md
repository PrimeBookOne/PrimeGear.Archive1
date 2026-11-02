# PrimeOne - Feature Document 08: Batch File Automation & Deployment
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** Project root batch files (`*.bat`), `main.cpp` build integration  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Batch File Automation system provides **deployment, maintenance, and operational automation** for PrimeOne on Windows. These scripts handle version management, executable signing, source code cleanup, update monitoring, and cluster deployment orchestration.

### Design Philosophy
- **Windows-native** - Uses CMD/Batch with WMIC, signtool, standard utilities
- **Idempotent** - Safe to run repeatedly
- **Cluster-aware** - Host/Guest deployment patterns
- **Developer-focused** - Source cleanup, version stamping

---

## 2. BATCH FILE INVENTORY

| File | Purpose | Complexity |
|------|---------|------------|
| `primeone8host - 54767.bat` | Launch host on port 54767 | Simple |
| `primeone9guestsShow - 54767.bat` | Launch guest(s) to host | Medium |
| `verifyupdater.bat` | Watchdog: monitor exe updates | Medium |
| `age.bat` | Compare exe timestamps | Simple |
| `checkversion.bat` | Query exe version via WMIC | Simple |
| `setversion.bat` | Sign executable with version | Medium |
| `clean.bat` / `cleanLocal.bat` | Normalize line endings | Simple |
| `Run Gear On Boot.xml` | Windows Task Scheduler config | XML |

---

## 3. HOST DEPLOYMENT (primeone8host)

### 3.1 Script Content
```batch
primeone.exe -m 8 -p 54767
```

### 3.2 Parameters
| Flag | Value | Meaning |
|------|-------|---------|
| `-m 8` | Menu option 8 | Network Host mode |
| `-p 54767` | Port 54767 | TCP listen port |

### 3.3 Behavior
- Starts PrimeOne in **host mode** (createHost=true)
- Listens on **all interfaces** (INADDR_ANY) port 54767
- Uses **default settings** for cores, compute method, flags
- Runs in **current console window** (blocking)

### 3.4 Production Hardening
```batch
@echo off
title PrimeOne Host - Port 54767
setlocal

:: Ensure we're in the right directory
cd /d "%~dp0"

:: Check if already running
tasklist /FI "IMAGENAME eq primeone.exe" /FI "WINDOWTITLE eq PrimeOne Host*" 2>nul | find /I /N "primeone.exe">nul
if "%ERRORLEVEL%"=="0" (
    echo Host already running.
    pause
    exit /b
)

:: Start with logging
primeone.exe -m 8 -p 54767 -c 0 -f quickPrime -x Gear -w h 2>&1 | tee host_%DATE:~-4,4%%DATE:~-10,2%%DATE:~-7,2%.log

endlocal
```

---

## 4. GUEST DEPLOYMENT (primeone9guestsShow)

### 4.1 Script Content
```batch
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```

### 4.2 Parameters
| Flag | Value | Meaning |
|------|-------|---------|
| `start "" cmd /c` | New console window | Allows multiple guests |
| `-m 9` | Menu option 9 | Network Guest mode |
| `-p 54767` | Port 54767 | Connect to host port |
| `-ip 10.0.0.22` | Hardcoded host IP | **Must edit per deployment** |
| `-c1` | Single core | `-c 1` |
| `-w g` | Guest role | Explicit guest mode |

### 4.3 Multi-Guest Pattern
```batch
@echo off
title PrimeOne Guest Launcher
setlocal enabledelayedexpansion

set HOST_IP=10.0.0.22
set PORT=54767
set GUEST_COUNT=4
set CORES_PER_GUEST=1

for /l %%i in (1,1,%GUEST_COUNT%) do (
    start "Guest %%i" cmd /c primeone.exe -m 9 -p %PORT% -ip %HOST_IP% -c%CORES_PER_GUEST% -w g
    timeout /t 1 /nobreak >nul
)

echo Launched %GUEST_COUNT% guests to %HOST_IP%:%PORT%
pause
endlocal
```

### 4.4 Cross-Machine Deployment
```batch
:: deploy_guests.bat - Run from network share
@echo off
set HOST_IP=%1
if "%HOST_IP%"=="" (
    echo Usage: deploy_guests.bat <HOST_IP> [GUEST_COUNT]
    exit /b
)
set GUEST_COUNT=%2
if "%GUEST_COUNT%"=="" set GUEST_COUNT=4

for /l %%i in (1,1,%GUEST_COUNT%) do (
    start "Guest_%%i" cmd /c primeone.exe -m 9 -p 54767 -ip %HOST_IP% -c1 -w g
)
```

---

## 5. UPDATE WATCHDOG (verifyupdater.bat)

### 5.1 Script Content
```batch
@echo off
setlocal enabledelayedexpansion

set "app1=primeoneold.exe"
set "app2=primeone.exe"

:CheckNewer
for %%A in ("%app1%") do set "app1_date=%%~tA"
for %%B in ("%app2%") do set "app2_date=%%~tB"

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
```

### 5.2 Logic Flow
```
┌─────────────────────────────────────────────────────────────┐
│                    VERIFYUPDATER LOGIC                        │
├─────────────────────────────────────────────────────────────┤
│                                                              │
│  START                                                       │
│    │                                                         │
│    ▼                                                         │
│  Get timestamp of primeoneold.exe (backup)                   │
│  Get timestamp of primeone.exe (current)                     │
│    │                                                         │
│    ▼                                                         │
│  Compare timestamps                                          │
│    │                                                         │
│    ├─► old > current:  Echo "old is newer"                   │
│    │                                                         │
│    ├─► current > old:  COPY current → old                    │
│    │       Echo "Overwritten old with current"               │
│    │       Wait 1 second                                     │
│    │       GOTO CheckNewer  (COMMENTED - would loop forever) │
│    │                                                         │
│    └─► equal: Echo "Same date"                               │
│                                                              │
│  END (exits because goto is commented)                       │
│                                                              │
└─────────────────────────────────────────────────────────────┘
```

### 5.3 Production Version (Continuous Loop)
```batch
@echo off
title PrimeOne Update Watchdog
setlocal enabledelayedexpansion

set "BACKUP=primeoneold.exe"
set "CURRENT=primeone.exe"
set "CHECK_INTERVAL=5"

:CheckNewer
if not exist "%CURRENT%" (
    echo [%TIME%] Current executable not found!
    timeout /t %CHECK_INTERVAL% /nobreak >nul
    goto CheckNewer
)

for %%A in ("%BACKUP%") do set "backup_date=%%~tA"
for %%B in ("%CURRENT%") do set "current_date=%%~tB"

if "%current_date%" gtr "%backup_date%" (
    echo [%TIME%] New version detected! Backing up...
    copy /y "%CURRENT%" "%BACKUP%" >nul
    if not errorlevel 1 (
        echo [%TIME%] Backup updated successfully.
    ) else (
        echo [%TIME%] ERROR: Failed to update backup!
    )
) else if "%backup_date%" gtr "%current_date%" (
    echo [%TIME%] Backup is newer (rollback?) - current: %current_date% backup: %backup_date%
)

timeout /t %CHECK_INTERVAL% /nobreak >nul
goto CheckNewer
```

---

## 6. VERSION MANAGEMENT

### 6.1 age.bat - Timestamp Comparison
```batch
@echo off
setlocal enabledelayedexpansion

set "app1=primeone.exe"
set "app2=primeoneold.exe"

for %%A in ("%app1%") do set "app1_date=%%~tA"
for %%B in ("%app2%") do set "app2_date=%%~tB"

if "%app1_date%" gtr "%app2_date%" (
    echo %app1% is newer than %app2%
) else if "%app1_date%" lss "%app2_date%" (
    echo %app2% is newer than %app1%
) else (
    echo Both applications have the same creation date.
)

endlocal
```
**Use Case:** Quick manual check which executable is newer.

### 6.2 checkversion.bat - WMIC Version Query
```batch
@echo off
setlocal enabledelayedexpansion

set "exe_path=primeone.exe"

if not exist "%exe_path%" (
    echo File not found: %exe_path%
    exit /b
)

for /f "tokens=2 delims==" %%v in (
    'wmic datafile where "name='%exe_path%'" get version /value ^| find "="'
) do set "file_version=%%v"

echo File Version of %exe_path%: %file_version%

endlocal
```
**Output Example:**
```
File Version of primeone.exe: 1.2.3.4
```

**WMIC Note:** Deprecated in Windows 10 21H1+, removed in Windows 11 24H2. Alternative:
```batch
:: PowerShell alternative
powershell -command "(Get-Item primeone.exe).VersionInfo.FileVersion"
```

### 6.3 setversion.bat - Code Signing & Version Stamping
```batch
@echo off
setlocal enabledelayedexpansion

set "signtool_path=C:\Program Files (x86)\Windows Kits\10\bin\10.0.19041.0\x64\signtool.exe"
set "exe_path=C:\Users\Shark\Desktop\gyro.cpp.2023\PrimeOne\primeone.exe"
set "new_version=1.2.3.4"

if not exist "%exe_path%" (
    echo File not found: %exe_path%
    exit /b
)

"%signtool_path%" sign /f "path\to\your\certificate.pfx" 
    /p YourPassword /d "Your Description" /du "Your URL" 
    /t http://timestamp.digicert.com "%exe_path%"

echo File Version of %exe_path% set to %new_version%
endlocal
```

**Parameters:**
| Parameter | Purpose |
|-----------|---------|
| `/f` | Certificate file (PFX) |
| `/p` | Certificate password |
| `/d` | Description embedded in signature |
| `/du` | URL for more info |
| `/t` | RFC 3161 timestamp server (DigiCert) |

**Prerequisites:**
- Windows SDK 10.0.19041+ installed
- Valid code signing certificate (EV preferred)
- Network access to timestamp server

---

## 7. SOURCE CODE MAINTENANCE

### 7.1 clean.bat - Project-Wide Cleanup
```batch
primeone\convertcarraigereturns.exe primeone\main.cpp
primeone\cleancarraige.exe primeone\main.cpp -l 3
convertcarraigereturns.exe main.cpp
cleancarraige.exe main.cpp -l 3
```

### 7.2 cleanLocal.bat - Local Cleanup
```batch
convertcarraigereturns.exe main.cpp
cleancarraige.exe main.cpp -l 3
```

### 7.3 Tool Purpose (Inferred)
| Tool | Purpose |
|------|---------|
| `convertcarraigereturns.exe` | Convert line endings (LF↔CRLF) |
| `cleancarraige.exe -l 3` | Clean carriage returns, keep 3 line limit? |

**Note:** These tools are compiled executables in the project (visible in directory listing).

---

## 8. WINDOWS TASK SCHEDULER (Run Gear On Boot.xml)

### 8.1 File Content (Inferred from name)
```xml
<?xml version="1.0" encoding="UTF-16"?>
<Task version="1.2" xmlns="http://schemas.microsoft.com/windows/2004/02/mit/task">
  <RegistrationInfo>
    <Author>PrimeBookOne</Author>
    <Description>Start PrimeOne Host on Boot</Description>
    <URI>\PrimeOne\HostAutoStart</URI>
  </RegistrationInfo>
  <Triggers>
    <BootTrigger>
      <Enabled>true</Enabled>
      <Delay>PT2M</Delay>  <!-- 2 minutes after boot -->
    </BootTrigger>
  </Triggers>
  <Principals>
    <Principal id="Author">
      <LogonType>Password</LogonType>
      <RunLevel>HighestAvailable</RunLevel>
    </Principal>
  </Principals>
  <Settings>
    <MultipleInstancesPolicy>IgnoreNew</MultipleInstancesPolicy>
    <DisallowStartIfOnBatteries>false</DisallowStartIfOnBatteries>
    <StopIfGoingOnBatteries>false</StopIfGoingOnBatteries>
    <AllowHardTerminate>true</AllowHardTerminate>
    <StartWhenAvailable>true</StartWhenAvailable>
    <RunOnlyIfNetworkAvailable>true</RunOnlyIfNetworkAvailable>
    <IdleSettings>
      <StopOnIdleEnd>true</StopOnIdleEnd>
      <RestartOnIdle>false</RestartOnIdle>
    </IdleSettings>
    <AllowStartOnDemand>true</AllowStartOnDemand>
    <Enabled>true</Enabled>
    <Hidden>false</Hidden>
    <RunOnlyIfNetworkAvailable>false</RunOnlyIfNetworkAvailable>
    <WakeToRun>false</WakeToRun>
    <ExecutionTimeLimit>PT0S</ExecutionTimeLimit>
    <Priority>7</Priority>
  </Settings>
  <Actions Context="Author">
    <Exec>
      <Command>cmd.exe</Command>
      <Arguments>/c "C:\Path\To\PrimeOne\primeone8host - 54767.bat"</Arguments>
      <WorkingDirectory>C:\Path\To\PrimeOne\</WorkingDirectory>
    </Exec>
  </Actions>
</Task>
```

### 8.2 Installation
```batch
:: Install as scheduled task
schtasks /create /xml "Run Gear On Boot.xml" /tn "PrimeOne Host AutoStart"

:: Or from PowerShell
Register-ScheduledTask -Xml (Get-Content "Run Gear On Boot.xml" -Raw) -TaskName "PrimeOne Host AutoStart"
```

---

## 9. DEPLOYMENT PATTERNS

### 9.1 Single Machine (Dev)
```
1. Build: Code::Blocks → Build
2. Sign: setversion.bat
3. Test: primeone.exe -m u
4. Run: primeone.exe (interactive)
```

### 9.2 LAN Cluster (Production)
```
Build Machine:
1. Build & Sign
2. Create PrimeOneUpdater.zip
3. Copy to Host Machine

Host Machine:
1. Run primeone8host - 54767.bat
2. Wait for guests

Guest Machines (each):
1. Edit primeone9guestsShow - 54767.bat with host IP
2. Run primeone9guestsShow - 54767.bat
3. Or run deploy_guests.bat HOST_IP 4

Maintenance:
1. verifyupdater.bat running on all machines
2. On update: Host menu → 5 (Network Updater)
```

### 9.3 Cloud/VM Deployment (Azure/AWS)
```powershell
# Azure VM Custom Script Extension
$script = @"
@echo off
mkdir C:\PrimeOne
copy \\fileshare\PrimeOne\* C:\PrimeOne\
cd C:\PrimeOne
primeone8host - 54767.bat
"@

Set-AzVMCustomScriptExtension -ResourceGroupName "PrimeOneRG" -VMName "HostVM" -FilePath "deploy_host.ps1"
```

---

## 10. ENVIRONMENT VARIABLES & CONFIGURATION

### 10.1 Recommended Environment Variables
```batch
:: Set in system environment or autoexec.bat
set PRIMEONE_HOME=C:\PrimeOne
set PRIMEONE_PORT=54767
set PRIMEONE_HOST_IP=10.0.0.22
set PRIMEONE_CORES=4
set PRIMEONE_COMPUTE=Gear
set PRIMEONE_FLAG=quickPrime
```

### 10.2 Parameterized Batch Files
```batch
:: primeone_host.bat
@echo off
setlocal
set PORT=%PRIMEONE_PORT%
set CORES=%PRIMEONE_CORES%
set COMPUTE=%PRIMEONE_COMPUTE%
set FLAG=%PRIMEONE_FLAG%

primeone.exe -m 8 -p %PORT% -c %CORES% -f %FLAG% -x %COMPUTE% -w h
endlocal
```

---

## 11. LOGGING & MONITORING

### 11.1 Enhanced Logging Wrapper
```batch
@echo off
setlocal enabledelayedexpansion

set LOG_DIR=%PRIMEONE_HOME%\logs
if not exist "%LOG_DIR%" mkdir "%LOG_DIR%"

set TIMESTAMP=%DATE:~-4,4%%DATE:~-10,2%%DATE:~-7,2%_%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%
set TIMESTAMP=%TIMESTAMP: =0%
set LOG_FILE=%LOG_DIR%\primeone_%TIMESTAMP%.log

primeone.exe -m 8 -p 54767 2>&1 | tee "%LOG_FILE%"
```

### 11.2 Log Rotation (PowerShell)
```powershell
# Rotate logs older than 7 days, keep max 50
Get-ChildItem "$env:PRIMEONE_HOME\logs\*.log" | 
    Where-Object { $_.LastWriteTime -lt (Get-Date).AddDays(-7) } | 
    Remove-Item

$logs = Get-ChildItem "$env:PRIMEONE_HOME\logs\*.log" | Sort-Object LastWriteTime -Descending
if ($logs.Count -gt 50) {
    $logs | Select-Object -Skip 50 | Remove-Item
}
```

---

## 12. HEALTH CHECKS & HEARTBEATS

### 12.1 Host Health Check Batch
```batch
@echo off
:: health_check_host.bat - Run via Task Scheduler every 5 min

set HOST=localhost
set PORT=54767

:: Check process
tasklist /FI "IMAGENAME eq primeone.exe" | find "primeone.exe" >nul
if errorlevel 1 (
    echo [%DATE% %TIME%] Host process not running! Restarting...
    start "" cmd /c "C:\PrimeOne\primeone8host - 54767.bat"
    exit /b
)

:: Check port
powershell -command "try { $tcp = New-Object Net.Sockets.TcpClient; $tcp.Connect('%HOST%', %PORT%); $tcp.Close(); exit 0 } catch { exit 1 }"
if errorlevel 1 (
    echo [%DATE% %TIME%] Port %PORT% not responding!
    :: Could restart or alert
)

echo [%DATE% %TIME%] Host healthy.
```

### 12.2 Guest Health Check
```batch
@echo off
:: health_check_guest.bat

set HOST_IP=10.0.0.22
set PORT=54767

tasklist /FI "IMAGENAME eq primeone.exe" /FI "WINDOWTITLE eq Guest*" | find "primeone.exe" >nul
if errorlevel 1 (
    echo Guest not running. Relaunching...
    start "" cmd /c primeone.exe -m 9 -p %PORT% -ip %HOST_IP% -c1 -w g
)
```

---

## 13. ROLLBACK AUTOMATION

### 13.1 Automatic Rollback on Crash
```batch
@echo off
:: watchdog_with_rollback.bat

set MAX_CRASHES=3
set CRASH_COUNT=0

:MonitorLoop
primeone.exe -m 8 -p 54767
set EXIT_CODE=%ERRORLEVEL%

if %EXIT_CODE% neq 0 (
    set /a CRASH_COUNT+=1
    echo Crash detected (count: %CRASH_COUNT%/%MAX_CRASHES%)
    
    if %CRASH_COUNT% geq %MAX_CRASHES% (
        echo Too many crashes. Rolling back...
        copy /y primeoneold.exe primeone.exe
        echo Rolled back to previous version.
        set CRASH_COUNT=0
    )
    
    timeout /t 10 /nobreak >nul
    goto MonitorLoop
) else (
    set CRASH_COUNT=0
)
```

---

## 14. CI/CD INTEGRATION

### 14.1 GitHub Actions Build
```yaml
# .github/workflows/build.yml
name: Build PrimeOne
on: [push, workflow_dispatch]

jobs:
  build-windows:
    runs-on: windows-latest
    steps:
      - uses: actions/checkout@v4
      
      - name: Setup MSBuild
        uses: microsoft/setup-msbuild@v1
      
      - name: Build with Code::Blocks
        run: |
          "C:\Program Files\CodeBlocks\codeblocks.exe" --build PrimeOne.cbp --target=Debug
      
      - name: Sign Executable
        run: |
          signtool sign /f ${{secrets.CERT_PFX}} /p ${{secrets.CERT_PASS}} /t http://timestamp.digicert.com PrimeOne.exe
      
      - name: Create Update Package
        run: |
          7z a PrimeOneUpdater.zip PrimeOne.exe version.res manifest.xml
      
      - name: Upload Artifacts
        uses: actions/upload-artifact@v4
        with:
          name: PrimeOne-Release
          path: |
            PrimeOne.exe
            PrimeOneUpdater.zip
```

### 14.2 Automated Deployment
```yaml
  deploy:
    needs: build-windows
    runs-on: windows-latest
    if: github.ref == 'refs/heads/main'
    steps:
      - uses: actions/download-artifact@v4
        with:
          name: PrimeOne-Release
      
      - name: Deploy to Host
        uses: appleboy/ssh-action@v1
        with:
          host: ${{secrets.HOST_IP}}
          username: ${{secrets.HOST_USER}}
          key: ${{secrets.HOST_SSH_KEY}}
          script: |
            mkdir -p C:\PrimeOne
            # Copy files via scp/winrm
            # Stop service, replace, start
```

---

## 15. TROUBLESHOOTING BATCH FILES

### 15.1 Common Issues

| Issue | Cause | Fix |
|-------|-------|-----|
| `primeone.exe` not found | Wrong working directory | `cd /d "%~dp0"` |
| Port already in use | Previous instance not killed | `taskkill /f /im primeone.exe` |
| Guest can't connect | Wrong host IP in batch | Edit batch file |
| Signing fails | Cert expired/wrong path | Check cert, timestamp server |
| WMIC not found | Windows 11 24H2+ | Use PowerShell alternative |

### 15.2 Debug Mode
```batch
@echo off
set DEBUG=1
if "%DEBUG%"=="1" (
    set ECHO_CMD=echo [DEBUG]
) else (
    set ECHO_CMD=rem
)

%ECHO_CMD% Starting PrimeOne with args: %*
primeone.exe %*
```

---

## 16. SECURITY HARDENING

### 16.1 Batch File Permissions
```batch
:: Set restrictive ACLs on batch files
icacls "*.bat" /inheritance:r /grant:r "Administrators:(OI)(CI)F" "SYSTEM:(OI)(CI)F" "Users:(OI)(CI)RX"
```

### 16.2 Certificate Protection
```batch
:: Store certificate in Windows Certificate Store, not file
:: Use signtool with /sha1 thumbprint instead of /f file
signtool sign /sha1 "THUMBPRINT" /t http://timestamp.digicert.com primeone.exe
```

### 16.3 Network Isolation
```batch
:: Windows Firewall rule for PrimeOne port
netsh advfirewall firewall add rule name="PrimeOne Host" dir=in action=allow protocol=TCP localport=54767 profile=domain,private
netsh advfirewall firewall add rule name="PrimeOne Guest" dir=out action=allow protocol=TCP remoteport=54767 profile=domain,private
```

---

## 17. KNOWN ISSUES & LIMITATIONS

### 17.1 Batch File Limitations
1. **Hardcoded IP** in guest batch (`10.0.0.22`)
2. **No argument parsing** - must edit file
3. **No logging** by default
4. **No health checks** built-in
5. **WMIC deprecated** - checkversion.bat will break
6. **No rollback automation** - manual only
7. **Single-threaded deployment** - no parallel guest launch

### 17.2 Platform Limitations
- **Windows only** - No Linux/macOS equivalents
- **Admin required** for signing, firewall, scheduled tasks
- **No container support** - Batch files don't work in containers

---

## 18. REFACTORING ROADMAP

### 18.1 Phase 1: Parameterization (Critical)
- [ ] Replace hardcoded IPs with `%1` arguments
- [ ] Add environment variable fallbacks
- [ ] Add `--help` to all batch files
- [ ] Create `deploy.bat` master script

### 18.2 Phase 2: Modernization (High)
- [ ] Rewrite in PowerShell (cross-platform via PWSH)
- [ ] Add structured logging (JSON)
- [ ] Implement health checks
- [ ] Add automatic rollback

### 18.3 Phase 3: Orchestration (Medium)
- [ ] Ansible playbooks for cluster deploy
- [ ] Kubernetes manifests (for containerized version)
- [ ] Terraform for cloud infrastructure
- [ ] GitOps deployment (ArgoCD/Flux)

### 18.4 Phase 4: Observability (Medium)
- [ ] Prometheus exporter for batch status
- [ ] Grafana dashboards
- [ ] Alertmanager integration
- [ ] Distributed tracing

---

## 19. COMPLETE COMMAND REFERENCE

### 19.1 Direct Execution
```cmd
# Host
primeone8host - 54767.bat

# Guest (edit IP first!)
primeone9guestsShow - 54767.bat

# Version check
checkversion.bat

# Compare versions
age.bat

# Sign new version
setversion.bat

# Clean source
clean.bat
cleanLocal.bat

# Watchdog (run in background)
verifyupdater.bat
```

### 19.2 Parameterized Versions (Recommended)
```cmd
# Host with custom port
deploy_host.bat 54767

# Guest with custom host IP and count
deploy_guests.bat 192.168.1.100 8

# Health check
health_check_host.bat
health_check_guest.bat

# With logging
primeone.exe -m 8 -p 54767 2>&1 | tee logs\host_%DATE%.log
```

### 19.3 Scheduled Tasks
```cmd
# Install auto-start
schtasks /create /xml "Run Gear On Boot.xml" /tn "PrimeOne Host"

# Install health check (every 5 min)
schtasks /create /tn "PrimeOne Health Check" /tr "C:\PrimeOne\health_check_host.bat" /sc minute /mo 5
```

---

## 20. CROSS-REFERENCE: SOURCE LOCATIONS

| Batch File | Project Location | Called From |
|------------|------------------|-------------|
| `primeone8host - 54767.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Manual, Task Scheduler |
| `primeone9guestsShow - 54767.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Manual, deploy script |
| `verifyupdater.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Background watchdog |
| `age.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Manual |
| `checkversion.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Manual, CI |
| `setversion.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Release process |
| `clean.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Pre-build |
| `cleanLocal.bat` | `/PB1/PrimeBook.CPP/PrimeOne/` | Pre-build |
| `Run Gear On Boot.xml` | `/PB1/PrimeBook.CPP/PrimeOne/` | Task Scheduler import |

---

*End of Feature Document 08: Batch File Automation & Deployment*  
*Next: 09_CONSOLE_UI_REALTIME_DISPLAY.md*