# PrimeOne - Feature Document 01: Command Line Interface & Argument Parsing
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines 11908-12070, 225 (Unicode argv)  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The PrimeOne command-line interface provides a comprehensive argument parsing system that allows direct execution of any menu function without interactive navigation. The parser is implemented in `main()` using a classic `argc/argv` loop with `std::istringstream` for typed argument extraction.

### Design Philosophy
- **Explicit over implicit** - Every option requires a flag
- **Type safety** - Integer arguments validated via stream extraction
- **Fail-fast** - Invalid arguments cause immediate exit with error message
- **Default-heavy** - Sensible defaults for all optional parameters

---

## 2. ARGUMENT PARSING ARCHITECTURE

### 2.1 Entry Point
```cpp
int main(int argc, char* argv[])
```
Located at line 11914 in `main.cpp`. The function declares all option variables at the top, then enters a for-loop starting at index 1 (skipping program name).

### 2.2 Variable Declarations (Lines 11918-11931)
```cpp
bool createHost = true;
string networkAssignment = "default";
bool singleCore = false;
string computeMethod = "null";
string hostIp = "null";
int hostPort = 0;
string optionComputeInput = "default";
bool optionO = false;
int optionCores = 0;
string optionMenueInput = "null";
string optionFlagInput = "null";
```

**Key Observations:**
- `hostIp` defaults to "null" (string), not empty string
- `hostPort` defaults to 0 (auto-assign)
- `optionMenueInput` and `optionFlagInput` default to "null" sentinel
- `networkAssignment` defaults to "default" (resolved later to h/g)

---

## 3. COMPLETE ARGUMENT REFERENCE

### 3.1 Flag Arguments (Boolean)

| Flag | Variable | Description |
|------|----------|-------------|
| `-o` | `optionO` | Enables "option O" (purpose unclear, legacy) |

```cpp
if (arg == "-o") {
    optionO = true;
}
```

### 3.2 Integer Arguments (Require Value)

| Flag | Variable | Validation | Usage |
|------|----------|------------|-------|
| `-c` | `optionCores` | Stream extraction + fail check | CPU core count/affinity |
| `-p` | `hostPort` | Stream extraction + fail check | TCP port number |
| `-c` | (also sets `globalNewHostPort`) | | Global port for network |

**Implementation Pattern (Lines 11934-11940, 11951-11957):**
```cpp
else if (arg == "-c" && i + 1 < argc) {
    std::istringstream stream(argv[i + 1]);
    stream >> optionCores;
    if (stream.fail()) {
        std::cerr << "Invalid argument for -c. Expected integer." << std::endl;
        return 1;
    }
    ++i; // Skip consumed argument
}
```

**Error Handling:**
- Checks `i + 1 < argc` to prevent out-of-bounds
- Uses `std::istringstream` for safe integer parsing
- On failure: prints to `std::cerr`, returns exit code 1
- Increments loop counter `i` to skip the value argument

### 3.3 String Arguments (Require Value)

| Flag | Variable | Description |
|------|----------|-------------|
| `-m` | `optionMenueInput` | Direct menu option (bypasses interactive menu) |
| `-ip` | `hostIp` | Bind IP (host) or connect IP (guest) |
| `-f` | `optionFlagInput` | Compute flags (`git_off`, `quickPrime`, `noPrime`) |
| `-x` | `optionComputeInput` | Compute method (`Gear`, `blindPrime`, etc.) |
| `-w` | `networkAssignment` | Network role (`h`=host, `g`=guest) |

**Implementation Pattern (Lines 11942-11970):**
```cpp
else if (arg == "-m" && i + 1 < argc) {
    optionMenueInput = argv[i + 1];
    ++i;
}
else if (arg == "-ip" && i + 1 < argc) {
    hostIp = argv[i + 1];
    ++i;
}
```

---

## 4. POST-PARSING LOGIC

### 4.1 Network Role Resolution (Lines 12035-12038)
```cpp
if (networkAssignment == "g") {
    networkAssignment = "g";
    createHost = false;
} else {
    networkAssignment = "h";
    createHost = true;
}
```
**Behavior:** Any value other than "g" defaults to host mode. This includes "default", "h", or any typo.

### 4.2 Core Affinity Logic (Lines 12054-12058)
```cpp
if (optionCores == 1) { singleCore = true; }
if (optionCores != 0) {
    cout << "CPU Core Assignment: " << optionCores;
    if (singleCore == true) { cout << "  SINGLE Core "; }
    cout << endl;
}
```
- `optionCores == 1` → `singleCore = true` (special case)
- `optionCores > 1` → Multi-core (exact behavior in primeTileClass)
- `optionCores == 0` → Auto (not displayed)

### 4.3 Compute Method Resolution (Lines 12063-12070)
```cpp
optionComputeInput = "Gear"; // blindPrime 
if (optionComputeInput != "default") {
    cout << "Compute Assignment: " << optionComputeInput << endl;
} else {
    cout << "Compute Assignment: " << optionComputeInput << endl;
    computeMethod = optionComputeInput;
}
```
**Note:** Hardcoded override to "Gear" regardless of `-x` argument (line 12063). This appears to be a debug/development override.

### 4.4 Menu Option Handling
```cpp
if (optionMenueInput != "null") {
    cout << "Menue Assignment: " << optionMenueInput << endl;
}
```
Passed directly to `librarian_functions()` which executes the corresponding menu action immediately.

---

## 5. CONSOLE WINDOW MANAGEMENT (Lines 11978-12000)

After argument parsing but before librarian execution, the code performs console window positioning:

```cpp
HWND consoleWindow = GetConsoleWindow();
if (consoleWindow == nullptr) {
    std::cerr << "Failed to get console window handle.\n";
    return 1;
}
RECT desktopRect;
const HWND hDesktop = GetDesktopWindow();
GetWindowRect(hDesktop, &desktopRect);
int screenWidth = desktopRect.right;
int screenHeight = desktopRect.bottom;
int x = 0; int y = 0;
int width = screenWidth / 3; int height = screenHeight / 2;
if (optionMenueInput == "8") {
    x = width * 2; y = height;
} else {
    width = width / 2; height = height * 0.75;
}
SetWindowPos(consoleWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
SetConsoleTitle("PrimeBookGear");
```

**Behavior:**
- **Host mode (`-m 8`)**: Positions window in right-half, lower quadrant
- **Other modes**: Positions in upper-left quadrant, smaller
- **Failure**: Exits with code 1 if no console window (GUI subsystem)

**This is why `PrimeOne3236.exe` (CONSOLE subsystem) works but `PrimeOne.exe` (GUI subsystem) fails on Wine.**

---

## 6. STATUS OUTPUT (Lines 12040-12052)

The parser prints a detailed status summary before entering librarian:

```cpp
if (hostIp == "null" && hostPort != 0 && networkAssignment == "g") {
    cout << "Guest connect to Host Port: " << hostPort << endl;
}
if (hostIp != "null" && hostPort != 0 && networkAssignment == "g") {
    cout << "Guest connect to Host IP & Port: " << hostIp << ":" << hostPort << endl;
}
if (hostPort != 0 && hostIp != "null" && networkAssignment == "h") {
    cout << "Host Assigned IP & Port: " << hostIp << ":" << hostPort << endl;
}
if (hostPort != 0 && hostIp == "null" && networkAssignment == "h") {
    cout << "Host Assigned Port: " << hostPort << endl;
}
```

**Output Examples:**

**Host with IP:**
```
Host Assigned IP & Port: 192.168.1.100:54767
CPU Core Assignment: 4
Menue Assignment: 8
Flag Assignment: quickPrime
Compute Assignment: Gear
```

**Guest with IP:**
```
Guest connect to Host IP & Port: 192.168.1.100:54767
CPU Core Assignment: 2  SINGLE Core
Menue Assignment: 9
Flag Assignment: quickPrime
Compute Assignment: Gear
```

---

## 7. UNICODE COMMAND LINE SUPPORT (Line 225)

```cpp
LPWSTR* argvW = CommandLineToArgvW(GetCommandLineW(), &argc);
```

At the very top of `main.cpp` (line 225), before `main()`, the code retrieves Unicode command line arguments. This enables proper handling of non-ASCII paths and arguments on Windows.

**Note:** This `argvW` is NOT used in the standard `main(int argc, char* argv[])` - the standard argc/argv is used instead. The Unicode version appears to be legacy or for future use.

---

## 8. COMMENTED COUNTDOWN CODE (Lines 12072-12100)

A significant block of commented code implements a countdown timer with async interrupt:

```cpp
/* std::mutex mtx;
std::cout << "Press ENTER to interrupt default SET to Load-N-Go!!!" << std::endl;
auto future = std::async(std::launch::async, [&mtx, &interrupted]() {
    std::cin.get();
    std::lock_guard<std::mutex> lock(mtx);
    interrupted = true;
});
for (int i = countdown_seconds; i >= 1; --i) {
    { std::lock_guard<std::mutex> lock(mtx);
        if (interrupted) { optionMenueInput = "null"; break; }
    }
    std::cout << i << " ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
int GO = interrupted ? 0 : 1;
std::cout << "GO = " << GO << std::endl; */
```

**Purpose:** Would have allowed user to press ENTER during countdown to enter interactive menu instead of auto-executing default "Load & Go".

---

## 9. FINAL LIBRARIAN INVOCATION (Line 12102)

```cpp
librarian_functions(hostIp, hostPort, optionCores, optionMenueInput, 
                    optionFlagInput, optionComputeInput, singleCore, 
                    computeMethod, createHost);
```

All parsed arguments forwarded to the central coordinator function.

---

## 10. USAGE EXAMPLES

### 10.1 Interactive Mode (Default)
```cmd
PrimeOne.exe
```
No arguments → Interactive menu with full dashboard display.

### 10.2 Host Mode - Minimal
```cmd
PrimeOne.exe -m 8 -p 54767
```
Direct to network host on port 54767.

### 10.3 Host Mode - Full Configuration
```cmd
PrimeOne.exe -m 8 -p 54767 -ip 192.168.1.100 -c 8 -f quickPrime -x Gear -w h
```
- Explicit bind IP
- 8 cores
- Quick prime algorithm
- Gear compute method
- Explicit host role

### 10.4 Guest Mode - Minimal
```cmd
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -w g
```
Connect to host at 192.168.1.100:54767 as guest.

### 10.5 Guest Mode - Full Configuration
```cmd
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -c 2 -f noPrime -x blindPrime -w g
```
- 2 cores (not single)
- No prime computation (just networking?)
- Blind prime method
- Explicit guest role

### 10.6 Library Mode (Archive Management)
```cmd
PrimeOne.exe -m l
```
Direct to library/archive menu (option 'l').

### 10.7 Update Mode
```cmd
PrimeOne.exe -m u
```
Direct to update check/install.

---

## 11. ERROR CONDITIONS & EXIT CODES

| Condition | Exit Code | Message |
|-----------|-----------|---------|
| Invalid integer for `-c` or `-p` | 1 | "Invalid argument for -c/-p. Expected integer." |
| Unknown argument | 1 | "Invalid argument: <arg>" (to stderr) |
| No console window (GUI exe) | 1 | "Failed to get console window handle." |
| Normal exit | 0 | (via `exit(0)` in librarian) |

---

## 12. KNOWN ISSUES & LIMITATIONS

### 12.1 Hardcoded Compute Override
Line 12063: `optionComputeInput = "Gear";` overrides `-x` argument. To use `-x`, this line must be removed or conditionalized.

### 12.2 No Help/Usage Message
No `-h` or `--help` implemented. Users must know arguments from source or documentation.

### 12.3 No Short/Long Aliases
Only single-letter flags. No `--menu`, `--port`, `--host` long forms.

### 12.4 No Argument Validation Beyond Type
- Port range not validated (1-65535)
- IP format not validated
- Core count not validated against system CPU count
- Menu option not validated against valid options

### 12.5 GUI Subsystem Console Issue
`PrimeOne.exe` built as GUI subsystem (`/SUBSYSTEM:WINDOWS`) fails `GetConsoleWindow()` unless run under `script` or `wineconsole`. Use `PrimeOne3236.exe` (CONSOLE subsystem) for headless operation.

---

## 13. EXTENSION POINTS

### Adding New Arguments
1. Add variable declaration in main() scope
2. Add `else if` block in parsing loop
3. Add post-processing logic if needed
4. Add to status output section
5. Pass to `librarian_functions()` or relevant subsystem

### Example: Adding `--config <file>`
```cpp
string configFile = "default.cfg";
// In parsing loop:
else if (arg == "--config" && i + 1 < argc) {
    configFile = argv[i + 1];
    ++i;
}
// In status output:
if (configFile != "default.cfg") cout << "Config: " << configFile << endl;
// Pass to librarian_functions (add parameter)
```

### Adding Argument Validation
```cpp
else if (arg == "-p" && i + 1 < argc) {
    std::istringstream stream(argv[i + 1]);
    stream >> hostPort;
    if (stream.fail() || hostPort < 1 || hostPort > 65535) {
        std::cerr << "Invalid port. Must be 1-65535." << std::endl;
        return 1;
    }
    globalNewHostPort = hostPort;
    ++i;
}
```

---

## 14. INTEGRATION WITH BATCH FILES

The batch files in the project directory demonstrate practical usage patterns:

### 14.1 `primeone8host - 54767.bat`
```batch
primeone.exe -m 8 -p 54767
```
Minimal host launcher. Uses defaults for everything else.

### 14.2 `primeone9guestsShow - 54767.bat`
```batch
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```
Guest launcher with:
- `-m 9` = Guest menu option
- `-p 54767` = Same port as host
- `-ip 10.0.0.22` = Hardcoded host IP (needs editing per deployment)
- `-c1` = Single core
- `-w g` = Explicit guest role
- `start "" cmd /c` = Launch in new window (allows multiple guests)

### 14.3 `verifyupdater.bat` - Auto-Update Loop
```batch
:CheckNewer
REM Compare timestamps of primeoneold.exe vs primeone.exe
if primeone.exe newer:
    copy primeone.exe primeoneold.exe
    timeout 1
    goto CheckNewer
```
Watches for newer executable and overwrites backup. Designed to run alongside PrimeOne for hot updates.

---

## 15. CROSS-PLATFORM CONSIDERATIONS

### Linux/Wine
- Arguments pass through Wine unchanged
- `GetConsoleWindow()` requires `script` pseudo-terminal
- Unicode `argvW` not available (Win32 API)
- Console positioning (`SetWindowPos`) fails silently on Wine

### MinGW Build
- Same `main()` signature works
- `CommandLineToArgvW` available in MinGW-w64
- No code changes needed for argument parsing

---

## 16. SECURITY CONSIDERATIONS

### 16.1 No Input Sanitization
- IP addresses passed directly to `inet_addr()` / `inet_pton()`
- Port numbers used directly in `socket()` bind/connect
- No validation against injection or overflow

### 16.2 No Authentication
- Network communication unencrypted
- No host/guest verification
- Trusted LAN assumed

### 16.3 Argument Injection
- String arguments (`-ip`, `-f`, `-x`) used in file paths and system calls
- Potential for command injection if passed to `system()` (not currently done)

---

## 17. DEBUGGING TIPS

### 17.1 Enable Argument Echo
Uncomment lines 12018-12020:
```cpp
// std::cout << "Option -o: " << std::boolalpha << optionO << std::endl;
// std::cout << "Option -c: " << optionCores << std::endl;
// std::cout << "Option -m: " << optionMenueInput << std::endl;
```

### 17.2 Enable Countdown Interrupt
Uncomment the countdown block (lines 12072-12100) to allow menu access even with `-m`.

### 17.3 Trace librarian_functions Entry
Add at start of `librarian_functions`:
```cpp
cout << "[DEBUG] librarian_functions called:" << endl;
cout << "  hostIp=" << hostIp << " hostPort=" << hostPort << endl;
cout << "  optionCores=" << optionCores << " optionMenue=" << optionMenue << endl;
cout << "  optionFlag=" << optionFlag << " optionCompute=" << optionCompute << endl;
cout << "  singleCore=" << singleCore << " computeMethod=" << computeMethod << endl;
cout << "  createHost=" << createHost << endl;
```

---

## 18. COMPLETE ARGUMENT SUMMARY TABLE

| Short | Long | Type | Required | Default | Passed To |
|-------|------|------|----------|---------|-----------|
| `-o` | -- | flag | No | false | (unused?) |
| `-c` | -- | int | No | 0 | librarian_functions, primeTileClass |
| `-m` | -- | string | No | "null" | librarian_functions (direct menu) |
| `-ip` | -- | string | No | "null" | librarian_functions, conduitClass |
| `-p` | -- | int | No | 0 | librarian_functions, conduitClass, globalNewHostPort |
| `-f` | -- | string | No | "null" | librarian_functions (compute flags) |
| `-x` | -- | string | No | "default" | librarian_functions (computeMethod) |
| `-w` | -- | string | No | "default" | main() → createHost/networkAssignment |

---

## 19. FUTURE ENHANCEMENT ROADMAP

### 19.1 Short Term
- [ ] Remove hardcoded `optionComputeInput = "Gear"` override
- [ ] Add `-h/--help` with formatted usage
- [ ] Add port range validation (1-65535)
- [ ] Add IP address format validation
- [ ] Add `--version` flag

### 19.2 Medium Term
- [ ] Long-form aliases (`--menu`, `--port`, `--host`, `--guest`)
- [ ] Configuration file support (`--config`)
- [ ] Environment variable fallbacks (`PRIMEONE_PORT`, etc.)
- [ ] JSON output mode (`--json`)

### 19.3 Long Term
- [ ] Subcommand structure (`primeone host`, `primeone guest`, `primeone update`)
- [ ] Shell completion (bash/zsh/fish)
- [ ] Man page generation
- [ ] Web-based configuration UI

---

*End of Feature Document 01: Command Line Interface & Argument Parsing*  
*Next: 02_INTERACTIVE_MENU_SYSTEM.md*