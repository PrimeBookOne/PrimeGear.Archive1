# PrimeOne - Feature Document 07: Windows System Utilities
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines ~14760-18000 (realm_win_handles_*, realm_os_windows, realm_win_save_state)  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Windows System Utilities (`realm_os_windows` and `realm_win_handles_*` functions) provide **deep system introspection** capabilities for PrimeOne. They enumerate processes, threads, file handles, sockets, events, mutexes, and can dump process memory. These utilities serve diagnostic, debugging, and potentially anti-analysis purposes.

### Design Philosophy
- **Native Windows API** - Direct Win32/WMI calls
- **Comprehensive** - Covers all major kernel object types
- **Diagnostic focus** - Visibility into process state
- **Extensible** - Modular handle enumerators

---

## 2. FUNCTION INVENTORY

### 2.1 Master Orchestrator
```cpp
// Line ~14760
void realm_os_windows() {
    realm_win_handles_process();
    realm_win_handles_thread();
    realm_win_handles_file();
    realm_win_handles_file2();
    realm_win_handles_sockets();
    realm_win_handles_events();
    realm_win_handles_mutex();
    realm_win_save_state();
}
```

### 2.2 Individual Enumerators

| Function | Purpose | Windows APIs Used |
|----------|---------|-------------------|
| `realm_win_handles_process()` | Current process handle | `GetCurrentProcessId`, `OpenProcess`, `CloseHandle` |
| `realm_win_handles_thread()` | Thread enumeration | `CreateToolhelp32Snapshot`, `Thread32First/Next`, `OpenThread`, `CloseHandle` |
| `realm_win_handles_file()` | File handles via WMI | `CoInitializeEx`, `CoCreateInstance` (WbemLocator), `IWbemServices::ExecQuery` |
| `realm_win_handles_file2()` | (Not visible - likely duplicate) | |
| `realm_win_handles_sockets()` | Socket handles | (Not implemented - commented) |
| `realm_win_handles_events()` | Event objects | (Stub - yesContinue=false) |
| `realm_win_handles_mutex()` | Mutex objects | (Stub - yesContinue=false) |
| `realm_win_save_state()` | Process memory dump | `GetCurrentProcess`, `GetSystemInfo`, `WriteProcessMemory` |

---

## 3. PROCESS HANDLE ENUMERATION

### 3.1 realm_win_handles_process() (Lines 14767-14800)
```cpp
void realm_win_handles_process() {
    bool yesContinue = true;
    if (yesContinue) {
        DWORD processId = GetCurrentProcessId();
        HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
        
        if (processHandle != NULL) {
            std::cout << "Windows Handle : " << processHandle << " . . . . " << endl;
            CloseHandle(processHandle);
        }
    }
}
```

**Purpose:** Obtain and display current process pseudo-handle.

**Issues:**
- `PROCESS_ALL_ACCESS` requires elevated privileges for some operations
- Only shows pseudo-handle, not actual handle table
- `yesContinue` hardcoded to true (dead code if false)

---

## 4. THREAD HANDLE ENUMERATION

### 4.1 realm_win_handles_thread() (Lines 17592-17615)
```cpp
void realm_win_handles_thread() {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshot != INVALID_HANDLE_VALUE) {
        THREADENTRY32 threadEntry;
        threadEntry.dwSize = sizeof(threadEntry);
        
        if (Thread32First(snapshot, &threadEntry)) {
            do {
                if (threadEntry.th32OwnerProcessID == GetCurrentProcessId()) {
                    HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, threadEntry.th32ThreadID);
                    // Process thread handle
                    CloseHandle(threadHandle);
                }
            } while (Thread32Next(snapshot, &threadEntry));
        }
        CloseHandle(snapshot);
    }
}
```

**Purpose:** Enumerate all threads owned by current process.

**APIs Used:**
- `CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0)` - System-wide thread snapshot
- `Thread32First/Next` - Iterate threads
- `OpenThread(THREAD_ALL_ACCESS, ...)` - Get thread handle
- `GetCurrentProcessId()` - Filter for own process

**Issues:**
- `THREAD_ALL_ACCESS` may fail for system threads
- No error handling for `OpenThread` failures
- Snapshot includes all system threads (performance)

---

## 5. FILE HANDLE ENUMERATION (WMI)

### 5.1 realm_win_handles_file() (Lines 14800-14950)
```cpp
void realm_win_handles_file() {
    bool yesContinue = false;  // DISABLED by default
    
    if (yesContinue) {
        // Full WMI implementation commented out:
        /*
        HRESULT hres;
        hres = CoInitializeEx(0, COINIT_MULTITHREADED);
        hres = CoInitializeSecurity(...);
        
        IWbemLocator* pLoc = NULL;
        CoCreateInstance(CLSID_WbemLocator, ..., IID_IWbemLocator, (LPVOID*)&pLoc);
        
        IWbemServices* pSvc = NULL;
        pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), ..., &pSvc);
        
        CoSetProxyBlanket(pSvc, ...);
        
        IEnumWbemClassObject* pEnumerator = NULL;
        pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_Process"),
                       WBEM_FLAG_FORWARD_ONLY, NULL, &pEnumerator);
        // Retrieve process information
        */
    }
}
```

**Purpose:** Use WMI to enumerate file handles via `Win32_Process` query.

**Status:** **Completely commented out** - disabled by `yesContinue = false`.

**WMI Infrastructure:**
```cpp
// Required headers (not included in visible code):
#include <wbemidl.h>
#include <comdef.h>
#pragma comment(lib, "wbemuuid.lib")

// COM initialization sequence:
1. CoInitializeEx(COINIT_MULTITHREADED)
2. CoInitializeSecurity(RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE)
3. CoCreateInstance(CLSID_WbemLocator) → IWbemLocator
4. IWbemLocator::ConnectServer(ROOT\CIMV2) → IWbemServices
5. CoSetProxyBlanket(RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, ...)
6. IWbemServices::ExecQuery("SELECT * FROM Win32_Process") → IEnumWbemClassObject
7. IEnumWbemClassObject::Next() → IWbemClassObject
8. IWbemClassObject::Get() for properties
```

---

## 6. SOCKET HANDLE ENUMERATION

### 6.1 realm_win_handles_sockets() (Commented)
```cpp
// Line 14811 in menu_librarian:
// realm_win_handles_sockets();  // Commented out

// Implementation not visible in excerpts
// Would require:
// - GetExtendedTcpTable / GetExtendedUdpTable (IPHLPAPI)
// - Or WMI Win32_NetworkConnection
// - Or socket handle enumeration via NtQuerySystemInformation
```

---

## 7. EVENT & MUTEX ENUMERATION (Stubs)

### 7.1 realm_win_handles_events() (Line 16018)
```cpp
void realm_win_handles_events() {
    bool yesContinue = false;  // DISABLED
    // Would enumerate event objects via:
    // - NtQuerySystemInformation(SystemHandleInformation)
    // - Or Toolhelp32 with TH32CS_SNAPEVENT (not standard)
}
```

### 7.2 realm_win_handles_mutex() (Line 16332)
```cpp
void realm_win_handles_mutex() {
    bool yesContinue = false;  // DISABLED
    // Would enumerate mutex objects
}
```

**Both are stubs** - disabled and not implemented.

---

## 8. PROCESS MEMORY DUMP (realm_win_save_state)

### 8.1 Function (Lines 16654-16690)
```cpp
void realm_win_save_state() {
    HANDLE processHandle = GetCurrentProcess();
    
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    
    LPVOID minAddress = systemInfo.lpMinimumApplicationAddress;
    LPVOID maxAddress = systemInfo.lpMaximumApplicationAddress;
    
    SIZE_T memorySize = static_cast<SIZE_T>(
        reinterpret_cast<BYTE*>(maxAddress) - 
        reinterpret_cast<BYTE*>(minAddress)
    );
    
    // BUG: WriteProcessMemory used incorrectly
    if (!WriteProcessMemory(processHandle, minAddress, minAddress, memorySize, nullptr)) {
        // Error
    }
    
    // BUG: minAddress, memorySize out of scope
    std::ofstream outFile("PrimeOneMemoryDump.bin", std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(minAddress), memorySize);
}
```

**Purpose:** Dump entire process virtual memory to file.

**Critical Bugs:**
1. `minAddress` and `maxAddress` declared inside `if` block → out of scope
2. `memorySize` declared inside `if` block → out of scope
3. `WriteProcessMemory` used **backwards** - reads from process, not writes
4. Dumps **entire user-mode address space** (terabytes on 64-bit)
5. No paging/streaming - attempts single allocation
6. No handle cleanup

### 8.2 Correct Implementation
```cpp
void realm_win_save_state_corrected() {
    HANDLE processHandle = GetCurrentProcess();
    
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    LPVOID minAddr = sysInfo.lpMinimumApplicationAddress;
    LPVOID maxAddr = sysInfo.lpMaximumApplicationAddress;
    
    // Dump in chunks (64KB)
    const SIZE_T CHUNK_SIZE = 65536;
    std::ofstream outFile("PrimeOneMemoryDump.bin", std::ios::binary);
    
    MEMORY_BASIC_INFORMATION mbi;
    for (LPVOID addr = minAddr; addr < maxAddr; addr = (BYTE*)addr + mbi.RegionSize) {
        if (VirtualQueryEx(processHandle, addr, &mbi, sizeof(mbi)) == 0) break;
        
        if (mbi.State == MEM_COMMIT && 
            (mbi.Protect & (PAGE_READWRITE | PAGE_READONLY | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE))) {
            
            std::vector<BYTE> buffer(mbi.RegionSize);
            SIZE_T bytesRead;
            if (ReadProcessMemory(processHandle, mbi.BaseAddress, buffer.data(), mbi.RegionSize, &bytesRead)) {
                outFile.write(reinterpret_cast<char*>(buffer.data()), bytesRead);
            }
        }
    }
}
```

---

## 9. NETWORK DIAGNOSTICS

### 9.1 realm_win_ipconfig() (Called from menu)
```cpp
// Called at end of menu_librarian() and menu option 3
void realm_win_ipconfig() {
    // Implementation not fully visible
    // Likely uses:
    // - GetAdaptersInfo() / GetAdaptersAddresses() (IPHLPAPI)
    // - Or system("ipconfig")
    // - Or WMI Win32_NetworkAdapterConfiguration
}
```

### 9.2 realm_win_port_check() (Commented in menu)
```cpp
// Line 14805 in menu_librarian:
/*
if (realm_win_port_check("555555")) {
    cout << "Port 555555 is in use. . ." << endl;
} else {
    cout << "Port is available. . ." << endl;
}
*/

// Implementation (inferred):
bool realm_win_port_check(const string& portStr) {
    int port = stoi(portStr);
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    int result = bind(s, (sockaddr*)&addr, sizeof(addr));
    closesocket(s);
    return result == SOCKET_ERROR;  // True if port in use
}
```

**Note:** Port "555555" (6 digits) appears to be typo for 55555.

---

## 10. TCP HOST/GUEST UTILITIES

### 10.1 realm_os_tcp_host() (Line 18215)
```cpp
void realm_os_tcp_host() {
    bool yesContinue = true;
    
    // TCP server implementation
    WORD ver = MAKEWORD(2, 2);
    WSAStartup(ver, &wsaData);
    
    SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    hint.sin_addr.s_addr = INADDR_ANY;
    
    bind(listenSock, (sockaddr*)&hint, sizeof(hint));
    listen(listenSock, SOMAXCONN);
    
    // Accept loop
    while (yesContinue) {
        SOCKET clientSock = accept(listenSock, nullptr, nullptr);
        // Handle client
    }
}
```

### 10.2 realm_os_tcp_guest() (Line 18529)
```cpp
void realm_os_tcp_guest(string remoteHostIPv4) {
    bool yesContinue = true;
    
    WORD ver = MAKEWORD(2, 2);
    WSAStartup(ver, &wsaData);
    
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    hint.sin_addr.s_addr = inet_addr(remoteHostIPv4.c_str());
    
    connect(sock, (sockaddr*)&hint, sizeof(hint));
    
    // Communication loop
}
```

**Issues:** Same `sin_addr` bug as updater.

---

## 11. CONSOLE & WINDOW MANAGEMENT

### 11.1 Console Attachment (main() lines 11978-12000)
```cpp
HWND consoleWindow = GetConsoleWindow();
if (consoleWindow == nullptr) {
    std::cerr << "Failed to get console window handle.\n";
    return 1;
}

// Position window
RECT desktopRect;
HWND hDesktop = GetDesktopWindow();
GetWindowRect(hDesktop, &desktopRect);

int x = 0, y = 0;
int width = desktopRect.right / 3;
int height = desktopRect.bottom / 2;

if (optionMenueInput == "8") {  // Host mode
    x = width * 2; y = height;
} else {
    width = width / 2; height = height * 0.75;
}

SetWindowPos(consoleWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
SetConsoleTitle("PrimeBookGear");
```

### 11.2 Debug Console Allocation (Line 12248)
```cpp
void AttachConsoleWindow() {
    AllocConsole();  // Allocate new console
    char* title = "Debug Console";
    SetConsoleTitle(title);
    // Redirect stdio
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    freopen("CONIN$", "r", stdin);
}
```

---

## 12. SYSTEM METRICS

### 12.1 realm_metalUptime() (Line 12352)
```cpp
double realm_metalUptime() {
    DWORD uptime = GetTickCount();  // Milliseconds since boot
    return static_cast<double>(uptime) / 1000.0;  // Seconds
}
```
**Note:** `GetTickCount()` wraps at 49.7 days. Use `GetTickCount64()` for long-running.

### 12.2 System Info (From save_state)
```cpp
SYSTEM_INFO sysInfo;
GetSystemInfo(&sysInfo);
// sysInfo.dwNumberOfProcessors
// sysInfo.lpMinimumApplicationAddress
// sysInfo.lpMaximumApplicationAddress
// sysInfo.dwPageSize
// sysInfo.dwAllocationGranularity
```

---

## 13. MENU INTEGRATION

### 13.1 Dashboard Display
The menu_librarian shows live output from `realm_win_ipconfig()` at bottom (lines 4-6 via ANSI positioning).

### 13.2 Sub-Menu Option 3
```cpp
// Line 14382-14384
else if (userInput == "3" && menueChoice == 1) {
    realm_win_ipconfig();
    reload = true;
}
```
Shows network configuration in sub-menu.

### 13.3 Commented Full Diagnostics
```cpp
// Line 14813 in menu_librarian:
// realm_os_windows();  // Would show ALL handle types
```

---

## 14. REQUIRED HEADERS & LIBRARIES

### 14.1 Headers Needed
```cpp
// Core
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <psapi.h>

// WMI
#include <wbemidl.h>
#include <comdef.h>

// Linker
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
```

### 14.2 Missing in Current Code
The excerpts show numerous missing includes causing compilation errors (documented in Feature Doc 04).

---

## 15. SECURITY & PRIVACY

### 15.1 Information Exposure
| Function | Data Exposed | Risk |
|----------|--------------|------|
| `realm_win_handles_process` | Process handle | Low |
| `realm_win_handles_thread` | Thread IDs, handles | Medium |
| `realm_win_handles_file` (WMI) | All process info | High |
| `realm_win_save_state` | Full memory dump | Critical |
| `realm_win_ipconfig` | Network topology | Medium |
| `realm_metalUptime` | System boot time | Low |

### 15.2 Mitigations
- Run with least privilege
- Disable WMI enumeration (`yesContinue = false`)
- Encrypt memory dumps
- Audit log all handle enumeration

---

## 16. CROSS-PLATFORM CONSIDERATIONS

### 16.1 Linux Equivalents
| Windows API | Linux Equivalent |
|-------------|------------------|
| `GetCurrentProcessId()` | `getpid()` |
| `OpenProcess()` | `/proc/self/` filesystem |
| `CreateToolhelp32Snapshot` | `/proc/<pid>/task/` |
| `GetAdaptersInfo()` | `getifaddrs()`, `/proc/net/dev` |
| `GetSystemInfo()` | `sysinfo()`, `/proc/cpuinfo` |
| `WriteProcessMemory` | `process_vm_readv()` |
| `VirtualQueryEx` | `/proc/<pid>/maps` |
| WMI | `systemd` D-Bus, `/sys` |

### 16.2 Abstraction Layer Needed
```cpp
class SystemInspector {
public:
    virtual vector<ProcessInfo> enumerateProcesses() = 0;
    virtual vector<ThreadInfo> enumerateThreads() = 0;
    virtual vector<ModuleInfo> enumerateModules() = 0;
    virtual vector<HandleInfo> enumerateHandles() = 0;
    virtual NetworkInfo getNetworkInfo() = 0;
    virtual bool dumpMemory(const string& path) = 0;
};

class WindowsInspector : public SystemInspector { ... };
class LinuxInspector : public SystemInspector { ... };
```

---

## 17. KNOWN BUGS & TECHNICAL DEBT

### 17.1 Compilation Errors
| Missing Symbol | Required Header |
|----------------|-----------------|
| `MAKEWORD` | `winsock2.h` |
| `WORD`, `WSADATA` | `winsock2.h` |
| `sockaddr_in`, `inet_addr` | `winsock2.h`, `ws2tcpip.h` |
| `INADDR_ANY` | `winsock2.h` |
| `MAX_COMPUTERNAME_LENGTH` | `windows.h` |
| `ZeroMemory` | `windows.h` |
| `GetComputerName` | `windows.h` |
| `INET_ADDRSTRLEN` | `ws2tcpip.h` |
| `GetCurrentProcessId` | `windows.h` |
| `OpenProcess`, `PROCESS_ALL_ACCESS` | `windows.h` |
| `CloseHandle` | `windows.h` |
| `CreateToolhelp32Snapshot` | `tlhelp32.h` |
| `THREADENTRY32`, `Thread32First/Next` | `tlhelp32.h` |
| `OpenThread`, `THREAD_ALL_ACCESS` | `windows.h` |
| `GetTickCount` | `windows.h` |
| `GetSystemInfo`, `SYSTEM_INFO` | `windows.h` |
| `LPVOID`, `SIZE_T`, `BYTE` | `windows.h` |
| `WriteProcessMemory` | `windows.h` |
| `VirtualQueryEx` | `windows.h` |
| `AllocConsole` | `windows.h` |
| `GetConsoleWindow` | `windows.h` |
| `GetDesktopWindow` | `windows.h` |
| `GetWindowRect` | `windows.h` |
| `SetWindowPos` | `windows.h` |
| `HWND_TOP`, `SWP_SHOWWINDOW` | `windows.h` |

### 17.2 Logic Bugs
1. `yesContinue = false` disables WMI, events, mutex enumeration
2. `realm_win_save_state` has scope bugs (variables in if-block)
3. `WriteProcessMemory` used backwards
4. Memory dump attempts terabyte allocation
5. Port check uses "555555" (typo)

### 17.3 Architecture Debt
- All utilities in single monolithic file
- No error handling propagation
- Synchronous blocking calls
- No timeout on WMI queries
- Hardcoded limits (ARRAY_SIZE, buffer sizes)

---

## 18. REFACTORING ROADMAP

### 18.1 Phase 1: Fix Compilation (Critical)
- [ ] Add all missing headers
- [ ] Fix variable scope in `realm_win_save_state`
- [ ] Fix `sin_addr` usage
- [ ] Fix `WriteProcessMemory` direction

### 18.2 Phase 2: Enable Disabled Features (High)
- [ ] Implement WMI file handle enumeration
- [ ] Implement socket handle enumeration (IPHLPAPI)
- [ ] Implement event/mutex enumeration
- [ ] Fix port check typo

### 18.3 Phase 3: Safety & Performance (High)
- [ ] Chunked memory dump with VirtualQueryEx
- [ ] Timeout on WMI connections
- [ ] Error handling for all Win32 calls
- [ ] Privilege checking before sensitive ops

### 18.4 Phase 4: Abstraction (Medium)
- [ ] Create `SystemInspector` interface
- [ ] Implement Linux backend
- [ ] Add structured logging
- [ ] JSON output for programmatic use

### 18.5 Phase 5: Diagnostics UI (Low)
- [ ] Real-time handle count graphs
- [ ] Memory map visualization
- [ ] Network connection map
- [ ] Thread timeline view

---

## 19. TESTING SPECIFICATIONS

### 19.1 Unit Tests
| Function | Test Cases |
|----------|------------|
| `realm_win_handles_process` | Valid handle returned, error on no access |
| `realm_win_handles_thread` | Count matches `GetCurrentProcessId` threads |
| `realm_win_ipconfig` | Returns at least loopback adapter |
| `realm_win_port_check` | True for bound port, false for free |
| `realm_win_save_state` | Creates valid dump file (small test) |

### 19.2 Integration Tests
- Full `realm_os_windows()` execution
- Memory dump of known process size
- WMI query performance (<5s)
- Concurrent enumeration safety

### 19.3 Security Tests
- Run under restricted token
- Verify no sensitive data in dumps
- Audit handle access permissions

---

## 20. COMPLETE COMMAND REFERENCE

### 20.1 Interactive Menu Access
```
Main Menu → (after 8 or 9) Sub-Menu → 3: Network Peers / IP Config
```
Runs `realm_win_ipconfig()` and displays.

### 20.2 Programmatic Access
```cpp
// Direct calls (if extracted to library)
realm_win_ipconfig();           // Show network config
realm_win_port_check("54767");  // Check port
realm_os_tcp_host();            // Start TCP server
realm_os_tcp_guest("1.2.3.4");  // Connect to host
realm_metalUptime();            // Get system uptime
```

### 20.3 Debug Console
```cmd
# In interactive menu, not directly accessible
# Would need to call AttachConsoleWindow() first
```

---

## 21. FUTURE ENHANCEMENTS

### 21.1 Diagnostic Features
- [ ] ETW (Event Tracing for Windows) integration
- [ ] Performance counter sampling
- [ ] Heap/stack analysis
- [ ] DLL injection detection
- [ ] Rootkit detection (DKOM, SSDT hooks)

### 21.2 Network Diagnostics
- [ ] Bandwidth measurement
- [ ] Latency histogram
- [ ] Packet capture (WinPcap/Npcap)
- [ ] TLS certificate inspection

### 21.3 Memory Analysis
- [ ] Heap fragmentation report
- [ ] Leak detection (UMDH integration)
- [ ] String search in memory
- [ ] Cryptographic key scanning

---

*End of Feature Document 07: Windows System Utilities*  
*Next: 08_BATCH_AUTOMATION_DEPLOYMENT.md*