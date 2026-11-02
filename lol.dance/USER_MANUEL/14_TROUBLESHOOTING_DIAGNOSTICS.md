# PrimeOne - Feature Document 14: Troubleshooting & Diagnostics
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` error paths, compilation errors, Wine test results, batch file behaviors  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

This document provides comprehensive troubleshooting guidance for PrimeOne, covering **compilation issues**, **runtime errors**, **network problems**, **performance bottlenecks**, and **deployment failures**. It synthesizes known issues from code analysis, build attempts, and Wine testing.

### Design Philosophy
- **Fail fast** - Clear error messages with actionable fixes
- **Diagnostic depth** - Built-in debugging utilities
- **Cross-platform awareness** - Windows vs Linux/Wine differences
- **Progressive disclosure** - Quick fixes → deep debugging

---

## 2. COMPILATION ISSUES

### 2.1 Critical Blockers (Linux/MinGW)

#### 2.1.1 Missing Windows Headers
```
fatal error: Ws2tcpip.h: No such file or directory
fatal error: cuda_runtime_api.h: No such file or directory
fatal error: d3d9.h: No such file or directory
fatal error: wbemidl.h: No such file or directory
```

**Fix:** Use Wine build with stub headers or install Windows SDK:
```bash
# Linux: Use Wine + MinGW with stub headers
/workspace/app/run_primeone_wine.sh  # Runs pre-built exe

# Or create stub headers in build system:
mkdir -p win_stubs
# Create winsock2.h, ws2tcpip.h, windows.h, d3d9.h, wbemidl.h, etc.
```

#### 2.1.2 std::byte Arithmetic Errors (20+ locations)
```
error: no match for 'operator+=' (operand types are '__int128' and 'std::byte')
error: cannot convert 'std::byte' to '__int128' in assignment
error: no match for 'operator*' (operand types are 'std::byte' and 'int')
error: no matching function for call to 'push_back(__int128&)'
```

**Fix:** Add explicit casts:
```cpp
// In primeTileClass methods:
etchWalkSum += static_cast<__int128>(data);
etchWalkSum = static_cast<__int128>(data);
primeBuild += static_cast<__int128>(breeze()) * 2;
primeFindsArray[idx] = static_cast<byte>(primeDifference & 0xFF);
wolfCatch.push_back(static_cast<byte>(primeDifference & 0xFF));
```

#### 2.1.3 pow() Ambiguity with __int128 (3 locations)
```
error: call of overloaded 'pow(int, __int128&)' is ambiguous
```

**Fix:** Implement integer power:
```cpp
__int128 ipow(__int128 base, __int128 exp) {
    __int128 result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}
// Replace: pow(2, factor) → ipow(2, factor)
```

#### 2.1.4 Missing Return Statements
```
warning: control reaches end of non-void function [-Wreturn-type]
// nextWalkPrime (line 4658), moonWalkPrime (line 4975)
```

**Fix:** Add return statements:
```cpp
__int128 nextWalkPrime(__int128 input) {
    // ... algorithm ...
    return foundPrime;  // Add at end
}
```

#### 2.1.5 uint8_t vs std::byte Pointer Conversions
```
error: cannot convert 'uint8_t**' to 'std::byte**'
error: cannot convert 'uint8_t*' to 'std::byte*'
```

**Fix:** Use consistent types:
```cpp
// Option 1: Use uint8_t everywhere
using byte = uint8_t;

// Option 2: Cast explicitly
byte** myTiles = reinterpret_cast<byte**>(new uint8_t*[count]);
myTiles[i] = reinterpret_cast<byte*>(new uint8_t[size]);
```

#### 2.1.5 Windows API Compilation Errors (30+)
```
error: 'MAKEWORD' was not declared
error: 'INVALID_HANDLE_VALUE' was not declared
error: 'TH32CS_SNAPTHREAD' was not declared
error: 'GetCurrentProcessId' was not declared
error: 'OpenThread' was not declared
error: 'CloseHandle' was not declared
```

**Fix:** Add missing headers:
```cpp
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tlhelp32.h>
#include <iphlpapi.h>
#include <wbemidl.h>
#include <comdef.h>
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "wbemuuid.lib")
```

### 2.2 Windows Build Issues

#### 2.2.1 Code::Blocks / MinGW
```bash
# Ensure correct compiler flags:
-march=x86-64 -std=c++17 -fexceptions -Wall
-I"$(CUDA_PATH)\include" -I"$(DXSDK_DIR)\Include"
-L"$(CUDA_PATH)\lib\x64" -L"$(DXSDK_DIR)\Lib\x64"
-lcudart -ld3d9 -ld3dx9 -lws2_32 -liphlpapi -lwbemuuid
```

#### 2.2.2 Visual Studio
```xml
<!-- Project properties -->
<ConfigurationType>Application</ConfigurationType>
<PlatformToolset>v143</PlatformToolset>
<WindowsTargetPlatformVersion>10.0.19041.0</WindowsTargetPlatformVersion>
<SubSystem>Console</SubSystem>  <!-- Critical for GetConsoleWindow() -->
```

---

## 3. RUNTIME ERRORS

### 3.1 Console Window Failures

#### 3.1.1 "Failed to get console window handle"
```
Failed to get console window handle.
```
**Cause:** Running GUI subsystem executable (`PrimeOne.exe`, `PrimeOneGui.exe`) without console.

**Fix:** Use CONSOLE subsystem executable:
```bash
# Linux/Wine:
script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null

# Windows: Build with /SUBSYSTEM:CONSOLE or use PrimeOne3236.exe
```

#### 3.1.2 Wine GUI Failures
```
err:winediag:nodrv_CreateWindow Application tried to create a window
err:winediag:nodrv_CreateWindow L"The explorer process failed to start."
```
**Cause:** GUI apps need X11/Wayland display.

**Fix:** Use Xvfb or console executable:
```bash
# GUI with virtual display:
xvfb-run -a /usr/lib/wine/wine64 PrimeOne.exe

# Console (preferred):
/usr/lib/wine/wine64 PrimeOne3236.exe
```

### 3.2 Network Errors

#### 3.2.1 Connection Refused
```
Guest connect to Host IP & Port: 192.168.1.100:54767
... timeout ...
```
**Causes & Fixes:**
| Cause | Fix |
|-------|-----|
| Host not running | Start host first: `primeone8host - 54767.bat` |
| Wrong IP | Edit guest batch with correct host IP |
| Firewall | `netsh advfirewall firewall add rule ... allow port 54767` |
| Wrong port | Match `-p` on host and guest |

#### 3.2.2 Bind Failures
```
bind() failed: Address already in use
```
**Fix:**
```batch
:: Check port
netstat -an | findstr :54767

:: Kill existing
taskkill /f /im primeone.exe

:: Or use different port
primeone.exe -m 8 -p 54768
```

#### 3.2.3 Wine Network Issues
```
err:winsock:WSARecv Failed to receive data
```
**Fix:** Ensure Wine networking works:
```bash
# Test Wine networking
wine64 cmd /c "ping 127.0.0.1"

# Use host network (if Docker)
docker run --network host ...
```

### 3.3 Memory & Performance

#### 3.3.1 Out of Memory
```
std::bad_alloc
```
**Causes:**
- Grid too large (`powerOf` > 25)
- Too many threads (`singers` > CPU cores)
- Memory leaks (no destructors)

**Fix:**
```cpp
// Limit grid size
if (powerOf > 25) powerOf = 25;  // 2^25 tiles = 33M tiles

// Limit threads
if (singers > hardware_concurrency() * 2) 
    singers = hardware_concurrency() * 2;

// Add destructors to primeTileClass
~primeTileClass() { 
    delete[] primeIndex; 
    delete[] returnTile; 
    delete[] primeFindsArray; 
}
```

#### 3.3.2 Slow Performance
| Symptom | Likely Cause | Fix |
|---------|--------------|-----|
| Low primes/sec | CPU only, no GPU | Enable `-f quickPrime`, check CUDA |
| High CPU, low output | Thread contention | Reduce `singers`, check locks |
| Network bottleneck | Slow LAN | Use 1Gbps+, enable compression |
| Memory thrashing | Grid too large | Reduce `powerOf` |

---

## 4. DEPLOYMENT FAILURES

### 4.1 Batch File Issues

#### 4.1.1 Guest Can't Connect
```
Guest connect to Host IP & Port: 10.0.0.22:54767
```
**Fix:** Edit `primeone9guestsShow - 54767.bat`:
```batch
:: Change IP to actual host
primeone.exe -m 9 -p 54767 -ip 192.168.1.100 -c1 -w g
```

#### 4.1.2 Multiple Guests Same Window
```batch
:: Current: start "" cmd /c ...
:: Problem: All guests in separate windows but hard to manage

:: Better: Use single window with job control
start "Guest1" /b primeone.exe -m 9 -p 54767 -ip %HOST% -c1 -w g
start "Guest2" /b primeone.exe -m 9 -p 54767 -ip %HOST% -c1 -w g
```

#### 4.1.3 VerifyUpdater Infinite Loop
```batch
:: Current has commented goto CheckNewer
:: Uncommented would loop forever

:: Fixed version:
:CheckNewer
... comparison logic ...
timeout /t 5 /nobreak >nul
goto CheckNewer  :: Now loops properly
```

### 4.2 Update Failures

#### 4.2.1 Signing Fails
```
SignTool Error: No certificates found
```
**Fix:**
```batch
:: 1. Install certificate
certutil -importpfx cert.pfx

:: 2. Use thumbprint instead of file
signtool sign /sha1 "THUMBPRINT" /t http://timestamp.digicert.com primeone.exe
```

#### 4.2.2 Roll Fails
```
PrimeOneUpdater.zip not found
```
**Fix:**
```batch
:: Ensure archive exists before roll
if not exist PrimeOneUpdater.zip (
    echo No update package found
    exit /b
)
```

---

## 5. DIAGNOSTIC TOOLS

### 5.1 Built-in Diagnostics

#### 5.1.1 Menu Option 3 (IP Config)
```
# In interactive mode after 8 or 9:
3
```
Shows network interfaces and IPs.

#### 5.1.2 realm_win_ipconfig()
```cpp
// Called from menu, outputs:
Ethernet0: 192.168.1.100
WiFi: 10.0.0.22
Loopback: 127.0.0.1
```

#### 5.1.3 realm_win_port_check()
```cpp
// Check if port available
realm_win_port_check("54767");
```

#### 5.1.4 System Handles (Commented)
```cpp
// Enable in menu_librarian:
// realm_os_windows();
// Shows: process, thread, file, socket, event, mutex handles
```

### 5.2 External Tools

#### 5.2.1 Network Debugging
```bash
# Windows
netstat -an | findstr :54767
Test-NetConnection 192.168.1.100 -Port 54767

# Linux
ss -tlnp | grep 54767
nc -zv 192.168.1.100 54767
tcpdump -i any port 54767
```

#### 5.2.2 Process Debugging
```bash
# Windows
tasklist /fi "imagename eq primeone.exe"
procmon.exe  # Sysinternals

# Linux/Wine
ps aux | grep primeone
wine64 taskmgr  # Wine task manager
```

#### 5.2.3 Memory Analysis
```bash
# Windows
vmmap.exe primeone.exe  # Sysinternals

# Linux
pmap -x $(pgrep primeone)
valgrind --tool=massif ./PrimeOne_linux
```

---

## 5.3 Logging & Tracing

### 5.3.1 Enable Debug Output
```cpp
// Add to main.cpp temporarily:
#define DEBUG_LOG 1
#ifdef DEBUG_LOG
#define DLOG(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
#define DLOG(fmt, ...)
#endif

// In librarian_functions:
DLOG("menuChoice=%d, input='%s'", menueChoice, userInput.c_str());

// In conduit:
DLOG("Host accepted connection from %s:%d", ip, port);
```

### 5.3.2 Structured Logging
```cpp
#include <chrono>
#include <fstream>

class Logger {
    std::ofstream logFile;
    std::mutex mtx;
public:
    Logger() { logFile.open("primeone_debug.log", std::ios::app); }
    
    template<typename... Args>
    void log(const char* level, const char* file, int line, Args&&... args) {
        std::lock_guard<std::mutex> lock(mtx);
        auto now = std::chrono::system_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch()) % 1000;
        auto time = std::chrono::system_clock::to_time_t(now);
        char buf[32];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
        
        logFile << "[" << buf << "." << std::setfill('0') << std::setw(3) << ms.count() 
                << "] " << level << " " << file << ":" << line << " ";
        (logFile << ... << args) << std::endl;
    }
};

#define LOG_INFO(...) Logger::instance().log("INFO", __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_ERROR(...) Logger::instance().log("ERROR", __FILE__, __LINE__, ##__VA_ARGS__)
```

---

## 6. COMMON ERROR CODES

### 6.1 Exit Codes
| Code | Meaning | Action |
|------|---------|--------|
| 0 | Success | Normal exit |
| 1 | Invalid argument | Check command line |
| 1 | No console window | Use PrimeOne3236.exe or script |
| 1 | Socket error | Check port/IP/firewall |
| 1 | File not found | Check paths |
| 255 | Unhandled exception | Check logs |

### 6.2 Winsock Errors
| Code | Constant | Meaning |
|------|----------|---------|
| 10048 | WSAEADDRINUSE | Port already in use |
| 10061 | WSAECONNREFUSED | Host not listening |
| 10060 | WSAETIMEDOUT | Network unreachable |
| 10013 | WSAEACCES | Permission denied (raw socket) |
| 10093 | WSANOTINITIALISED | WSAStartup not called |

---

## 7. DEBUGGING WORKFLOWS

### 7.1 Compilation Debugging
```bash
# 1. Verbose compilation
g++ -v -std=c++17 main.cpp 2>&1 | head -100

# 2. Preprocessor output
g++ -E -std=c++17 main.cpp 2>&1 | grep -n "Ws2tcpip\|cuda_runtime"

# 3. Check include paths
g++ -std=c++17 -H main.cpp 2>&1 | grep -E "winsock|ws2tcpip|cuda"
```

### 7.2 Runtime Debugging (Windows)
```cmd
:: Visual Studio Debugger
devenv PrimeOne.exe

:: WinDbg
windbg -g -G PrimeOne.exe

:: Debug with logging
PrimeOne.exe -m 8 -p 54767 2>&1 | tee debug.log
```

### 7.3 Runtime Debugging (Linux/Wine)
```bash
# Wine debug channels
WINEDEBUG=+winsock,+seh,+tid,+relay /usr/lib/wine/wine64 PrimeOne3236.exe

# GDB with Wine
gdb /usr/lib/wine/wine64
(gdb) run PrimeOne3236.exe

# Strace equivalent
wine64 strace.exe PrimeOne3236.exe 2>&1 | head -100
```

---

## 8. PERFORMANCE TUNING

### 8.1 Profiling
```bash
# Windows: Windows Performance Analyzer (WPA)
# 1. Record: wpr -start CPU -filemode primeone.etl
# 2. Run PrimeOne
# 3. Stop: wpr -stop primeone.etl
# 4. Analyze: wpa primeone.etl

# Linux: perf
perf record -g /usr/lib/wine/wine64 PrimeOne3236.exe
perf report
```

### 8.2 Key Metrics to Monitor
| Metric | Target | Alert If |
|--------|--------|----------|
| Primes/second | > 10K/s (CPU) | < 1K/s |
| GPU utilization | > 80% | < 50% |
| Memory usage | < 80% RAM | > 90% |
| Network throughput | > 10 Mbps | < 1 Mbps |
| Thread count | = CPU cores | > 2x cores |
| Prime gap avg | ~log(p) | Anomalous |

---

## 9. RECOVERY PROCEDURES

### 9.1 Corrupted Prime Book
```cmd
:: 1. Backup corrupted
copy primebook.bin primebook.corrupted

:: 2. Restore from backup
copy primebook.backup primebook.bin

:: 3. Or fresh start
del primebook.bin
PrimeOne.exe -m 1  :: Start New
```

### 9.2 Network Desync
```cmd
:: Host: Restart network
:: Press 'r' in main menu (Rebind)

:: Guests: Reconnect
:: Restart guest batch files
```

### 9.3 Executable Corruption
```cmd
:: Rollback
copy primeoneold.exe primeone.exe

:: Or re-download
:: From build artifact / release
```

---

## 10. SUPPORT MATRIX

### 10.1 Platform Support
| Platform | Build | Run | Notes |
|----------|-------|-----|-------|
| Windows 10/11 x64 | ✅ Native | ✅ Native | Full support |
| Windows Server 2019+ | ✅ Native | ✅ Native | Headless OK |
| Linux (Wine) | ⚠️ MinGW | ✅ Console | GUI needs Xvfb |
| Linux (Native) | ❌ Fails | ❌ Fails | Missing Win32 API |
| macOS (Wine/CrossOver) | ⚠️ | ⚠️ | Untested |
| Docker (Linux) | ⚠️ MinGW | ✅ Console | Use wine image |

### 10.2 Dependency Versions
| Dependency | Minimum | Recommended |
|------------|---------|-------------|
| Windows SDK | 10.0.17763 | 10.0.19041 |
| CUDA Toolkit | 11.0 | 12.2 |
| DirectX SDK | June 2010 | June 2010 |
| Visual C++ Runtime | 2019 | 2022 |
| Wine | 6.0 | 10.0 |
| MinGW-w64 | 8.0 | 12.0 |

---

## 11. ESCALATION PATH

### 11.1 Self-Service
1. Check this document
2. Enable debug logging
3. Search error in codebase
4. Try alternative executable (3236 vs GUI)

### 11.2 Community
- Check GearSlice analysis docs
- Review batch file patterns
- Compare with working deployment

### 11.3 Development
- Add missing headers
- Fix std::byte casts
- Implement integer pow
- Add return statements

---

## 12. QUICK REFERENCE CARD

### 12.1 Most Common Fixes
| Problem | Quick Fix |
|---------|-----------|
| Won't compile on Linux | Use Wine + pre-built exe |
| "Failed to get console" | Use `PrimeOne3236.exe` + `script` |
| Guest won't connect | Edit batch file with correct host IP |
| Port in use | `taskkill /f /im primeone.exe` |
| Missing DLLs | Copy from `curl/lib`, `libssh/lib` to exe dir |
| Update fails | Check `PrimeOneUpdater.zip` exists |
| Slow primes | Enable GPU: menu 'c' or `-f quickPrime` |

### 12.2 Key Files
```
Executables:
  PrimeOne3236.exe     ← USE THIS (console subsystem)
  PrimeOne.exe         ← GUI subsystem (needs display)
  PrimeOneGui.exe      ← GUI variant

Batch:
  primeone8host - 54767.bat      ← Host launcher
  primeone9guestsShow - 54767.bat ← Guest launcher (EDIT IP!)
  verifyupdater.bat              ← Update watchdog

Config:
  PrimeOne.cbp                   ← Code::Blocks project
  main.cpp                       ← 20K+ line source
  Run Gear On Boot.xml           ← Auto-start task
```

---

*End of Feature Document 14: Troubleshooting & Diagnostics*  
*Next: 15_MASTER_COMPENDIUM.md*