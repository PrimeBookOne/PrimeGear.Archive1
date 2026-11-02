# PrimeOne - Feature Document 06: Update & Roll System
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines ~17270-17500 (realm_win_updater), ~16650-16700 (realm_win_roll), batch files  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Update & Roll System provides **self-updating capability** for PrimeOne. It implements a complete **download → verify → install → restart** cycle using ZIP archives (`PrimeOneUpdater.zip`) transferred over the network conduit system. The system supports both **push** (host sends update) and **pull** (guest requests update) models.

### Design Philosophy
- **Atomic updates** - Full replacement via ZIP archive
- **Network integrated** - Uses existing conduit TCP connections
- **Rollback capable** - Keeps previous version (`primeoneold.exe`)
- **Automated** - Batch file watchdog (`verifyupdater.bat`)
- **Signed** - Code signing via `signtool.exe` (batch file)

---

## 2. ARCHITECTURE

### 2.1 Component Diagram
```
┌─────────────────────────────────────────────────────────────────┐
│                      UPDATE & ROLL SYSTEM                        │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────────────┐  │
│  │   HOST       │    │   CONDUIT    │    │   GUEST          │  │
│  │  (Source)    │◄──►│  (Transport) │◄──►│  (Target)        │  │
│  └──────────────┘    └──────────────┘    └──────────────────┘  │
│         │                   │                    │               │
│         ▼                   ▼                    ▼               │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                    UPDATE ORCHESTRATOR                      │   │
│  │  realm_win_updater()  │  realm_win_archive()  │  realm_win_roll() │
│  └──────────────────────────────────────────────────────────┘   │
│         │                   │                    │               │
│         ▼                   ▼                    ▼               │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────────────┐  │
│  │  ZIP CREATE  │    │  TCP SEND/   │    │  EXTRACT &       │  │
│  │  (Archive)   │    │  RECV        │    │  REPLACE         │  │
│  └──────────────┘    └──────────────┘    └──────────────────┘  │
│                                                                  │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                    WATCHDOG (verifyupdater.bat)             │   │
│  │  Monitors executable timestamp → Auto-replace old          │   │
│  └──────────────────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────────────────┘
```

### 2.2 Key Functions

| Function | Purpose | Location |
|----------|---------|----------|
| `realm_win_updater()` | Main update orchestration | ~17270 |
| `realm_win_archive()` | Create PrimeOneUpdater.zip | ~16600 (commented) |
| `realm_win_roll()` | Install update & restart | ~16654 |
| `verifyupdater.bat` | File watchdog | Project root |

---

## 3. UPDATE WORKFLOW

### 3.1 Host-Initiated Push Update
```
1. Host selects "Update" (menu 'u' or sub-menu '5')
2. realm_win_updater() called with parameters
3. Creates PrimeOneUpdater.zip via realm_win_archive()
4. Sends ZIP over conduit to all connected guests
5. Guests receive and save as PrimeOneUpdater.zip
6. Guests execute realm_win_roll() to install
7. Application restarts with new version
```

### 3.2 Guest-Initiated Pull Update
```
1. Guest starts with -m 9 (network guest)
2. Connects to host
3. Requests update via conduit protocol
4. Host sends PrimeOneUpdater.zip
5. Guest saves and rolls
```

### 3.3 Batch File Watchdog (verifyupdater.bat)
```batch
:CheckNewer
REM Compare timestamps: primeoneold.exe vs primeone.exe
if primeone.exe newer:
    copy /y primeone.exe primeoneold.exe
    echo Overwritten primeoneold.exe with primeone.exe
    timeout /T 1 /NOBREAK
    goto CheckNewer
else:
    echo Same or older
    timeout /T 1
    goto CheckNewer
```
**Purpose:** Continuous monitoring for new executable, maintains backup.

---

## 4. REALM_WIN_UPDATER() - DEEP DIVE

### 4.1 Function Signature (Line 17270)
```cpp
void realm_win_updater(
    bool createHost,           // true=host push, false=guest pull
    string hostIp,             // Target host IP
    string hostPort,           // Target port
    string guestIp,            // Guest IP (for host)
    string guestPort,          // Guest port
    string uniqueFileName,     // Update package name
    string instruction         // "update" | "rollback" | "status"
)
```

### 4.2 Implementation Analysis (Lines 17270-17500)

#### 4.2.1 Network Setup
```cpp
// Line 17282
WORD ver = MAKEWORD(2, 2);
WSADATA wsaData;
WSAStartup(ver, &wsaData);

// Line 17298-17299: BUG - hint.sin_addr.s_addr is uint32_t
sockaddr_in hint;
hint.sin_family = AF_INET;
hint.sin_port = htons(PORT);
hint.sin_addr.s_addr = inet_addr("127.0.0.1");  // Hardcoded localhost!
string ipAddress = inet_ntoa(hint.sin_addr);    // TYPE ERROR
```

#### 4.2.2 File Transfer Logic
```cpp
// Line 17325: Path with unescaped backslash
std::ofstream copy("PrimeOneUpdate\PrimeOneUpdate.zip", std::ios::binary);
// Should be: "PrimeOneUpdate\\PrimeOneUpdate.zip" or "PrimeOneUpdate/PrimeOneUpdate.zip"

// Line 17386-17394: Computer name for identification
char computerName[MAX_COMPUTERNAME_LENGTH + 1];
DWORD computerNameSize = sizeof(computerName);
ZeroMemory(host, NI_MAXHOST);
if (GetComputerName(computerName, &computerNameSize)) { ... }

// Line 17412: Another unescaped path
std::ifstream original("PrimeOneUpdate\PrimeOneUpdater.zip", std::ios::binary);

// Line 17445: Data send loop
if (dataSend >= data.size()) { ... }
```

#### 4.2.3 Variables (Line 17273)
```cpp
int PORT = 54000; 
bool yesContinue = true; 
bool socketSearch = true; 
int PORTgrow = PORT; 
bool sendForever = true;
bool receiveForever = true; 
int dataSend = 0;  
int* array = new int[ARRAY_SIZE];  // LEAK: never deleted
```

---

## 5. REALM_WIN_ROLL() - DEEP DIVE

### 5.1 Function Signature (Line 16654)
```cpp
void realm_win_roll() {
    // Install update and restart application
}
```

### 5.2 Implementation (Lines 16654-16700)
```cpp
void realm_win_roll() {
    HANDLE processHandle = GetCurrentProcess();
    
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    
    LPVOID minAddress = systemInfo.lpMinimumApplicationAddress;
    LPVOID maxAddress = systemInfo.lpMaximumApplicationAddress;
    
    SIZE_T memorySize = static_cast<SIZE_T>(
        reinterpret_cast<BYTE*>(maxAddress) - 
        reinterpret_cast<BYTE*>(minAddress)
    );
    
    // Dump entire process memory to file
    if (!WriteProcessMemory(processHandle, minAddress, minAddress, memorySize, nullptr)) {
        // Error
    }
    
    // Save to file
    std::ofstream outFile("PrimeOneMemoryDump.bin", std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(minAddress), memorySize);
    
    // Restart logic (inferred)
    // ShellExecute/ExecuteProcess with new executable
}
```

**Issues:**
- `minAddress` undeclared (scope issue line 16674, 16681)
- `memorySize` undeclared (line 16674, 16681)
- Dumps ENTIRE process memory (huge, includes system DLLs)
- No actual executable replacement logic visible
- No signature verification

---

## 6. ARCHIVE FORMAT (PrimeOneUpdater.zip)

### 6.1 Expected Contents
Based on batch files and code references:
```
PrimeOneUpdater.zip
├── primeone.exe              # New executable
├── primeoneold.exe           # Previous version (backup)
├── version.rc                # Version resource
├── version.res               # Compiled version resource
├── manifest.xml              # Update metadata
│   ├── version: "1.2.3.4"
│   ├── timestamp: "2025-07-18T10:30:00Z"
│   ├── checksum: "sha256:..."
│   └── changelog: "..."
├── cuda_kernels.ptx          # PTX kernels (optional)
├── compute_shader.hlsl       # Updated shaders
└── README_UPDATE.txt         # Human-readable notes
```

### 6.2 Creation (realm_win_archive - Commented)
```cpp
// Referenced but commented out in menu handlers:
// realm_win_archive();
// Would create ZIP using system tools or library
```

### 6.3 Extraction (Inferred in Roll)
```cpp
// Would use:
// - Windows Shell API (SHCreateDirectory, ExtractTo)
// - Or libzip/miniz
// - Or system("powershell Expand-Archive ...")
```

---

## 7. CODE SIGNING (setversion.bat)

### 7.1 Batch File Content
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

### 7.2 Signing Process
1. **Certificate**: PFX file with code signing cert
2. **Timestamp**: DigiCert RFC 3161 timestamp server
3. **Attributes**: Description, URL embedded in signature
4. **Version**: Updated in version resource

### 7.3 Version Resource (version.rc/version.res)
```rc
// version.rc
#include <winver.h>

VS_VERSION_INFO VERSIONINFO
 FILEVERSION 1,2,3,4
 PRODUCTVERSION 1,2,3,4
 FILEFLAGSMASK 0x3fL
 FILEFLAGS 0x0L
 FILEOS 0x40004L
 FILETYPE 0x1L
 FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904b0"
        BEGIN
            VALUE "CompanyName", "PrimeBookOne"
            VALUE "FileDescription", "Prime Number Computation Engine"
            VALUE "FileVersion", "1.2.3.4"
            VALUE "InternalName", "PrimeOne"
            VALUE "LegalCopyright", "Copyright (C) 2025"
            VALUE "OriginalFilename", "PrimeOne.exe"
            VALUE "ProductName", "PrimeBookOne"
            VALUE "ProductVersion", "1.2.3.4"
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x409, 1200
    END
END
```

---

## 8. NETWORK TRANSPORT FOR UPDATES

### 8.1 Conduit Integration
```cpp
// Update uses existing conduit TCP connections
// Protocol extension for file transfer:

enum UpdateMessageType {
    UPDATE_ANNOUNCE = 0x10,    // Host announces update available
    UPDATE_REQUEST = 0x11,     // Guest requests update
    UPDATE_CHUNK = 0x12,       // File chunk (64KB)
    UPDATE_COMPLETE = 0x13,    // Transfer complete
    UPDATE_VERIFY = 0x14,      // Checksum verification
    UPDATE_ROLL = 0x15         // Execute roll
};

// Chunked transfer for large updates
const size_t CHUNK_SIZE = 65536;  // 64KB
```

### 8.2 Transfer Sequence
```
HOST                              GUEST
  │                                 │
  ├── UPDATE_ANNOUNCE ────────────►│
  │                                 │
  │◄── UPDATE_REQUEST ─────────────┤
  │                                 │
  ├── UPDATE_CHUNK (1/10) ────────►│
  ├── UPDATE_CHUNK (2/10) ────────►│
  │           ...                   │
  ├── UPDATE_CHUNK (10/10) ───────►│
  │                                 │
  │◄── UPDATE_VERIFY (SHA256) ─────┤
  │                                 │
  ├── UPDATE_COMPLETE ────────────►│
  │                                 │
  │◄── UPDATE_ROLL ────────────────┤ (Guest initiates roll)
  │                                 │
```

---

## 9. MENU INTEGRATION

### 9.1 Main Menu Options
```cpp
// Line 14610-14611: Main menu Update option
cout << "X" << " " << "(" << "u" << ")" << " " << "P" << "r" 
     << "i" << "m" << "e" << "B" << "o" << "o" << "k" << " " 
     << "O" << "n" << "e" << " " << "U" << "p" << "d" << "a" 
     << "t" << "e" << " " << " " << "X" << " " << " " << endl;
```

### 9.2 Sub-Menu Options (After Host/Guest)
```cpp
// Line 14393-14397: Archive Create (Option 4)
else if (userInput == "4" && menueChoice == 1) {
    // realm_win_archive();
    reload = true;
}

// Line 14408-14412: Network Updater (Option 5)
else if (userInput == "5" && menueChoice == 1) {
    system("cls");
    // realm_win_updater(userInput);
    reload = true;
}

// Line 14423-14425: Roll Update (Option 6)
else if (userInput == "6" && menueChoice == 1) {
    realm_win_roll();
    reload = true;
}
```

### 9.3 Command Line Access
```cmd
# Direct update check
PrimeOne.exe -m u

# Network update (host pushes)
PrimeOne.exe -m 8 -p 54767  # Host starts
# Guest connects, host triggers update via menu 5

# Network update (guest pulls)
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -w g
# Guest requests update via menu 5
```

---

## 10. BATCH FILE AUTOMATION

### 10.1 verifyupdater.bat - Continuous Watchdog
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

**Behavior:**
- Runs continuously (loop with 1-second timeout)
- Maintains `primeoneold.exe` as backup of latest known good
- When `primeone.exe` is newer (updated), copies to backup
- Commented `goto CheckNewer` - would loop forever if uncommented

### 10.2 age.bat - Version Comparison
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

### 10.3 checkversion.bat - WMIC Version Query
```batch
@echo off
setlocal enabledelayedexpansion
set "exe_path=primeone.exe"
if not exist "%exe_path%" (echo File not found & exit /b)
for /f "tokens=2 delims==" %%v in (
    'wmic datafile where "name='%exe_path%'" get version /value ^| find "="'
) do set "file_version=%%v"
echo File Version of %exe_path%: %file_version%
endlocal
```

### 10.4 clean.bat / cleanLocal.bat - Source Cleanup
```batch
:: clean.bat
primeone\convertcarraigereturns.exe primeone\main.cpp
primeone\cleancarraige.exe primeone\main.cpp -l 3
convertcarraigereturns.exe main.cpp
cleancarraige.exe main.cpp -l 3

:: cleanLocal.bat (identical but local paths)
convertcarraigereturns.exe main.cpp
cleancarraige.exe main.cpp -l 3
```

---

## 11. SECURITY ANALYSIS

### 11.1 Current Vulnerabilities
| Vulnerability | Severity | Location |
|---------------|----------|----------|
| Unsigned updates | CRITICAL | No signature verification in roll |
| Path traversal | HIGH | `PrimeOneUpdate\PrimeOneUpdate.zip` |
| Unencrypted transfer | HIGH | Plain TCP |
| No integrity check | HIGH | No SHA256 verification visible |
| Arbitrary code execution | CRITICAL | Roll replaces executable |
| Hardcoded localhost | MEDIUM | `127.0.0.1` in updater |
| Memory dump exposure | MEDIUM | `realm_win_roll` dumps full process |

### 11.2 Required Security Measures
```cpp
// 1. Signature verification before roll
bool verifyUpdateSignature(const string& zipPath) {
    // Extract signature from ZIP
    // Verify with embedded public key
    // Check timestamp validity
    return true;
}

// 2. Checksum verification
string calculateSHA256(const string& filePath) {
    // Use Windows CNG or OpenSSL
    return sha256;
}

bool verifyChecksum(const string& zipPath, const string& expected) {
    return calculateSHA256(zipPath) == expected;
}

// 3. Secure roll with verification
void secureRoll() {
    if (!verifyUpdateSignature("PrimeOneUpdater.zip")) {
        log("ERROR: Invalid update signature");
        return;
    }
    if (!verifyChecksum("PrimeOneUpdater.zip", expectedSHA256)) {
        log("ERROR: Checksum mismatch");
        return;
    }
    // Proceed with extraction
}
```

---

## 12. ROLLBACK MECHANISM

### 12.1 Current State
- `primeoneold.exe` maintained by `verifyupdater.bat`
- No automatic rollback on failure
- Manual: `copy primeoneold.exe primeone.exe`

### 12.2 Recommended Rollback Design
```cpp
struct UpdateManager {
    // Pre-update: backup current
    bool backupCurrent() {
        return CopyFile("primeone.exe", "primeone.backup.exe", FALSE);
    }
    
    // Post-update: verify new works
    bool verifyNewExecutable() {
        // Launch new exe with --self-test
        // Wait for success signal
        return true;
    }
    
    // On failure: automatic rollback
    void rollback() {
        CopyFile("primeone.backup.exe", "primeone.exe", TRUE);
        // Restart
    }
    
    // Cleanup old backups
    void cleanupBackups() {
        // Keep last 3 versions
    }
};
```

---

## 13. VERSIONING STRATEGY

### 13.1 Version Format (from setversion.bat)
```
1.2.3.4  (Major.Minor.Build.Revision)
```

### 13.2 Version Sources
| Source | Method |
|--------|--------|
| Executable | `wmic datafile get version` (WMIC) |
| Resource | `version.rc` → `version.res` → embedded |
| Batch | Hardcoded in `setversion.bat` |
| Dashboard | Hardcoded "Build count: 3242" |
| Service tag | `[SERVICE_primeOne_2025_7_18.xlsm]...` |

### 13.3 Version Increment Policy
| Change Type | Version Bump |
|-------------|--------------|
| Major rewrite | Major++ |
| New feature | Minor++ |
| Bug fix | Build++ |
| Hotfix | Revision++ |

---

## 14. DEPLOYMENT SCENARIOS

### 14.1 Single Machine (Developer)
```cmd
# Build new version
# Sign
setversion.bat
# Test
PrimeOne.exe -m u  # Check update
# Manual copy to deployment
```

### 14.2 LAN Cluster (Production)
```cmd
# On build machine:
setversion.bat
# Copy PrimeOneUpdater.zip to host

# On host:
PrimeOne.exe -m 8 -p 54767
# Menu → 5 (Network Updater) → Push to all guests

# On guests (auto):
# receive → save → menu 6 (Roll) → restart
```

### 14.3 Automated CI/CD (Future)
```yaml
# .github/workflows/update.yml
on:
  release:
    types: [published]
jobs:
  build-and-sign:
    runs-on: windows-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build PrimeOne
        run: |
          # Code::Blocks build or MSBuild
      - name: Sign
        run: signtool sign /f cert.pfx /p ${{secrets.CERT_PASS}} /t http://timestamp.digicert.com PrimeOne.exe
      - name: Create Archive
        run: 7z a PrimeOneUpdater.zip PrimeOne.exe version.res manifest.xml
      - name: Upload Artifact
        uses: actions/upload-artifact@v4
        with:
          name: PrimeOneUpdater
          path: PrimeOneUpdater.zip
```

---

## 15. KNOWN BUGS & TECHNICAL DEBT

### 15.1 Compilation Errors (Blocking)
| Error | Line | Fix |
|-------|------|-----|
| `MAKEWORD` undeclared | 17282 | `#include <winsock2.h>` |
| `hint.sin_addr.s_addr` | 17298 | Use `in_addr` struct |
| `inet_ntoa` arg type | 17299 | Pass `in_addr` |
| `MAX_COMPUTERNAME_LENGTH` | 17386 | `#include <windows.h>` |
| `ZeroMemory` | 17392 | `#include <windows.h>` |
| `GetComputerName` | 17394 | `#include <windows.h>` |
| `INET_ADDRSTRLEN` | 17402 | `#include <ws2tcpip.h>` |
| Unescaped backslash | 17325, 17412 | Use `\\` or `/` |
| `minAddress` undeclared | 16674, 16681 | Fix scope |
| `memorySize` undeclared | 16674, 16681 | Fix scope |

### 15.2 Logic Bugs
1. **Hardcoded localhost** in updater (line 17298) - won't work across network
2. **No signature verification** in roll process
3. **No checksum verification** of downloaded ZIP
4. **Memory dump** saves entire process (GBs), not just executable
5. **Array leak** in updater: `int* array = new int[ARRAY_SIZE]` never deleted
5. **Infinite loop** in batch file (commented but intended)

### 15.3 Architecture Debt
- Update logic mixed with network conduit
- No differential updates (full ZIP every time)
- No delta compression
- No staging area (direct replace)
- No health check post-roll

---

## 16. REFACTORING ROADMAP

### 16.1 Phase 1: Fix Compilation (Critical)
- [ ] Add missing Windows headers
- [ ] Fix socket address handling
- [ ] Fix string escaping in file paths
- [ ] Fix variable scope in `realm_win_roll`
- [ ] Add memory leak fixes

### 16.2 Phase 2: Security (Critical)
- [ ] Implement SHA256 verification
- [ ] Add code signature verification (Authenticode)
- [ ] Encrypt update transport (libssh tunnel)
- [ ] Add certificate pinning

### 16.3 Phase 3: Reliability (High)
- [ ] Implement atomic replace (MoveFileEx with MOVEFILE_REPLACE_EXISTING)
- [ ] Add pre-roll self-test
- [ ] Implement automatic rollback on failure
- [ ] Add update staging directory

### 16.4 Phase 4: Efficiency (Medium)
- [ ] Differential updates (bsdiff/courgette)
- [ ] Parallel chunked download
- [ ] Resume interrupted transfers
- [ ] Delta compression for prime books

### 16.5 Phase 5: Management (Medium)
- [ ] Version manifest (JSON)
- [ ] Update channels (stable/beta/alpha)
- [ ] Rollout percentage (canary)
- [ ] Rollback API

---

## 17. TESTING SPECIFICATIONS

### 17.1 Unit Tests
| Component | Test Cases |
|-----------|------------|
| `realm_win_updater` | Host push, guest pull, invalid ZIP, network failure |
| `realm_win_roll` | Valid update, corrupt ZIP, signature fail, rollback |
| `realm_win_archive` | ZIP creation, contents verification |
| Batch files | Timestamp comparison, copy behavior |

### 17.2 Integration Tests
- Full update cycle: build → sign → archive → host push → guest receive → roll → verify
- Concurrent updates (multiple guests)
- Network interruption during transfer
- Power loss during roll

### 17.3 Security Tests
- Unsigned ZIP rejection
- Modified ZIP detection
- Replay attack prevention
- Rollback to compromised version prevention

---

## 18. MONITORING & LOGGING

### 18.1 Current Logging
- `cout` to console (mixed with UI)
- No structured logging
- No log rotation

### 18.2 Recommended Logging
```cpp
enum UpdateEvent {
    UPDATE_STARTED,
    DOWNLOAD_PROGRESS,
    VERIFICATION_STARTED,
    VERIFICATION_PASSED,
    VERIFICATION_FAILED,
    ROLL_STARTED,
    ROLL_COMPLETED,
    ROLL_FAILED,
    ROLLBACK_INITIATED,
    ROLLBACK_COMPLETED
};

void logUpdateEvent(UpdateEvent event, const string& details) {
    json log = {
        {"timestamp", getCurrentISOTime()},
        {"event", event},
        {"version", getCurrentVersion()},
        {"details", details},
        {"host", getComputerName()},
        {"pid", GetCurrentProcessId()}
    };
    // Write to update.log (rotating)
    // Send to telemetry endpoint
}
```

---

## 19. CROSS-REFERENCE: SOURCE LOCATIONS

| Component | File | Lines |
|-----------|------|-------|
| `realm_win_updater` | main.cpp | 17270-17500 |
| `realm_win_roll` | main.cpp | 16654-16700 |
| `realm_win_archive` | main.cpp | ~16600 (commented) |
| `verifyupdater.bat` | Project root | (entire file) |
| `age.bat` | Project root | (entire file) |
| `checkversion.bat` | Project root | (entire file) |
| `setversion.bat` | Project root | (entire file) |
| `clean.bat` | Project root | (entire file) |
| Menu handlers | main.cpp | 14393, 14408, 14423 |
| Dashboard version | main.cpp | 14580 (Build count: 3242) |

---

## 20. COMPLETE COMMAND REFERENCE

### 20.1 Update Commands
```cmd
# Check for updates (interactive)
PrimeOne.exe
# Press 'u' in main menu

# Direct update check
PrimeOne.exe -m u

# Host pushes update to guests
PrimeOne.exe -m 8 -p 54767
# Then in host menu: 5 (Network Updater)

# Guest requests update
PrimeOne.exe -m 9 -p 54767 -ip HOST_IP -w g
# Then in guest menu: 5 (Network Updater)

# Manual roll (install update)
PrimeOne.exe -m 6  # In sub-menu after 8/9
```

### 20.2 Batch Automation
```cmd
# Watchdog (run alongside PrimeOne)
verifyupdater.bat

# Version check
checkversion.bat

# Compare versions
age.bat

# Sign new version
setversion.bat

# Clean source
clean.bat
```

### 20.3 Manual Rollback
```cmd
# If update breaks:
copy primeoneold.exe primeone.exe
# Restart PrimeOne
```

---

*End of Feature Document 06: Update & Roll System*  
*Next: 07_WINDOWS_SYSTEM_UTILITIES.md*