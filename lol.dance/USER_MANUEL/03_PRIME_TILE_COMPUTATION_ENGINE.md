# PrimeOne - Feature Document 03: Prime Tile Computation Engine
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines ~1900-8500 (primeTileClass)  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Prime Tile Computation Engine (`primeTileClass`) is the mathematical core of PrimeOne. It implements a novel **tile-based prime number generation and verification algorithm** using 128-bit integer arithmetic (`__int128`) and byte-level tile manipulation (`std::byte`). The engine supports multiple walk algorithms, distributed computation, and persistent state management.

### Design Philosophy
- **Infinite precision** - `__int128` for primes beyond 64-bit range
- **Tile abstraction** - Primes organized as 2D grid "tiles" for parallelization
- **Walk algorithms** - Multiple traversal patterns (forward, reverse, moon, sun)
- **Distributed ready** - Stateless tile operations enable host/guest splitting
- **Persistence** - Book/Archive serialization for checkpoint/restart

---

## 2. CLASS ARCHITECTURE

### 2.1 Class Definition (Approximate Structure)
```cpp
class primeTileClass {
private:
    // Core state
    __int128 singers = 0;              // Worker thread count
    __int128 indexTiles = 0;           // Current tile index
    __int128 perThreadSlices = 0;      // Work slices per thread
    __int128 primeIndex = 0;           // Prime array index
    __int128* primeIndex;              // Dynamic prime array
    __int128 grid = 0;                 // Grid dimension (power of 2)
    __int128 infiniteWalk = 0;         // Continuous walk position
    __int128 total = 0;                // Total primes found
    
    // Buffers
    byte* returnTile = nullptr;        // Current tile buffer
    byte* primeFindsArray = nullptr;   // Found primes buffer
    
    // Configuration
    bool singleCore = false;
    string computeMethod = "Gear";
    
public:
    // Constructor
    primeTileClass(__int128 powerOfIN, __int128 singersIN, 
                   __int128 indexTilesIN, __int128 primeIndexIN,
                   __int128* primeIndexPtr, __int128 perThreadSlicesIN,
                   __int128 infiniteWalkIN);
    
    // Core algorithms
    __int128 nextWalkPrime(__int128);
    __int128 moonWalkPrime(__int128);
    void etchTile(byte);
    void etchFeast(byte);
    bool verifyPrime(__int128);
    
    // Distributed computation
    void librarianDancer(__int128, __int128, __int128, int, byte*);
    vector<byte> ptv_primeBookAuthor(__int128, int, int, int);
    
    // State management
    void initiateBreeze();
    void testBook();
    void conductor(...);
    
    // Getters
    __int128 getInfiniteWalk() { return infiniteWalk; }
    void advanceInfiniteWalk(__int128 factor) { 
        infiniteWalk += pow(2, factor); 
    }
};
```

---

## 3. DATA TYPES & CONSTANTS

### 3.1 Primary Types
| Type | Definition | Purpose |
|------|------------|---------|
| `__int128` | MSVC/GCC 128-bit signed integer | Prime values, indices, counters |
| `byte` | `typedef std::byte byte;` | Raw tile data (8-bit) |
| `vector<byte>` | `std::vector<std::byte>` | Dynamic tile/prime buffers |

### 3.2 Key Constants (from code)
```cpp
const int arrayGrid = static_cast<int>(std::pow(2, 20)); // 1,048,576
const int singers = 16; // Default thread count
__int128 grid = pow(2, powerOf); // Grid size = 2^powerOf
```

### 3.3 Magic Numbers Observed
| Value | Context |
|-------|---------|
| `228` | Largest Difference (dashboard) |
| `5678` | Default conduit port |
| `54767` | Batch file host port |
| `55555` | Dashboard display port |
| `3242` | Build count |
| `300` | Network peers (dashboard) |
| `16` | Default singers/threads |

---

## 4. CORE ALGORITHMS

### 4.1 nextWalkPrime() - Forward Prime Walk
**Location:** Lines ~4610-4660  
**Purpose:** Find next prime in forward direction

```cpp
__int128 primeTileClass::nextWalkPrime(__int128 input) {
    __int128 myPrimeFindsLocal = 0;
    __int128 primeDifference = 0;
    __int128 primeBuild = 0;
    __int128 myPreviousPrime = 0;
    bool dance = true;
    bool findPrevious = true;
    
    // Algorithm: Iterative prime search with gap analysis
    while (dance) {
        // ... prime verification logic ...
        // Uses verifyPrime() internally
        // Tracks primeDifference (gap), primeBuild (accumulator)
        // Updates myPreviousPrime for moonWalk reverse lookup
    }
    // WARNING: Missing return statement (line 4658)
}
```

**Issues:**
- Missing return statement (compiler warning)
- Unused variables: `myPrimeFindsLocal`, `primeDifference`, `primeBuild`, `myPreviousPrime`, `dance`, `findPrevious`
- `pow(2, factor)` ambiguity with `__int128`

### 4.2 moonWalkPrime() - Reverse Prime Walk
**Location:** Lines ~4930-4975  
**Purpose:** Find previous prime (reverse traversal)

```cpp
__int128 primeTileClass::moonWalkPrime(__int128 input) {
    __int128 myPrimeFindsLocal = 0;
    __int128 countThis = 0;
    __int128 primeDifference = 0;
    __int128 primeBuild = 0;
    __int128 intTail = 0;
    __int128 myPreviousPrime = 0;
    __int128 moonWalker = 0;
    __int128 slice = 0;
    __int128 spaceBuffer = 0;
    bool dance = true;
    bool findPrevious = true;
    
    // Reverse walk algorithm
    while (dance) {
        // ... reverse prime search ...
    }
    // WARNING: Missing return statement (line 4975)
}
```

**Issues:** Same as nextWalkPrime - missing return, unused variables, pow ambiguity.

### 4.3 etchTile() / etchFeast() - Tile Data Inscription
**Location:** Lines ~6130-6160, ~8480

```cpp
void primeTileClass::etchTile(byte data) {
    etchWalkSum += data;  // ERROR: __int128 += std::byte
    // ...
    etchWalkSum = data;   // ERROR: __int128 = std::byte
}

void primeTileClass::etchFeast(byte data) {
    etchTile(data);
    total++;
}
```

**Type Errors:**
- `std::byte` cannot be added to `__int128` directly
- `std::byte` cannot be assigned to `__int128`
- Requires explicit cast: `static_cast<__int128>(data)`

### 4.4 verifyPrime() - Primality Testing
**Location:** Lines ~6720-6800

```cpp
bool primeTileClass::verifyPrime(__int128 candidate) {
    __int128 isPrime = false;
    __int128 myTileWalk = 0;
    __int128 myBreezeWalk = 0;
    __int128 primeBuild = 0;
    
    // ... verification logic ...
    primeBuild += breeze() * 2; // ERROR: std::byte * int
    
    return static_cast<bool>(isPrime);
}
```

**Issues:**
- `breeze()` returns `std::byte`, multiplied by `int`
- `std::byte` arithmetic not defined in C++17

### 4.5 librarianDancer() - Multi-threaded Distributed Computation
**Location:** Lines ~8040-8250  
**Purpose:** Coordinate multi-threaded prime computation with tile distribution

```cpp
void primeTileClass::librarianDancer(
    __int128 powerOf, __int128 singersIN, __int128 indexTilesIN,
    int conduit, byte* primeCatch) 
{
    // Thread management
    __int128 myPrimeFindsLocalStep = 0;
    __int128 countThis = 0;
    __int128 return16b = 0;
    __int128 spaceBuffer = 0;
    __int128 d3 = 0; int dice = 0;
    __int128 startTime = 0;
    int myBreezeWalk = 0;
    int itWorks = 0;
    int jump = 6;
    int TIlePlacement = 0;
    bool foreverRead = true;
    
    // Dynamic 2D tile array
    int myTargetTile = 0;
    int myMinimumTileCount = 0;
    int gridInt = 0;
    int arrayGrid = 0;
    
    byte* myTargetTile = new byte[gridInt];  // ERROR: byte* = new byte[]
    byte** myTiles = new uint8_t*[myMinimumTileCount]; // ERROR: type mismatch
    for (int i = 0; i < myMinimumTileCount; ++i) {
        myTiles[i] = new uint8_t[arrayGrid]; // ERROR: uint8_t* → byte*
    }
    
    // Computation loop
    while (foreverRead) {
        // ... distributed work distribution ...
        primeBuild += return16 * 2; // ERROR: std::byte * int
        return16 = myTiles[myThreadTileWalk][myThreadBreezeWalk] * 2; // ERROR
        primeBuild += return16; // ERROR: __int128 += std::byte
        primeFindsArray[myPrimeFindsLocal] = primeDifference; // ERROR: __int128 → byte
    }
}
```

**Critical Issues:**
1. `byte** myTiles = new uint8_t*[...]` - Type mismatch (`uint8_t**` vs `byte**`)
2. `myTiles[i] = new uint8_t[...]` - Assignment mismatch
3. `std::byte` arithmetic throughout
4. `primeFindsArray` indexed with `__int128` but stores `byte`
5. Memory leaks (no corresponding `delete[]`)
6. Unused variables: `myPrimeFindsLocalStep`, `countThis`, `return16b`, `spaceBuffer`, `d3`, `dice`, `startTime`, `myBreezeWalk`, `itWorks`, `jump`, `TIlePlacement`, `foreverRead`, `myTargetTile`

### 4.6 ptv_primeBookAuthor() - Prime Book Serialization
**Location:** Lines ~7470-7550

```cpp
vector<byte> primeTileClass::ptv_primeBookAuthor(
    __int128 primeDifference, int singerCount, int gridSize, int tileCount) 
{
    vector<byte> wolfCatch;
    wolfCatch.push_back(primeDifference); // ERROR: __int128 → byte
    // ... serialization logic ...
    return wolfCatch;
}
```

**Issue:** `vector<byte>::push_back()` expects `byte`, receives `__int128`.

### 4.7 initiateBreeze() - Thread Initialization
**Location:** Lines ~7030-7100

```cpp
void primeTileClass::initiateBreeze() {
    byte* threadBreezeWalk = new byte[singers]; // singers is __int128
    // ... thread setup ...
    // Missing delete[] threadBreezeWalk
}
```

### 4.8 testBook() - Validation Routine
**Location:** Lines ~7850-7900

```cpp
void primeTileClass::testBook() {
    __int128 singersPlus = singers + 1;
    primeBuild += breeze() * 2; // ERROR: std::byte * int
    // ... validation logic ...
}
```

### 4.9 Constructor (Lines ~8350-8390)
```cpp
primeTileClass(__int128 powerOfIN, __int128 singersIN, 
               __int128 indexTilesIN, __int128 primeIndexIN,
               __int128* primeIndexPtr, __int128 perThreadSlicesIN,
               __int128 infiniteWalkIN) {
    // Member initialization with reorder warnings:
    // perThreadSlices initialized after singers
    // primeIndex initialized after indexTiles
    
    grid = pow(2, powerOf); // AMBIGUOUS: pow(int, __int128)
    const int arrayGrid = static_cast<int>(std::pow(2, 20));
    __int128 tileLay = 0;
}
```

---

## 5. TYPE SYSTEM ISSUES (CRITICAL)

### 5.1 std::byte Arithmetic Limitations
`std::byte` (C++17) is a **type-safe byte** with **no arithmetic operators**:
- ❌ `byte + byte`
- ❌ `byte + int`
- ❌ `byte * int`
- ❌ `byte = int`
- ❌ `int += byte`
- ✅ `byte | byte` (bitwise)
- ✅ `byte & byte`
- ✅ `byte ^ byte`
- ✅ `~byte`
- ✅ `byte << n`, `byte >> n`

### 5.2 Required Fixes
```cpp
// Current (broken):
primeBuild += breeze() * 2;
etchWalkSum += data;
etchWalkSum = data;
primeFindsArray[idx] = primeDifference;
wolfCatch.push_back(primeDifference);

// Fixed:
primeBuild += static_cast<__int128>(breeze()) * 2;
etchWalkSum += static_cast<__int128>(data);
etchWalkSum = static_cast<__int128>(data);
primeFindsArray[idx] = static_cast<byte>(primeDifference & 0xFF);
wolfCatch.push_back(static_cast<byte>(primeDifference & 0xFF));
```

### 5.3 __int128 Portability
- **MSVC**: `__int128` supported as extension
- **GCC/Clang**: `__int128` supported on 64-bit targets
- **Standard C++**: No standard 128-bit type (C++23 may add)
- **Alternative**: `boost::multiprecision::cpp_int` or custom struct

### 5.4 pow() Ambiguity
```cpp
grid = pow(2, powerOf); // powerOf is __int128
```
**Candidates:**
- `double pow(double, double)`
- `float pow(float, float)`
- `long double pow(long double, long double)`
- `std::pow` overloads

**Fix:** Cast to double or implement integer power:
```cpp
grid = static_cast<__int128>(std::pow(2.0, static_cast<double>(powerOf)));
// Or:
__int128 ipow(__int128 base, __int128 exp) {
    __int128 result = 1;
    while (exp) { if (exp & 1) result *= base; base *= base; exp >>= 1; }
    return result;
}
grid = ipow(2, powerOf);
```

---

## 6. MEMORY MANAGEMENT

### 6.1 Dynamic Allocations
| Allocation | Location | Leak Risk |
|------------|----------|-----------|
| `primeIndex` array | Constructor | High - no destructor |
| `returnTile` buffer | librarianDancer | High - no delete |
| `primeFindsArray` | librarianDancer | High - no delete |
| `threadBreezeWalk` | initiateBreeze | High - no delete |
| `myTiles` 2D array | librarianDancer | High - no delete |
| `myTargetTile` | librarianDancer | High - no delete |

### 6.2 Required Destructor
```cpp
~primeTileClass() {
    delete[] primeIndex;
    delete[] returnTile;
    delete[] primeFindsArray;
    // For 2D arrays:
    if (myTiles) {
        for (int i = 0; i < myMinimumTileCount; ++i) {
            delete[] myTiles[i];
        }
        delete[] myTiles;
    }
    delete[] myTargetTile;
    delete[] threadBreezeWalk;
}
```

### 6.3 Rule of Five
Class needs:
- Destructor (above)
- Copy constructor (deep copy)
- Copy assignment operator
- Move constructor
- Move assignment operator

---

## 7. THREADING MODEL

### 7.1 Thread Creation (initiateBreeze)
```cpp
byte* threadBreezeWalk = new byte[singers];
// Spawns 'singers' threads
// Each thread processes tile slices
```

### 7.2 Work Distribution (librarianDancer)
- Grid divided into `perThreadSlices` per worker
- Each thread gets `myMinimumTileCount` tiles
- Results aggregated into `primeFindsArray`

### 7.3 Synchronization
- **No explicit mutexes** visible in excerpts
- **Atomic operations** not used
- **Race conditions** likely on shared arrays
- **ConduitClass** uses `std::async` for network I/O

---

## 8. NETWORK INTEGRATION

### 8.1 Tile Serialization for Network
```cpp
// In conduit_win_host/guest:
vector<byte> primeCatch; // Received tile data
// Sent via TCP sockets
// Serialized as raw byte stream
```

### 8.2 Host Work Distribution
```cpp
// Host in conduit_win_hosts:
conduit_weaver(uniqueIdGlobal, createHost, weaverBeginData, hostIp, hostPort);
// Distributes tile ranges to guests
// Collects verified primes
```

### 8.3 Guest Computation
```cpp
// Guest in conduit_win_guests:
conduit_win_guests(weaverDataGear, uniqueId, ..., primeCatch, hostIp);
// Receives tile range
// Computes primes via primeTileClass
// Returns results to host
```

---

## 9. PERSISTENCE (BOOK/ARCHIVE)

### 9.1 Prime Book Format
```cpp
vector<byte> ptv_primeBookAuthor(__int128 primeDifference, 
                                   int singerCount, int gridSize, int tileCount);
// Returns serialized tile data
// Saved as PrimeOneUpdater.zip via realm_win_archive()
```

### 9.2 Archive Structure (from batch files)
- `PrimeOneUpdater.zip` - Contains prime book state
- `primebookindex.txt` - Index file
- Sent via `realm_win_updater()` over network

### 9.3 Roll Mechanism
```cpp
realm_win_roll(); // Install update + reload
// Called from menu option 5/6
// Downloads ZIP, extracts, restarts
```

---

## 10. GPU/CUDA INTEGRATION

### 10.1 CUDA Headers Present
```cpp
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <cuda_device_runtime_api.h>
#include <vector_types.h>
#include <driver_types.h>
#include <surface_types.h>
#include <texture_types.h>
#include <host_config.h>
#include <builtin_types.h>
#include <device_types.h>
```

### 10.2 CUDA Files in Project
- `main.cu` - CUDA kernel source
- `cudart64_110.dll`, `cudart64_12.dll` - Runtime DLLs
- `compute_shader.hlsl` - HLSL compute shader (DirectX)

### 10.3 Integration Points
- `computeMethod` parameter selects backend
- `PU=Yes/No` menu toggles GPU
- `-f quickPrime` flag may enable GPU path
- Actual kernel launches not visible in excerpts

---

## 11. PERFORMANCE CHARACTERISTICS

### 11.1 Computational Complexity
- **Prime verification**: O(√n) trial division (assumed)
- **Tile generation**: O(grid_size × singers)
- **Memory**: O(grid_size) for tile buffers
- **Network**: O(primes_found) bandwidth

### 11.2 Scalability Factors
| Factor | Impact |
|--------|--------|
| `singers` (threads) | Linear speedup to CPU cores |
| `grid` (2^powerOf) | Exponential memory growth |
| Network latency | Limits guest synchronization |
| `__int128` ops | 2-4x slower than 64-bit |

### 11.3 Observed Limits
- `arrayGrid = 2^20 = 1,048,576` tiles max
- `singers = 16` default threads
- `infiniteWalk` unbounded (128-bit)

---

## 12. MATHEMATICAL FOUNDATIONS

### 12.1 Tile Concept
Primes mapped to 2D grid coordinates:
```
Tile(x, y) → Prime candidate at position (x, y)
Grid = 2^powerOf × 2^powerOf
Total tiles = 2^(2×powerOf)
```

### 12.2 Walk Algorithms
- **nextWalk**: Linear scan forward (x++, y++)
- **moonWalk**: Reverse scan (x--, y--)
- **breeze**: Per-thread slice traversal
- **librarianDancer**: Coordinated multi-thread sweep

### 12.3 Verification Method
Appears to use **trial division** with known primes:
```cpp
// In verifyPrime:
for each known_prime in primeIndex:
    if candidate % known_prime == 0: return false
return true
```

### 12.4 Gap Analysis
Tracks `primeDifference` (gap between consecutive primes):
- Used for statistical analysis
- Stored in `primeFindsArray`
- Serialized in prime book

---

## 13. CONFIGURATION PARAMETERS

| Parameter | Type | Default | Source |
|-----------|------|---------|--------|
| `powerOf` | `__int128` | From constructor | Menu/args |
| `singers` | `__int128` | 16 | Menu 's' |
| `indexTiles` | `__int128` | 0 | State |
| `primeIndex` | `__int128*` | Allocated | Constructor |
| `perThreadSlices` | `__int128` | Computed | Constructor |
| `infiniteWalk` | `__int128` | 0 | State |
| `singleCore` | `bool` | false | `-c 1` / menu |
| `computeMethod` | `string` | "Gear" | `-x` / menu |
| `grid` | `__int128` | 2^powerOf | Computed |

---

## 14. INTEGRATION WITH MAIN APPLICATION

### 14.1 Instantiation (from main/librarian)
```cpp
primeTileClass PrimeOne(
    powerOf, singers, indexTiles, primeIndex,
    primeIndexPtr, perThreadSlices, infiniteWalk
);
```

### 14.2 Conductor Call (Commented)
```cpp
// PrimeOne.conductor(singers, singleCore, computeMethod, 
//                    perThreadSlices, mrTsaysRead, primerBase,
//                    gitState, uniqueIdGlobal, createHost,
//                    weaverBeginData, hostIp, hostPort);
```

### 14.3 Network Handoff
```cpp
conduitClass winTelConduits(5678);
winTelConduits.weaverBegin(uniqueIdGlobal, createHost, 
                           weaverBeginData, hostIp, hostPort);
// Inside weaverBegin → conduit_weaver → 
// conduit_win_host/guest → primeTileClass methods
```

---

## 15. ERROR HANDLING & ROBUSTNESS

### 15.1 Current State
- **No exception handling** in primeTileClass
- **No bounds checking** on array accesses
- **No null checks** on pointers
- **Assertions** not used
- **Return value validation** missing

### 15.2 Required Hardening
```cpp
// Example: Safe array access
byte primeTileClass::getTile(size_t index) {
    if (index >= static_cast<size_t>(grid)) {
        throw std::out_of_range("Tile index out of bounds");
    }
    return returnTile[index];
}

// Example: Safe allocation
bool primeTileClass::allocateBuffers() {
    try {
        primeIndex = new __int128[grid];
        returnTile = new byte[grid];
        primeFindsArray = new byte[grid];
        return true;
    } catch (std::bad_alloc&) {
        return false;
    }
}
```

---

## 16. TESTING & VALIDATION

### 16.1 Unit Test Points
| Method | Test Cases |
|--------|------------|
| `nextWalkPrime` | Known prime sequences, edge cases (2, 3, large) |
| `moonWalkPrime` | Reverse consistency with nextWalk |
| `verifyPrime` | Primes, composites, Carmichael numbers |
| `etchTile/etchFeast` | Byte serialization round-trip |
| `ptv_primeBookAuthor` | Serialization/deserialization |
| `librarianDancer` | Thread count scaling, result consistency |

### 16.2 Integration Tests
- Host/Guest prime consistency
- Network interrupt/resume
- Archive save/load cycle
- GPU vs CPU result matching

---

## 17. KNOWN BUGS & TECHNICAL DEBT

### 17.1 Compilation Errors (Blocking)
1. `std::byte` arithmetic (10+ locations)
2. `pow(int, __int128)` ambiguity (3 locations)
3. `vector<byte>::push_back(__int128)` (1 location)
4. `uint8_t**` → `byte**` conversion (2 locations)
5. `uint8_t*` → `byte*` assignment (2 locations)
6. Missing return statements (2 functions)
7. Unused variable warnings (30+)

### 17.2 Logic Bugs (Potential)
1. `optionComputeInput = "Gear"` hardcoded override
2. Dashboard values hardcoded, not dynamic
3. Memory leaks (no destructor)
4. Race conditions in multi-threaded access
4. Buffer overflows (no bounds checking)

### 17.3 Architecture Debt
- Monolithic `main.cpp` (20,000+ lines)
- Global state variables (`uniqueIdGlobal`, `globalRemotePortString`, etc.)
- Mixed concerns (UI, network, math, Windows API)
- No separation of interface/implementation

---

## 18. REFACTORING ROADMAP

### 18.1 Phase 1: Fix Compilation (Critical)
- [ ] Replace all `std::byte` arithmetic with explicit casts
- [ ] Implement `ipow(__int128, __int128)` for integer powers
- [ ] Fix `vector<byte>` serialization with proper casting
- [ ] Fix `uint8_t` ↔ `byte` pointer conversions
- [ ] Add missing return statements
- [ ] Remove unused variables or mark `[[maybe_unused]]`

### 18.2 Phase 2: Memory Safety (High)
- [ ] Implement destructor with proper cleanup
- [ ] Implement Rule of Five
- [ ] Replace raw pointers with `std::vector`/`std::unique_ptr`
- [ ] Add bounds checking with assertions

### 18.3 Phase 3: Architecture (Medium)
- [ ] Split `primeTileClass` into:
  - `PrimeTileMath` - Pure algorithms
  - `PrimeTileState` - Data management
  - `PrimeTileSerializer` - Book/Archive I/O
  - `PrimeTileDistributed` - Network coordination
- [ ] Extract `ConduitClass` to separate files
- [ ] Create interface abstractions for compute backends

### 18.4 Phase 4: Portability (Medium)
- [ ] Replace `__int128` with `boost::multiprecision::cpp_int`
- [ ] Abstract Windows APIs behind platform layer
- [ ] Replace `system("cls")` with cross-platform clear
- [ ] Use CMake instead of Code::Blocks project

### 18.5 Phase 5: Features (Low)
- [ ] Dynamic dashboard with real values
- [ ] GPU kernel integration
- [ ] Checkpoint/restart robustness
- [ ] Web dashboard API

---

## 19. CROSS-REFERENCE: SOURCE LOCATIONS

| Feature | Line Range | Function |
|---------|------------|----------|
| Class definition | ~1900-2000 | Member variables |
| Constructor | ~8350-8390 | primeTileClass() |
| nextWalkPrime | ~4610-4660 | Forward walk |
| moonWalkPrime | ~4930-4975 | Reverse walk |
| etchTile | ~6130-6160 | Tile inscribe |
| etchFeast | ~8480 | Tile inscribe + count |
| verifyPrime | ~6720-6800 | Primality test |
| librarianDancer | ~8040-8250 | Distributed compute |
| ptv_primeBookAuthor | ~7470-7550 | Serialization |
| initiateBreeze | ~7030-7100 | Thread init |
| testBook | ~7850-7900 | Validation |
| conductor | ~10680 | Orchestration |
| getInfiniteWalk | ~8415 | Getter |
| advanceInfiniteWalk | ~8415 | Walk control |

---

## 20. COMPLETE ALGORITHM PSEUDOCODE

### 20.1 nextWalkPrime (Corrected)
```
function nextWalkPrime(start: i128) -> i128:
    current ← start
    previous ← 0
    while true:
        if verifyPrime(current):
            gap ← current - previous
            recordGap(gap)
            previous ← current
            return current
        current ← current + 1
```

### 20.2 verifyPrime (Corrected)
```
function verifyPrime(candidate: i128) -> bool:
    if candidate < 2: return false
    if candidate == 2: return true
    if candidate % 2 == 0: return false
    
    limit ← isqrt(candidate)
    for p in primeIndex where p ≤ limit:
        if candidate % p == 0:
            return false
    return true
```

### 20.3 librarianDancer (Corrected)
```
function librarianDancer(power, singers, tiles, conduit, buffer):
    grid ← 2^power
    slicesPerThread ← grid / singers
    
    parallel for each thread t in 0..singers-1:
        start ← t * slicesPerThread
        end ← min(start + slicesPerThread, grid)
        
        for tile in start..end:
            prime ← findPrimeInTile(tile)
            if prime ≠ null:
                atomic_append(buffer, prime)
                atomic_increment(totalPrimes)
    
    wait for all threads
    return buffer
```

---

*End of Feature Document 03: Prime Tile Computation Engine*  
*Next: 04_NETWORK_CONDUIT_SYSTEM.md*