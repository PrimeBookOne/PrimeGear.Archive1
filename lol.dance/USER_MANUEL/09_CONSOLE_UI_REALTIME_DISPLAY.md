# PrimeOne - Feature Document 09: Console UI & Real-time Display
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines 14538-15200 (menu_librarian), 11978-12000 (console positioning), ANSI codes throughout  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Console UI system provides a **rich text-based dashboard** for PrimeOne using ANSI escape sequences and Windows Console API. It displays real-time system statistics, network status, computation progress, and provides hierarchical menu navigation - all within a standard Windows console window.

### Design Philosophy
- **ASCII art aesthetic** - Character-by-character rendering for precise layout
- **Real-time updates** - ANSI cursor positioning for live data regions
- **Keyboard-driven** - Single-key navigation with typed command fallback
- **Information dense** - Maximum data in 80x25+ console

---

## 2. RENDERING ARCHITECTURE

### 2.1 Character-by-Character Construction
The `menu_librarian()` function builds the dashboard using **60+ individual `cout` statements**, each concatenating string literals character-by-character:

```cpp
cout << " " << " " << " " << " " << " " << "X" << "X" << "X" 
     << " " << "O" << "P" << "E" << "R" << "A" << "T" << "I" 
     << "N" << "G" << " " << "S" << "Y" << "S" << "T" << "E" << "M" 
     << " " << "X" << "X" << "X" << " " << " " << " " << " " << " " 
     << " " << " " << "X" << "X" << "X" << " " << "N" << "E" << "T" 
     << "W" << "O" << "R" << "K" << " " << " " << "A" << "D" << "D" 
     << "R" << "E" << "S" << "S" << "E" << "S" << " " << "X" << "X" 
     << "X" << " " << " " << " " << " " << " " << "X" << "X" << "X" 
     << " " << "P" << "R" << "O" << "C" << "E" << "S" << "S" << "I" 
     << "N" << "G" << " " << "U" << "N" << "I" << "T" << "S" << "X" 
     << "X" << "X" << " " << "" << "" << "" << "" << "" << "" << "" 
     << "" << "" << "" << "" << "" << "" << "" << endl;
```

**Pattern:** Every visible character is a separate `<< "X"` or `<< " "` token. This allows pixel-perfect positioning but creates extremely verbose code.

### 2.2 Dashboard Layout Map
```
Row 1:  XXX OPERATING SYSTEM XXX   NETWORK ADDRESSES XXX  PROCESSING UNITS XXX
Row 2:  (empty spacer)
Row 3:  127.0.0.1                              Build count: 3242
Row 4:  [SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew
Row 5:  (empty)
Row 6:  XXXXXX MENUE OPTIONS XXXXXX
Row 7:  X
Row 8:  X  (0) PrimeBook Load & Go!               X  (l) Library     X
Row 9:  X  (1) PrimeBook Start A New              X  (a) Archive      X
Row 10: XXXX PRIMEBOOK ONE STATUS XXXX  XXXX PARAMETERS XXXX  X (r) Rebind   X
Row 11: X                                                               X
Row 12: X  Prime Ratio =                     X (a) Archive      X
Row 13: X  Total Tiles =                     X (r) Rebind         X
Row 14: X  Largest Difference = 228          X (u) Update         X
Row 15: X  infiniteWalk =                    X (s) Singers        X
Row 16: XXXXXXXXXXXXXXXXXXXXXXXXXXXX  X (c) PU=Yes          X
Row 17: X                              X (g) PU=No          X
Row 18: X  Total Primes =              X (p) primer         X
Row 19: X  TYPE COMMAND: : : : : : : : : X (t) thermal       X
Row 20: X  ||  |||||  |||  ||  ||      X (pause)            X
Row 21: X  |       | | | | |  |        X                    X
Row 22: X  |       | | | | |  |        X (c) PU=Yes         X
Row 23: X  |       | PRIMEBOOK ONE     X (g) PU=No          X
Row 24: X  ||  |   | | | | |  |        X (t) thermal=No     X
Row 25: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X                  X
Row 26: X                            X GRID =          X
Row 27: X   Network Peers = 300      X                 X
Row 28: X   Active ip = 1            X Power =         X
Row 29: XXXXXXXXXXXXXXX  XXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXX
Row 30:       X       X  XXXXXXXX  XXXXX  XXXXX  Port = 55555
```

---

## 3. ANSI ESCAPE SEQUENCES

### 3.1 Cursor Positioning (menu_librarian lines 14800-14820)
```cpp
cout << "\033[3;1H";  // Move cursor to row 3, column 1
// realm_win_port_check("555555");  // Commented
cout << "\033[4;1H";  // Move cursor to row 4, column 1
realm_win_ipconfig(); // Display network interfaces
cout << "\033[4;1H";  // Move cursor to row 4, column 1
// realm_win_handles_sockets();  // Commented
cout << "\033[4;1H";  // Move cursor to row 4, column 1
```

### 3.2 ANSI Code Reference
| Code | Sequence | Purpose |
|------|----------|---------|
| Cursor Position | `\033[{row};{col}H` | Move cursor to absolute position |
| Cursor Up | `\033[{n}A` | Move up n lines |
| Cursor Down | `\033[{n}B` | Move down n lines |
| Cursor Forward | `\033[{n}C` | Move right n columns |
| Cursor Back | `\033[{n}D` | Move left n columns |
| Clear Screen | `\033[2J` | Clear entire screen |
| Clear Line | `\033[K` | Clear from cursor to end of line |
| Save Cursor | `\033[s` | Save current position |
| Restore Cursor | `\033[u` | Restore saved position |
| Hide Cursor | `\033[?25l` | Hide cursor (observed in output) |
| Show Cursor | `\033[?25h` | Show cursor |
| Set Title | `\033]0;{title}\007` | Set window title (observed) |

### 3.3 Observed Output Codes
From Wine test run:
```
]0;PrimeBookGear     // OSC 0 - Set window title
[?25l                // Hide cursor
[K                   // Clear line (repeated many times)
```

---

## 4. WINDOWS CONSOLE API INTEGRATION

### 4.1 Console Window Positioning (main() lines 11978-12000)
```cpp
HWND consoleWindow = GetConsoleWindow();
if (consoleWindow == nullptr) {
    std::cerr << "Failed to get console window handle.\n";
    return 1;
}

RECT desktopRect;
HWND hDesktop = GetDesktopWindow();
GetWindowRect(hDesktop, &desktopRect);

int screenWidth = desktopRect.right;
int screenHeight = desktopRect.bottom;

int x = 0, y = 0;
int width = screenWidth / 3;
int height = screenHeight / 2;

if (optionMenueInput == "8") {  // Host mode
    x = width * 2; y = height;
} else {
    width = width / 2; 
    height = static_cast<int>(height * 0.75);
}

SetWindowPos(consoleWindow, HWND_TOP, x, y, width, height, SWP_SHOWWINDOW);
SetConsoleTitle("PrimeBookGear");
```

### 4.2 Window Positioning Logic
| Mode | X | Y | Width | Height |
|------|---|---|-------|--------|
| Host (`-m 8`) | 2/3 screen | 1/2 screen | 1/3 screen | 1/2 screen |
| Guest/Other | 0 | 0 | 1/6 screen | 3/8 screen |

### 4.3 Console Title
```cpp
SetConsoleTitle("PrimeBookGear");  // Windows API
// Also observed via ANSI: \033]0;PrimeBookGear\007
```

---

## 5. REAL-TIME UPDATE REGIONS

### 5.1 Live Network Display (Rows 3-6)
The ANSI positioning creates a **live update region** at rows 3-6:

```cpp
// Row 3: Static IP (overwritten by ipconfig)
cout << "\033[3;1H";

// Row 4: Live ipconfig output (repeatedly overwritten)
cout << "\033[4;1H";
realm_win_ipconfig();  // Outputs multiple lines
cout << "\033[4;1H";   // Reset for next update

// Row 4 again: Socket handles (commented)
// realm_win_handles_sockets();
cout << "\033[4;1H";
```

### 5.2 Update Frequency
- **Only updates** when `menu_librarian()` called
- Called at top of main loop when `menueChoice == 0 && noGui == false`
- **Stops updating** when in sub-menu (`menueChoice == 1`) or network mode
- **No automatic timer** - updates on menu redraw only

---

## 6. INPUT HANDLING

### 6.1 realm_os_user_input() (Not fully visible)
```cpp
void realm_os_user_input(string& userInput);
```

**Inferred Implementation:**
```cpp
void realm_os_user_input(string& userInput) {
    // Option 1: Line buffered (Enter required)
    std::getline(std::cin, userInput);
    
    // Option 2: Single key (non-blocking)
    // if (_kbhit()) { userInput = _getch(); }
    
    // Option 3: Windows Console API
    // INPUT_RECORD ir[128]; DWORD count;
    // ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ir, 128, &count);
}
```

### 6.2 Input Processing (librarian_functions)
```cpp
if (optionMenue == "null") {
    realm_os_user_input(userInput);  // Interactive only
}

// Single-character commands processed:
if (userInput == "8") { /* Host */ }
else if (userInput == "9") { /* Guest */ }
else if (userInput == "3") { /* IP Config */ }
else if (userInput == ".." || userInput == "back") { /* Back */ }
else if (userInput == "exit") { exit(0); }
else { /* INVALID ENTRY */ }
```

### 6.3 Navigation Keys
| Key | Action |
|-----|--------|
| `0-9` | Menu options |
| `l,a,r,u,s,g,c,p,t` | Parameter toggles |
| `8,9` | Network Host/Guest |
| `..` or `back` | Navigate up |
| `exit` | Quit application |

---

## 7. SCREEN CLEARING

### 7.1 Current Method
```cpp
// Used throughout librarian_functions loop
system("cls");  // Windows: calls cmd /c cls
```

### 7.2 Cross-Platform Alternative
```cpp
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[H";  // ANSI clear + home
#endif
}
```

### 7.3 Issues with `system("cls")`
- **Slow** - Spawns cmd.exe process
- **Flicker** - Full screen clear/redraw
- **Linux/Wine** - Requires cmd.exe in PATH
- **Not atomic** - Visible flash between clear and redraw

---

## 8. DASHBOARD DATA SOURCES

### 8.1 Static/Hardcoded Values (Current)
| Field | Value | Source |
|-------|-------|--------|
| Build count | `3242` | Hardcoded literal |
| Service tag | `[SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew` | Hardcoded |
| Largest Difference | `228` | Hardcoded |
| Network Peers | `300` | Hardcoded |
| Active IP | `1` | Hardcoded |
| Port | `55555` | Hardcoded |

### 8.2 Dynamic Values (Should Be)
| Field | Source | Status |
|-------|--------|--------|
| Prime Ratio | `primeTileClass` computation | **Empty** |
| Total Tiles | `grid` variable | **Empty** |
| infiniteWalk | `infiniteWalk` counter | **Empty** |
| Total Primes | `total` counter | **Empty** |
| Grid | `grid` dimension | **Empty** |
| Power | `powerOf` parameter | **Empty** |

### 8.3 Live Data (Working)
| Field | Source | Update Method |
|-------|--------|---------------|
| Network Interfaces | `realm_win_ipconfig()` | ANSI overwrite rows 3-6 |
| Port Check | `realm_win_port_check()` | Commented |

---

## 9. MENU HIERARCHY RENDERING

### 9.1 Main Menu (menueChoice = 0)
Full dashboard with all options visible.

### 9.2 Sub Menu (menueChoice = 1)
```cpp
// menu_librarian() NOT called when menueChoice == 1
// Only handler logic runs:
// Options 3,4,5,6,..,back,exit
```

### 9.3 Deep Menu (menueChoice = 2)
```cpp
// Placeholder - no handlers visible
if (menueChoice == 2) { }
```

---

## 10. COLOR SUPPORT (Not Currently Used)

### 10.1 ANSI Color Codes Available
```cpp
// Foreground
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"

// Background
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
// ...

// Bright variants
#define BRIGHT_RED "\033[91m"
// ...

// Styles
#define BOLD      "\033[1m"
#define DIM       "\033[2m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"
```

### 10.2 Windows 10+ VT100 Enable
```cpp
// Required for ANSI colors on Windows
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;
GetConsoleMode(hOut, &dwMode);
dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
SetConsoleMode(hOut, dwMode);
```

---

## 11. INTEGRATION WITH PRIME TILE ENGINE

### 11.1 Data Flow
```
primeTileClass (computation)
    │
    ├── infiniteWalk ──────► Dashboard "infiniteWalk = "
    ├── totalPrimes ──────► Dashboard "Total Primes = "
    ├── grid ─────────────► Dashboard "Grid = "
    ├── powerOf ──────────► Dashboard "Power = "
    ├── primeRatio ───────► Dashboard "Prime Ratio = "
    ├── totalTiles ───────► Dashboard "Total Tiles = "
    └── largestDiff ──────► Dashboard "Largest Difference = "

conduitClass (network)
    │
    ├── connectedGuests ──► Dashboard "Network Peers = "
    ├── activeIPs ────────► Dashboard "Active ip = "
    └── listenPort ───────► Dashboard "Port = "
```

### 11.2 Required Exports (Global/Static)
```cpp
// In primeTileClass or global namespace:
extern __int128 g_infiniteWalk;
extern __int128 g_totalPrimes;
extern __int128 g_grid;
extern __int128 g_powerOf;
extern double g_primeRatio;
extern __int128 g_totalTiles;
extern __int128 g_largestDiff;

// In conduitClass:
extern int g_connectedGuests;
extern int g_activeIPs;
extern int g_listenPort;
```

---

## 12. CROSS-PLATFORM CONSIDERATIONS

### 11.1 Windows
- **Native**: `system("cls")`, `SetConsoleTitle`, `GetConsoleWindow`, `SetWindowPos`
- **ANSI**: Works on Windows 10+ with `ENABLE_VIRTUAL_TERMINAL_PROCESSING`

### 11.2 Linux/macOS
- **Clear**: `cout << "\033[2J\033[H";`
- **Title**: `cout << "\033]0;PrimeBookGear\007";`
- **Positioning**: ANSI only (no `SetWindowPos`)
- **Input**: `termios` for raw mode, or `ncurses`

### 11.3 Wine
- **ANSI**: Works
- **Win32 API**: Partial (`GetConsoleWindow` fails for GUI subsystem)
- **Window positioning**: Fails silently

---

## 13. KNOWN ISSUES & LIMITATIONS

### 13.1 Rendering Issues
1. **No dynamic data** - Most dashboard fields empty
2. **Flicker** - `system("cls")` causes visible flash
3. **No double buffering** - Direct write to console
4. **Fixed layout** - Doesn't adapt to console size
5. **Character-by-character** - 60+ cout statements per frame

### 13.2 Input Issues
1. **Line-buffered** - Requires Enter key
2. **No arrow keys** - Single char only
3. **No history** - Can't recall previous commands
4. **Case sensitive** - Lowercase only in handlers

### 13.3 Platform Issues
1. **GUI subsystem** - `GetConsoleWindow()` returns NULL
2. **Wine** - Requires `script` for pseudo-terminal
3. **Linux** - `system("cls")` fails without cmd.exe
4. **Resize** - No `SIGWINCH` / `WM_SIZE` handling

---

## 14. REFACTORING ROADMAP

### 14.1 Phase 1: Dynamic Data (Critical)
- [ ] Export primeTileClass state to globals
- [ ] Export conduitClass state to globals
- [ ] Replace hardcoded dashboard values with live data
- [ ] Format `__int128` for display (custom formatter)

### 14.2 Phase 2: Rendering Engine (High)
- [ ] Create `DashboardRenderer` class
- [ ] Implement double-buffered rendering
- [ ] Use `std::stringstream` for line composition
- [ ] Add layout engine (rows/cols/anchors)

### 14.3 Phase 3: Input System (High)
- [ ] Raw input mode (`_kbhit`/`_getch` or `ReadConsoleInput`)
- [ ] Arrow key navigation
- [ ] Command history (up/down)
- [ ] Tab completion

### 14.4 Phase 4: Visual Enhancement (Medium)
- [ ] Enable ANSI colors (enable VT100)
- [ ] Color-code sections (green=OK, red=error, yellow=warn)
- [ ] Progress bars for computation
- [ ] Sparkline graphs for prime rate

### 14.5 Phase 5: Cross-Platform (Medium)
- [ ] Abstract console API (`IConsole` interface)
- [ ] Implement `WindowsConsole`, `AnsiConsole`, `NcursesConsole`
- [ ] Auto-detect best backend
- [ ] Resize handling

### 14.6 Phase 5: Advanced UI (Low)
- [ ] Split panes (computation | network | log)
- [ ] Mouse support (Windows Console API)
- [ ] Plugin system for custom panels
- [ ] WebSocket dashboard export

---

## 15. TESTING SPECIFICATIONS

### 15.1 Visual Regression Tests
```cpp
// Capture dashboard output, compare to baseline
string captureDashboard() {
    stringstream ss;
    // Redirect cout to stringstream
    menu_librarian();
    return ss.str();
}

// Test: All sections present
assert(captureDashboard().find("OPERATING SYSTEM") != npos);
assert(captureDashboard().find("NETWORK ADDRESSES") != npos);
assert(captureDashboard().find("MENUE OPTIONS") != npos);
```

### 15.2 Input Tests
```cpp
// Simulate key presses
TEST(MenuNavigation, HostMode) {
    userInput = "8";
    librarian_functions(...);
    ASSERT_TRUE(createHost);
    ASSERT_EQ(menueChoice, 1);
}

TEST(MenuNavigation, BackNavigation) {
    menueChoice = 1;
    userInput = "back";
    // Process loop iteration
    ASSERT_EQ(menueChoice, 0);
}
```

### 15.3 ANSI Output Tests
```cpp
// Verify ANSI sequences emitted
TEST(AnsiOutput, CursorPositioning) {
    string output = captureAnsiOutput();
    EXPECT_THAT(output, HasSubstr("\033[3;1H"));
    EXPECT_THAT(output, HasSubstr("\033[4;1H"));
}
```

---

## 16. COMPLETE COMMAND REFERENCE

### 16.1 Interactive Commands
```
Main Menu:
  0  - PrimeBook Load & Go!
  1  - PrimeBook Start A New
  l  - PrimeBook One Library
  a  - PrimeBook One Archive
  r  - PrimeBook One Rebind
  u  - PrimeBook One Update
  s  - Singers (threads)
  c  - PU = Yes (GPU on)
  g  - PU = No (GPU off)
  p  - Primer (algorithm)
  t  - Thermal (throttle)
  8  - Network Host → Sub-menu
  9  - Network Guest → Sub-menu
  exit - Quit

Sub-Menu (after 8/9):
  3  - Network Peers / IP Config
  4  - Archive Create
  5  - Network Updater
  6  - Roll Update
  .. / back - Return to Main
  exit - Quit
```

### 16.2 Command Line Equivalents
```cmd
PrimeOne.exe -m 0  # Load & Go
PrimeOne.exe -m 1  # Start New
PrimeOne.exe -m l  # Library
PrimeOne.exe -m 8  # Host
PrimeOne.exe -m 9  # Guest
PrimeOne.exe -m u  # Update
# etc.
```

---

## 17. CROSS-REFERENCE: SOURCE LOCATIONS

| Component | File | Lines |
|-----------|------|-------|
| `menu_librarian()` | main.cpp | 14538-15200 |
| Console positioning | main.cpp | 11978-12000 |
| ANSI positioning | main.cpp | 14800-14820 |
| Input handling | main.cpp | 14277, 14233 |
| Menu handlers | main.cpp | 14304-14448 |
| Dashboard static text | main.cpp | 14540-14800 |

---

## 18. FUTURE ENHANCEMENTS

### 18.1 Dashboard 2.0
- Real-time prime rate graph (sparkline)
- Network topology map
- GPU utilization bars
- Memory usage gauge
- Thread activity timeline

### 18.2 Interaction 2.0
- Vim-style keybindings
- Command palette (Ctrl+P)
- Fuzzy search menu
- Context-sensitive help

### 18.3 Remote Access
- WebSocket dashboard
- SSH/Telnet interface
- REST API for metrics
- Prometheus exporter

---

*End of Feature Document 09: Console UI & Real-time Display*  
*Next: 10_DATA_PERSISTENCE_BOOK_ARCHIVE.md*