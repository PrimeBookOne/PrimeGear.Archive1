# PrimeOne - Feature Document 13: Configuration & State Management
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` global variables, menu system, command line, primeTileClass, conduitClass  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Configuration & State Management system handles **runtime configuration**, **persistent state**, **session management**, and **cross-component coordination** for PrimeOne. It spans command-line arguments, interactive menu state, network configuration, computation parameters, and checkpoint/restart data.

### Design Philosophy
- **Layered configuration** - CLI → Menu → Defaults
- **Global state singleton** - Single source of truth (current anti-pattern)
- **Session persistence** - Survive restarts via Prime Book
- **Network coherence** - Shared config across host/guest cluster

---

## 2. CONFIGURATION LAYERS

### 2.1 Layer Hierarchy (Priority Order)
```
┌─────────────────────────────────────────────────────────────────┐
│                    CONFIGURATION LAYERS                          │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  1. COMPILE-TIME (Lowest Priority)                              │
│     #define DEFAULT_PORT 5678                                   │
│     #define DEFAULT_SINGERS 16                                  │
│     #define DEFAULT_COMPUTE "Gear"                              │
│                                                                  │
│  2. HARDCODED DEFAULTS (main.cpp)                               │
│     int hostPort = 0;                                           │
│     string computeMethod = "Gear";                              │
│     bool createHost = true;                                     │
│                                                                  │
│  3. COMMAND LINE (High Priority)                                │
│     -p 54767 -m 8 -c 4 -f quickPrime -x Gear -w h              │
│                                                                  │
│  4. INTERACTIVE MENU (Highest Priority)                         │
│     User selects options at runtime                             │
│                                                                  │
│  5. PERSISTED STATE (Prime Book)                                │
│     Loaded on startup, overrides above                          │
│                                                                  │
│  6. NETWORK SYNC (Cluster)                                      │
│     Host pushes config to guests                                │
│                                                                  │
└─────────────────────────────────────────────────────────────────┘
```

### 2.2 Command Line → Internal Mapping
```cpp
// main() lines 11918-12070
struct CLIConfig {
    bool optionO = false;           // -o
    int optionCores = 0;            // -c
    string optionMenueInput = "null"; // -m
    string hostIp = "null";         // -ip
    int hostPort = 0;               // -p
    string optionFlagInput = "null";   // -f
    string optionComputeInput = "default"; // -x
    string networkAssignment = "default";  // -w
};

// Post-processing:
bool createHost = (networkAssignment != "g");
bool singleCore = (optionCores == 1);
string computeMethod = optionComputeInput;  // BUG: hardcoded to "Gear" line 12063
```

---

## 3. GLOBAL STATE VARIABLES

### 3.1 Critical Globals (Scattered in main.cpp)
```cpp
// Network
string uniqueIdGlobal;              // Session identifier
string globalRemoteIpString;        // Remote host IP
string globalRemotePortString;      // Remote port
int globalNewHostPort = 0;          // Host port from -p

// Computation
__int128 powerOf = 20;              // Grid = 2^powerOf
__int128 singers = 16;              // Thread count
__int128 indexTiles = 0;            // Current tile
__int128 infiniteWalk = 0;          // Continuous walk position
__int128 totalPrimes = 0;           // Total found
__int128 largestDiff = 228;         // Max gap

// UI State
bool mrTsaysRead = false;           // "Mr. T says read" flag
bool questionDemonstrate = true;    // Menu loop control
bool reload = false;                // Screen refresh flag

// Network
bool createHost = true;             // Host vs guest
string networkAssignment = "default"; // "h" or "g"
```

### 3.2 primeTileClass Member State
```cpp
class primeTileClass {
    // Configuration
    __int128 powerOf;               // Grid exponent
    __int128 singers;               // Thread count
    __int128 indexTiles;            // Tile index
    __int128 perThreadSlices;       // Work per thread
    bool singleCore;                // Force single thread
    string computeMethod;           // "Gear", "blindPrime"
    
    // Runtime State
    __int128* primeIndex;           // Known primes array
    __int128 primeIndexCount;       // Array size
    __int128 grid;                  // 2^powerOf
    __int128 infiniteWalk;          // Walk position
    __int128 total;                 // Total primes
    byte* returnTile;               // Tile buffer
    byte* primeFindsArray;          // Found primes buffer
    
    // Network
    int conduitPort;                // 5678 default
};
```

### 3.3 conduitClass Member State
```cpp
class conduitClass {
    int dataPort;                   // TCP port
    
    // Weaving state
    __int128 songCount;             // Work units
    __int128 privateGrid;           // Local grid size
    byte* returnTile;               // Result buffer
    
    // Host state
    bool weaveNewHost;
    bool infinite;
    __int128 infiniteWalk;
    int choirSize;
    int assignedPort;
    int hostConduits;
    int guestConduits;
    int conduitCount;
    __int128 weaverDataHost;
    
    // Guest state
    bool weaveHost;
    int weavePort;
    int returnData;
    int weavePortHost;
    int weaveNewPort;
    vector<byte> primeCatch;        // Received primes
};
```

---

## 4. SESSION MANAGEMENT

### 4.1 Session Lifecycle
```
┌─────────────────────────────────────────────────────────────────┐
│                      SESSION LIFECYCLE                           │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  STARTUP                                                        │
│  ├── Parse command line                                         │
│  ├── Initialize WinSock                                         │
│  ├── Load Prime Book (if exists)                                │
│  ├── Initialize primeTileClass                                  │
│  ├── Initialize conduitClass                                    │
│  ├── Position console window                                    │
│  └── Enter librarian_functions()                                │
│                                                                  │
│  INTERACTIVE MODE                                               │
│  ├── Display menu_librarian()                                   │
│  ├── realm_os_user_input()                                      │
│  ├── Process menu selection                                     │
│  ├── Update state                                               │
│  └── Loop                                                       │
│                                                                  │
│  NETWORK MODE                                                   │
│  ├── conduitClass::weaverBegin()                                │
│  ├── conduit_weaver()                                           │
│  ├── conduit_win_host() OR conduit_win_guests()                 │
│  ├── Background threads (async)                                 │
│  └── Menu still accessible (sub-menu)                           │
│                                                                  │
│  SHUTDOWN                                                       │
│  ├── Save Prime Book                                            │
│  ├── Close network sockets                                      │
│  ├── Join worker threads                                        │
│  ├── WSACleanup()                                               │
│  └── exit(0)                                                    │
│                                                                  │
└─────────────────────────────────────────────────────────────────┘
```

### 4.2 Unique Session ID
```cpp
// Generation (not fully visible)
string uniqueIdGlobal;  // Set at startup

// Likely generation:
string generateUniqueId() {
    // Timestamp + Machine ID + Random
    return to_string(time(nullptr)) + "_" + getComputerName() + "_" + randomHex(8);
}
```

### 4.3 Session Persistence
```cpp
// Saved in Prime Book:
struct SessionState {
    string uniqueIdGlobal;
    __int128 infiniteWalk;
    __int128 totalPrimes;
    __int128 powerOf;
    __int128 singers;
    string hostIp;
    int hostPort;
    bool createHost;
    time_t sessionStart;
    time_t lastCheckpoint;
};
```

---

## 5. NETWORK CONFIGURATION

### 5.1 Port Management
| Port | Purpose | Configurable |
|------|---------|--------------|
| 5678 | Default conduit port (constructor) | No (hardcoded) |
| 54767 | Batch file default | Yes (`-p`) |
| 55555 | Dashboard display | No (hardcoded) |
| 54000 | Updater default | No (hardcoded in updater) |

### 5.2 IP Configuration
```cpp
// Host: bind address
string hostIp = "null";  // INADDR_ANY when null

// Guest: connect address
string hostIp = "10.0.0.22";  // From -ip or menu

// Auto-detection (realm_win_ipconfig):
// Shows all interfaces, user selects
```

### 5.3 Network Role
```cpp
// Determined by:
bool createHost = (networkAssignment != "g");  // -w g forces guest

// Menu options:
'8' -> createHost = true
'9' -> createHost = false
```

---

## 6. COMPUTE CONFIGURATION

### 6.1 Compute Methods
| Method | String | GPU | Network | Use Case |
|--------|--------|-----|---------|----------|
| Gear | `"Gear"` | Yes | Yes | Production |
| Blind Prime | `"blindPrime"` | No | No | Debug |
| Quick Prime | flag `quickPrime` | Yes | Yes | Screening |
| No Prime | flag `noPrime` | No | Yes | Relay only |

### 6.2 Thread/CPU Configuration
```cpp
// From -c N:
int optionCores = N;

// Mapping:
if (optionCores == 1) singleCore = true;
else if (optionCores > 1) { /* affinity? */ }
else { /* auto-detect */ }

// In primeTileClass:
__int128 singers = optionCores > 0 ? optionCores : hardware_concurrency();
```

### 6.3 Flags
```cpp
string optionFlagInput;  // -f

if (optionFlagInput == "git_off") gitState = false;
if (optionFlagInput == "quickPrime") computeMethod = "quickPrime";
if (optionFlagInput == "noPrime") computeMethod = "noPrime";
```

---

## 7. STATE SERIALIZATION

### 7.1 Prime Book (Complete State)
```cpp
struct PrimeBookSnapshot {
    // Metadata
    string version = "1.0";
    string serviceTag = "[SERVICE_primeOne_2025_7_18.xlsm]";
    int buildCount = 3242;
    time_t timestamp;
    
    // Computation
    __int128 powerOf;
    __int128 singers;
    __int128 indexTiles;
    __int128 perThreadSlices;
    __int128 infiniteWalk;
    __int128 totalPrimes;
    __int128 primeRatio;
    __int128 totalTiles;
    __int128 largestDiff;
    
    // Prime Index
    vector<__int128> primeIndex;
    
    // Tile State
    vector<TileState> tiles;
    
    // Network
    string hostIp;
    int hostPort;
    bool createHost;
    string uniqueIdGlobal;
    
    // Config
    bool singleCore;
    string computeMethod;
    string optionFlag;
    
    // Checksum
    string sha256;
};
```

### 7.2 Lightweight Checkpoint (Frequent)
```cpp
struct Checkpoint {
    __int128 infiniteWalk;
    __int128 totalPrimes;
    __int128 indexTiles;
    time_t timestamp;
    string sha256;  // Of full book
};
```

### 7.3 Serialization Functions
```cpp
// In primeTileClass:
vector<byte> ptv_primeBookAuthor(__int128 primeDifference, 
                                  int singerCount, int gridSize, int tileCount);

bool loadPrimeBook(const vector<byte>& data);
bool savePrimeBook(const string& path);
bool saveCheckpoint(const string& path);
```

---

## 8. MENU STATE MACHINE

### 8.1 Menu State Variables
```cpp
int menueChoice = 0;           // 0=main, 1=sub, 2=deep
bool questionDemonstrate = true; // Main loop flag
bool mrTsaysRead = false;      // Network mode entered
bool reload = false;           // Screen refresh
bool commandLineMode = false;  // -m used
bool noGui = false;            // Skip menu display
bool gitState = true;          // Git integration
```

### 8.2 State Transitions
```
menueChoice=0 (Main)
  ├─ '8'/'9' → menueChoice=1, mrTsaysRead=true, reload=true
  ├─ 'l','a','r','u','s','c','g','p','t' → action, reload=true
  ├─ 'exit' → questionDemonstrate=false, exit(0)
  └─ invalid → "INVALID ENTRY", reload=true

menueChoice=1 (Sub)
  ├─ '3','4','5','6' → action, reload=true
  ├─ '..'/'back' → menueChoice--, reload=true
  ├─ 'exit' → exit(0)
  └─ invalid → "INVALID ENTRY", reload=true
```

---

## 9. CONFIGURATION VALIDATION

### 9.1 Current Validation (Minimal)
```cpp
// Port validation: NONE (just stream extraction)
// IP validation: NONE (passed to inet_addr)
// Core count: NONE (passed directly)
// Menu option: NONE (string match in handlers)
```

### 9.2 Required Validation
```cpp
bool validateConfig(const Config& cfg) {
    // Port range
    if (cfg.port < 1 || cfg.port > 65535) return false;
    
    // IP format
    if (!cfg.hostIp.empty() && !isValidIPv4(cfg.hostIp)) return false;
    
    // Core count
    int maxCores = thread::hardware_concurrency();
    if (cfg.cores < 0 || cfg.cores > maxCores * 2) return false;
    
    // Menu option
    static const set<string> validMenus = {
        "0","1","l","a","r","u","s","c","g","p","t","8","9"
    };
    if (!cfg.menuOption.empty() && !validMenus.count(cfg.menuOption)) 
        return false;
    
    // Compute method
    static const set<string> validCompute = {
        "Gear", "blindPrime", "quickPrime", "noPrime"
    };
    if (!validCompute.count(cfg.computeMethod)) return false;
    
    return true;
}
```

---

## 10. RUNTIME RECONFIGURATION

### 10.1 Hot-Reloadable Settings
```cpp
// Can change without restart:
atomic<int> singers;           // Thread count
atomic<bool> useGPU;           // GPU toggle
atomic<string> computeMethod;  // Algorithm
atomic<int> logLevel;          // Verbosity

// Require restart:
const string uniqueIdGlobal;   // Session identity
const int conduitPort;         // Network port
```

### 10.2 Menu Hot-Reload
```cpp
// Menu options that take effect immediately:
'c'/'g' -> useGPU = true/false
's' -> singers = new value
'p' -> primer algorithm
't' -> thermal throttle

// Require network restart:
'8'/'9' -> createHost toggle
'r' -> rebind (re-bind socket)
```

---

## 11. ENVIRONMENT VARIABLES

### 11.1 Supported Variables
```bash
# Network
PRIMEONE_PORT=54767
PRIMEONE_HOST_IP=192.168.1.100
PRIMEONE_ROLE=host|guest

# Compute
PRIMEONE_CORES=8
PRIMEONE_COMPUTE=Gear
PRIMEONE_FLAG=quickPrime
PRIMEONE_SINGLE_CORE=0

# Paths
PRIMEONE_HOME=/opt/primeone
PRIMEONE_BOOK_PATH=/var/lib/primeone/book.bin
PRIMEONE_LOG_DIR=/var/log/primeone

# Security
PRIMEONE_CERT_PATH=/etc/primeone/cert.pfx
PRIMEONE_CERT_PASS=***
```

### 11.2 Variable Precedence
```
1. Command line (-p, -c, -m, etc.)
2. Environment variables (PRIMEONE_*)
3. Prime Book (loaded state)
4. Hardcoded defaults
```

---

## 12. CONFIGURATION FILES (Future)

### 12.1 Proposed primeone.conf
```ini
[network]
port = 54767
host_ip = 0.0.0.0
role = host
max_guests = 64
heartbeat_interval = 30

[compute]
method = Gear
cores = 8
single_core = false
gpu_enabled = true
cuda_device = 0

[book]
auto_save_interval = 300
checkpoint_interval = 60
backup_count = 5
path = ${PRIMEONE_HOME}/primebook.bin

[logging]
level = info
file = ${PRIMEONE_LOG_DIR}/primeone.log
max_size = 100MB
max_files = 10
console = true

[security]
tls_enabled = false
cert_path = ${PRIMEONE_CERT_PATH}
verify_guests = true
max_guests_per_ip = 4
```

### 12.2 Loading
```cpp
Config loadConfig() {
    Config cfg;
    
    // 1. Defaults
    cfg.setDefaults();
    
    // 2. Config file
    if (fileExists("primeone.conf")) {
        cfg.parseIni("primeone.conf");
    }
    
    // 3. Environment
    cfg.applyEnv("PRIMEONE_");
    
    // 4. Command line (highest)
    cfg.applyCmdLine(argc, argv);
    
    // 5. Validate
    if (!validateConfig(cfg)) throw ConfigError("Invalid configuration");
    
    return cfg;
}
```

---

## 13. STATE MIGRATION

### 13.1 Version Upgrades
```cpp
// Book format versioning
int CURRENT_BOOK_VERSION = 3;

bool migrateBook(PrimeBookSnapshot& book) {
    if (book.version == 1) {
        migrate_v1_to_v2(book);
        book.version = 2;
    }
    if (book.version == 2) {
        migrate_v2_to_v3(book);
        book.version = 3;
    }
    return true;
}

void migrate_v1_to_v2(PrimeBookSnapshot& book) {
    // Add new fields with defaults
    book.computeMethod = "Gear";
    book.optionFlag = "default";
    book.singleCore = false;
}
```

### 13.2 Backward Compatibility
- New executable reads old book format
- Auto-migrates on load
- Preserves all historical data
- Logs migration steps

---

## 14. KNOWN ISSUES & TECHNICAL DEBT

### 14.1 Current Problems
| Issue | Location | Impact |
|-------|----------|--------|
| Global variables everywhere | main.cpp | Tight coupling, testing impossible |
| Hardcoded "Gear" override | Line 12063 | -x flag ignored |
| No config validation | main() | Silent failures |
| Menu state in globals | librarian_functions | Not thread-safe |
| Network config in multiple places | main, conduit, menu | Inconsistency |
| No config file support | N/A | Deployment friction |
| Environment vars ignored | N/A | No container/config mgmt |

### 14.2 Architecture Debt
- **God object**: main.cpp holds all state
- **No dependency injection**: Everything accesses globals
- **No configuration abstraction**: Direct variable access
- **No hot reload**: Restart required for most changes
- **No schema validation**: Typos in config silent

---

## 15. REFACTORING ROADMAP

### 15.1 Phase 1: Centralize Config (Critical)
- [ ] Create `Config` class with all settings
- [ ] Single `Config& getConfig()` accessor
- [ ] Remove global variables from main.cpp
- [ ] Add validation on set

### 15.2 Phase 2: Config Sources (High)
- [ ] INI file parser (primeone.conf)
- [ ] Environment variable mapping
- [ ] Command line → Config mapping
- [ ] Prime Book → Config loading

### 15.3 Phase 3: Runtime Management (High)
- [ ] Hot-reload for tunable params
- [ ] Config change notifications (observer pattern)
- [ ] Audit log for config changes
- [ ] Config versioning

### 15.4 Phase 4: Cluster Config (Medium)
- [ ] Host pushes config to guests
- [ ] Config consensus (all guests same)
- [ ] Rolling config updates
- [ ] Config drift detection

### 15.5 Phase 5: Advanced (Low)
- [ ] Web UI for config management
- [ ] Config templates (dev/staging/prod)
- [ ] Feature flags
- [ ] A/B testing framework

---

## 16. TESTING SPECIFICATIONS

### 16.1 Config Tests
| Test | Description |
|------|-------------|
| Default config | All defaults valid |
| CLI override | -p, -c, -m, etc. work |
| Env var override | PRIMEONE_* respected |
| Config file | INI parsed correctly |
| Priority order | CLI > Env > File > Default |
| Validation | Invalid rejected with message |
| Migration | v1→v2→v3 works |

### 16.2 State Tests
| Test | Description |
|------|-------------|
| Book save/load | Round-trip identical |
| Checkpoint save/load | Minimal state restored |
| Session restore | After crash, continues |
| Network sync | Host/guest configs match |

### 16.3 Migration Tests
- v1 book → current
- Corrupted book → graceful fail
- Downgrade attempt → rejected

---

## 17. COMPLETE COMMAND REFERENCE

### 17.1 Configuration Commands
```cmd
# Network
PrimeOne.exe -p 54767           # Port
PrimeOne.exe -ip 192.168.1.100  # Bind/connect IP
PrimeOne.exe -w h               # Host role
PrimeOne.exe -w g               # Guest role

# Compute
PrimeOne.exe -c 8               # 8 cores
PrimeOne.exe -c 1               # Single core
PrimeOne.exe -f quickPrime      # Fast mode
PrimeOne.exe -f noPrime         # Network only
PrimeOne.exe -x Gear            # Algorithm (ignored currently)

# Menu
PrimeOne.exe -m 8               # Direct to host
PrimeOne.exe -m 9               # Direct to guest
PrimeOne.exe -m u               # Direct to update

# Boolean
PrimeOne.exe -o                 # Option O
```

### 17.2 Menu Configuration
```
Main Menu:
  s - Singers (threads)
  c - PU=Yes (GPU)
  g - PU=No (CPU)
  p - Primer (algorithm)
  t - Thermal (throttle)
  r - Rebind (network)
  u - Update
  l - Library
  a - Archive
```

### 17.3 Environment Variables
```bash
export PRIMEONE_PORT=54767
export PRIMEONE_HOST_IP=10.0.0.22
export PRIMEONE_CORES=8
export PRIMEONE_COMPUTE=Gear
export PRIMEONE_HOME=/opt/primeone
```

---

## 18. CROSS-REFERENCE: SOURCE LOCATIONS

| Config Aspect | File | Lines |
|---------------|------|-------|
| CLI parsing | main.cpp | 11918-12070 |
| Post-processing | main.cpp | 12035-12070 |
| Menu state | main.cpp | 14225-14540 |
| Menu display | main.cpp | 14538-15200 |
| PrimeTile state | main.cpp | ~1900-2000 |
| Conduit state | main.cpp | ~8918-9000 |
| Global variables | main.cpp | Scattered |

---

## 19. FUTURE ENHANCEMENTS

### 19.1 Configuration 2.0
- **Schema validation** (JSON Schema for config)
- **Encrypted secrets** (cert passwords, keys)
- **Config signatures** (tamper detection)
- **Distributed config** (etcd/Consul)

### 19.2 State Management 2.0
- **Event sourcing** (state as event log)
- **CQRS** (separate read/write models)
- **Snapshotting** (periodic full state)
- **Replay** (debug from any point)

---

*End of Feature Document 13: Configuration & State Management*  
*Next: 14_TROUBLESHOOTING_DIAGNOSTICS.md*