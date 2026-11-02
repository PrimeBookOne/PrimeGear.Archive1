# PrimeOne / PrimeBookOne - Master Direction Document - by Jason Brodsky
## The Prime Number Computation Engine & Distributed Network System

**Version:** 1.0  
**Build:** 3242 (as of SERVICE_primeOne_2025_7_18.xlsm)  
**Platform:** Windows (x64) / Linux via Wine  
**Language:** C++17 (MSVC/MinGW compatible)  
**Author:** Extrapolated from source code analysis

---

## 1. EXECUTIVE SUMMARY

PrimeOne (also known as PrimeBookOne) is a sophisticated **prime number computation engine** with **distributed network capabilities**, **GPU acceleration**, and **real-time visualization**. It implements a novel tile-based algorithm for prime number generation and verification, capable of distributed computation across multiple networked nodes (host/guest architecture).

### Core Identity
- **Primary Purpose:** Prime number discovery, verification, and distributed computation
- **Architecture:** Tile-based prime walk algorithms with infinite precision arithmetic (__int128)
- **Network Model:** Host/Guest conduit system with TCP socket communication
- **Compute Backends:** CPU (multi-threaded), GPU (CUDA), Hybrid
- **Interface:** Console-based ASCII UI with real-time status display

### Key Innovations
1. **Tile-Based Prime Algorithm** - Primes computed as "tiles" in a 2D grid space
2. **Infinite Walk** - Continuous prime generation without theoretical upper bound
3. **Distributed Consensus** - Host coordinates multiple guests for parallel computation
4. **State Persistence** - Book/Archive system for saving/restoring computation state
5. **Real-time Visualization** - ASCII dashboard showing prime statistics live

---

## 2. SYSTEM ARCHITECTURE OVERVIEW

```
┌─────────────────────────────────────────────────────────────────┐
│                      PRIMEONE APPLICATION                        │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌──────────────┐    ┌──────────────┐    ┌──────────────────┐  │
│  │   CONSOLE    │    │  MENU SYSTEM │    │  COMMAND LINE    │  │
│  │   INTERFACE  │◄──►│  (Librarian) │◄──►│  ARGUMENT PARSER │  │
│  └──────────────┘    └──────────────┘    └──────────────────┘  │
│         │                   │                    │               │
│         ▼                   ▼                    ▼               │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                  LIBRARIAN FUNCTIONS                      │  │
│  │  (Central Coordinator - Menu Navigation & Mode Selection) │  │
│  └──────────────────────────────────────────────────────────┘   │
│         │                   │                    │               │
│         ▼                   ▼                    ▼               │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────────────┐  │
│  │ PRIME TILE   │  │  CONDUIT     │  │   SYSTEM             │  │
│  │ ENGINE       │  │  NETWORK     │  │   UTILITIES          │  │
│  │ (primeTileClass)│ │ (conduitClass)│ │ (Win32, IPConfig,   │  │
│  └──────────────┘  └──────────────┘  │  WMI, Update, Roll)  │  │
│         │                   │         └──────────────────────┘  │
│         ▼                   ▼                                    │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │              EXTERNAL DEPENDENCIES                          │   │
│  │  curl │ libssh │ libminiupnpc │ CUDA │ DirectX 9 │ Win32  │   │
│  └──────────────────────────────────────────────────────────┘   │
│                                                                  │
└─────────────────────────────────────────────────────────────────┘
```

---

## 3. CORE COMPONENTS

### 3.1 primeTileClass - The Computation Engine
**File:** `main.cpp` (lines ~1900-8500)  
**Purpose:** Core prime number generation and verification using tile-based algorithms

**Key Algorithms:**
- `nextWalkPrime()` - Forward prime walk
- `moonWalkPrime()` - Reverse prime walk  
- `etchTile()` / `etchFeast()` - Tile data inscription
- `verifyPrime()` - Primality testing
- `librarianDancer()` - Multi-threaded distributed computation
- `ptv_primeBookAuthor()` - Prime book serialization

**Data Types:**
- `__int128` - 128-bit integers for massive prime handling
- `std::byte` - Raw byte manipulation for tile data
- `std::vector<std::byte>` - Dynamic tile buffers

### 3.2 conduitClass - The Network Layer
**File:** `main.cpp` (lines ~8918-11800)  
**Purpose:** Host/Guest TCP socket communication for distributed computation

**Modes:**
- **Host (`createHost=true`)** - Listens on port, coordinates guests, distributes work
- **Guest (`createHost=false`)** - Connects to host, requests work, returns results

**Key Methods:**
- `weaverBegin()` - Entry point for network operations
- `conduit_weaver()` - Main weaving loop (host or guest)
- `conduit_win_host()` - Host socket server implementation
- `conduit_win_guest()` - Guest socket client implementation
- `realm_conduit_win_guest()` - Async guest connection handler

### 3.3 System Utilities (realm_* functions)
**File:** `main.cpp` (scattered throughout)

| Function | Purpose |
|----------|---------|
| `realm_win_ipconfig()` | Display network interfaces & IPs |
| `realm_win_port_check()` | Check if port is available |
| `realm_win_updater()` | Self-update mechanism (ZIP-based) |
| `realm_win_roll()` | Update install & reload |
| `realm_win_handles_*` | Process/thread/file/socket/event/mutex enumeration |
| `realm_win_save_state()` | Process memory dump |
| `realm_os_tcp_host/guest` | Raw TCP host/guest utilities |

---

## 4. OPERATIONAL MODES

### 4.1 Menu-Driven Interactive Mode (Default)
```
PrimeOne.exe
```
Launches interactive ASCII menu (menu_librarian) with real-time status display.

### 4.2 Command-Line Direct Mode
```
PrimeOne.exe -m <menu_option> [options...]
```
Bypasses interactive menu, executes specific function directly.

### 4.3 Network Host Mode
```
PrimeOne.exe -m 8 -p <port> [-ip <bind_ip>] [-c <cores>] [-f <flag>] [-x <compute>]
```
Starts as network host, listens for guest connections.

### 4.4 Network Guest Mode
```
PrimeOne.exe -m 9 -p <port> -ip <host_ip> [-c <cores>] [-f <flag>] [-x <compute>]
```
Connects to host as guest worker.

---

## 5. COMMAND LINE REFERENCE

| Argument | Description | Values | Default |
|----------|-------------|--------|---------|
| `-o` | Enable option O | (flag) | false |
| `-c <N>` | CPU core count / affinity | Integer | 0 (auto) |
| `-m <N>` | Menu option to execute directly | 0-9, l, a, r, u, p, s, g, t | null (interactive) |
| `-ip <IP>` | Bind IP (host) / Connect IP (guest) | IPv4 address | null |
| `-p <PORT>` | TCP port for network communication | 1-65535 | 0 (auto) |
| `-f <FLAG>` | Compute flags | `git_off`, `quickPrime`, `noPrime` | null |
| `-x <MODE>` | Compute method | `Gear`, `blindPrime`, etc. | `Gear` |
| `-w <ROLE>` | Network role | `h` (host), `g` (guest) | `h` |

---

## 6. MENU OPTIONS REFERENCE

### Main Menu (menueChoice == 0)
| Key | Function | Description |
|-----|----------|-------------|
| `0` | **PrimeBook Load & Go!** | Quick start with defaults |
| `1` | **PrimeBook Start A New** | Fresh computation session |
| `l` | **PrimeBook One Library** | Library/Archive management |
| `a` | **PrimeBook One Archive** | Create/update archive |
| `r` | **PrimeBook One Rebind** | Rebind network/config |
| `u` | **PrimeBook One Update** | Check/apply updates |
| `s` | **Singers** | Thread/worker configuration |
| `g` | **PU = No** | GPU compute disable |
| `c` | **PU = Yes** | GPU compute enable |
| `p` | **primer** | Prime algorithm selector |
| `t` | **thermal** | Thermal/throttle management |

### Sub-Menu (menueChoice == 1) - Accessed via options 8/9
| Key | Function | Description |
|-----|----------|-------------|
| `3` | **Network Peers** | Show connected peers / ipconfig |
| `4` | **Archive Create** | Create PrimeOneUpdater.zip |
| `5` | **Network Updater** | Send/receive update package |
| `6` | **Roll Update** | Install & reload update |
| `..` / `back` | **Back** | Return to main menu |

### Special Entries
| Input | Action |
|-------|--------|
| `8` | **NETWORK HOST** - Start as host (port 5678 default) |
| `9` | **NETWORK GUEST** - Start as guest (connect to host) |
| `exit` | Terminate application |

---

## 7. NETWORK ARCHITECTURE

### Host Role (-m 8 / -w h)
```
┌─────────────────────────────────────────────────────────────┐
│                        HOST PROCESS                          │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────────────┐  │
│  │ TCP Server  │  │ Work Queue  │  │ Result Aggregator   │  │
│  │ (Port 5678) │◄─│ (Prime Tiles)│─►│ (Prime Verification)│  │
│  └─────────────┘  └─────────────┘  └─────────────────────┘  │
│         │                │                    │               │
│         ▼                ▼                    ▼               │
│  ┌─────────────────────────────────────────────────────┐     │
│  │              GUEST CONNECTION POOL                   │     │
│  │  Guest 1 ◄──► Guest 2 ◄──► Guest 3 ◄──► ... Guest N │     │
│  └─────────────────────────────────────────────────────┘     │
└─────────────────────────────────────────────────────────────┘
```

### Guest Role (-m 9 / -w g)
```
┌─────────────────────────────────────────────────────────────┐
│                        GUEST PROCESS                         │
│  ┌─────────────┐  ┌─────────────┐  ┌─────────────────────┐  │
│  │ TCP Client  │  │ Compute     │  │ Result Sender       │  │
│  │ (Connect)   │──│ Engine      │──│ (Prime Tiles/Proofs)│  │
│  └─────────────┘  └─────────────┘  └─────────────────────┘  │
└─────────────────────────────────────────────────────────────┘
```

### Communication Protocol
- **Transport:** TCP/IP (Winsock2)
- **Port:** Default 5678 (configurable via `-p`)
- **Data Format:** Binary serialized `__int128` primes + `std::byte` tile data
- **Authentication:** None (trusted LAN assumed)
- **Encryption:** None (libssh available but not used in conduit)

---

## 8. BATCH FILE AUTOMATION

### 8.1 Host Launcher (primeone8host - 54767.bat)
```batch
primeone.exe -m 8 -p 54767
```
**Purpose:** Start host on port 54767 with menu option 8 (Network Host)

### 8.2 Guest Launcher (primeone9guestsShow - 54767.bat)
```batch
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```
**Purpose:** Launch guest connecting to host at 10.0.0.22:54767, single core, guest role

### 8.3 Maintenance Scripts
| Script | Purpose |
|--------|---------|
| `age.bat` | Compare executable timestamps |
| `checkversion.bat` | Display file version via WMIC |
| `clean.bat` | Clean carriage returns in source |
| `setversion.bat` | Sign executable with signtool |
| `verifyupdater.bat` | Auto-update loop (watch for newer exe) |

---

## 9. FEATURE DOCUMENT MAP

This master document connects to the following detailed feature documents:

| Doc # | Title | Lines | Status |
|-------|-------|-------|--------|
| 01 | Command Line Interface & Argument Parsing | 250+ | ✓ |
| 02 | Interactive Menu System (Librarian) | 250+ | ✓ |
| 03 | Prime Tile Computation Engine | 250+ | ✓ |
| 04 | Network Conduit System (Host/Guest) | 250+ | ✓ |
| 05 | GPU/CUDA Acceleration | 250+ | ✓ |
| 06 | Update & Roll System | 250+ | ✓ |
| 07 | Windows System Utilities | 250+ | ✓ |
| 08 | Batch File Automation & Deployment | 250+ | ✓ |
| 09 | Console UI & Real-time Display | 250+ | ✓ |
| 10 | Data Persistence (Book/Archive) | 250+ | ✓ |
| 11 | Prime Algorithms Deep Dive | 250+ | ✓ |
| 12 | Distributed Consensus & Verification | 250+ | ✓ |
| 13 | Configuration & State Management | 250+ | ✓ |
| 14 | Troubleshooting & Diagnostics | 250+ | ✓ |
| 15 | Master Compendium (All Features) | 500+ | ✓ |

---

## 10. QUICK START GUIDE

### 10.1 Single Machine (Interactive)
```cmd
PrimeOne.exe
# Press 0 for "Load & Go" or 1 for "Start New"
```

### 10.2 Network Host (Server)
```cmd
PrimeOne.exe -m 8 -p 54767 -c 4 -f quickPrime -x Gear
```
- `-m 8` = Network Host mode
- `-p 54767` = Listen on port 54767
- `-c 4` = Use 4 CPU cores
- `-f quickPrime` = Fast prime algorithm
- `-x Gear` = Gear compute method

### 10.3 Network Guest (Worker) - Run on Multiple Machines
```cmd
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -c 2 -f quickPrime -x Gear -w g
```
- `-m 9` = Network Guest mode
- `-ip 192.168.1.100` = Connect to host IP
- `-w g` = Explicit guest role

### 10.4 Automated Cluster Launch (Windows Batch)
**On Host Machine:**
```batch
primeone8host - 54767.bat
```

**On Each Guest Machine:**
```batch
primeone9guestsShow - 54767.bat
```
(Edit the batch file to match your host IP)

### 10.5 Linux via Wine (Headless)
```bash
# Console version works with pseudo-terminal
script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null

# Or use wrapper script
/workspace/app/run_primeone_wine.sh
```

---

## 11. SYSTEM REQUIREMENTS

### Windows (Native)
- Windows 10/11 x64
- Visual C++ Redistributable 2019+
- CUDA Toolkit 11+/12+ (for GPU)
- DirectX SDK June 2010 (for D3D9)
- Windows SDK 10.0.19041+
- 8GB+ RAM, Multi-core CPU, NVIDIA GPU (optional)

### Linux (Wine)
- Wine 10.0+
- wine32:i386 (for wineconsole)
- winbind (for ntlm_auth)
- xvfb (for GUI apps)
- MinGW-w64 (for building)
- libcurl, libssl, libssh development headers

### Network
- LAN with <1ms latency recommended
- Port 5678 (or custom) open TCP inbound on host
- Static IPs preferred for cluster stability

---

## 12. FILE STRUCTURE

```
PrimeOne/
├── PrimeOne.exe              # Main executable (GUI subsystem)
├── PrimeOne3236.exe          # Console subsystem variant
├── PrimeOneGui.exe           # GUI variant
├── PrimeOne.cbp              # Code::Blocks project
├── main.cpp                  # 20,000+ line monolithic source
├── *.bat                     # Batch automation scripts
├── cppcodec/                 # Base64 encoding library
├── curl/                     # libcurl (HTTP/HTTPS)
│   ├── include/              # Headers
│   ├── lib/                  # Static libs
│   └── bin/                  # DLLs
├── libssh/                   # libssh (SFTP/SSH)
│   ├── include/
│   └── lib/x64/
├── libminiupnpc/             # UPnP port forwarding
├── cudart64_110.dll          # CUDA Runtime 11.0
├── cudart64_12.dll           # CUDA Runtime 12.0
├── cuda_runtime.h            # CUDA headers
├── cuda_runtime_api.h
├── d3d9.dll                  # DirectX 9
├── jsoncpp*.dll/.lib         # JSON parsing
├── libssh.dll/.lib           # SSH library
├── ws2_32.dll                # Winsock2
└── version.rc / version.res  # Version resource
```

---

## 13. DOCUMENT NAVIGATION

```
00_MASTER_DIRECTION.md (THIS FILE)
    │
    ├── 01_COMMAND_LINE_INTERFACE.md
    ├── 02_INTERACTIVE_MENU_SYSTEM.md
    ├── 03_PRIME_TILE_COMPUTATION_ENGINE.md
    ├── 04_NETWORK_CONDUIT_SYSTEM.md
    ├── 05_GPU_CUDA_ACCELERATION.md
    ├── 06_UPDATE_ROLL_SYSTEM.md
    ├── 07_WINDOWS_SYSTEM_UTILITIES.md
    ├── 08_BATCH_AUTOMATION_DEPLOYMENT.md
    ├── 09_CONSOLE_UI_REALTIME_DISPLAY.md
    ├── 10_DATA_PERSISTENCE_BOOK_ARCHIVE.md
    ├── 11_PRIME_ALGORITHMS_DEEP_DIVE.md
    ├── 12_DISTRIBUTED_CONSENSUS_VERIFICATION.md
    ├── 13_CONFIGURATION_STATE_MANAGEMENT.md
    ├── 14_TROUBLESHOOTING_DIAGNOSTICS.md
    └── 15_MASTER_COMPENDIUM.md
```

Each feature document (01-14) contains **minimum 250 lines** of detailed technical documentation.
Document 15 (Master Compendium) contains **minimum 500 lines** integrating all features.

---

## 14. VERSION HISTORY & EVOLUTION

Based on GearSlice analysis of 1,623 converted spreadsheets (2022-2025):

| Year | Files | Key Evolution |
|------|-------|---------------|
| 2022 | 65 | Foundation: Basic prime tile, simple menu |
| 2023 | 509 | Network layer: Host/Guest, conduit system |
| 2024 | 384 | GPU: CUDA integration, compute shaders |
| 2025 | 665 | Maturity: Update system, roll, archive, WMI |

**Current State:** Feature-complete for Windows. Cross-platform build requires porting.

---

## 15. SUPPORT & EXTENSION POINTS

### Extending Prime Algorithms
- Modify `primeTileClass::nextWalkPrime()` and `moonWalkPrime()`
- Add new compute methods in `computeMethod` string parsing
- Register in `librarian_functions` optionCompute handling

### Adding Network Protocols
- Extend `conduitClass` with new message types
- Implement in `conduit_weaver()` message loop
- Use existing `std::vector<std::byte>` serialization

### New Menu Options
- Add case in `librarian_functions()` switch logic
- Update `menu_librarian()` display
- Add command-line mapping in `main()` argument parser

### Custom Compute Backends
- Implement in `primeTileClass` virtual methods
- Add CUDA kernels in `.cu` files
- Link via `nvcc` in Code::Blocks project

---

*End of Master Direction Document*  
*Proceed to individual feature documents for complete specifications*