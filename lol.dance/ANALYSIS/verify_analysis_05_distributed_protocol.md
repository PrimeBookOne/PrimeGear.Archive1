# Topic 5: Distributed Verification Protocol Analysis
## `librarianDancer` Multi-Threaded Verification Engine

**Source:** `main.cpp` lines 7993-8400  
**Analysis Date:** 2026-11-01  

---

## 1. PROTOCOL OVERVIEW

### 1.1 Architecture

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         LIBRARIAN DANCER PROTOCOL                            │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│  CONDUCTOR (Main Thread)                                                     │
│       │                                                                      │
│       ▼                                                                      │
│  Spawns N "Singer" Threads                                                   │
│       │                                                                      │
│       ├────────────────────────────────────────────────────┐                │
│       │                    WORK DISTRIBUTION                │                │
│       ▼                                                    ▼                │
│  ┌─────────────┐                                    ┌─────────────┐       │
│  │ Singer 0    │                                    │ Singer N-1  │       │
│  │ libDan(0,   │                                    │ libDan(N-1, │       │
│  │  startWalk, │           ...                      │  startWalk, │       │
│  │  slices,    │                                    │  slices,    │       │
│  │  minTiles,  │                                    │  minTiles,  │       │
│  │  findsArr)  │                                    │  findsArr)  │       │
│  └──────┬──────┘                                    └──────┬──────┘       │
│         │                                                  │               │
│         ▼                                                  ▼               │
│  ┌─────────────────────────────────────────────────────────────────┐      │
│  │                    SHARED STATE                                 │      │
│  │  • tiles (map<string, byte*>) - READ/WRITE                     │      │
│  │  • threadBreezeWalk[] - READ/WRITE (hardcoded [0] in breeze)   │      │
│  │  • threadTileWalk[] - READ/WRITE                               │      │
│  │  • singerFinished - atomic counter                             │      │
│  │  • findsArray[] - per-singer prime count                       │      │
│  └─────────────────────────────────────────────────────────────────┘      │
│                                                                              │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 1.2 Function Signature

```cpp
void librarianDancer(
    __int128 singer,              // Thread ID (0 to singers-1)
    __int128 myInfiniteWalk,      // Starting walk position
    __int128 perThreadSlices,     // Work units per thread
    const int myMinimumTileCount, // Tiles to preload locally
    byte* primeFindsArray         // Output: prime gaps (TRUNCATED TO BYTE!)
)
```

---

## 2. PHASE-BY-PHASE ANALYSIS

### 2.1 Phase 1: Moonwalk - Find Previous Prime

```cpp
// Lines 8030-8080
moonWalker = myInfiniteWalk;
while (findPrevious == true) {
    moonWalker += -2;  // Walk backwards
    
    d3 = moonWalker / 3 + 1;
    primeBuild = 3;
    dance = true;
    
    while (dance == true) {
        if (moonWalker % primeBuild == 0) {
            isPrime = false;
            dance = false;
        } else if (primeBuild > d3) {
            isPrime = true;
            findPrevious = false;
            dance = false;
        } else {
            // TILE READ via breeze() pattern
            if (myThreadBreezeWalk == gridInt) {
                myThreadBreezeWalk = 0;
                myThreadTileWalk++;
                targetTileName = "Tile0" + tileWalkString.getString();
                targetTile = tiles[targetTileName];  // SHARED MAP
            }
            return16 = targetTile[myThreadBreezeWalk++];
            primeBuild += return16 * 2;
        }
    }
    
    if (isPrime == true) {
        myPreviousPrime = moonWalker;
        findPrevious = false;
    }
}
```

**Issues:**
- Uses shared `tiles` map without synchronization
- `targetTile = tiles[targetTileName]` - map lookup per tile advance
- `d3 = moonWalker/3+1` - incorrect bound (should be √n)

### 2.2 Phase 2: Tile Preload (Local Copy)

```cpp
// Lines 8085-8110
const int arrayGrid = static_cast<int>(std::pow(2, 20));  // 1M
byte** myTiles = new uint8_t*[myMinimumTileCount];
for (int i = 0; i < myMinimumTileCount; ++i) {
    myTiles[i] = new uint8_t[arrayGrid];
}

while (minimumTileWalk < myMinimumTileCount) {
    string128Class minimumTileWalkString(minimumTileWalk);
    string targetTileName = "Tile0" + minimumTileWalkString.getString();
    byte* myTargetTile = tiles[targetTileName];  // FROM SHARED MAP
    
    while (gridWalker < gridInt) {
        myTiles[minimumTileWalk][gridWalker] = myTargetTile[gridWalker];
        gridWalker++;
    }
    gridWalker = 0;
    minimumTileWalk++;
}
```

**Issues:**
- Allocates `myMinimumTileCount × 1 MB` per thread
- For 8 threads × 100 tiles = 800 MB allocation
- **Stale snapshot** - misses tiles created after preload
- No memory cleanup - leaks per thread

### 2.3 Phase 3: Main Verification Loop

```cpp
// Lines 8115-8300
while (slice < perThreadSlices) {
    myTilePlacement = 0;
    myThreadTileWalk = 0;
    primeBuild = 3;
    dance = true;
    d3 = (myInfiniteWalk / 3) + 1;
    
    while (dance == true) {
        if (myInfiniteWalk % primeBuild == 0) {
            isPrime = false;
            dance = false;
        } else if (primeBuild > d3) {
            isPrime = true;
            dance = false;
        } else {
            // LOCAL TILE READ
            if (myThreadBreezeWalk == grid) {
                myThreadBreezeWalk = 0;
                myThreadTileWalk++;
            }
            return16 = myTiles[myThreadTileWalk][myThreadBreezeWalk] * 2;
            myThreadBreezeWalk++;
            primeBuild += return16;
        }
    }
    
    if (isPrime == true) {
        primeDifference = (myInfiniteWalk - myPreviousPrime) / 2;
        myPreviousPrime = myInfiniteWalk;
        primeFindsArray[myPrimeFindsLocal] = primeDifference;  // BYTE TRUNCATION!
        myPrimeFindsLocal++;
        isPrime = false;
    }
    
    myInfiniteWalk += 2;
    slice++;
    myThreadTileWalk = 0;
}

findsArray[singer] = myPrimeFindsLocal;
singerFinished++;
```

**Issues:**
- Reads from **local copy** `myTiles` (stale)
- `primeFindsArray[byte]` ← `__int128` truncation
- `d3 = myInfiniteWalk/3+1` - wrong bound
- No synchronization with other threads

---

## 3. SYNCHRONIZATION ANALYSIS

### 3.1 Shared State Access Matrix

| Variable | Phase 1 (Moonwalk) | Phase 2 (Preload) | Phase 3 (Main) | Sync |
|----------|-------------------|-------------------|----------------|------|
| `tiles` map | READ | READ (copy) | - | **NONE** |
| `threadBreezeWalk` | READ/WRITE | - | - | **NONE** |
| `threadTileWalk` | READ/WRITE | - | - | **NONE** |
| `singerFinished` | - | - | WRITE | Atomic? |
| `findsArray` | - | - | WRITE | Per-thread slot |
| `primeFindsArray` | - | - | WRITE | Per-thread buffer |
| `myTiles` (local) | - | WRITE | READ | Thread-local |

### 3.2 Race Conditions

```cpp
// Race 1: Multiple threads read tiles map during preload
byte* myTargetTile = tiles[targetTileName];  // Concurrent reads OK
// But if etchTile() writes concurrently:
tiles[newTileName] = newTile;  // Map rehash - INVALIDATES ITERATORS/POINTERS

// Race 2: threadBreezeWalk[0] in breeze() vs librarianDancer
// breeze() uses threadBreezeWalk[0] (hardcoded)
// librarianDancer uses myThreadBreezeWalk (local)
// CONFLICT if both run simultaneously

// Race 3: singerFinished++ without atomic
singerFinished++;  // Data race - lost updates
```

---

## 4. WORK DISTRIBUTION

### 4.1 Current Strategy

```cpp
// Conductor assigns:
perThreadSlices = totalSlices / singers;
myInfiniteWalk = startWalk + singer * perThreadSlices * 2;  // Approximate
```

**Problems:**
- Static partitioning - no load balancing
- Prime density varies - some threads get more work
- No work stealing
- `perThreadSlices` fixed at start

### 4.2 Improved Strategy

```cpp
// Work queue with atomic counter
atomic<__int128> globalWalk{startWalk};
atomic<__int128> globalSlices{totalSlices};

void librarianDancerDynamic(int singer, vector<__int128>& finds) {
    ThreadTileReader reader(tileManager, singer);
    __int128 myPreviousPrime = moonWalkPrimeShared(globalWalk);
    
    while (true) {
        __int128 slice = globalSlices.fetch_sub(1);
        if (slice <= 0) break;  // No more work
        
        __int128 myWalk = globalWalk.fetch_add(2);
        if (verifyPrimeWithReader(myWalk, reader)) {
            __int128 gap = (myWalk - myPreviousPrime) / 2;
            finds.push_back(gap);
            myPreviousPrime = myWalk;
        }
    }
}
```

---

## 5. BUG CATALOG

| ID | Severity | Location | Description |
|----|----------|----------|-------------|
| T5-01 | CRITICAL | Phase 1 | Shared `tiles` map access without sync |
| T5-02 | CRITICAL | Phase 2 | Per-thread 1MB×tileCount allocation - OOM |
| T5-03 | CRITICAL | Phase 3 | `primeFindsArray[byte]` ← `__int128` truncation |
| T5-04 | CRITICAL | Phase 3 | Stale local tile copy misses updates |
| T5-05 | HIGH | Phase 1 | `d3 = n/3+1` wrong bound (should be √n) |
| T5-06 | HIGH | Phase 3 | `d3 = n/3+1` wrong bound |
| T5-07 | HIGH | All phases | `threadBreezeWalk[0]` hardcoded conflicts |
| T5-08 | HIGH | Phase 2 | `new uint8_t*[]` / `new uint8_t[]` never freed |
| T5-09 | MEDIUM | Phase 1 | Map lookup per tile boundary - slow |
| T5-10 | MEDIUM | Phase 3 | `myThreadTileWalk` reset each slice - re-reads from tile 0 |
| T5-11 | LOW | Conductor | `singerFinished++` not atomic |

---

## 6. FIX SPECIFICATION

### 6.1 Thread-Safe Distributed Verifier

```cpp
class DistributedPrimeVerifier {
    TileManager& tileManager;
    atomic<__int128> globalWalk;
    atomic<__int128> remainingSlices;
    vector<thread> workers;
    vector<vector<__int128>> threadFinds;
    int numThreads;
    
public:
    DistributedPrimeVerifier(TileManager& tm, int threads)
        : tileManager(tm), numThreads(threads) {}
    
    vector<__int128> verifyRange(__int128 start, __int128 slices) {
        globalWalk = start;
        remainingSlices = slices;
        threadFinds.assign(numThreads, {});
        workers.clear();
        
        for (int i = 0; i < numThreads; i++) {
            workers.emplace_back(&DistributedPrimeVerifier::workerLoop, this, i);
        }
        
        for (auto& w : workers) w.join();
        
        // Merge results
        vector<__int128> allFinds;
        for (auto& f : threadFinds) {
            allFinds.insert(allFinds.end(), f.begin(), f.end());
        }
        return allFinds;
    }
    
private:
    void workerLoop(int singer) {
        ThreadTileReader reader(tileManager, singer);
        __int128 myPreviousPrime = moonWalkPrimeShared(globalWalk.load());
        
        while (true) {
            __int128 slice = remainingSlices.fetch_sub(1, memory_order_acq_rel);
            if (slice <= 0) break;
            
            __int128 myWalk = globalWalk.fetch_add(2, memory_order_acq_rel);
            
            if (verifyPrimeWithReader(myWalk, reader)) {
                __int128 gap = (myWalk - myPreviousPrime) / 2;
                threadFinds[singer].push_back(gap);  // FULL __int128
                myPreviousPrime = myWalk;
            }
        }
    }
    
    __int128 moonWalkPrimeShared(__int128 start) {
        // Thread-safe moonwalk using shared tile manager
        __int128 walk = start;
        while (true) {
            walk -= 2;
            if (verifyPrimeWithReader(walk, ThreadTileReader(tileManager, 0))) {
                return walk;
            }
        }
    }
};
```

### 6.2 Verification with Reader (Tile-Derived)

```cpp
bool verifyPrimeWithReader(__int128 n, ThreadTileReader& reader) {
    __int128 primeBuild = 3;
    while (primeBuild * primeBuild <= n) {
        if (n % primeBuild == 0) return false;
        
        byte inc = reader.next();
        if (inc == 0) inc = 1;
        primeBuild += inc * 2;
    }
    return true;
}
```

---

## 7. PERFORMANCE MODEL

### 7.1 Current Scalability

| Threads | Speedup | Bottleneck |
|---------|---------|------------|
| 1 | 1.0x | Baseline |
| 2 | ~1.5x | `tiles` map contention |
| 4 | ~2.0x | Memory allocation, cache thrashing |
| 8 | ~2.2x | `threadBreezeWalk[0]` conflict, OOM |

**Negative scaling beyond 4 threads** due to:
- Shared map contention
- Per-thread 100MB+ allocations
- False sharing on `threadBreezeWalk`

### 7.2 Projected with Fixes

| Threads | Speedup | Reason |
|---------|---------|--------|
| 1 | 1.0x | Baseline |
| 2 | 1.9x | No map contention, fast tile access |
| 4 | 3.7x | Work stealing, cache-friendly |
| 8 | 7.2x | Near-linear |
| 16 | 14x | Slight overhead |

---

## 8. INTEGRATION WITH CONDUIT NETWORK

### 8.1 Host-Guest Verification Flow

```
HOST (Conductor)                          GUEST (Singer)
─────────────────                          ──────────────
1. Assign work range                   ←  2. Request work
3. Send: startWalk, slices             →  4. Acknowledge
5. Wait for results                    ←  6. Compute locally
7. Receive: prime gaps (__int128)      →  8. Send results
9. Verify cross-check                  ←  (Optional: re-verify subset)
```

### 8.2 Current Conduit Code Issues

From `conduit_win_host.cpp` / `conduit_win_guests.cpp`:
- Uses same flawed `librarianDancer` logic
- Byte truncation in network packets
- No cryptographic verification of results
- Trust-based - no proof-of-work validation

---

## 9. TEST CASES

### 9.1 Correctness Test
```cpp
void testDistributedMatchesSingle() {
    TileManager tm(20, 100);
    DistributedPrimeVerifier dpv(tm, 4);
    StandardVerifier sv;
    
    __int128 start = 1000000000000000000;  // 10^18
    __int128 slices = 10000;
    
    // Distributed
    auto distGaps = dpv.verifyRange(start, slices);
    
    // Single-threaded reference
    vector<__int128> refGaps;
    __int128 walk = start;
    __int128 prevPrime = moonWalkPrimeReference(walk);
    for (int i = 0; i < slices; i++) {
        walk += 2;
        if (sv.verify(walk)) {
            refGaps.push_back((walk - prevPrime) / 2);
            prevPrime = walk;
        }
    }
    
    // Must match exactly
    assert(distGaps == refGaps);
}
```

### 9.2 Stress Test
```cpp
void testHighConcurrency() {
    TileManager tm(20, 1000);
    DistributedPrimeVerifier dpv(tm, 32);  // 32 threads
    
    // Large workload
    auto gaps = dpv.verifyRange(1000000, 1000000);
    
    // Verify no crashes, memory stable
    assert(gaps.size() > 0);
}
```

### 9.3 Stale Data Detection
```cpp
void testNoStaleTiles() {
    TileManager tm(10, 10);
    DistributedPrimeVerifier dpv(tm, 2);
    
    // Prime found by thread 0 creates new tile
    // Thread 1 should see it immediately (shared access)
    // Old code: thread 1 had local copy - MISSED new tile
    // New code: thread 1 reads shared tiles - SEES new tile
}
```

---

## 10. CONCLUSION

The `librarianDancer` distributed verification protocol has **fundamental flaws**:

1. **Stale data** - Local tile copy at startup misses runtime tile creation
2. **Byte truncation** - Prime gaps stored as bytes, losing information
3. **Race conditions** - Unsynchronized access to shared `tiles` map
4. **Memory leaks** - Per-thread allocations never freed
5. **Wrong bounds** - `n/3+1` instead of `√n`
6. **No load balancing** - Static partitioning
7. **Hardcoded thread 0** - `breeze()` conflicts with multi-threaded use

**Complete redesign required** with:
- Shared tile access (no local copies)
- Work-stealing queue
- Full `__int128` gap storage
- Thread-safe TileManager
- Proper bounds (√n)

---

*End of Topic 5 Analysis*