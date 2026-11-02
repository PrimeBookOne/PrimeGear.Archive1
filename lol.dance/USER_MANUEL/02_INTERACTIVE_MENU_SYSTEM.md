# PrimeOne - Feature Document 02: Interactive Menu System (Librarian)
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines 14225-14540, 14538-15200 (menu_librarian)  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Interactive Menu System (codenamed "Librarian") is the primary user interface for PrimeOne when launched without command-line menu directives (`-m`). It presents a rich ASCII-art dashboard displaying real-time system status, network configuration, and computation statistics, while providing hierarchical menu navigation for all major functions.

### Design Philosophy
- **Visual-first** - Full-screen ASCII dashboard with color-coded sections
- **Real-time** - Live updates of IP config, prime stats, network peers
- **Hierarchical** - Main menu → Sub-menu navigation with breadcrumb support
- **Keyboard-driven** - Single-keypress navigation with typed command fallback
- **Stateful** - Maintains context across menu levels

---

## 2. ARCHITECTURE

### 2.1 Entry Points

#### 2.1.1 Interactive Entry (Default)
```cpp
// In librarian_functions() line 14270-14272
if (menueChoice == 0) {
    if (noGui == false) { menu_librarian(); }
}
```
Called when `optionMenue == "null"` (no `-m` argument).

#### 2.1.2 Direct Menu Entry (Command Line)
```cpp
// In librarian_functions() line 14233
if (optionMenue != "null") {
    commandLineMode = true;
    userInput = optionMenue;
    noGui = true;
}
```
Bypasses display, executes single menu action immediately.

### 2.2 State Machine

```
┌─────────────────────────────────────────────────────────────┐
│                    MENU STATE MACHINE                        │
├─────────────────────────────────────────────────────────────┤
│                                                              │
│  menueChoice = 0          menueChoice = 1                   │
│  ┌─────────────────┐      ┌─────────────────┐               │
│  │   MAIN MENU     │      │   SUB MENU      │               │
│  │ (menueChoice=0) │      │ (menueChoice=1) │               │
│  └────────┬────────┘      └────────┬────────┘               │
│           │                        │                         │
│    Input: 0,1,l,a,r,u,s,     Input: 3,4,5,6,..,back         │
│           8,9,exit                   exit                     │
│           │                        │                         │
│           ▼                        ▼                         │
│  ┌─────────────────────────────────────────────────┐         │
│  │              TRANSITION LOGIC                    │         │
│  │  8/9 → menueChoice=1, reload=true, system("cls")│         │
│  │  ..  → menueChoice--, reload=true, system("cls")│         │
│  │  exit → questionDemonstrate=false, exit(0)      │         │
│  └─────────────────────────────────────────────────┘         │
│                                                              │
└─────────────────────────────────────────────────────────────┘
```

### 2.3 Core Loop (Lines 14245-14536)

```cpp
while (questionDemonstrate == true) {
    reload = false;
    if (menueChoice < 0) menueChoice = 0;

    if (menueChoice == 0) {
        if (noGui == false) { menu_librarian(); }
    }
    if (menueChoice == 1) { }
    if (menueChoice == 2) { }

    if (optionMenue == "null") {
        realm_os_user_input(userInput);
    }
    // ... menu option handling ...
    if (reload == true) { system("cls"); }
    else { cout << "INVALID ENTRY"; system("cls"); }
}
```

---

## 3. MENU_DASHBOARD RENDERING (menu_librarian)

### 3.1 Function Signature
```cpp
void menu_librarian()  // Lines 14538-15200 (~660 lines)
```

### 3.2 Visual Layout Structure

```
╔══════════════════════════════════════════════════════════════╗
║  XXX OPERATING SYSTEM XXX   NETWORK ADDRESSES XXX  PROCESSING  ║
║  UNITS XXX                                                                 ║
║                                                                  ║
║  127.0.0.1                              Build count: 3242        ║
║  [SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew           ║
║                                                                  ║
║  XXXXXX MENUE OPTIONS XXXXXX                                     ║
║  X                                                              ║
║  X  (0) PrimeBook Load & Go!               X  (l) Library     X ║
║  X  (1) PrimeBook Start A New              X  (a) Archive      X ║
║  XXXX PRIMEBOOK ONE STATUS XXXX  XXXX PARAMETERS XXXX  X (r) Rebind   X ║
║  X                                                               X ║
║  X  Prime Ratio =                     X (a) Archive      X     ║
║  X  Total Tiles =                     X (r) Rebind         X ║
║  X  Largest Difference = 228          X (u) Update         X ║
║  X  infiniteWalk =                    X (s) Singers        X ║
║  XXXXXXXXXXXXXXXXXXXXXXXXXXXX  X (c) PU=Yes          X     ║
║  X                              X (g) PU=No          X     ║
║  X  Total Primes =              X (p) primer         X     ║
║  X  TYPE COMMAND: : : : : : : : : X (t) thermal       X     ║
║  X  ||  |||||  |||  ||  ||      X (pause)            X     ║
║  X  |       | | | | |  |        X                    X ║
║  X  |       | | | | |  |        X (c) PU=Yes         X ║
║  X  |       | PRIMEBOOK ONE     X (g) PU=No          X ║
║  X  ||  |   | | | | |  |        X (t) thermal=No     X ║
║  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X                  X ║
║  X                            X GRID =          X     ║
║  X   Network Peers = 300      X                 X     ║
║  X   Active ip = 1            X Power =         X     ║
║  XXXXXXXXXXXXXXX  XXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXX     ║
║        X       X  XXXXXXXX  XXXXX  XXXXX  Port = 55555     ║
╚══════════════════════════════════════════════════════════════╝
```

### 3.3 Rendering Implementation (Lines 14540-14800)

The function uses **60+ individual `cout` statements** to build the dashboard line-by-line. Each line is constructed through character-by-character concatenation:

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

**Pattern:** Every character is a separate string literal concatenated with `<<`. This allows precise column alignment but makes the code extremely verbose.

### 3.4 Dynamic Content Injection

Key dashboard values injected at render time:

| Line | Content | Source |
|------|---------|--------|
| Build count | `3242` | Hardcoded literal |
| Service tag | `[SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew` | Hardcoded |
| Prime Ratio | (empty) | Variable not shown |
| Total Tiles | (empty) | Variable not shown |
| Largest Diff | `228` | Hardcoded |
| infiniteWalk | (empty) | Variable not shown |
| Total Primes | (empty) | Variable not shown |
| Network Peers | `300` | Hardcoded |
| Active IP | `1` | Hardcoded |
| Grid | (empty) | Variable not shown |
| Power | (empty) | Variable not shown |
| Port | `55555` | Hardcoded |

**Note:** Most dynamic values appear as empty strings in the rendered output. The actual runtime values are displayed via `realm_win_ipconfig()` called at the end of the function.

### 3.5 ANSI Cursor Positioning (Lines 14800-14820)

```cpp
cout << "\033[3;1H";  // Move cursor to row 3, column 1
// realm_win_port_check("555555");  // Commented out
cout << "\033[4;1H";  // Move cursor to row 4, column 1
realm_win_ipconfig(); // Display network interfaces
cout << "\033[4;1H";  // Move cursor to row 4, column 1
// realm_win_handles_sockets();  // Commented out
cout << "\033[4;1H";  // Move cursor to row 4, column 1
```

**ANSI Escape Codes Used:**
- `\033[3;1H` - Cursor to line 3, column 1 (overwrites dashboard lines)
- `\033[4;1H` - Cursor to line 4, column 1 (overwrites for ipconfig output)

This creates a **live-updating region** at the bottom of the dashboard where network info refreshes.

---

## 4. MAIN MENU OPTIONS (menueChoice == 0)

### 4.1 Option 0: PrimeBook Load & Go!
```cpp
// Line 14585-14586 in menu display:
cout << "X" << " " << "(" << "0" << ")" << " " << "P" << "r" << "i" 
     << "m" << "e" << "B" << "o" << "o" << "k" << " " << "L" 
     << "o" << "a" << "d" << " " << "&" << " " << "G" << "o" << "!" 
     << " " << " " << "X" << " " << " " << endl;
```
**Handler:** Not explicitly handled in switch - falls through to default Load & Go behavior in librarian_functions when menueChoice=0 and no input.

**Behavior:** Quick start with default settings. Loads existing prime book state and begins computation.

### 4.2 Option 1: PrimeBook Start A New
```cpp
// Line 14590-14591:
cout << "X" << " " << "(" << "1" << ")" << " " << "P" << "r" << "i" 
     << "m" << "e" << "B" << "o" << "o" << "k" << " " << "S" 
     << "t" << "a" << "r" << "t" << " " << "A" << " " << "N" 
     << "e" << "w" << " " << "X" << " " << " " << endl;
```
**Handler:** Not explicitly handled. Presumably initializes fresh prime tile grid.

### 4.3 Option l: PrimeBook One Library
```cpp
// Line 14595-14596:
cout << "X" << " " << " " << " " << "X" << " " << "(" << "l" << ")" 
     << " " << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" 
     << "k" << " " << "O" << "n" << "e" << " " << "L" << "i" << "b" 
     << "r" << "a" << "r" << "y" << " " << "X" << " " << " " << endl;
```
**Handler:** Not in main switch. Likely handled in deeper menu level (menueChoice=2?).

### 4.4 Option a: PrimeBook One Archive
```cpp
// Line 14600-14601:
cout << "X" << " " << "X" << " " << "(" << "a" << ")" << " " 
     << "P" << "r" << "i" << "m" << "e" << "B" << "o" << "o" << "k" 
     << " " << "O" << "n" << "e" << " " << "A" << "r" << "c" << "h" 
     << "i" << "v" << "e" << " " << "X" << " " << " " << endl;
```
**Handler:** Creates archive (ZIP) of current state. Related to `realm_win_archive()`.

### 4.5 Option r: PrimeBook One Rebind
```cpp
// Line 14605-14606:
cout << "X" << " " << "(" << "r" << ")" << " " << "P" << "r" << "i" 
     << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" 
     << "e" << " " << "R" << "e" << "b" << "i" << "n" << "d" << " " 
     << "X" << " " << " " << endl;
```
**Handler:** Rebind network configuration (port, IP, interface).

### 4.6 Option u: PrimeBook One Update
```cpp
// Line 14610-14611:
cout << "X" << " " << "(" << "u" << ")" << " " << "P" << "r" << "i" 
     << "m" << "e" << "B" << "o" << "o" << "k" << " " << "O" << "n" 
     << "e" << " " << "U" << "p" << "d" << "a" << "t" << "e" << " " 
     << " " << "X" << " " << " " << endl;
```
**Handler:** Triggers `realm_win_updater()` for self-update.

### 4.7 Option s: Singers (Thread Configuration)
```cpp
// Line 14615-14616:
cout << "X" << " " << "(" << "s" << ")" << "i" << "n" << "g" << "e" 
     << "r" << "s" << " " << "=" << " " << " " << " " << " " << " " 
     << " " << " " << " " << "X" << "" << endl;
```
**Handler:** Configure number of worker threads ("singers").

### 4.8 Option c/g: PU (Processing Unit) GPU Toggle
```cpp
// Line 14655-14656 (PU=Yes):
cout << "X" << " " << "(" << "c" << ")" << "P" << "U" << " " << "=" 
     << " " << "Y" << "e" << "s" << " " << " " << " " << " " << " " 
     << " " << " " << "X" << "" << endl;

// Line 14665-14666 (PU=No):
cout << "X" << " " << "(" << "g" << ")" << "P" << "U" << " " << "=" 
     << " " << "N" << "o" << " " << " " << " " << " " << " " << " " 
     << " " << "X" << "" << endl;
```
**Handler:** Toggle GPU/CUDA acceleration on/off.

### 4.9 Option p: Primer (Algorithm Selector)
```cpp
// Line 14625-14626:
cout << "X" << " " << "(" << "p" << ")" << "r" << "i" << "m" << "e" 
     << "r" << " " << "=" << " " << " " << " " << " " << " " << " " 
     << " " << " " << "X" << "" << endl;
```
**Handler:** Select prime algorithm variant.

### 4.10 Option t: Thermal Management
```cpp
// Line 14670-14671:
cout << "X" << " " << "(" << "t" << ")" << "h" << "e" << "r" << "m" 
     << "a" << "l" << " " << "=" << " " << "N" << "o" << " " << " " 
     << " " << " " << " " << " " << " " << "X" << " " << "" << endl;
```
**Handler:** Enable/disable thermal throttling.

### 4.11 Option 8: NETWORK HOST
```cpp
// Handler in librarian_functions line 14318-14326:
if (userInput == "8" && menueChoice == 0 && reload == false) {
    mrTsaysRead = true;
    menueChoice = 1;
    system("cls");
    conduitClass winTelConduits(5678);
    createHost = true;
    __int128 weaverBeginData = 0;
    globalRemotePortString = hostPort;
    winTelConduits.weaverBegin(uniqueIdGlobal, createHost, 
                               weaverBeginData, hostIp, hostPort);
    reload = true;
}
```
**Action:** Immediately starts host network mode, transitions to sub-menu (menueChoice=1).

### 4.12 Option 9: NETWORK GUEST
```cpp
// Handler in librarian_functions line 14304-14316:
if (userInput == "9" && menueChoice == 0 && reload == false) {
    mrTsaysRead = true;
    menueChoice = 1;
    system("cls");
    conduitClass winTelConduits(5678);
    createHost = false;
    __int128 weaverBeginData = 0;
    globalRemotePortString = hostPort;
    globalRemoteIpString = hostIp;
    winTelConduits.weaverBegin(uniqueIdGlobal, createHost, 
                               weaverBeginData, hostIp, hostPort);
    reload = true;
}
```
**Action:** Immediately starts guest network mode, transitions to sub-menu.

---

## 5. SUB-MENU OPTIONS (menueChoice == 1)

Accessed after selecting 8 (Host) or 9 (Guest) from main menu.

### 5.1 Option 3: Network Peers / IP Config
```cpp
// Handler line 14382-14384:
else if (userInput == "3" && menueChoice == 1 && reload == false) {
    realm_win_ipconfig();
    reload = true;
}
```
**Action:** Displays current network interfaces and IP addresses.

### 5.2 Option 4: Archive Create
```cpp
// Handler line 14393-14397:
else if (userInput == "4" && menueChoice == 1 && reload == false) {
    // realm_win_archive();
    reload = true;
}
```
**Action:** Creates PrimeOneUpdater.zip archive (currently commented out).

### 5.3 Option 5: Network Updater Send/Receive
```cpp
// Handler line 14408-14412:
else if (userInput == "5" && menueChoice == 1 && reload == false) {
    system("cls");
    // realm_win_updater(userInput);
    reload = true;
}
```
**Action:** Sends/receives update package over network (commented out).

### 5.4 Option 6: Roll Update (Install & Reload)
```cpp
// Handler line 14423-14425:
else if (userInput == "6" && menueChoice == 1 && reload == false) {
    realm_win_roll();
    reload = true;
}
```
**Action:** Installs downloaded update and restarts application.

### 5.5 Navigation: Back (.. or back)
```cpp
// Handler line 14430-14432:
else if (userInput == ".." || userInput == "back") {
    menueChoice--;
    reload = true;
}
```
**Action:** Returns to previous menu level (main menu).

---

## 6. SPECIAL HANDLERS

### 6.1 Exit Command
```cpp
// Line 14435-14438:
if (userInput == "exit") {
    questionDemonstrate = false;
    exit(0);
}
```
Immediate termination from any menu level.

### 6.2 Invalid Entry
```cpp
// Line 14443-14448:
else {
    cout << endl << " INVALID ENTRY " << endl << endl;
    system("cls");
}
```
Clears screen and redisplays current menu.

### 6.3 Reload Flag Pattern
Every valid menu action sets `reload = true`, triggering `system("cls")` at loop bottom to refresh display.

---

## 7. INPUT HANDLING (realm_os_user_input)

### 7.1 Function Declaration
```cpp
void realm_os_user_input(string& userInput);
```

### 7.2 Implementation (Not shown in excerpts)
Based on usage pattern, likely implements:
- Non-blocking key press detection (`_kbhit()` / `GetAsyncKeyState()`)
- Line-buffered input with Enter
- Arrow key navigation support
- ANSI escape sequence handling

### 7.3 Integration
```cpp
if (optionMenue == "null") {
    realm_os_user_input(userInput);
}
```
Only called in interactive mode. In command-line mode (`-m`), `userInput` is pre-set from `optionMenueInput`.

---

## 8. MENU STATE VARIABLES

| Variable | Type | Purpose |
|----------|------|---------|
| `menueChoice` | `int` | Current menu level (0=main, 1=sub, 2=deep) |
| `questionDemonstrate` | `bool` | Main loop continuation flag |
| `reload` | `bool` | Screen refresh trigger |
| `mrTsaysRead` | `bool` | Flag set when entering network modes |
| `commandLineMode` | `bool` | True when `-m` used |
| `noGui` | `bool` | True when bypassing menu display |
| `gitState` | `bool` | Git integration enabled |
| `singleCore` | `bool` | Single-thread mode |
| `createHost` | `bool` | Network role (host vs guest) |

---

## 9. COMMAND LINE INTEGRATION

### 9.1 Direct Menu Execution
When `-m <option>` provided:
1. `optionMenueInput` set in `main()`
2. Passed to `librarian_functions()` as `optionMenue`
3. `commandLineMode = true`, `noGui = true`
4. `userInput = optionMenue` (bypasses `realm_os_user_input`)
5. Single iteration of loop executes matching handler
6. `reload = true` → `system("cls")` → loop continues or exits

### 9.2 Menu Option Mapping Table

| `-m` Value | Menu Level | Action |
|------------|------------|--------|
| `0` | Main | Load & Go |
| `1` | Main | Start New |
| `l` | Main | Library |
| `a` | Main | Archive |
| `r` | Main | Rebind |
| `u` | Main | Update |
| `s` | Main | Singers |
| `c` | Main | PU=Yes (GPU on) |
| `g` | Main | PU=No (GPU off) |
| `p` | Main | Primer |
| `t` | Main | Thermal |
| `8` | Main→Sub | Network Host |
| `9` | Main→Sub | Network Guest |
| `3` | Sub | IP Config |
| `4` | Sub | Archive Create |
| `5` | Sub | Network Updater |
| `6` | Sub | Roll Update |
| `..`/`back` | Sub→Main | Navigate back |

---

## 10. ANSI ESCAPE SEQUENCES USED

| Sequence | Purpose | Location |
|----------|---------|----------|
| `\033[3;1H` | Cursor to row 3, col 1 | menu_librarian |
| `\033[4;1H` | Cursor to row 4, col 1 | menu_librarian (x3) |
| `system("cls")` | Clear screen (Windows) | librarian_functions loop |

**Note:** `system("cls")` is Windows-specific. On Linux/Wine, this calls `cmd /c cls` which may not work properly. Should use ANSI `\033[2J\033[H` for cross-platform.

---

## 11. LEGACY MENU ELEMENTS (Partial/Commented)

### 11.1 Commented Port Check (Line 14805)
```cpp
/*
if (realm_win_port_check("555555")) {
    cout << "Port 555555 is in use. . ." << endl;
} else {
    cout << "Port is available. . ." << endl;
}
*/
```
Port 555555 (5 digits) - likely typo for 55555.

### 11.2 Commented GPU Query (Line 14808)
```cpp
// realm_gl_querry();
```
Would query OpenGL/CUDA device info.

### 11.3 Commented Socket Handles (Line 14811)
```cpp
// realm_win_handles_sockets();
```
Would display open socket handles.

### 11.4 Commented Full Windows Handles (Line 14813)
```cpp
// realm_os_windows();
```
Would enumerate all Windows handles (process, thread, file, socket, event, mutex).

### 11.5 Countdown Timer (Lines 12072-12100 in main)
```cpp
/* Auto-execute default after countdown unless interrupted */
```
Would auto-select "Load & Go" after 10-second countdown.

---

## 12. USER INTERACTION FLOWS

### 12.1 Flow: Interactive Start → Host
```
1. PrimeOne.exe (no args)
2. menu_librarian() displays dashboard
3. User presses '8'
4. librarian_functions: menueChoice=1, system("cls")
5. conduitClass(5678).weaverBegin(createHost=true)
6. Sub-menu displays (options 3,4,5,6,back)
7. Host runs indefinitely until 'exit'
```

### 12.2 Flow: Interactive Start → Guest
```
1. PrimeOne.exe (no args)
2. menu_librarian() displays dashboard
3. User presses '9'
4. Prompts for host IP? (uses hostIp from args or default)
5. librarian_functions: menueChoice=1, system("cls")
6. conduitClass(5678).weaverBegin(createHost=false)
7. Sub-menu displays
8. Guest runs until 'exit' or host disconnects
```

### 12.3 Flow: Command Line Direct Host
```
1. PrimeOne.exe -m 8 -p 54767 -ip 192.168.1.100
2. main() parses args
3. librarian_functions(optionMenue="8", ...)
4. commandLineMode=true, noGui=true
5. userInput="8", menueChoice=0
6. Handler for "8" executes immediately
7. weaverBegin(createHost=true) starts host
8. Loop continues (questionDemonstrate still true)
```

---

## 13. DASHBOARD REAL-TIME UPDATES

### 13.1 Live Region (Lines 4-6 of console)
The ANSI positioning `\033[4;1H` repeatedly overwrites lines 4-6 with:
1. `realm_win_ipconfig()` output (network interfaces)
2. Commented: port check, GPU query, socket handles

### 13.2 Update Frequency
- Only updates when `menu_librarian()` called
- Called at top of loop when `menueChoice == 0` and `noGui == false`
- In network modes (`menueChoice == 1`), `menu_librarian()` NOT called
- Live updates stop when in network sub-menu

### 13.3 Missing Dynamic Data
Most dashboard fields show empty values:
- Prime Ratio, Total Tiles, infiniteWalk, Total Primes, Grid, Power
- These should be populated from `primeTileClass` static/global state
- Current implementation appears to be placeholder/template

---

## 14. INTEGRATION WITH BATCH FILES

### 14.1 Host Batch File
```batch
primeone.exe -m 8 -p 54767
```
Bypasses interactive menu entirely. Direct to network host.

### 14.2 Guest Batch File
```batch
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```
Direct to network guest. `start "" cmd /c` launches in new window.

### 14.3 Implication
**Batch files never use interactive menu.** They use `-m` for direct execution. The interactive menu is for manual operation only.

---

## 15. EXTENSIBILITY & CUSTOMIZATION

### 15.1 Adding New Main Menu Option
1. Add display line in `menu_librarian()` (character-by-character)
2. Add handler in `librarian_functions()` main switch (menueChoice==0)
3. Set `reload = true` for screen refresh
4. Optionally add to sub-menu if needed

### 15.2 Adding New Sub-Menu Option
1. Ensure `menueChoice == 1` context
2. Add handler in `librarian_functions()` sub-menu section
3. Add navigation hint in dashboard display

### 15.3 Dynamic Dashboard Values
To populate empty fields:
```cpp
// In menu_librarian(), before rendering:
extern __int128 globalPrimeRatio;
extern __int128 globalTotalTiles;
extern __int128 globalInfiniteWalk;
extern __int128 globalTotalPrimes;

// In rendering, replace empty strings:
cout << "Prime Ratio = " << globalPrimeRatio << " ";
// Instead of:
cout << "Prime Ratio = " << " " << " " << " " << " " << " ";
```

### 15.4 Cross-Platform Clear Screen
Replace `system("cls")` with:
```cpp
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[H"; // ANSI clear + home
#endif
```

---

## 16. KNOWN ISSUES & LIMITATIONS

### 16.1 Hardcoded Dashboard Values
- Build count: 3242 (hardcoded)
- Service tag: hardcoded date
- Largest Difference: 228 (hardcoded)
- Network Peers: 300 (hardcoded)
- Active IP: 1 (hardcoded)
- Port: 55555 (hardcoded, differs from default 5678/54767)

### 16.2 No Mouse Support
Pure keyboard interface. No clickable elements.

### 16.3 No Scrollback/History
`system("cls")` clears entire history. Previous outputs lost.

### 16.4 Windows-Only Clear Screen
`system("cls")` fails on Linux/Wine without cmd.exe.

### 16.5 ANSI Code Compatibility
`\033[` codes work on:
- Windows 10+ (VT100 enabled by default)
- Linux/macOS terminals
- Wine console (with proper TERM)

May not work on older Windows cmd.exe without `SetConsoleMode(ENABLE_VIRTUAL_TERMINAL_PROCESSING)`.

### 16.6 No Input Validation
- Any input not matching handlers → "INVALID ENTRY"
- No fuzzy matching or suggestions
- Case-sensitive (lowercase only in handlers)

### 16.7 Single-Threaded UI
Menu loop blocks on `realm_os_user_input()`. Network operations run in separate threads via `std::async` in conduitClass.

---

## 17. DEBUGGING & DIAGNOSTICS

### 17.1 Enable Menu Tracing
Add at top of `librarian_functions` loop:
```cpp
cout << "[MENU] menueChoice=" << menueChoice 
     << " userInput='" << userInput << "'" 
     << " reload=" << reload << endl;
```

### 17.2 Trace menu_librarian Calls
```cpp
void menu_librarian() {
    static int callCount = 0;
    cout << "[MENU_DRAW] Call #" << ++callCount << endl;
    // ... rest of function
}
```

### 17.3 Monitor ANSI Output
On Linux/Wine, capture raw output:
```bash
script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null | cat -A
```
Shows ANSI escape codes as `^[[3;1H` etc.

---

## 18. COMPLETE MENU MAP

```
MAIN MENU (menueChoice=0)
├── 0: Load & Go! (default action)
├── 1: Start New
├── l: Library
├── a: Archive
├── r: Rebind
├── u: Update
├── s: Singers (threads)
├── c: PU=Yes (GPU on)
├── g: PU=No (GPU off)
├── p: Primer (algorithm)
├── t: Thermal (throttle)
├── 8: NETWORK HOST → SUB MENU
├── 9: NETWORK GUEST → SUB MENU
└── exit: Quit

SUB MENU (menueChoice=1, after 8 or 9)
├── 3: Network Peers / IP Config
├── 4: Archive Create (PrimeOneUpdater.zip)
├── 5: Network Updater Send/Receive
├── 6: Roll Update (Install & Reload)
├── .. / back: Return to Main Menu
└── exit: Quit
```

---

## 19. FUTURE ENHANCEMENT ROADMAP

### 19.1 Visual Improvements
- [ ] Dynamic dashboard values from actual computation state
- [ ] Color support (ANSI 256-color or truecolor)
- [ ] Progress bars for prime generation
- [ ] Real-time prime rate graph (sparkline)

### 19.2 Interaction Improvements
- [ ] Arrow key navigation
- [ ] Mouse click support (Windows Console API)
- [ ] Command history (up/down arrows)
- [ ] Tab completion for typed commands
- [ ] Searchable command palette (Ctrl+P)

### 19.3 Architecture Improvements
- [ ] Separate UI thread from computation
- [ ] WebSocket dashboard for remote monitoring
- [ ] Configuration file for dashboard layout
- [ ] Plugin system for custom menu items
- [ ] Localization/internationalization

### 19.4 Cross-Platform
- [ ] Replace `system("cls")` with ANSI clear
- [ ] Abstract `realm_os_user_input` for termios/readline
- [ ] NCurses-based UI option
- [ ] Web-based UI (HTTP + WebSocket)

---

*End of Feature Document 02: Interactive Menu System (Librarian)*  
*Next: 03_PRIME_TILE_COMPUTATION_ENGINE.md*