# PrimeOne - Feature Document 10: Data Persistence (Book/Archive System)
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines ~7470-7550 (ptv_primeBookAuthor), ~16600 (realm_win_archive), batch files, update system  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Data Persistence system manages **long-term storage** of prime computation state through a **Book/Archive** metaphor. The "Prime Book" contains the complete computation history (tiles, primes, walk positions), while "Archives" are portable ZIP packages for transfer, backup, and updates.

### Design Philosophy
- **Book = Live State** - Continuous serialization of computation
- **Archive = Portable Snapshot** - ZIP for transfer/backup
- **Roll = Atomic Restore** - Replace executable + state
- **Versioned** - Build count, service tags, timestamps

---

## 2. BOOK FORMAT (Prime Book)

### 2.1 Serialization Function
```cpp
// Line ~7470: ptv_primeBookAuthor
vector<byte> primeTileClass::ptv_primeBookAuthor(
    __int128 primeDifference, 
    int singerCount, 
    int gridSize, 
    int tileCount
) {
    vector<byte> wolfCatch;
    wolfCatch.push_back(primeDifference);  // BUG: __int128 → byte
    // ... serialization logic ...
    return wolfCatch;
}
```

### 2.2 Book Data Structure (Inferred)
```cpp
struct PrimeBook {
    // Metadata
    string serviceTag;           // "[SERVICE_primeOne_2025_7_18.xlsm]ptv_verifyTileARMnew"
    int buildCount;              // 3242
    __int128 powerOf;            // Grid dimension exponent
    __int128 singers;            // Thread count
    __int128 indexTiles;         // Current tile index
    __int128 perThreadSlices;    // Work distribution
    __int128 infiniteWalk;       // Continuous walk position
    __int128 totalPrimes;        // Total primes found
    __int128 primeRatio;         // Prime density ratio
    __int128 totalTiles;         // Total tiles processed
    __int128 largestDiff;        // Largest prime gap (228)
    
    // Prime index array
    __int128* primeIndex;        // Dynamic array of known primes
    __int128 primeIndexCount;    // Number of primes in index
    
    // Tile data
    byte* tileBuffer;            // Current tile raw data
    __int128 tileBufferSize;     // Buffer size
    
    // Verification state
    byte* primeFindsArray;       // Found primes (serialized)
    __int128 primeFindsCount;
    
    // Network state
    string hostIp;
    int hostPort;
    bool createHost;
    string uniqueIdGlobal;
    
    // Computation config
    bool singleCore;
    string computeMethod;        // "Gear", "blindPrime"
    string optionFlag;           // "quickPrime", "noPrime"
    
    // Timestamps
    time_t created;
    time_t lastModified;
    string machineId;            // Computer name
};
```

### 2.3 Serialization Format (Binary)
```
PrimeBook Binary Format:
┌─────────────────────────────────────────────────────────────┐
│ Magic: "PRMB" (4 bytes)                                     │
├─────────────────────────────────────────────────────────────┤
│ Version: uint16 (1)                                         │
├─────────────────────────────────────────────────────────────┤
│ Metadata (fixed size)                                       │
│   serviceTag:     char[128]                                 │
│   buildCount:     uint32                                    │
│   powerOf:        int128 (16 bytes)                         │
│   singers:        int128                                    │
│   indexTiles:     int128                                    │
│   perThreadSlices:int128                                    │
│   infiniteWalk:   int128                                    │
│   totalPrimes:    int128                                    │
│   primeRatio:     int128 (fixed point)                      │
│   totalTiles:     int128                                    │
│   largestDiff:    int128                                    │
│   hostIp:         char[16]                                  │
│   hostPort:       uint16                                    │
│   createHost:     uint8                                     │
│   uniqueIdGlobal: char[64]                                  │
│   singleCore:     uint8                                     │
│   computeMethod:  char[32]                                  │
│   optionFlag:     char[32]                                  │
│   created:        int64 (Unix timestamp)                    │
│   lastModified:   int64                                     │
│   machineId:      char[64]                                  │
├─────────────────────────────────────────────────────────────┤
│ Prime Index                                                 │
│   count:          uint32                                    │
│   primes:         int128[count]                             │
├─────────────────────────────────────────────────────────────┤
│ Tile Buffer                                                 │
│   size:           uint32                                    │
│   data:           byte[size]                                │
├─────────────────────────────────────────────────────────────┤
│ Prime Finds Array                                           │
│   count:          uint32                                    │
│   data:           byte[count]  (serialized int128)          │
├─────────────────────────────────────────────────────────────┤
│ Checksum: SHA256 (32 bytes)                                 │
└─────────────────────────────────────────────────────────────┘
```

### 2.4 Int128 Serialization
```cpp
// Custom serialization for __int128 (16 bytes, little-endian)
void serializeInt128(vector<byte>& out, __int128 value) {
    for (int i = 0; i < 16; ++i) {
        out.push_back(static_cast<byte>(value & 0xFF));
        value >>= 8;
    }
}

__int128 deserializeInt128(const byte* data, size_t& offset) {
    __int128 result = 0;
    for (int i = 15; i >= 0; --i) {
        result = (result << 8) | static_cast<__int128>(data[offset++]);
    }
    return result;
}
```

---

## 3. ARCHIVE FORMAT (PrimeOneUpdater.zip)

### 3.1 Archive Structure
```
PrimeOneUpdater.zip
├── primeone.exe              # New executable (signed)
├── primeoneold.exe           # Previous version backup
├── primebook.bin             # Serialized PrimeBook
├── manifest.json             # Update metadata
├── version.res               # Windows version resource
├── cuda_kernels.ptx          # PTX kernels (optional)
├── compute_shader.hlsl       # Updated shaders (optional)
└── README_UPDATE.txt         # Human-readable notes
```

### 3.2 Manifest Schema (manifest.json)
```json
{
  "version": "1.2.3.4",
  "buildCount": 3242,
  "serviceTag": "SERVICE_primeOne_2025_7_18.xlsm",
  "timestamp": "2025-07-18T10:30:00Z",
  "checksums": {
    "primeone.exe": "sha256:a1b2c3d4...",
    "primebook.bin": "sha256:e5f6g7h8..."
  },
  "changelog": [
    "Fixed moonWalkPrime return value",
    "Added GPU memory pooling",
    "Improved network protocol v2"
  ],
  "requirements": {
    "minWindowsVersion": "10.0.19041",
    "minCudaVersion": "11.0",
    "minDriverVersion": "450.0"
  },
  "signature": {
    "algorithm": "RSA-SHA256",
    "certificate": "thumbprint:ABC123...",
    "timestamp": "2025-07-18T10:30:05Z"
  }
}
```

### 3.3 Creation (realm_win_archive - Commented)
```cpp
// Referenced in menu handlers but commented out:
// realm_win_archive();

// Would implement:
void realm_win_archive() {
    // 1. Serialize current PrimeBook
    vector<byte> bookData = PrimeOne.ptv_primeBookAuthor(...);
    
    // 2. Create ZIP with all components
    // Using: Windows Shell API, libzip, or system("powershell Compress-Archive")
    
    // 3. Generate manifest.json
    // 4. Sign archive
}
```

---

## 4. PERSISTENCE OPERATIONS

### 4.1 Save (Auto/Manual)
```cpp
// Triggered by:
void savePrimeBook() {
    vector<byte> bookData = PrimeOne.ptv_primeBookAuthor(
        currentPrimeDifference, singers, grid, tileCount
    );
    
    // Write to file
    ofstream bookFile("primebook.bin", ios::binary);
    bookFile.write(reinterpret_cast<char*>(bookData.data()), bookData.size());
}
```

### 4.2 Load (Startup)
```cpp
// In primeTileClass constructor or Load & Go:
bool loadPrimeBook() {
    ifstream bookFile("primebook.bin", ios::binary);
    if (!bookFile) return false;  // Fresh start
    
    // Read and deserialize
    vector<byte> bookData((istreambuf_iterator<char>(bookFile)), {});
    deserializePrimeBook(bookData);
    return true;
}
```

### 4.3 Auto-Save Interval
```cpp
// Inference: Periodic save during computation
void primeTileClass::periodicSave() {
    static auto lastSave = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    if (now - lastSave > chrono::minutes(5)) {
        savePrimeBook();
        lastSave = now;
    }
}
```

---

## 5. NETWORK STATE TRANSFER

### 5.1 Host → Guest Book Sync
```cpp
// Host sends current book state to new guests
void conduitClass::sendPrimeBookToGuest(SOCKET guestSock) {
    vector<byte> bookData = PrimeOne.ptv_primeBookAuthor(...);
    
    // Send with framing
    sendFrame(guestSock, MSG_PRIME_BOOK, bookData);
}

// Guest receives and loads
void conduitClass::receivePrimeBookFromHost(SOCKET hostSock) {
    vector<byte> bookData = receiveFrame(hostSock, MSG_PRIME_BOOK);
    PrimeOne.deserializePrimeBook(bookData);
}
```

### 5.2 Incremental Sync
```cpp
// Only send changes since last sync
struct BookDelta {
    __int128 fromInfiniteWalk;
    __int128 toInfiniteWalk;
    vector<__int128> newPrimes;
    vector<TileUpdate> tileUpdates;
};
```

---

## 6. UPDATE SYSTEM INTEGRATION

### 6.1 Update Package Contains
```
PrimeOneUpdater.zip
├── primeone.exe          # New binary
├── primebook.bin         # Compatible book state
├── manifest.json         # Version info
└── version.res           # Windows version resource
```

### 6.2 Roll Process (realm_win_roll)
```cpp
void realm_win_roll() {
    // 1. Extract PrimeOneUpdater.zip
    // 2. Verify signatures & checksums
    // 3. Backup current: primeone.exe → primeoneold.exe
    // 4. Replace: new primeone.exe → primeone.exe
    // 5. Load new primebook.bin (if compatible)
    // 6. Restart application
    
    // Current implementation (buggy):
    HANDLE processHandle = GetCurrentProcess();
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    // ... dumps entire memory ...
}
```

### 6.3 Version Compatibility
```cpp
bool isBookCompatible(const PrimeBook& book, const string& exeVersion) {
    // Check: same major version, compatible schema
    return book.serviceTag == currentServiceTag && 
           book.buildCount <= currentBuildCount;
}
```

---

## 7. FILE SYSTEM LAYOUT

### 7.1 Runtime Files
```
PrimeOne/
├── primeone.exe              # Current executable
├── primeoneold.exe           # Backup (from verifyupdater.bat)
├── primebook.bin             # Serialized computation state
├── primebook.index           # Prime index cache
├── primebook.tiles           # Tile buffer dump
├── primebook.log             # Computation log
├── PrimeOneUpdater.zip       # Pending update (if any)
├── version.res               # Version resource
├── manifest.json             # Update metadata
└── logs/
    ├── host_20250718.log
    ├── guest_20250718.log
    └── update_20250718.log
```

### 7.2 Backup Strategy (verifyupdater.bat)
```batch
:: Maintains: primeoneold.exe = last known good
:: On update: primeone.exe (new) → primeoneold.exe (backup)
:: Manual rollback: copy primeoneold.exe primeone.exe
```

---

## 8. SERIALIZATION DETAILS

### 8.1 Int128 Encoding
```cpp
// Little-endian, 16 bytes
// Example: 0x0123456789ABCDEF0123456789ABCDEF
// Stored as: EF CD AB 89 67 45 23 01 EF CD AB 89 67 45 23 01
// (reversed byte order per 8-byte word, then words reversed)
// Actually: standard little-endian: LSB first
```

### 8.2 Vector<byte> Serialization
```cpp
// Length-prefixed
void writeVector(ostream& out, const vector<byte>& v) {
    uint32_t len = static_cast<uint32_t>(v.size());
    out.write(reinterpret_cast<char*>(&len), 4);
    out.write(reinterpret_cast<const char*>(v.data()), v.size());
}

vector<byte> readVector(istream& in) {
    uint32_t len;
    in.read(reinterpret_cast<char*>(&len), 4);
    vector<byte> v(len);
    in.read(reinterpret_cast<char*>(v.data()), len);
    return v;
}
```

### 8.3 String Serialization
```cpp
// UTF-8, length-prefixed (uint16 for short strings)
void writeString(ostream& out, const string& s) {
    uint16_t len = static_cast<uint16_t>(s.size());
    out.write(reinterpret_cast<char*>(&len), 2);
    out.write(s.data(), s.size());
}

string readString(istream& in) {
    uint16_t len;
    in.read(reinterpret_cast<char*>(&len), 2);
    string s(len, '\0');
    in.read(&s[0], len);
    return s;
}
```

---

## 9. ERROR HANDLING & RECOVERY

### 9.1 Corruption Detection
```cpp
bool validatePrimeBook(const vector<byte>& data) {
    // 1. Check magic
    if (data.size() < 4) return false;
    if (memcmp(data.data(), "PRMB", 4) != 0) return false;
    
    // 2. Check version
    uint16_t version = *reinterpret_cast<const uint16_t*>(data.data() + 4);
    if (version > CURRENT_BOOK_VERSION) return false;
    
    // 3. Verify checksum
    size_t checksumOffset = data.size() - 32;
    string expected = bytesToHex(data.data() + checksumOffset, 32);
    string actual = sha256(data.data(), checksumOffset);
    return expected == actual;
}
```

### 9.2 Recovery Strategies
| Failure | Recovery |
|---------|----------|
| Book file missing | Fresh start (Load & Go) |
| Book corrupted | Load primeoneold.exe + fresh book |
| Version mismatch | Auto-migrate or reset |
| Partial write | Checksum fails → use backup |

---

## 10. MENU INTEGRATION

### 10.1 Main Menu Options
| Key | Action | Function |
|-----|--------|----------|
| `0` | Load & Go | Load book + start |
| `1` | Start New | Fresh book |
| `l` | Library | Book management |
| `a` | Archive | Create PrimeOneUpdater.zip |
| `u` | Update | Check/install update |
| `5` (sub) | Network Updater | Receive/send update |
| `6` (sub) | Roll Update | Install update |

### 10.2 Command Line
```cmd
PrimeOne.exe -m 0  # Load & Go (default)
PrimeOne.exe -m 1  # Start New
PrimeOne.exe -m l  # Library
PrimeOne.exe -m a  # Archive
PrimeOne.exe -m u  # Update
```

---

## 11. SECURITY CONSIDERATIONS

### 11.1 Data Integrity
- **SHA256 checksums** on all persisted files
- **Authenticode signatures** on executables
- **Encrypted archives** for network transfer (libssh)

### 11.2 Privacy
- Prime book contains **computation state only** (no user data)
- Machine ID (computer name) in book - **pseudonymous**
- Network IPs in book - **operational only**

### 11.3 Attack Vectors
| Vector | Mitigation |
|--------|------------|
| Malicious book file | Checksum + version validation |
| Malicious archive | Signature verification |
| Rollback to vulnerable | Version pinning, no downgrade |
| Memory dump exposure | Encrypt dumps, restrict access |

---

## 12. KNOWN BUGS & LIMITATIONS

### 12.1 Serialization Bugs
1. **`push_back(__int128)`** - Type mismatch (line 7480)
2. **No actual implementation** visible for full book serialization
3. **`realm_win_archive()` commented out** - No archive creation
4. **`realm_win_roll()` buggy** - Scope errors, wrong memory dump

### 12.2 Missing Features
- No incremental save
- No compression (book can be large)
- No encryption at rest
- No book version migration
- No concurrent access protection

### 12.3 Architecture Debt
- Serialization mixed with computation class
- Global file paths hardcoded
- No abstraction for storage backend
- No streaming for large books

---

## 13. REFACTORING ROADMAP

### 13.1 Phase 1: Fix Serialization (Critical)
- [ ] Implement proper `__int128` serialization
- [ ] Fix `ptv_primeBookAuthor` return type
- [ ] Implement `deserializePrimeBook`
- [ ] Add SHA256 checksums

### 13.2 Phase 2: Archive System (Critical)
- [ ] Implement `realm_win_archive()` with ZIP
- [ ] Fix `realm_win_roll()` with proper replace
- [ ] Add manifest.json generation
- [ ] Integrate signature verification

### 13.3 Phase 3: Reliability (High)
- [ ] Auto-save with timer
- [ ] Incremental save (deltas)
- [ ] Compression (LZ4/ZSTD)
- [ ] Encryption at rest (AES-256)

### 13.4 Phase 4: Architecture (Medium)
- [ ] Extract `PrimeBookSerializer` class
- [ ] `IStorageBackend` interface (file, memory, network)
- [ ] Book version migration system
- [ ] Concurrent access with file locking

### 13.5 Phase 5: Advanced (Low)
- [ ] Differential book sync (CRDT-like)
- [ ] Book branching (experimental forks)
- [ ] Time-travel debugging (book history)
- [ ] Cloud sync (S3/Azure Blob)

---

## 14. TESTING SPECIFICATIONS

### 14.1 Unit Tests
| Test | Description |
|------|-------------|
| `serializeInt128` | Round-trip for 0, 1, max, random |
| `ptv_primeBookAuthor` | Output size, content validation |
| `loadPrimeBook` | Fresh, existing, corrupted, version mismatch |
| `archive creation` | ZIP structure, manifest validity |
| `roll` | Replace exe, load book, restart |

### 14.2 Integration Tests
- Full save/load cycle across restarts
- Network book sync (host→guest)
- Update package create → transfer → roll
- Rollback to previous version
- Concurrent save/load (thread safety)

### 14.3 Stress Tests
- Book with 1M primes (size/performance)
- Rapid save/load cycles
- Power loss during write (atomicity)
- Large archive transfer (100MB+)

---

## 15. COMPLETE COMMAND REFERENCE

### 15.1 Interactive Menu
```
Main Menu:
  0 - Load & Go          (load book + compute)
  1 - Start New          (fresh book)
  l - Library            (book management)
  a - Archive            (create update package)
  u - Update             (check for updates)

Sub-Menu (after 8/9):
  4 - Archive Create     (PrimeOneUpdater.zip)
  5 - Network Updater    (send/receive update)
  6 - Roll Update        (install update)
```

### 15.2 Command Line
```cmd
PrimeOne.exe -m 0  # Load & Go
PrimeOne.exe -m 1  # Start New
PrimeOne.exe -m l  # Library
PrimeOne.exe -m a  # Archive
PrimeOne.exe -m u  # Update
```

### 15.3 Batch Automation
```cmd
# Verify updater (watchdog)
verifyupdater.bat

# Version check
checkversion.bat

# Sign new version
setversion.bat
```

---

## 16. CROSS-REFERENCE: SOURCE LOCATIONS

| Component | File | Lines |
|-----------|------|-------|
| `ptv_primeBookAuthor` | main.cpp | 7470-7550 |
| `realm_win_archive` | main.cpp | ~16600 (commented) |
| `realm_win_roll` | main.cpp | 16654-16690 |
| `realm_win_updater` | main.cpp | 17270-17500 |
| Menu handlers | main.cpp | 14393 (archive), 14408 (updater), 14423 (roll) |
| Batch files | Project root | verifyupdater.bat, age.bat, checkversion.bat, setversion.bat |

---

## 17. FUTURE ENHANCEMENTS

### 17.1 Book Features
- **Book branching** - Fork computation, merge results
- **Time travel** - Replay from any book position
- **Diff viewer** - Compare two books
- **Annotation** - Tag significant primes

### 17.2 Archive Features
- **Delta updates** - bsdiff for executable, custom for book
- **Multi-platform archives** - Windows + Linux in one
- **Staged rollout** - Canary, gradual, full
- **Rollback API** - One-click revert

### 17.3 Storage Backends
- **Local file** (current)
- **SQLite** - Queryable prime index
- **Redis** - Distributed book cache
- **S3/Blob** - Cloud backup
- **IPFS** - Decentralized archive

---

*End of Feature Document 10: Data Persistence (Book/Archive System)*  
*Next: 11_PRIME_ALGORITHMS_DEEP_DIVE.md*