# PrimeOne - Feature Document 12: Distributed Consensus & Verification
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` conduitClass, primeTileClass verification, network protocol  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Distributed Consensus system ensures **correctness and agreement** across the PrimeOne network. When guests compute primes, the host must **verify** results before accepting them into the global prime book. This creates a **trust-but-verify** model where guests do work but host validates.

### Design Philosophy
- **Host authority** - Final arbiter of prime validity
- **Deterministic verification** - Same algorithm on host and guest
- **Byzantine tolerance** - Malicious/broken guests detected
- **Incentive compatible** - Guests rewarded for valid work
- **Audit trail** - Complete history for dispute resolution

---

## 2. CONSENSUS ARCHITECTURE

### 2.1 Trust Model
```
┌─────────────────────────────────────────────────────────────────┐
│                     TRUST BOUNDARIES                             │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  HOST (Authority)                                               │
│  ├── Owns prime book (source of truth)                          │
│  ├── Validates ALL guest submissions                            │
│  ├── Distributes work units                                     │
│  ├── Maintains guest reputation scores                          │
│  └── Can blacklist malicious guests                             │
│                                                                  │
│  GUESTS (Workers)                                               │
│  ├── Receive work units from host                               │
│  ├── Compute primes independently                               │
│  ├── Submit results with proof                                  │
│  ├── Cannot modify prime book directly                          │
│  └── Reputation affects work assignment                         │
│                                                                  │
│  NETWORK (Transport)                                            │
│  ├── TCP/IP (unencrypted, unauthenticated)                      │
│  ├── No consensus protocol (host = leader)                      │
│  └── Vulnerable to MITM, replay, injection                      │
│                                                                  │
└─────────────────────────────────────────────────────────────────┘
```

### 2.2 Consensus Flow
```
1. HOST: Generate work unit (tile range)
   │
   ▼
2. HOST → GUEST: Send work unit via conduit
   │
   ▼
3. GUEST: Compute primes in range
   │
   ▼
4. GUEST → HOST: Submit results + metadata
   │
   ▼
5. HOST: VERIFY each submitted prime
   ├── Trial division against primeIndex
   ├── Miller-Rabin (for large primes)
   ├── Check gap consistency
   └── Check tile continuity
   │
   ▼
6. HOST: ACCEPT or REJECT
   ├── ACCEPT: Add to prime book, update stats, reward guest
   ├── REJECT: Request re-compute, penalize guest
   │
   ▼
7. HOST: Broadcast accepted primes to all guests (sync)
```

---

## 3. VERIFICATION PROTOCOL

### 3.1 Verification Levels
| Level | Algorithm | Use Case | Cost |
|-------|-----------|----------|------|
| **L1: Quick** | Trial division by small primes | Screening | Low |
| **L2: Full** | Trial division up to √n | 64-bit primes | Medium |
| **L3: Probabilistic** | Miller-Rabin (12 bases) | 128-bit primes | Low |
| **L4: Certificate** | Pratt certificate | Audit trail | High |

### 3.2 Host Verification Implementation
```cpp
bool Host::verifyGuestPrime(const GuestSubmission& sub) {
    // 1. Basic sanity
    if (sub.prime < 2) return false;
    if (sub.prime % 2 == 0) return sub.prime == 2;
    
    // 2. Range check
    if (sub.prime < sub.workUnit.start || sub.prime >= sub.workUnit.end) {
        log("Prime out of assigned range");
        return false;
    }
    
    // 3. Deterministic verification
    if (!primeTileClass::verifyPrime(sub.prime)) {
        log("Prime verification failed");
        return false;
    }
    
    // 4. Gap consistency (optional)
    __int128 expectedGap = sub.prime - getPreviousPrime(sub.prime);
    if (sub.gap != expectedGap) {
        log("Gap mismatch: expected " + toString(expectedGap) + 
            " got " + toString(sub.gap));
        return false;
    }
    
    // 5. Tile continuity
    if (!verifyTileContinuity(sub)) return false;
    
    return true;
}
```

### 3.3 Guest Proof of Work
```cpp
struct GuestSubmission {
    __int128 prime;
    __int128 workUnitId;
    __int128 gap;                    // Prime gap from previous
    vector<byte> tileData;           // Serialized tile state
    __int128 computeTimeMs;          // Proof of work
    string guestId;                  // Unique identifier
    uint64_t nonce;                  // Anti-replay
    byte signature[64];              // Ed25519 (future)
};
```

---

## 4. REPUTATION SYSTEM

### 4.1 Guest Scoring
```cpp
struct GuestReputation {
    string guestId;
    int totalSubmissions = 0;
    int accepted = 0;
    int rejected = 0;
    int timeouts = 0;
    double score = 1.0;  // 0.0 - 1.0
    
    void recordAccept() {
        totalSubmissions++;
        accepted++;
        score = min(1.0, score + 0.01);
    }
    
    void recordReject() {
        totalSubmissions++;
        rejected++;
        score = max(0.0, score - 0.05);
    }
    
    void recordTimeout() {
        timeouts++;
        score = max(0.0, score - 0.02);
    }
    
    bool isTrusted() const { return score > 0.7; }
    bool isSuspicious() const { return score < 0.3; }
    bool isBanned() const { return score <= 0.0; }
};
```

### 4.2 Work Assignment by Reputation
```cpp
TileRange Host::assignWork(const GuestReputation& rep) {
    if (rep.isBanned()) return TileRange::EMPTY;
    
    int difficulty = 1;
    if (rep.isTrusted()) difficulty = 3;      // More work
    else if (rep.score > 0.5) difficulty = 2;
    
    return getWorkUnit(difficulty);
}
```

---

## 5. BYZANTINE FAULT TOLERANCE

### 5.1 Attack Vectors
| Attack | Description | Detection | Mitigation |
|--------|-------------|-----------|------------|
| **Invalid primes** | Submit composites | Verification | Reject + penalty |
| **Duplicates** | Re-submit known primes | PrimeIndex lookup | Reject |
| **Range violation** | Primes outside assigned tile | Range check | Reject |
| **Gap spoofing** | Fake gap values | Gap verification | Reject |
| **Replay** | Resubmit old results | Nonce/timestamp | Reject |
| **Sybil** | Many fake guests | IP/identity limit | Rate limit |
| **Eclipse** | Isolate host from honest guests | Multi-path | Mesh network |

### 5.2 Detection Algorithms
```cpp
bool Host::detectAnomaly(const GuestSubmission& sub) {
    // 1. Statistical anomaly
    if (sub.computeTimeMs < MIN_EXPECTED_TIME) {
        return true;  // Too fast = precomputed/faked
    }
    
    // 2. Pattern analysis
    if (sub.gap == lastGapFromSameGuest) {
        return true;  // Repeated gaps = not computing
    }
    
    // 3. Prime distribution
    if (!followsPrimeDistribution(sub.prime)) {
        return true;  // Doesn't match prime number theorem
    }
    
    return false;
}
```

---

## 6. NETWORK PROTOCOL FOR CONSENSUS

### 6.1 Message Types
```cpp
enum ConsensusMessageType : uint8_t {
    // Work distribution
    MSG_WORK_ASSIGN = 0x10,
    MSG_WORK_REQUEST = 0x11,
    MSG_WORK_COMPLETE = 0x12,
    
    // Verification
    MSG_PRIME_SUBMIT = 0x20,
    MSG_PRIME_ACCEPT = 0x21,
    MSG_PRIME_REJECT = 0x22,
    MSG_PRIME_RECOMPUTE = 0x23,
    
    // Synchronization
    MSG_BOOK_SYNC = 0x30,
    MSG_BOOK_DELTA = 0x31,
    MSG_HEARTBEAT = 0x32,
    
    // Reputation
    MSG_REPUTATION_UPDATE = 0x40,
    MSG_BAN_NOTICE = 0x41,
    
    // Errors
    MSG_ERROR = 0xFF
};
```

### 6.2 Verification Message Flow
```
GUEST                              HOST
  │                                  │
  ├── MSG_PRIME_SUBMIT ────────────►│
  │   {prime, workUnitId, gap,      │
  │    tileData, computeTime,       │
  │    guestId, nonce}              │
  │                                  │
  │       [VERIFICATION]             │
  │                                  │
  │◄── MSG_PRIME_ACCEPT ────────────┤
  │   {prime, bookIndex, reward}    │
  │                                  │
  // OR
  │◄── MSG_PRIME_REJECT ────────────┤
  │   {reason, penalty}             │
  │                                  │
  // OR
  │◄── MSG_PRIME_RECOMPUTE ─────────┤
  │   {workUnitId, hint}            │
```

---

## 7. SYNCHRONIZATION & STATE CONSISTENCY

### 7.1 Prime Book Synchronization
```cpp
// Host broadcasts accepted primes to all guests
void Host::broadcastAcceptedPrime(const AcceptedPrime& prime) {
    SyncMessage msg;
    msg.type = MSG_BOOK_DELTA;
    msg.prime = prime.prime;
    msg.index = prime.index;
    msg.gap = prime.gap;
    msg.timestamp = time(nullptr);
    
    for (auto& guest : connectedGuests) {
        guest.send(msg);
    }
}

// Guest applies delta
void Guest::applyBookDelta(const SyncMessage& msg) {
    if (msg.type == MSG_BOOK_DELTA) {
        primeTileClass.addPrime(msg.prime);
        primeTileClass.setPrimeIndex(msg.index, msg.prime);
        primeTileClass.recordGap(msg.gap);
    }
}
```

### 7.2 Conflict Resolution
```cpp
// If guest has different prime at same index
enum ConflictResolution {
    HOST_WINS,        // Host is authority
    VERIFY_BOTH,      // Re-verify both, accept valid
    MAJORITY_VOTE,    // If multiple guests agree
    HIGHEST_REP       // Trust highest reputation
};

// Current: HOST_WINS (implicit)
```

### 7.3 Fork Handling
```cpp
// If network partition creates forks
void Host::resolveFork(const vector<PrimeBook>& forks) {
    // 1. Find common ancestor
    auto ancestor = findCommonAncestor(forks);
    
    // 2. Validate each fork from ancestor
    vector<PrimeBook> validForks;
    for (auto& fork : forks) {
        if (verifyForkFrom(ancestor, fork)) {
            validForks.push_back(fork);
        }
    }
    
    // 3. Choose longest valid chain (most primes)
    auto best = max_element(validForks, 
        [](a,b) { return a.totalPrimes < b.totalPrimes; });
    
    // 4. Broadcast chosen fork
    broadcastBook(*best);
}
```

---

## 8. INCENTIVE MECHANICS

### 8.1 Reward Structure
```cpp
struct Reward {
    __int128 primeCredit;      // Credit for prime discovery
    double reputationBonus;    // Reputation multiplier
    bool bonusPrime;           // Special prime (twin, Sophie Germain, etc.)
};

Reward calculateReward(const AcceptedPrime& prime, const GuestReputation& rep) {
    Reward r;
    r.primeCredit = 1;  // Base credit per prime
    
    // Gap bonus
    if (prime.gap > 100) r.primeCredit *= 2;
    if (prime.gap > 1000) r.primeCredit *= 5;
    
    // Special prime bonuses
    if (isTwinPrime(prime.prime)) r.bonusPrime = true;
    if (isSophieGermain(prime.prime)) r.primeCredit *= 3;
    if (isSafePrime(prime.prime)) r.primeCredit *= 2;
    
    // Reputation multiplier
    r.reputationBonus = 0.5 + rep.score * 0.5;  // 0.5x to 1.0x
    
    return r;
}
```

### 8.2 Penalty Structure
```cpp
struct Penalty {
    double reputationLoss;
    int workBanDuration;  // seconds
    bool permanentBan;
};

Penalty calculatePenalty(const RejectionReason reason, const GuestReputation& rep) {
    switch (reason) {
        case INVALID_PRIME:      return {0.10, 300, false};
        case DUPLICATE_PRIME:    return {0.05, 60, false};
        case RANGE_VIOLATION:    return {0.20, 600, false};
        case GAP_SPOOFING:       return {0.30, 1800, false};
        case REPLAY_ATTACK:      return {0.50, 0, true};  // Permaban
        case SYBIL_DETECTED:     return {1.00, 0, true};  // Permaban
    }
}
```

---

## 9. AUDIT & TRANSPARENCY

### 9.1 Verification Log
```cpp
struct VerificationLogEntry {
    time_t timestamp;
    string guestId;
    __int128 prime;
    VerificationResult result;  // ACCEPTED/REJECTED
    string reason;              // If rejected
    int hostVerifierId;         // Which verifier (if multiple)
    string guestProofHash;      // Hash of submission
};

vector<VerificationLogEntry> verificationLog;

// Periodic audit
void auditVerificationLog() {
    // Check: No gaps in verification sequence
    // Check: Rejection rates within bounds
    // Check: No single guest dominates accepts
    // Export for external audit
}
```

### 9.2 Public Verifiability
```cpp
// Anyone can verify host's prime book
class PublicAuditor {
    bool verifyPrimeBook(const PrimeBook& book) {
        // 1. Verify all primes in book
        for (auto p : book.primeIndex) {
            if (!verifyPrime(p)) return false;
        }
        
        // 2. Verify gaps match
        for (size_t i = 1; i < book.primeIndex.size(); ++i) {
            __int128 gap = book.primeIndex[i] - book.primeIndex[i-1];
            if (gap != book.gapHistory[i-1].gap) return false;
        }
        
        // 3. Verify chronological order
        for (size_t i = 1; i < book.gapHistory.size(); ++i) {
            if (book.gapHistory[i].timestamp < book.gapHistory[i-1].timestamp) 
                return false;
        }
        
        return true;
    }
};
```

---

## 10. CURRENT IMPLEMENTATION GAPS

### 10.1 What Exists
- Basic host/guest work distribution (conduitClass)
- Prime verification in primeTileClass
- Network transport (TCP)
- Menu integration for host/guest modes

### 10.2 What's Missing
| Feature | Status | Priority |
|---------|--------|----------|
| Explicit verification step | ❌ Implicit only | CRITICAL |
| Guest submission structure | ❌ Ad-hoc | HIGH |
| Reputation system | ❌ None | HIGH |
| Rejection handling | ❌ None | HIGH |
| Book synchronization | ❌ Commented | HIGH |
| Audit logging | ❌ None | MEDIUM |
| Byzantine detection | ❌ None | MEDIUM |
| Incentive mechanics | ❌ None | LOW |

### 10.3 Code Evidence of Gaps
```cpp
// In conduit_win_hosts - no verification visible:
void conduitClass::conduit_win_hosts(...) {
    // Receives data but doesn't call verifyPrime()
    // Just processes and continues
}

// In librarian_functions - direct trust:
winTelConduits.weaverBegin(...);  // No verification callback
```

---

## 11. REQUIRED CONSENSUS ENHANCEMENTS

### 11.1 Phase 1: Explicit Verification (Critical)
```cpp
// In host work handling loop:
while (running) {
    auto submission = receiveSubmission();
    
    // EXPLICIT VERIFICATION
    if (verifyPrime(submission.prime)) {
        // Check against work unit
        if (isInWorkUnit(submission.prime, submission.workUnitId)) {
            acceptPrime(submission);
            broadcastAccepted(submission);
            updateReputation(submission.guestId, +1);
        } else {
            rejectPrime(submission, "RANGE_VIOLATION");
            updateReputation(submission.guestId, -1);
        }
    } else {
        rejectPrime(submission, "INVALID_PRIME");
        updateReputation(submission.guestId, -2);
    }
}
```

### 11.2 Phase 2: Reputation System (High)
- [ ] GuestReputation class
- [ ] Persistent reputation storage
- [ ] Work assignment by reputation
- [ ] Ban/unban mechanics

### 11.3 Phase 3: Byzantine Hardening (High)
- [ ] Nonce/timestamp anti-replay
- [ ] Statistical anomaly detection
- [ ] Sybil resistance (IP limits, PoW)
- [ ] Eclipse attack detection

### 11.4 Phase 4: Audit & Transparency (Medium)
- [ ] VerificationLog with tamper-evident append-only
- [ ] Merkle tree for prime book
- [ ] Public audit API
- [ ] Third-party verifier support

---

## 12. INTEGRATION WITH PRIME TILE ENGINE

### 12.1 Verification Callback
```cpp
// PrimeTileClass needs to expose verification
class primeTileClass {
public:
    // Static - no instance state needed for pure verification
    static bool verifyPrimeStatic(__int128 candidate, 
                                   const vector<__int128>& knownPrimes) {
        // Trial division + Miller-Rabin
    }
    
    // Instance - uses internal primeIndex
    bool verifyPrime(__int128 candidate) {
        return verifyPrimeStatic(candidate, primeIndex);
    }
};
```

### 12.2 Work Unit Binding
```cpp
// Each prime cryptographically bound to work unit
struct WorkUnitProof {
    __int128 prime;
    __int128 workUnitHash;  // Hash of work unit parameters
    __int128 nonce;         // Proof of work nonce
    byte signature[64];     // Guest signature
};
```

---

## 13. TESTING SPECIFICATIONS

### 13.1 Consensus Tests
| Test | Description |
|------|-------------|
| Valid prime acceptance | Host accepts correct prime |
| Invalid prime rejection | Host rejects composite |
| Range enforcement | Host rejects out-of-range |
| Duplicate detection | Host rejects known prime |
| Gap verification | Host checks gap consistency |
| Reputation update | Score changes on accept/reject |

### 13.2 Byzantine Tests
| Test | Description |
|------|-------------|
| Sybil attack | Multiple guests same IP limited |
| Replay attack | Old submission rejected |
| Eclipse attack | Host detects isolation |
| Collusion | Multiple bad guests can't override |

### 13.3 Stress Tests
- 100 guests, 10% malicious
- Network partition during sync
- Host restart with guest reconnect
- Rapid prime submission flood

---

## 14. CROSS-REFERENCE: SOURCE LOCATIONS

| Component | File | Lines |
|-----------|------|-------|
| Host work handling | main.cpp | 9718-10630 (conduit_win_host) |
| Guest work handling | main.cpp | 9090-9717 (conduit_win_guests) |
| Verification | main.cpp | 6720-6800 (verifyPrime) |
| Network protocol | main.cpp | 10632-11550 (conduit_weaver) |
| Prime submission | main.cpp | 13079 (realm_conduit_win_guest) |
| Menu integration | main.cpp | 14304-14326 (options 8/9) |

---

## 15. COMPLETE COMMAND REFERENCE

### 15.1 Consensus Commands (Menu)
```
Host Mode (-m 8):
  Sub-menu option 3: Show peers (verify connectivity)
  Sub-menu option 5: Network Updater (sync books)

Guest Mode (-m 9):
  Sub-menu option 3: Show host connection
  Sub-menu option 5: Request update/sync
```

### 15.2 Programmatic
```cpp
// Host
host.verifyGuestPrime(submission);  // Returns bool
host.getGuestReputation(guestId);   // Returns score
host.banGuest(guestId);             // Permanent ban

// Guest
guest.submitPrime(prime, workUnit); // Returns ACCEPT/REJECT
guest.getReputation();              // Returns own score
```

---

## 16. FUTURE CONSENSUS EVOLUTION

### 16.1 Multi-Host (Future)
```
┌─────────────────────────────────────────────────────────────┐
│                    FEDERATED CONSENSUS                       │
├─────────────────────────────────────────────────────────────┤
│                                                              │
│  Host Cluster (Raft/Paxos)                                  │
│  ├── Leader: Coordinates work, validates                    │
│  ├── Followers: Replicate prime book, validate              │
│  └── Guests: Submit to any host                             │
│                                                              │
│  Benefits:                                                  │
│  - No single point of failure                               │
│  - Horizontal scaling                                       │
│  - Geographic distribution                                  │
│                                                              │
└─────────────────────────────────────────────────────────────┘
```

### 16.2 Zero-Knowledge Verification
- Guests prove prime validity without revealing computation
- ZK-SNARKs for prime verification
- Privacy-preserving prime discovery

### 16.3 Blockchain Integration
- Prime book as immutable ledger
- Smart contracts for rewards
- Decentralized verification market

---

*End of Feature Document 12: Distributed Consensus & Verification*  
*Next: 13_CONFIGURATION_STATE_MANAGEMENT.md*