# Topic 1: Tile-Derived Increment Algorithm Deep Analysis
## The `breeze()` Function and Prime Increment Generation

**Source:** `main.cpp` lines 7563-7650 (`breeze()`), 6724-6800 (`verifyPrime`), 4299-4380 (`verifyPrimeGear`)  
**Analysis Date:** 2026-11-01  

---

## 1. ALGORITHM SPECIFICATION

### 1.1 Mathematical Definition

The tile-derived increment algorithm generates prime test divisors using bytes read from pre-computed tile arrays:

```
Let T[i][j] be the byte at tile i, position j (0 ≤ T[i][j] ≤ 255)
Let grid = 2^powerOf (typically 2^20 = 1,048,576)

Define breeze sequence B = {b₀, b₁, b₂, ...} where:
  bₖ = T[⌊k/grid⌋][k mod grid]

Define primeBuild sequence P = {p₀, p₁, p₂, ...} where:
  p₀ = 3
  pₖ₊₁ = pₖ + 2 × bₖ

Verification of candidate n:
  For k = 0, 1, 2, ... while pₖ ≤ √n:
    if n mod pₖ == 0: return COMPOSITE
  return PRIME
```

### 1.2 Key Properties

| Property | Value | Implication |
|----------|-------|-------------|
| **Increment range** | 0 to 510 (even numbers only) | Skips odd divisors sometimes |
| **Minimum increment** | 0 (if T[i][j] = 0) | **STALLS** - infinite loop if tile byte = 0 |
| **Maximum increment** | 510 (if T[i][j] = 255) | Large jumps, may skip divisors |
| **Tile progression** | Sequential tile walk | Deterministic but opaque |
| **Entropy source** | Pre-computed tile data | Not cryptographically random |

---

## 2. CODE WALKTHROUGH

### 2.1 `breeze()` Function (Lines 7563-7650)

```cpp
byte breeze() {
    bool forever = true;
    while (forever == true) {
        // TILE BOUNDARY CHECK
        if (threadBreezeWalk[0] == grid) {
            threadTileWalk[0]++;           // Advance to next tile
            threadBreezeWalk[0] = 0;       // Reset position
        }
        
        // TILE NAME CONSTRUCTION (expensive string ops per call)
        string128Class tileWalkString(threadTileWalk[0]);
        string myTargetTileName = "Tile0" + tileWalkString.getString();
        
        // MAP LOOKUP (O(log N) each call)
        byte* targetTile = tiles[myTargetTileName];
        
        // READ AND ADVANCE
        int breezePos = threadBreezeWalk[0]++;
        return targetTile[breezePos];
    }
}
```

**Critical Issues:**
1. **String allocation per call** - `string128Class` + `string` construction
2. **Map lookup per call** - `std::map<string, byte*>` O(log N)
3. **Hardcoded thread 0** - `threadBreezeWalk[0]`, `threadTileWalk[0]`
4. **No bounds check** - `tiles[myTargetTileName]` creates entry if missing
5. **Zero-byte stall** - Returns 0 → `primeBuild += 0` → infinite loop

### 2.2 `verifyPrime()` Integration (Lines 6724-6800)

```cpp
bool verifyPrime(__int128 myInfiniteWalk) {
    __int128 primeBuild = 3;
    __int128 primeRange = 0;
    bool findPrime = true;
    
    while (findPrime) {
        still(0);  // Unknown purpose - possibly yield
        
        if (myInfiniteWalk % primeBuild == 0) {
            findPrime = false;
            isPrime = false;
        } else {
            primeRange = (myInfiniteWalk / primeBuild) + 1;
            if (primeBuild > primeRange) {
                findPrime = false;
                isPrime = true;
            } else {
                primeBuild += breeze() * 2;  // ← TILE INCREMENT HERE
            }
        }
    }
    return isPrime;
}
```

### 2.3 Termination Condition Analysis

```
primeRange = (n / primeBuild) + 1
primeBuild > primeRange
primeBuild > n/primeBuild + 1
primeBuild² > n + primeBuild
primeBuild² > n (approximately)
primeBuild > √n
```

**Correct √n termination** - mathematically sound IF increments are valid.

---

## 3. MATHEMATICAL ANALYSIS

### 3.1 Completeness Question

**Does the sequence P = {3, 3+2b₀, 3+2b₀+2b₁, ...} cover all necessary divisors?**

For correct trial division up to √n, we need to test **all odd numbers** up to √n (or at least all primes up to √n).

The tile-derived sequence:
- **Starts at 3** ✓
- **Increments by even numbers** (2×b where b ∈ [0,255]) ✓ (stays odd)
- **But increments are not +2** - they vary based on tile data

**CRITICAL FLAW:** If tile byte = 0, increment = 0 → `primeBuild` never advances → **infinite loop**

**COMPLETENESS FLAW:** If tile bytes skip values, some divisors never tested → **false primes possible**

### 3.2 Example: Missing Divisors

Suppose tile sequence: [1, 3, 0, 2, ...]
- p₀ = 3
- p₁ = 3 + 2×1 = 5
- p₂ = 5 + 2×3 = 11  **← SKIPS 7, 9**
- p₃ = 11 + 2×0 = 11  **← STALLS!**
- p₄ = 11 + 2×2 = 15  **← Never reached if stalled**

**Result:** Never tests 7, 9, 13, etc. Composite numbers divisible by 7 pass as prime!

### 3.3 Probability of Zero Bytes

If tile data is uniformly distributed (unlikely - it's derived from prime gaps):
- P(byte = 0) ≈ 1/256 per position
- Expected zeros per tile (1M bytes): ~3,900
- **Near certainty of stalls**

If tile data is prime gaps mod 256:
- Prime gaps are even (except 2→3)
- Gap/2 mod 128 distribution
- Still possible zeros

---

## 4. COMPARISON WITH STANDARD TRIAL DIVISION

| Aspect | Standard (fixed +2) | Tile-Derived (breeze) |
|--------|---------------------|----------------------|
| **Sequence** | 3, 5, 7, 9, 11, 13... | 3, 3+2b₀, 3+2b₀+2b₁... |
| **Completeness** | Tests ALL odd numbers | Tests SUBSET (tile-dependent) |
| **Correctness** | Mathematically proven | **NOT PROVEN** - depends on tiles |
| **Performance** | O(√n) divisions | O(√n/avg_increment) divisions |
| **Stall risk** | None | **High** (zero bytes) |
| **Determinism** | Fully deterministic | Depends on tile content |
| **Verification** | Self-contained | Requires valid tile data |

### 4.1 When Tile-Derived Might Work

Only if tile bytes encode a **valid prime wheel** or **increment sequence** that:
1. Never produces 0
2. Covers all prime divisors up to √n
3. Is pre-computed correctly

But tile data comes from `etchTile()` which writes **prime gaps mod 256** - not a designed wheel!

---

## 5. BUG CATALOG

| ID | Severity | Location | Description |
|----|----------|----------|-------------|
| T1-01 | CRITICAL | `breeze()`:7563 | Returns 0 → `primeBuild += 0` → infinite loop |
| T1-02 | CRITICAL | `verifyPrime`:6750 | No check for `breeze() == 0` before increment |
| T1-03 | HIGH | `breeze()`:7575 | String allocation + map lookup per byte read |
| T1-04 | HIGH | `breeze()`:7570 | Hardcoded `threadBreezeWalk[0]` - single-threaded |
| T1-05 | HIGH | `verifyPrime`:6724 | No max iteration limit - hangs on bad tiles |
| T1-06 | MEDIUM | `breeze()`:7578 | `tiles[myTargetTileName]` creates entry if missing |
| T1-07 | MEDIUM | `verifyPrime`:6740 | `primeRange` recomputed each iteration (redundant) |
| T1-08 | LOW | `breeze()`:7565 | `forever` variable unnecessary (while(true)) |

---

## 6. FIX SPECIFICATION

### 6.1 Immediate Fix: Zero-Byte Guard

```cpp
byte breeze() {
    while (true) {
        if (threadBreezeWalk[0] == grid) {
            threadTileWalk[0]++;
            threadBreezeWalk[0] = 0;
        }
        
        string128Class tileWalkString(threadTileWalk[0]);
        string myTargetTileName = "Tile0" + tileWalkString.getString();
        byte* targetTile = tiles[myTargetTileName];
        
        int breezePos = threadBreezeWalk[0]++;
        byte result = targetTile[breezePos];
        
        // CRITICAL FIX: Never return 0
        if (result == 0) return 1;  // Minimum increment = 2
        return result;
    }
}
```

### 6.2 Better Fix: Validated Increment Sequence

```cpp
// Pre-compute validated increment sequence at tile creation
class TileIncrementValidator {
    vector<byte> validatedIncrements;
    
    void validateTile(byte* tile, size_t size) {
        validatedIncrements.clear();
        validatedIncrements.reserve(size);
        for (size_t i = 0; i < size; i++) {
            byte inc = tile[i];
            if (inc == 0) inc = 1;  // Clamp minimum
            validatedIncrements.push_back(inc);
        }
    }
    
    byte getIncrement(size_t index) {
        return validatedIncrements[index % validatedIncrements.size()];
    }
};
```

### 6.3 Architectural Fix: Abstract Verifier Interface

```cpp
class PrimeVerifier {
public:
    virtual bool verify(__int128 n) = 0;
    virtual ~PrimeVerifier() = default;
};

class TileDerivedVerifier : public PrimeVerifier {
    TileManager& tiles;
    size_t tileWalk = 0, breezeWalk = 0;
    
    bool verify(__int128 n) override {
        __int128 primeBuild = 3;
        while (primeBuild * primeBuild <= n) {
            if (n % primeBuild == 0) return false;
            primeBuild += tiles.getIncrement(tileWalk, breezeWalk) * 2;
            advanceTilePosition();
        }
        return true;
    }
};

class StandardTrialDivision : public PrimeVerifier {
    bool verify(__int128 n) override {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;
        for (__int128 d = 3; d * d <= n; d += 2) {
            if (n % d == 0) return false;
        }
        return true;
    }
};
```

---

## 7. TEST CASES

### 7.1 Zero-Byte Stall Test
```cpp
// Create tile with zero byte
byte testTile[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
tiles["Tile00"] = testTile;
threadTileWalk[0] = 0;
threadBreezeWalk[0] = 0;

// Verify prime 49 (7×7) - should be COMPOSITE
// But with zero byte at position 1:
// p₀=3, p₁=3+2×1=5, p₂=5+2×0=5 (STALL!)
// Never tests 7 → returns PRIME (WRONG!)
assert(!verifyPrime(49));  // FAILS with current code
```

### 7.2 Missing Divisor Test
```cpp
// Tile skips 7: increments [1, 3, 1] → 3, 5, 11, 13...
byte testTile[3] = {1, 3, 1};
tiles["Tile00"] = testTile;

// 49 = 7×7, divisor 7 never tested
assert(!verifyPrime(49));  // May PASS incorrectly
```

### 7.3 Large Prime Test
```cpp
// Known 128-bit prime
__int128 prime = 170141183460469231731687303715884105727;  // 2^127 - 1
assert(verifyPrime(prime));  // Must complete in reasonable time
```

### 7.4 Cross-Verification Test
```cpp
// Compare with standard trial division
StandardTrialDivision stdVerifier;
TileDerivedVerifier tileVerifier(tiles);

for (int i = 0; i < 10000; i++) {
    __int128 candidate = randomOdd128();
    bool stdResult = stdVerifier.verify(candidate);
    bool tileResult = tileVerifier.verify(candidate);
    assert(stdResult == tileResult);  // Must match!
}
```

---

## 8. PERFORMANCE ANALYSIS

### 8.1 Current Implementation Overhead
```
Per breeze() call:
  - string128Class construction: ~50ns
  - string concatenation: ~100ns
  - map<string, byte*> lookup: ~200ns
  - array access: ~1ns
  Total: ~350ns per increment

Per verifyPrime() for n ~ 10^12 (√n ~ 10^6):
  - ~500,000 iterations (avg increment ~4)
  - 500,000 × 350ns = 175ms overhead just for breeze()
  - Plus division operations
```

### 8.2 Optimization Opportunities
1. **Cache tile pointer** - Avoid map lookup per call
2. **Pre-validate tiles** - Clamp zeros at creation
3. **Batch increments** - Read 64 bytes at once
4. **Thread-local tile walk** - Remove hardcoded [0]

---

## 9. CONCLUSION

The tile-derived increment algorithm is **fundamentally flawed**:

1. **Zero-byte stalls** make it unreliable
2. **Incomplete divisor coverage** produces false primes
3. **No mathematical proof** of correctness
4. **Performance overhead** from string/map operations
5. **Single-threaded design** prevents parallelization

**Recommendation:** Replace with standard trial division (`d += 2`) or a proven wheel factorization. If tile-derived increments are required for the "PrimeOne" methodology, they must be:
- Pre-validated (no zeros)
- Mathematically proven complete
- Generated by a known algorithm (not prime gaps mod 256)

---

*End of Topic 1 Analysis*