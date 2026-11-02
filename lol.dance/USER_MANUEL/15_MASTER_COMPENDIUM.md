# PrimeOne / PrimeBookOne - Master Compendium
## Complete Integrated User Manual & Technical Reference

**Version:** 1.0 (Build 3242)  
**Date:** 2025-07-18 (SERVICE_primeOne_2025_7_18.xlsm)  
**Platform:** Windows x64 (Native) / Linux x64 (Wine)  
**Source:** 1,623 converted spreadsheets (2022-2025) → 20,000+ line C++ monolith

---

## 📚 DOCUMENT MAP

| # | Document | Lines | Focus |
|---|----------|-------|-------|
| 00 | **MASTER_DIRECTION** | 300+ | Executive summary, architecture, quick start |
| 01 | **COMMAND_LINE_INTERFACE** | 400+ | Arguments, parsing, batch integration |
| 02 | **INTERACTIVE_MENU_SYSTEM** | 500+ | Librarian, dashboard, navigation |
| 03 | **PRIME_TILE_COMPUTATION_ENGINE** | 600+ | Algorithms, math, type fixes |
| 04 | **NETWORK_CONDUIT_SYSTEM** | 500+ | Host/Guest, TCP, weaver protocol |
| 05 | **GPU_CUDA_ACCELERATION** | 400+ | CUDA, D3D9, compute methods |
| 06 | **UPDATE_ROLL_SYSTEM** | 500+ | ZIP updates, signing, rollback |
| 07 | **WINDOWS_SYSTEM_UTILITIES** | 400+ | WMI, handles, diagnostics |
| 08 | **BATCH_AUTOMATION_DEPLOYMENT** | 500+ | Scripts, cluster launch, CI/CD |
| 09 | **CONSOLE_UI_REALTIME_DISPLAY** | 400+ | ANSI, dashboard, rendering |
| 10 | **DATA_PERSISTENCE_BOOK_ARCHIVE** | 500+ | Prime Book, ZIP, checkpoints |
| 11 | **PRIME_ALGORITHMS_DEEP_DIVE** | 600+ | Math, walk algorithms, gaps |
| 12 | **DISTRIBUTED_CONSENSUS_VERIFICATION** | 500+ | Host verification, reputation |
| 13 | **CONFIGURATION_STATE_MANAGEMENT** | 500+ | Config layers, session, migration |
| 14 | **TROUBLESHOOTING_DIAGNOSTICS** | 500+ | Fixes, debugging, recovery |
| 15 | **MASTER_COMPENDIUM** | **800+** | **THIS DOCUMENT - Integration** |

---

## 🎯 EXECUTIVE SUMMARY

### What Is PrimeOne?
PrimeOne is a **distributed prime number computation engine** with a novel **tile-based algorithm** that organizes prime search space into a 2D grid. It supports:
- **Multi-threaded CPU** computation (16+ threads)
- **GPU acceleration** via CUDA & DirectX 9
- **Network distribution** across host/guest cluster
- **Persistent state** via Prime Book serialization
- **Self-updating** via ZIP archives over network

### Core Innovation: Tile-Based Prime Walk
```
Traditional: Check each number sequentially
Tile-Based:  Grid of tiles → Parallel independent processing
             Each tile = prime candidate range
             Host distributes tiles → Guests compute → Host verifies
```

### Three Operational Modes
| Mode | Command | Use Case |
|------|---------|----------|
| **Interactive** | `PrimeOne.exe` | Manual operation, dashboard |
| **Host** | `PrimeOne.exe -m 8 -p 54767` | Cluster coordinator |
| **Guest** | `PrimeOne.exe -m 9 -p 54767 -ip HOST` | Worker node |

---

## 🏗️ SYSTEM ARCHITECTURE (Integrated View)

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                           PRIMEONE ECOSYSTEM                                 │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│  ┌──────────────────┐      ┌──────────────────┐      ┌──────────────────┐  │
│  │   HOST NODE      │      │   GUEST NODE 1   │      │   GUEST NODE N   │  │
│  │                  │      │                  │      │                  │  │
│  │ ┌──────────────┐ │      │ ┌──────────────┐ │      │ ┌──────────────┐ │  │
│  │ │primeTileClass│ │      │ │primeTileClass│ │      │ │primeTileClass│ │  │
│  │ │(verification)│ │      │ │(computation) │ │      │ │(computation) │ │  │
│  │ └──────┬───────┘ │      │ └──────┬───────┘ │      │ └──────┬───────┘ │  │
│  │        │         │      │        │         │      │        │         │  │
│  │ ┌──────▼───────┐ │      │ ┌──────▼───────┐ │      │ ┌──────▼───────┐ │  │
│  │ │conduitClass  │ │◄────►│ │conduitClass  │ │◄────►│ │conduitClass  │ │  │
│  │ │(TCP server)  │ │      │ │(TCP client)  │ │      │ │(TCP client)  │ │  │
│  │ └──────────────┘ │      │ └──────────────┘ │      │ └──────────────┘ │  │
│  └──────────────────┘      └──────────────────┘      └──────────────────┘  │
│         │                         │                         │              │
│         └─────────────────────────┼─────────────────────────┘              │
│                                   ▼                                        │
│                    ┌──────────────────────────────┐                        │
│                    │      PRIME BOOK (Shared)      │                        │
│                    │  • Prime Index (verified)     │                        │
│                    │  • Tile States                │                        │
│                    │  • Infinite Walk Position     │                        │
│                    │  • Gap Statistics             │                        │
│                    │  • Network Topology           │                        │
│                    └──────────────────────────────┘                        │
│                                                                              │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## 🚀 QUICK START GUIDE (Complete)

### Single Machine (Interactive)
```cmd
PrimeOne.exe
# Dashboard appears → Press '0' for Load & Go, '1' for Start New
```

### Host (Server) - Windows Batch
```batch
:: Edit not needed for localhost
primeone8host - 54767.bat
```

### Guest (Worker) - Windows Batch
```batch
:: EDIT THIS FILE: Change 10.0.0.22 to your host IP
primeone9guestsShow - 54767.bat
```

### Guest (Worker) - Command Line
```cmd
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -c 4 -f quickPrime -x Gear -w g
```

### Linux/Wine (Headless Console)
```bash
# Only PrimeOne3236.exe (CONSOLE subsystem) works headless
/workspace/app/run_primeone_wine.sh

# Or manually:
cd /workspace/app/.wine_primeone/drive_c/PrimeOne
script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null
```

### Multi-Guest Cluster (Production)
```batch
:: deploy_cluster.bat
@echo off
set HOST_IP=192.168.1.100
set PORT=54767
set GUESTS=8

:: On host machine:
primeone8host - 54767.bat

:: On each guest machine (or same machine with start):
for /l %%i in (1,1,%GUESTS%) do (
    start "Guest_%%i" cmd /c primeone.exe -m 9 -p %PORT% -ip %HOST_IP% -c1 -w g
)
```

---

## ⌨️ COMMAND LINE REFERENCE (Complete)

| Flag | Type | Description | Default | Example |
|------|------|-------------|---------|---------|
| `-o` | flag | Option O (legacy) | false | `-o` |
| `-c N` | int | CPU cores / threads | 0 (auto) | `-c 8` |
| `-m X` | string | Direct menu option | null | `-m 8` |
| `-ip X` | string | Bind/connect IP | null | `-ip 192.168.1.100` |
| `-p N` | int | TCP port | 0 (auto) | `-p 54767` |
| `-f X` | string | Compute flag | null | `-f quickPrime` |
| `-x X` | string | Compute method | Gear | `-x Gear` |
| `-w X` | string | Network role | h | `-w g` |

### Flag Values
| Flag `-f` | Effect |
|-----------|--------|
| `git_off` | Disable git integration |
| `quickPrime` | Fast probabilistic mode |
| `noPrime` | Network relay only |

### Compute Method `-x`
| Method | GPU | Network | Use Case |
|--------|-----|---------|----------|
| `Gear` | ✓ | ✓ | Production (default) |
| `blindPrime` | ✗ | ✗ | Debug/validation |
| `quickPrime` | ✓ | ✓ | Screening |

### Network Role `-w`
| Role | createHost | Description |
|------|------------|-------------|
| `h` | true | Host (server) |
| `g` | false | Guest (worker) |
| `default` | true | Host |

---

## 📋 MENU REFERENCE (Complete)

### Main Menu (menueChoice=0)
| Key | Label | Function | CLI Equivalent |
|-----|-------|----------|----------------|
| `0` | PrimeBook Load & Go! | Quick start with book | `-m 0` |
| `1` | PrimeBook Start A New | Fresh computation | `-m 1` |
| `l` | PrimeBook One Library | Library management | `-m l` |
| `a` | PrimeBook One Archive | Create update ZIP | `-m a` |
| `r` | PrimeBook One Rebind | Network rebind | `-m r` |
| `u` | PrimeBook One Update | Check/install update | `-m u` |
| `s` | Singers | Thread count | `-c N` |
| `c` | PU = Yes | Enable GPU | `-f quickPrime` |
| `g` | PU = No | Disable GPU | (default) |
| `p` | Primer | Algorithm select | `-x METHOD` |
| `t` | Thermal | Throttle management | N/A |
| `8` | NETWORK HOST | Start host | `-m 8` |
| `9` | NETWORK GUEST | Start guest | `-m 9` |
| `exit` | Quit | Exit application | N/A |

### Sub-Menu (menueChoice=1, after 8/9)
| Key | Label | Function |
|-----|-------|----------|
| `3` | Network Peers / IP Config | Show interfaces |
| `4` | Archive Create | Create PrimeOneUpdater.zip |
| `5` | Network Updater | Send/receive update |
| `6` | Roll Update | Install & restart |
| `..` / `back` | Back to Main | Navigate up |
| `exit` | Quit | Exit application |

---

## 🔧 CONFIGURATION MANAGEMENT

### Priority Order (Highest Wins)
```
1. Command Line (-p, -c, -m, etc.)
2. Environment Variables (PRIMEONE_*)
3. Prime Book (loaded state)
4. Hardcoded Defaults
```

### Environment Variables
```bash
export PRIMEONE_PORT=54767
export PRIMEONE_HOST_IP=192.168.1.100
export PRIMEONE_CORES=8
export PRIMEONE_COMPUTE=Gear
export PRIMEONE_HOME=/opt/primeone
export PRIMEONE_LOG_DIR=/var/log/primeone
```

### Key Config Files
| File | Purpose |
|------|---------|
| `PrimeOne.cbp` | Code::Blocks project |
| `Run Gear On Boot.xml` | Auto-start task |
| `primeone.conf` | (Future) INI config |
| `version.rc` | Windows version resource |

---

## 🌐 NETWORK DEPLOYMENT PATTERNS

### Pattern 1: Single Host, Multiple Guests (LAN)
```
Host (192.168.1.100) ←── Guest 1 (192.168.1.101)
                    ←── Guest 2 (192.168.1.102)
                    ←── Guest 3 (192.168.1.103)
                    ←── Guest N (192.168.1.x)
Port: 54767 (TCP)
```

### Pattern 2: Multi-Host Hierarchy (Future)
```
Super-Host ←── Host A ←── Guests
           ←── Host B ←── Guests
```

### Pattern 3: Cloud Deployment
```yaml
# Docker Compose (conceptual)
services:
  primeone-host:
    image: primeone:latest
    ports: ["54767:54767"]
    command: -m 8 -p 54767
    deploy: replicas: 1
  
  primeone-guest:
    image: primeone:latest
    command: -m 9 -p 54767 -ip host -c 4 -w g
    deploy: replicas: 8
```

---

## 📊 DASHBOARD & MONITORING

### Live Dashboard (menu_librarian)
```
XXX OPERATING SYSTEM XXX  NETWORK ADDRESSES XXX  PROCESSING UNITS XXX
                                                                 
127.0.0.1                              Build count: 3242        
[SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew           
                                                                 
XXXXXX MENUE OPTIONS XXXXXX                                      
X  (0) PrimeBook Load & Go!     X  (l) Library     X            
X  (1) PrimeBook Start A New    X  (a) Archive     X            
XXXX PRIMEBOOK ONE STATUS XXXX  XXXX PARAMETERS XXXX  X (r) Rebind X
X                                                               X
X  Prime Ratio =                X (a) Archive      X            
X  Total Tiles =                X (r) Rebind       X            
X  Largest Difference = 228     X (u) Update       X            
X  infiniteWalk =               X (s) Singers      X            
XXXXXXXXXXXXXXXXXXXXXXXXXXXX  X (c) PU=Yes       X            
X                              X (g) PU=No        X            
X  Total Primes =              X (p) primer       X            
X  TYPE COMMAND: :::::::::::::: X (t) thermal      X            
X  ||  |||||  |||  ||  ||       X (pause)          X            
X  |       | | | | |  |         X                  X            
X  |       | PRIMEBOOK ONE      X (c) PU=Yes       X            
X  ||  |   | | | | |  |         X (g) PU=No        X            
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X                  X            
X                            X GRID =          X            
X   Network Peers = 300      X                 X            
X   Active ip = 1            X Power =         X            
XXXXXXXXXXXXX  XXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXX            
      X       X  XXXXXXXX  XXXXX  XXXXX  Port = 55555         
```

### Live Updates (ANSI Positioning)
- Rows 3-6: `realm_win_ipconfig()` output (refreshes)
- `\033[3;1H` → Row 3, Col 1
- `\033[4;1H` → Row 4, Col 1 (repeated for multiple updates)

### Key Metrics to Watch
| Metric | Location | Healthy Range |
|--------|----------|---------------|
| Build Count | Dashboard | Increments per build |
| Network Peers | Dashboard | > 0 when clustered |
| Active IP | Dashboard | 1+ interfaces |
| Port | Dashboard | Matches `-p` value |
| infiniteWalk | Computation | Monotonically increasing |
| Total Primes | Computation | Growing steadily |
| Largest Gap | Statistics | ~228 (observed) |

---

## 🔐 SECURITY CHECKLIST

### Current State (Minimal)
- [ ] **Authentication**: None (trusted LAN assumed)
- [ ] **Encryption**: None (plain TCP)
- [ ] **Integrity**: SHA256 on updates (partial)
- [ ] **Signing**: Authenticode via signtool (manual)
- [ ] **Authorization**: Host controls all

### Production Hardening Required
```cpp
// 1. TLS via libssh (already linked)
ssh_session session = ssh_new();
ssh_options_set(session, SSH_OPTIONS_HOST, hostIp.c_str());
ssh_connect(session);

// 2. Message authentication
struct SecureMessage {
    uint32_t magic;
    uint8_t type;
    uint32_t length;
    byte payload[];
    byte hmac[32];  // HMAC-SHA256 with shared secret
};

// 3. Host verification
bool verifyHostIdentity(const string& hostIp, const string& expectedFingerprint);

// 4. Guest attestation
struct GuestAttestation {
    string guestId;
    string primeBookHash;
    string signature;  // Signed by host CA
};
```

---

## 🐛 KNOWN ISSUES & WORKAROUNDS

### Critical (Block Build)
| Issue | Location | Workaround |
|-------|----------|------------|
| Missing Windows headers | Linux build | Use Wine + pre-built exe |
| std::byte arithmetic | 20+ locations | Add explicit casts |
| pow(__int128) ambiguity | 3 locations | Use `ipow()` function |
| Missing return statements | 2 functions | Add `return value;` |
| uint8_t/byte pointer mismatch | 4 locations | Use consistent `byte` typedef |

### Runtime (Workarounds Exist)
| Issue | Workaround |
|-------|------------|
| GUI exe fails on Wine | Use `PrimeOne3236.exe` + `script` |
| Guest batch has hardcoded IP | Edit `primeone9guestsShow - 54767.bat` |
| Update watchdog loop commented | Uncomment `goto CheckNewer` in verifyupdater.bat |
| Signing fails | Use cert thumbprint: `/sha1 "THUMB"` |
| Console positioning fails | Use Wine console exe |

### Architecture Debt (Long-term)
- Monolithic `main.cpp` (20K+ lines)
- Global variables everywhere
- No config file support
- No automated testing
- No CI/CD pipeline

---

## 🔄 UPDATE & MAINTENANCE WORKFLOW

### Developer Workflow
```
1. Code Changes → main.cpp
2. Build → Code::Blocks (F9) or MSBuild
3. Sign → setversion.bat (needs cert)
4. Test → PrimeOne.exe -m u
4. Package → realm_win_archive() → PrimeOneUpdater.zip
5. Deploy → Host menu '5' (Network Updater) → Guests auto-roll
```

### Automated CI/CD (Target)
```yaml
# .github/workflows/release.yml
on:
  release:
    types: [published]
jobs:
  build:
    runs-on: windows-latest
    steps:
      - uses: actions/checkout@v4
      - name: Build
        run: msbuild PrimeOne.sln /p:Configuration=Release
      - name: Sign
        run: signtool sign /f ${{secrets.CERT}} /p ${{secrets.PASS}} /t http://timestamp.digicert.com PrimeOne.exe
      - name: Archive
        run: 7z a PrimeOneUpdater.zip PrimeOne.exe manifest.json
      - name: Release
        uses: softprops/action-gh-release@v1
        with:
          files: PrimeOneUpdater.zip
```

---

## 📈 PERFORMANCE TUNING GUIDE

### CPU Optimization
```cpp
// 1. Optimal thread count
singers = min(optionCores, hardware_concurrency());

// 2. NUMA awareness (future)
SetThreadAffinityMask(thread, numaNodeMask);

// 3. Huge pages
VirtualAllocEx(process, NULL, size, MEM_LARGE_PAGES, PAGE_READWRITE);
```

### GPU Optimization
```cuda
// 1. Persistent kernels
__global__ void persistentPrimeKernel() {
    while (atomicAdd(globalCounter, 1) < totalWork) {
        // Process tile
    }
}

// 2. Async streams
cudaStream_t streams[4];
for (int i = 0; i < 4; ++i) cudaStreamCreate(&streams[i]);
// Overlap compute + copy
```

### Network Optimization
```cpp
// 1. Nagle off
setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on));

// 2. Buffer sizes
setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &size, sizeof(size));
setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &size, sizeof(size));

// 3. Compression (future)
zstd_compress(dst, src, size, 3);  // Level 3 = fast
```

---

## 🧪 TESTING STRATEGY

### Unit Tests (Target)
```cpp
// Prime algorithms
TEST(PrimeAlgorithms, NextWalkPrime) {
    primeTileClass p(20, 1, 0, 0, nullptr, 0, 0);
    EXPECT_EQ(p.nextWalkPrime(10), 11);
    EXPECT_EQ(p.nextWalkPrime(100), 101);
}

TEST(PrimeAlgorithms, VerifyPrime) {
    EXPECT_TRUE(primeTileClass::verifyPrimeStatic(17));
    EXPECT_FALSE(primeTileClass::verifyPrimeStatic(18));
}

// Network
TEST(Network, HostGuestHandshake) {
    Host h(54767); Guest g("127.0.0.1", 54767);
    h.start(); g.connect();
    EXPECT_TRUE(g.isConnected());
    g.submitPrime(101);
    EXPECT_TRUE(h.verifyAndAccept(101));
}
```

### Integration Tests
- Host + 4 Guests (local)
- Network partition recovery
- Update package deploy
- Rollback verification

### Stress Tests
- 100 concurrent guests
- 24-hour continuous run
- 10GB prime book
- Network latency injection

---

## 📦 FILE STRUCTURE (Complete)

```
PrimeOne/
├── EXECUTABLES
│   ├── PrimeOne.exe            # GUI subsystem (9.1 MB)
│   ├── PrimeOne3236.exe        # CONSOLE subsystem ← USE THIS
│   ├── PrimeOneGui.exe         # GUI variant
│   └── prePrimeOne.exe         # Previous build
│
├── SOURCE
│   ├── main.cpp                # 20,000+ lines (monolith)
│   ├── main.cu                 # CUDA kernels
│   ├── compute_shader.hlsl     # D3D9 compute
│   └── PrimeOne.cbp            # Code::Blocks project
│
├── LIBRARIES
│   ├── cppcodec/               # Base64
│   ├── curl/                   # libcurl (HTTP)
│   │   ├── include/
│   │   ├── lib/libcurl.a
│   │   └── bin/*.dll
│   ├── libssh/                 # SSH/SFTP
│   │   ├── include/
│   │   └── lib/x64/*.lib, *.dll
│   ├── libminiupnpc/           # UPnP
│   └── jsoncpp/                # JSON
│
├── CUDA / DIRECTX
│   ├── cudart64_110.dll
│   ├── cudart64_12.dll
│   ├── cuda_runtime.h
│   ├── cuda_runtime_api.h
│   ├── d3d9.dll
│   └── compute_shader.hlsl
│
├── BATCH AUTOMATION
│   ├── primeone8host - 54767.bat
│   ├── primeone9guestsShow - 54767.bat
│   ├── verifyupdater.bat
│   ├── age.bat
│   ├── checkversion.bat
│   ├── setversion.bat
│   ├── clean.bat
│   └── cleanLocal.bat
│
├── STATE
│   ├── primebook.bin           # Serialized computation
│   ├── primebook.index         # Prime index cache
│   ├── PrimeOneUpdater.zip     # Update package
│   └── version.res             # Version resource
│
├── WINE PREFIX (/workspace/app/.wine_primeone/)
│   └── drive_c/PrimeOne/       # Full copy with stubs
│
└── DOCUMENTATION (/workspace/app/lol.dance/user_manual/)
    ├── 00_MASTER_DIRECTION.md
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
    └── 15_MASTER_COMPENDIUM.md  ← THIS FILE
```

---

## 🎓 LEARNING PATH

### Beginner (1 hour)
1. Read **00_MASTER_DIRECTION** - Executive summary
2. Run **Quick Start** - Single machine interactive
3. Explore **Menu System** - Press keys, observe dashboard

### Operator (2 hours)
1. Read **01_COMMAND_LINE_INTERFACE** - Batch automation
2. Read **08_BATCH_AUTOMATION_DEPLOYMENT** - Cluster deploy
3. Practice **Host/Guest** - Two machines or VMs
4. Read **14_TROUBLESHOOTING_DIAGNOSTICS** - Common fixes

### Developer (4+ hours)
1. Read **03_PRIME_TILE_COMPUTATION_ENGINE** - Core math
2. Read **04_NETWORK_CONDUIT_SYSTEM** - Distributed protocol
3. Read **05_GPU_CUDA_ACCELERATION** - GPU integration
4. Read **11_PRIME_ALGORITHMS_DEEP_DIVE** - Mathematical depth
5. Read **12_DISTRIBUTED_CONSENSUS_VERIFICATION** - Security model
6. Attempt **Native Build** - Fix compilation errors

### Architect (Ongoing)
1. Read **All Documents** - Complete system view
2. Design **Refactoring** - Modular architecture
3. Plan **Cross-Platform** - Abstraction layers
4. Implement **Security** - TLS, auth, audit
5. Build **Observability** - Metrics, tracing, dashboards

---

## 🔮 FUTURE ROADMAP (Integrated)

### Phase 1: Stabilization (Months 1-2)
- [ ] Fix all compilation errors (std::byte, pow, headers)
- [ ] Implement missing return statements
- [ ] Add destructors for memory safety
- [ ] Enable automated testing (CI)

### Phase 2: Modularization (Months 3-4)
- [ ] Split `main.cpp` into 10+ modules
- [ ] Create `PrimeTileEngine`, `ConduitNetwork`, `ConfigManager` classes
- [ ] Implement `IStorageBackend` for book persistence
- [ ] Add configuration file support (primeone.conf)

### Phase 3: Cross-Platform (Months 5-6)
- [ ] Abstract Windows APIs (`IConsole`, `INetwork`, `ISystemInfo`)
- [ ] Implement Linux backends (epoll, termios, /proc)
- [ ] CMake build system
- [ ] Docker images (wine + native)

### Phase 4: Security & Consensus (Months 7-8)
- [ ] TLS via libssh for all network traffic
- [ ] Host/Guest certificate authentication
- [ ] Explicit verification with audit log
- [ ] Reputation system for guests
- [ ] Byzantine fault tolerance

### Phase 5: Scale & Intelligence (Months 9-12)
- [ ] Multi-host federation (Raft consensus)
- [ ] WebSocket dashboard + REST API
- [ ] Prometheus metrics + Grafana dashboards
- [ ] Prime certificate generation (Pratt proofs)
- [ ] ZK-SNARK verification (privacy-preserving)
- [ ] Kubernetes operator for cluster management

---

## 📞 SUPPORT & ESCALATION

### Self-Service
1. **Start Here**: This Compendium (Document 15)
2. **Deep Dive**: Feature Documents 01-14
3. **Quick Fixes**: Document 14 (Troubleshooting)
4. **Source Truth**: `main.cpp` and GearSlice analysis

### Debugging Priority
```
1. Compilation → Check Document 14, Section 2
2. Runtime Crash → Check Document 14, Section 3
3. Network → Check Document 04, Document 14 Section 3.2
4. Performance → Check Document 11, Document 05
5. Update → Check Document 06, Document 14 Section 4.2
```

### Known Working Configuration
```
OS: Windows 10/11 x64 or Linux (Wine 10+)
CPU: 4+ cores (8+ recommended)
RAM: 8GB+ (16GB for large grids)
GPU: NVIDIA CUDA 11+ (optional but recommended)
Network: 1Gbps LAN, port 54767 open
Build: Code::Blocks + MinGW-w64 or Visual Studio 2022
Run: PrimeOne3236.exe (console) or PrimeOne.exe (GUI)
```

---

## 📝 CHANGELOG (This Manual)

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2025-07-18 | Initial complete manual from 1,623 spreadsheet analysis |

---

## 🏁 CONCLUSION

PrimeOne represents a **unique computational system** combining:
- **Novel mathematics** (tile-based prime walks)
- **Distributed systems** (host/guest consensus)
- **GPU acceleration** (CUDA + D3D9)
- **Self-updating deployment** (ZIP over TCP)
- **Rich diagnostics** (WMI, handles, network)

**Current State**: Functionally complete on Windows, buildable with effort on Linux via Wine. The 15-document manual provides complete operational and technical coverage.

**Next Steps for Production**:
1. Fix compilation blockers (Document 14)
2. Implement security (TLS, auth, verification)
3. Modularize codebase (Documents 03, 04, 13)
4. Add observability (metrics, logging, dashboards)
5. Automate deployment (CI/CD, containerization)

---

*End of Master Compendium*  
*All 15 documents complete - Total: ~7,000+ lines of integrated documentation*  
*Generated from 1,623 spreadsheets → 20,000+ lines C++ → Comprehensive manual*