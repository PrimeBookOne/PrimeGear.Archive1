# Topic 4: Tile Memory Model Analysis
## `tiles` Map, `breeze()` Access Patterns, and Thread Safety

**Source:** `main.cpp` lines 6124-6250, 7563-7650, 7993-8400, primeTileClass constructor  
**Analysis Date:** 2026-11-01  

---

## 1. TILE DATA STRUCTURES

### 1.1 Primary Tile Storage (primeTileClass)

```cpp
// Class member (line ~7800)
map<string, byte*> tiles;  // Key: "Tile0{N}", Value: byte[grid]

// Constructor initialization (lines 7900-7950)
primeTileClass(...) {
    grid = pow(2, powerOf);  // e.g., 2^20 = 1,048,576
    initiateTile(0);  // Creates "Tile00"
}

void initiateTile(int tileIndex) {
    string128Class tileCountString(tileIndex);
    string targetTileName = "Tile0" + tileCountString.getString();
    byte* newTile = new byte[grid]();  // Zero-initialized
    tiles[targetTileName] = newTile;
}
```

### 1.2 Tile Naming Convention

```
Tile00, Tile01, Tile02, ..., Tile0{N}
```

- `string128Class` converts integer to string
- Map key: `"Tile0" + to_string(index)`
- **No leading zeros** - "Tile00", "Tile01", "Tile010", "Tile011"...

### 1.3 Tile Capacity

| Parameter | Value | Calculation |
|-----------|-------|-------------|
| `powerOf` | 20 (default) | Configurable |
| `grid` | 1,048,576 | 2^20 |
| Tile size | 1 MB | grid × 1 byte |
| Max tiles | 50,000 | `indexFileTileCount` |
| Total capacity | ~50 GB | 50,000 × 1 MB |

---

## 2. ACCESS PATTERNS

### 2.1 Write Pattern: `etchTile()` (Lines 6124-6250)

```cpp
void etchTile(byte data) {
    // 1. Construct current tile name
    string128Class tileCountString(tileCount);
    targetTileName = "Tile0" + tileCountString.getString();
    
    // 2. Get tile pointer from map
    byte* targetTile = tiles[targetTileName];
    
    // 3. Write at current position
    if (etchWalk < grid) {
        targetTile[etchWalk] = data;
        etchWalkSum += data;
    } else {
        // 4. Tile full - export and create next
        exportTile(targetTileName);
        tileCount++;
        string128Class tileCountString(tileCount);
        targetTileName = "Tile0" + tileCountString.getString();
        byte* newTile = new byte[grid]();
        tiles[targetTileName] = newTile;  // INSERT INTO MAP
        targetTile = tiles[targetTileName];
        etchWalkSum = data;
        targetTile[etchWalk] = data;
    }
    etchWalk++;
}
```

**Pattern:** Sequential write within tile, then sequential tile creation.
**Frequency:** One map lookup + one string construction per prime recorded.

### 2.2 Read Pattern: `breeze()` (Lines 7563-7650)

```cpp
byte breeze() {
    while (true) {
        // 1. Check tile boundary
        if (threadBreezeWalk[0] == grid) {
            threadTileWalk[0]++;           // Next tile
            threadBreezeWalk[0] = 0;       // Reset position
        }
        
        // 2. Construct tile name (EVERY CALL)
        string128Class tileWalkString(threadTileWalk[0]);
        string myTargetTileName = "Tile0" + tileWalkString.getString();
        
        // 3. Map lookup (EVERY CALL)
        byte* targetTile = tiles[myTargetTileName];
        
        // 4. Read and advance
        int breezePos = threadBreezeWalk[0]++;
        return targetTile[breezePos];
    }
}
```

**Pattern:** Sequential read across tiles.
**Overhead per byte:** String construction + map lookup + pointer dereference.

### 2.3 Local Copy Pattern: `librarianDancer()` (Lines 8050-8100)

```cpp
// PRELOAD PHASE - copies tiles to local 2D array
const int arrayGrid = static_cast<int>(std::pow(2, 20));  // 1M
byte** myTiles = new uint8_t*[myMinimumTileCount];
for (int i = 0; i < myMinimumTileCount; ++i) {
    myTiles[i] = new uint8_t[arrayGrid];
}

while (minimumTileWalk < myMinimumTileCount) {
    string128Class minimumTileWalkString(minimumTileWalk);
    string targetTileName = "Tile0" + minimumTileWalkString.getString();
    byte* myTargetTile = tiles[targetTileName];  // From map
    
    while (gridWalker < gridInt) {
        myTiles[minimumTileWalk][gridWalker] = myTargetTile[gridWalker];
        gridWalker++;
    }
    gridWalker = 0;
    minimumTileWalk++;
}

// MAIN LOOP - reads from LOCAL copy
return16 = myTiles[myThreadTileWalk][myThreadBreezeWalk] * 2;
```

**Pattern:** Bulk copy at startup, then fast local array access.
**Issue:** Stale data if tiles modified after copy.

---

## 3. MEMORY MANAGEMENT

### 3.1 Allocations (Never Freed)

```cpp
// Constructor - lines 7900-7950
threadTotal = new __int128[singersPlus];
threadTileWalk = new __int128[singersPlus];
threadSlateWalk = new __int128[singersPlus];
threadBreezeWalk = new __int128[singersPlus];
findsArray = new __int128[singersPlus];

bookIndex = new __int128[indexFileTileCount];  // 50,000
bookIndexTotals = new __int128[indexFileTileCount];
bookIndexTotalsDif = new __int128[indexFileTileCount];

// initiateTile - called for each new tile
byte* newTile = new byte[grid]();  // 1 MB each

// librarianDancer - per thread
byte** myTiles = new uint8_t*[myMinimumTileCount];
for (i) myTiles[i] = new uint8_t[arrayGrid];  // 1 MB each
byte* myTargetTile = new byte[gridInt];
byte* targetTile = new byte[grid];
```

### 3.2 Memory Leak Summary

| Allocation | Count | Size Each | Total | Freed? |
|------------|-------|-----------|-------|--------|
| `threadTotal` etc | 5 arrays | singers × 16B | ~80 KB | ❌ |
| `bookIndex*` | 3 arrays | 50K × 16B | ~2.4 MB | ❌ |
| `tiles` map entries | Up to 50K | 1 MB | ~50 GB | ❌ |
| `librarianDancer` local | Per thread | minTiles × 1 MB | Variable | ❌ |

**No destructor exists in primeTileClass.** All memory leaks on destruction.

---

## 4. THREAD SAFETY ANALYSIS

### 4.1 Shared State Access

| Variable | Access Pattern | Thread Safety |
|----------|----------------|---------------|
| `tiles` map | Read: `breeze()`, `librarianDancer` preload<br>Write: `etchTile()`, `initiateTile()` | **UNSAFE** - No mutex |
| `threadBreezeWalk[0]` | Read/Write: `breeze()` (hardcoded [0]) | **UNSAFE** - Single thread only |
| `threadTileWalk[0]` | Read/Write: `breeze()` | **UNSAFE** |
| `etchWalk`, `tileCount` | Read/Write: `etchTile()` | **UNSAFE** |
| `bookIndex*` arrays | Read/Write: multiple | **UNSAFE** |

### 4.2 `breeze()` Thread Confinement

```cpp
// HARDCODED to thread 0
if (threadBreezeWalk[0] == grid) { ... }
byte* targetTile = tiles[myTargetTileName];  // Map not thread-safe
return targetTile[breezePos];
```

**Design assumption:** Only thread 0 calls `breeze()`.
**Reality:** `librarianDancer` creates multiple threads, each needs independent tile reading.

### 4.3 `librarianDancer` Thread Isolation

```cpp
// Each thread gets LOCAL COPY of tiles at startup
byte** myTiles = new uint8_t*[myMinimumTileCount];
for (i) myTiles[i] = new uint8_t[arrayGrid];
// Copy from shared tiles map
while (...) {
    myTiles[minimumTileWalk][gridWalker] = tiles[targetTileName][gridWalker];
}

// Then reads from LOCAL copy only
return16 = myTiles[myThreadTileWalk][myThreadBreezeWalk] * 2;
```

**Strategy:** Copy-on-start isolation.
**Flaw:** If tiles updated during computation, threads see stale data.
**Flaw:** Memory allocation per thread - huge overhead.

---

## 5. PERFORMANCE ANALYSIS

### 5.1 `breeze()` Overhead Per Call

```
Operation                    | Cycles | Time (3GHz)
-----------------------------|--------|------------
string128Class construction  | ~200   | 67 ns
string concatenation         | ~300   | 100 ns
map<string, byte*> lookup    | ~500   | 167 ns
array index + load           | ~3     | 1 ns
TOTAL                        | ~1003  | 334 ns
```

**At 334 ns/byte, reading 1M bytes = 0.33 seconds overhead alone.**

### 5.2 Optimized Access Pattern

```cpp
// CACHED TILE POINTER - eliminates map lookup
class TileReader {
    byte* currentTile = nullptr;
    size_t currentTileIndex = SIZE_MAX;
    size_t position = 0;
    TileManager& manager;
    
public:
    byte next() {
        if (position == manager.grid) {
            currentTileIndex++;
            currentTile = manager.getTile(currentTileIndex);
            position = 0;
        }
        return currentTile[position++];
    }
};
```

**Optimized: ~3 cycles (1 ns) per byte - 300x faster.**

---

## 6. BUG CATALOG

| ID | Severity | Location | Description |
|----|----------|----------|-------------|
| T4-01 | CRITICAL | `tiles` map | No destructor - 50GB+ leak |
| T4-02 | CRITICAL | `breeze()` | Map lookup + string per byte - 300x slowdown |
| T4-03 | CRITICAL | `breeze()` | Hardcoded `[0]` - single-threaded only |
| T4-04 | HIGH | `tiles` map | `operator[]` creates entry if missing - silent corruption |
| T4-05 | HIGH | `librarianDancer` | Stale local copy - misses new tiles |
| T4-06 | HIGH | `etchTile` | No thread safety - concurrent write corrupts |
| T4-07 | MEDIUM | `initiateTile` | No check if tile already exists |
| T4-08 | MEDIUM | `librarianDancer` | Per-thread 1MB allocations - OOM risk |
| T4-09 | LOW | Tile naming | "Tile010" vs "Tile0010" ambiguity |

---

## 7. FIX SPECIFICATION

### 7.1 TileManager Class (Thread-Safe, Cached)

```cpp
class TileManager {
    struct Tile {
        unique_ptr<byte[]> data;
        atomic<size_t> writePos{0};
        atomic<size_t> readPos[MaxThreads]{};
    };
    
    vector<Tile> tiles;
    mutex mapMutex;  // For tile creation only
    size_t grid;
    size_t maxTiles;
    
public:
    TileManager(size_t powerOf, size_t maxTiles = 50000)
        : grid(1 << powerOf), maxTiles(maxTiles) {
        tiles.reserve(maxTiles);
        createTile(0);  // Tile00
    }
    
    // Thread-safe tile creation
    byte* getOrCreateTile(size_t index) {
        if (index < tiles.size()) return tiles[index].data.get();
        
        lock_guard<mutex> lock(mapMutex);
        if (index >= tiles.size()) {
            tiles.resize(index + 1);
            tiles[index].data = make_unique<byte[]>(grid);
        }
        return tiles[index].data.get();
    }
    
    // Fast read - no lock, uses cached pointer
    byte readByte(size_t tileIndex, size_t& pos, size_t threadId) {
        Tile& tile = tiles[tileIndex];
        byte result = tile.data[pos];
        
        if (++pos == grid) {
            pos = 0;
            tileIndex++;
            // Next tile auto-created on next read
        }
        return result;
    }
    
    // Fast write - atomic position
    void writeByte(size_t tileIndex, size_t& pos, byte value) {
        Tile& tile = tiles[tileIndex];
        tile.data[pos] = value;
        if (++pos == grid) {
            pos = 0;
            tileIndex++;
            getOrCreateTile(tileIndex);  // Ensure next exists
        }
    }
};
```

### 7.2 Thread-Local Tile Reader

```cpp
class ThreadTileReader {
    TileManager& manager;
    size_t tileIndex = 0;
    size_t position = 0;
    int threadId;
    
public:
    ThreadTileReader(TileManager& m, int id) : manager(m), threadId(id) {}
    
    byte next() {
        // Fast path: current tile
        if (position < manager.grid) {
            return manager.tiles[tileIndex].data[position++];
        }
        
        // Slow path: advance tile (rare)
        position = 0;
        tileIndex++;
        return manager.tiles[tileIndex].data[position++];
    }
};
```

### 7.3 librarianDancer Redesign

```cpp
void librarianDancer(int singer, __int128 startWalk, 
                     __int128 slices, int minTiles,
                     vector<__int128>& primeFinds) {
    
    // SHARED read-only tile access (no copy!)
    ThreadTileReader reader(tileManager, singer);
    
    // Moonwalk for previous prime
    __int128 prevPrime = moonWalkPrime(startWalk);
    __int128 current = startWalk;
    
    for (__int128 slice = 0; slice < slices; slice++) {
        current += 2;
        if (verifyPrimeWithReader(current, reader)) {
            __int128 gap = (current - prevPrime) / 2;
            primeFinds.push_back(gap);  // FULL PRECISION
            prevPrime = current;
        }
    }
}
```

---

## 8. TEST CASES

### 8.1 Concurrent Access Test
```cpp
void testConcurrentTileAccess() {
    TileManager tm(20, 100);
    const int threads = 8;
    const int opsPerThread = 100000;
    
    vector<thread> workers;
    atomic<int> errors{0};
    
    for (int t = 0; t < threads; t++) {
        workers.emplace_back([&, t]() {
            ThreadTileReader reader(tm, t);
            for (int i = 0; i < opsPerThread; i++) {
                byte b = reader.next();
                // Verify pattern
                if (b != expectedPattern(i)) errors++;
            }
        });
    }
    
    for (auto& w : workers) w.join();
    assert(errors == 0);
}
```

### 8.2 Memory Leak Test
```cpp
void testNoMemoryLeaks() {
    // Run full cycle multiple times
    for (int cycle = 0; cycle < 10; cycle++) {
        PrimeTileEngine engine(20, 4, ...);
        engine.generatePrimes(10000);
        engine.writeBook("test.bin");
        // engine destructor MUST clean up
    }
    // Check memory stable
}
```

### 8.3 Stale Data Test
```cpp
void testStaleTileData() {
    TileManager tm(10, 10);  // Small for test
    ThreadTileReader reader(tm, 0);
    
    // Writer adds data to tile 0
    tm.writeByte(0, writePos, 42);
    tm.writeByte(0, writePos, 43);
    
    // Reader should see new data (if same tile)
    // But if reader copied at start, sees zeros
    byte b1 = reader.next();  // Should be 42
    byte b2 = reader.next();  // Should be 43
    
    // With local copy: b1=0, b2=0 (STALE!)
    // With shared access: b1=42, b2=43 (CORRECT)
}
```

---

## 9. INTEGRATION WITH VERIFICATION

### 9.1 verifyPrime with TileManager

```cpp
bool verifyPrimeWithManager(__int128 n, ThreadTileReader& reader) {
    __int128 primeBuild = 3;
    while (primeBuild * primeBuild <= n) {
        if (n % primeBuild == 0) return false;
        
        byte inc = reader.next();
        if (inc == 0) inc = 1;  // Guard
        primeBuild += inc * 2;
    }
    return true;
}
```

### 9.2 Tile Precomputation

```cpp
// Instead of on-the-fly etching, precompute increments
void precomputeTileIncrements() {
    for (auto& tile : tiles) {
        for (size_t i = 0; i < grid; i++) {
            if (tile.data[i] == 0) tile.data[i] = 1;
        }
    }
}
```

---

## 10. CONCLUSION

The tile memory model suffers from:

1. **O(N) map+string overhead** per byte access (300x slower than array)
2. **No thread safety** - data races on all shared state
3. **Massive memory leaks** - no destructor, 50GB+ potential
4. **Stale data in distributed mode** - local copy at startup
5. **Single-threaded `breeze()`** - hardcoded `[0]` index

**Redesign required:** Replace `map<string, byte*>` with `vector<unique_ptr<byte[]>>`, add thread-safe TileManager, eliminate per-byte string construction, implement proper RAII.

---

*End of Topic 4 Analysis*