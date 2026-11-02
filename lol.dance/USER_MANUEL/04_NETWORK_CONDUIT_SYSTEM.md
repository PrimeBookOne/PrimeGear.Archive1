# PrimeOne - Feature Document 04: Network Conduit System (Host/Guest)
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` lines ~8918-11800 (conduitClass), 14304-14326 (menu handlers)  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

The Network Conduit System (`conduitClass`) implements a **distributed prime computation network** using a **Host/Guest architecture** over TCP/IP. The host coordinates work distribution and result aggregation, while guests perform assigned prime computations and return results. The system uses raw Winsock2 sockets with custom binary serialization for `__int128` prime data and `std::byte` tile buffers.

### Design Philosophy
- **Simple protocol** - Raw TCP, custom binary format
- **Host authority** - Host controls work queue, guests are workers
- **Stateless tiles** - Work units independently verifiable
- **Resilient** - Guests can join/leave, host redistributes work
- **Extensible** - Weaver pattern for protocol evolution

---

## 2. CLASS ARCHITECTURE

### 2.1 conduitClass Definition
```cpp
class conduitClass {
private:
    int dataPort;                    // TCP port (default 5678)
    // Network state
    SOCKET hostSocket;               // Host listening socket
    SOCKET guestSocket;              // Guest connection socket
    // Threading
    std::vector<std::thread> workerThreads;
    std::mutex queueMutex;
    std::condition_variable workCV;
    // Work distribution
    std::queue<TileRange> workQueue;
    std::unordered_map<GuestID, GuestState> guests;
    // Synchronization
    std::atomic<bool> running{true};
    std::atomic<bool> weaving{false};

public:
    conduitClass(int dataPortIN = 5678) : dataPort(dataPortIN) {}
    
    // Entry points
    void weaverBegin(string uniqueIdGlobal, bool createHost,
                     __int128 weaverBeginData, string hostIp, int hostPort);
    
    // Host methods
    void conduit_weaver(string uniqueIdGlobal, bool createHostCommand,
                        __int128 weaverBeginData, string hostIp, int hostPort);
    void conduit_win_hosts(__int128 weaverDataHost, string uniqueId,
                           string randomString1, string randomString2, string randomString3,
                           bool firstPassTorch, bool passTorch, int weavePort,
                           bool reAssignmentBool, primeTileClass PrimeOne);
    void conduit_win_host(string uniqueId, int conduit, int myPort, string myIP,
                          int remotePort, string remoteIP, string instruction,
                          string randomString1, string randomString2, string randomString4,
                          bool firstPassTorch, bool passTorch, bool reAssignmentBool,
                          primeTileClass PrimeOne);
    
    // Guest methods
    void conduit_win_guests(__int128 weaverDataGear, string uniqueId,
                            string randomString1, string randomString2, string randomString3,
                            bool& weaveHost, int& weavePort, int& returnData,
                            int& weavePortHost, int& weaveNewPort,
                            vector<byte> primeCatch, string hostIp);
    
    // Async guest connection
    tuple<int, string, string, __int128, int, int, int, vector<byte>, int, 
          unique_ptr<byte[]>> realm_conduit_win_guest(
        string hostIp, string returnGuestStatusIn, string uniqueId, int conduit,
        int myPort, string myIP, int remotePort, string remoteIP, string instruction,
        string randomString1, string randomString2, string randomString3,
        vector<byte> primeCatch, int returnPrimeQue, int privateGrid,
        int tileCount, int returnTileReceives);
    
    // Utilities
    int vectorToByteArray(const vector<byte>&, byte*, size_t);
};
```

---

## 3. NETWORK PROTOCOL

### 3.1 Transport Layer
- **Protocol**: TCP/IP (Winsock2)
- **Port**: Configurable (default 5678, batch files use 54767)
- **Address Family**: AF_INET (IPv4)
- **Socket Type**: SOCK_STREAM (reliable, ordered)

### 3.2 Message Format (Inferred)
```
┌─────────────────────────────────────────────────────────────┐
│                    CONDUIT MESSAGE FRAME                     │
├──────────────┬──────────────┬──────────────┬────────────────┤
│  Magic (4B)  │  Type (1B)   │  Length (4B) │  Payload (N B) │
├──────────────┼──────────────┼──────────────┼────────────────┤
│ 0x50524D31  │  0x01=WORK   │  Variable    │  Tile Range    │
│  ("PRM1")   │  0x02=RESULT │  (big-endian)│  + Prime Data  │
│             │  0x03=HEART  │              │                │
│             │  0x04=SYNC   │              │                │
│             │  0xFF=ERROR  │              │                │
└──────────────┴──────────────┴──────────────┴────────────────┘
```

### 3.3 Serialization (Inferred from Code)
```cpp
// __int128 serialization (16 bytes, little-endian)
void serializeInt128(__int128 value, byte* buffer) {
    for (int i = 0; i < 16; ++i) {
        buffer[i] = static_cast<byte>(value & 0xFF);
        value >>= 8;
    }
}

__int128 deserializeInt128(const byte* buffer) {
    __int128 result = 0;
    for (int i = 15; i >= 0; --i) {
        result = (result << 8) | static_cast<__int128>(buffer[i]);
    }
    return result;
}

// std::byte vector → raw buffer
int vectorToByteArray(const vector<byte>& vec, byte* out, size_t maxSize) {
    size_t len = min(vec.size(), maxSize);
    memcpy(out, vec.data(), len);
    return static_cast<int>(len);
}
```

---

## 4. HOST OPERATION (conduit_win_hosts / conduit_win_host)

### 4.1 Host Initialization Sequence
```cpp
// From weaverBegin() → conduit_weaver() → conduit_win_hosts()
void conduitClass::conduit_win_hosts(...) {
    // 1. Initialize Winsock
    WORD ver = MAKEWORD(2, 2);
    WSADATA wsaData;
    WSAStartup(ver, &wsaData);
    
    // 2. Create listening socket
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // 3. Bind to port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(weavePort);  // 5678 or from -p
    hint.sin_addr.S_un.S_addr = INADDR_ANY;  // Bind all interfaces
    
    bind(listenSocket, (sockaddr*)&hint, sizeof(hint));
    listen(listenSocket, SOMAXCONN);
    
    // 4. Accept loop
    while (running) {
        SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
        // Spawn handler thread
        workerThreads.emplace_back(&conduitClass::handleGuest, this, clientSocket);
    }
}
```

### 4.2 Host Work Distribution (conduit_win_hosts)
```cpp
// Work queue management
struct TileRange {
    __int128 startTile;
    __int128 endTile;
    __int128 powerOf;
    int singerCount;
    string computeMethod;
};

void conduitClass::distributeWork() {
    lock_guard<mutex> lock(queueMutex);
    while (!workQueue.empty() && !availableGuests.empty()) {
        auto range = workQueue.front(); workQueue.pop();
        auto guest = availableGuests.front(); availableGuests.pop();
        sendWorkToGuest(guest.socket, range);
    }
}
```

### 4.3 Host Result Aggregation
```cpp
void conduitClass::handleGuest(SOCKET guestSocket) {
    while (running) {
        // Receive result
        vector<byte> result = receiveFullMessage(guestSocket);
        
        // Deserialize primes
        vector<__int128> primes = deserializePrimes(result);
        
        // Verify each prime
        for (auto prime : primes) {
            if (PrimeOne.verifyPrime(prime)) {
                acceptedPrimes.push_back(prime);
                totalPrimes++;
            }
        }
        
        // Send next work unit or heartbeat
        if (!workQueue.empty()) {
            sendWorkToGuest(guestSocket, workQueue.front());
        } else {
            sendHeartbeat(guestSocket);
        }
    }
}
```

---

## 5. GUEST OPERATION (conduit_win_guests / realm_conduit_win_guest)

### 5.1 Guest Initialization Sequence
```cpp
// From weaverBegin() → conduit_weaver() → conduit_win_guests()
void conduitClass::conduit_win_guests(...) {
    // 1. Initialize Winsock
    WORD ver = MAKEWORD(2, 2);
    WSADATA wsaData;
    WSAStartup(ver, &wsaData);
    
    // 2. Create socket
    SOCKET connSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    // 3. Connect to host
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(hostPort);
    inet_pton(AF_INET, hostIp.c_str(), &hint.sin_addr);
    
    connect(connSocket, (sockaddr*)&hint, sizeof(hint));
    
    // 4. Send identification
    sendIdentification(connSocket, uniqueId, myPort, myIP);
    
    // 5. Work loop
    while (running) {
        // Receive work assignment
        TileRange range = receiveWork(connSocket);
        
        // Compute primes
        vector<__int128> primes = computeTileRange(range);
        
        // Send results
        sendResults(connSocket, primes);
    }
}
```

### 5.2 Async Guest Connection (realm_conduit_win_guest)
```cpp
// Launched via std::async for non-blocking connection
tuple<int, string, string, __int128, int, int, int, vector<byte>, int, 
      unique_ptr<byte[]>> realm_conduit_win_guest(
    string hostIp, string returnGuestStatusIn, string uniqueId, int conduit,
    int myPort, string myIP, int remotePort, string remoteIP, string instruction,
    string randomString1, string randomString2, string randomString3,
    vector<byte> primeCatch, int returnPrimeQue, int privateGrid,
    int tileCount, int returnTileReceives) 
{
    // Async TCP connection with timeout
    // Returns tuple with connection status and received data
    
    // Implementation uses non-blocking connect with select()
    // Timeout handling for unresponsive hosts
}
```

### 5.3 Guest Computation Loop
```cpp
vector<__int128> conduitClass::computeTileRange(const TileRange& range) {
    primeTileClass worker(range.powerOf, range.singerCount, 
                          0, 0, nullptr, 0, 0);
    
    vector<__int128> foundPrimes;
    for (__int128 tile = range.startTile; tile < range.endTile; ++tile) {
        // Compute primes in this tile
        __int128 prime = worker.nextWalkPrime(tile);
        if (prime != 0) {
            foundPrimes.push_back(prime);
        }
        
        // Check for cancellation
        if (!running) break;
    }
    return foundPrimes;
}
```

---

## 6. WEAVER PATTERN (conduit_weaver)

### 6.1 Purpose
The `conduit_weaver` is the **protocol orchestrator** that manages the host/guest state machine and coordinates the "weaving" of prime computation across the network.

### 6.2 State Machine
```
┌────────────────────────────────────────────────────────────────┐
│                     WEAVER STATE MACHINE                        │
├────────────────────────────────────────────────────────────────┤
│                                                                 │
│  createHost=true (HOST)          createHost=false (GUEST)      │
│  ┌─────────────────────┐         ┌─────────────────────┐       │
│  │ INIT                │         │ INIT                │       │
│  │   ↓ bind/listen     │         │   ↓ connect         │       │
│  │ LISTENING           │         │ CONNECTING          │       │
│  │   ↓ accept          │         │   ↓ connected       │       │
│  │ HANDLING_GUESTS ◄───┼────────►│ WORKING             │       │
│  │   ↓ work done       │         │   ↓ work done       │       │
│  │ AGGREGATING         │         │ SENDING_RESULTS     │       │
│  │   ↓ more work       │         │   ↓ ack received    │       │
│  └─────────────────────┘         └─────────────────────┘       │
│         │                                │                      │
│         └──────────────┬─────────────────┘                      │
│                        ▼                                        │
│              ┌─────────────────┐                                │
│              │ SHUTDOWN        │                                │
│              │ (on exit/err)   │                                │
│              └─────────────────┘                                │
└────────────────────────────────────────────────────────────────┘
```

### 6.3 Key Variables
```cpp
void conduitClass::conduit_weaver(string uniqueIdGlobal, bool createHostCommand,
                                  __int128 weaverBeginData, string hostIp, int hostPort) {
    __int128 songCount = pow(2, songPowerOf);      // Work units
    __int128 privateGrid = pow(2, powerOf);        // Tile grid size
    byte* returnTile = new byte[privateGrid];      // Result buffer
    
    // Host variables
    bool weaveNewHost = false;
    bool infinite = true;
    __int128 infiniteWalk = 0;
    int choirSize = 0;
    int assignedPort = globalNewHostPort;
    int hostConduits = conduits;
    int guestConduits = conduits;
    int conduitCount = 0;
    __int128 weaverDataHost = 0;
    
    // Guest variables (when not host)
    bool weaveHost = false;
    int weavePort = 0;
    int returnData = 0;
    int weavePortHost = 0;
    int weaveNewPort = 0;
    vector<byte> primeCatch;  // Received from host
    
    // Main weaving loop
    while (infinite) {
        if (createHostCommand) {
            conduit_win_hosts(weaverDataHost, uniqueIdGlobal, 
                             randomString1, randomString2, randomString3,
                             true, true, assignedPort, true, PrimeOne);
        } else {
            conduit_win_guests(weaverDataGear, uniqueIdGlobal,
                              randomString1, randomString2, randomString3,
                              weaveHost, weavePort, returnData,
                              weavePortHost, weaveNewPort,
                              primeCatch, hostIp);
        }
    }
}
```

---

## 7. SOCKET IMPLEMENTATION DETAILS

### 7.1 Winsock Initialization (Repeated in Host/Guest)
```cpp
// Lines 9742, 13107, 17282, 18233, 18543
WORD ver = MAKEWORD(2, 2);
WSADATA wsaData;
WSAStartup(ver, &wsaData);
```

**Issue:** Called multiple times without `WSACleanup()`. Should be once per process.

### 7.2 Socket Creation
```cpp
SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (sock == INVALID_SOCKET) {
    // Error handling
}
```

### 7.3 Address Structure Issues
```cpp
// Line 9761, 13118, 17298, 18565
sockaddr_in hint;
hint.sin_family = AF_INET;
hint.sin_port = htons(port);
hint.sin_addr.s_addr = inet_addr(ip.c_str());  // Returns uint32_t

// Line 9762, 13119, 17299 - BUG:
string ipAddress = inet_ntoa(hint.sin_addr);  // ERROR: hint.sin_addr is uint32_t, not in_addr
```
**Bug:** `sockaddr_in::sin_addr` is `in_addr` struct with `S_un.S_addr` member. Direct access to `sin_addr.s_addr` works on some platforms but `inet_ntoa()` expects `struct in_addr`.

**Fix:**
```cpp
in_addr addr;
addr.s_addr = hint.sin_addr.s_addr;
string ipAddress = inet_ntoa(addr);
```

### 7.4 Host Binding
```cpp
// Line 9761
hint.sin_addr.s_addr = inet_addr("127.0.0.1");  // Bind to localhost only
// Should use INADDR_ANY for all interfaces:
hint.sin_addr.s_addr = INADDR_ANY;
```

### 7.5 Computer Name Resolution (Lines 9888-9898, 17386-17394)
```cpp
char computerName[MAX_COMPUTERNAME_LENGTH + 1];
DWORD computerNameSize = sizeof(computerName);
ZeroMemory(host, NI_MAXHOST);
if (GetComputerName(computerName, &computerNameSize)) { ... }
```
Requires `windows.h` and linking with `kernel32.lib`.

---

## 8. COMMAND LINE INTEGRATION

### 8.1 Host Launch (Menu Option 8)
```cpp
// librarian_functions line 14318-14326
if (userInput == "8" && menueChoice == 0) {
    conduitClass winTelConduits(5678);
    createHost = true;
    __int128 weaverBeginData = 0;
    globalRemotePortString = hostPort;
    winTelConduits.weaverBegin(uniqueIdGlobal, createHost, 
                               weaverBeginData, hostIp, hostPort);
}
```

### 8.2 Guest Launch (Menu Option 9)
```cpp
// librarian_functions line 14304-14316
if (userInput == "9" && menueChoice == 0) {
    conduitClass winTelConduits(5678);
    createHost = false;
    __int128 weaverBeginData = 0;
    globalRemotePortString = hostPort;
    globalRemoteIpString = hostIp;
    winTelConduits.weaverBegin(uniqueIdGlobal, createHost, 
                               weaverBeginData, hostIp, hostPort);
}
```

### 8.3 Command Line Equivalent
```cmd
# Host
PrimeOne.exe -m 8 -p 54767 -ip 192.168.1.100 -c 4 -f quickPrime -x Gear

# Guest
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -c 2 -f quickPrime -x Gear -w g
```

---

## 9. BATCH FILE AUTOMATION

### 9.1 Host Batch (primeone8host - 54767.bat)
```batch
primeone.exe -m 8 -p 54767
```
- Starts host on port 54767
- Uses default IP (INADDR_ANY)
- No core limit (uses all)
- Default compute method (Gear)

### 9.2 Guest Batch (primeone9guestsShow - 54767.bat)
```batch
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```
- `start "" cmd /c` - Launches in NEW console window
- Allows multiple guests on same machine
- Connects to hardcoded host IP `10.0.0.22`
- Single core (`-c1`)
- Explicit guest role (`-w g`)

### 9.3 Multi-Guest Deployment Pattern
```batch
:: Launch 4 guests on same machine
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
start "" cmd /c primeone.exe -m 9 -p 54767 -ip 10.0.0.22 -c1 -w g
```

---

## 10. THREADING & CONCURRENCY

### 10.1 Host Threading
```cpp
// In conduit_win_hosts:
vector<thread> gitChoir;  // Worker threads
int vectorWalk = 0;

// Thread creation pattern:
gitChoir.emplace_back([this, clientSocket]() {
    handleGuest(clientSocket);
});

// Join on shutdown
for (auto& t : gitChoir) {
    if (t.joinable()) t.join();
}
```

### 10.2 Guest Threading
```cpp
// In realm_conduit_win_guest (async):
auto future = std::async(std::launch::async, [&]() {
    return realm_conduit_win_guest(...);
});

// Main thread can monitor or do other work
```

### 10.3 Synchronization Primitives Used
| Primitive | Purpose |
|-----------|---------|
| `std::mutex` | Protect work queue |
| `std::condition_variable` | Signal work available |
| `std::atomic<bool>` | Running/weaving flags |
| `std::async` | Async guest connection |
| `std::promise`/`std::future` | Result retrieval |

### 10.4 Missing Synchronization
- **No mutex** on `primeFindsArray` in primeTileClass
- **No atomic** on `infiniteWalk` counter
- **No memory ordering** specifications
- **Potential data races** on shared state

---

## 11. ERROR HANDLING & RESILIENCE

### 11.1 Current Error Handling
```cpp
// Socket errors checked but not propagated well
if (connect(...) == SOCKET_ERROR) {
    int err = WSAGetLastError();
    // Just continues or exits silently
}
```

### 11.2 Missing Resilience Features
| Feature | Status | Needed |
|---------|--------|--------|
| Connection retry | ❌ | Exponential backoff |
| Heartbeat/keepalive | ❌ | Detect dead guests |
| Work requeue on guest disconnect | ❌ | Host must track |
| Graceful shutdown | ❌ | Signal handling |
| TLS/Encryption | ❌ | libssh available but unused |
| Authentication | ❌ | Trusted LAN only |

### 11.3 Resource Leaks
- `WSACleanup()` never called
- Sockets not closed on error paths
- Thread handles not joined on early exit
- `addrinfo` not freed in `getaddrinfo` paths

---

## 12. SECURITY ANALYSIS

### 12.1 Vulnerabilities
| Issue | Severity | Location |
|-------|----------|----------|
| No authentication | HIGH | All network code |
| No encryption | HIGH | All network code |
| Buffer overflows | HIGH | `recv()` into fixed buffers |
| Command injection | MEDIUM | `system("cls")`, `system()` calls |
| Hardcoded IPs | LOW | Batch files, defaults |
| Port prediction | LOW | Sequential ports |

### 12.2 Mitigation (Current)
- **None** - Code assumes trusted LAN environment
- libssh compiled but not used in conduit path

### 12.3 Recommended Security Additions
```cpp
// 1. TLS via libssh (already linked)
ssh_session session = ssh_new();
ssh_options_set(session, SSH_OPTIONS_HOST, hostIp.c_str());
ssh_connect(session);
ssh_userauth_password(session, "primeone", "secure_password");
ssh_channel channel = ssh_channel_new(session);
ssh_channel_open_session(channel);
// Tunnel TCP through SSH

// 2. Message authentication
struct SignedMessage {
    uint32_t magic;
    uint8_t type;
    uint32_t length;
    byte payload[];
    byte hmac[32];  // HMAC-SHA256
};

// 3. Input validation
bool validateIP(const string& ip) {
    // RFC 3986 compliant validation
}
```

---

## 13. PERFORMANCE CHARACTERISTICS

### 13.1 Latency Budget
| Operation | Typical Latency |
|-----------|-----------------|
| Localhost TCP round-trip | < 1ms |
| LAN (1Gbps) round-trip | 0.5-2ms |
| Work unit serialization | ~10μs per 1KB |
| Prime verification (CPU) | ~100μs per 64-bit prime |
| Prime verification (GPU) | ~10μs per 64-bit prime |

### 13.2 Throughput Estimates
- **Single guest (CPU)**: ~10,000 primes/second (64-bit)
- **Single guest (GPU)**: ~100,000 primes/second
- **Host aggregation**: ~1,000,000 results/second
- **Network saturation**: ~100 Mbps sustained

### 13.3 Scaling Limits
| Guests | Host CPU | Network | Bottleneck |
|--------|----------|---------|------------|
| 1-8 | Low | Low | Guest compute |
| 16-32 | Medium | Medium | Host aggregation |
| 64+ | High | High | Network/Serialization |

---

## 14. CONFIGURATION PARAMETERS

| Parameter | Host | Guest | Default | Source |
|-----------|------|-------|---------|--------|
| `dataPort` | ✓ | ✓ | 5678 | Constructor |
| `weavePort` | ✓ | | hostPort | `-p` / menu |
| `hostIp` | (bind) | ✓ (connect) | "null"/INADDR_ANY | `-ip` |
| `uniqueIdGlobal` | ✓ | ✓ | Generated | Global |
| `conduits` | ✓ | | 5678 | Hardcoded |
| `createHost` | ✓ | | true/false | `-w` / menu |
| `singers` | ✓ | ✓ | 16 | `-c` / menu |

---

## 15. DEBUGGING & MONITORING

### 14.1 Network Tracing
```cpp
// Add to socket operations:
cout << "[NET] " << (createHost ? "HOST" : "GUEST") 
     << " sock=" << sock 
     << " ip=" << ip 
     << " port=" << port 
     << " bytes=" << bytesTransferred << endl;
```

### 14.2 Packet Capture
```bash
# Windows (Admin)
netsh trace start capture=yes tracefile=primeone.etl

# Linux
tcpdump -i any -w primeone.pcap port 54767

# Wireshark filter
tcp.port == 54767 || tcp.port == 5678
```

### 14.3 Connection Testing
```cmd
# Test host port
telnet 192.168.1.100 54767

# Test with netcat
nc -zv 192.168.1.100 54767

# PowerShell
Test-NetConnection 192.168.1.100 -Port 54767
```

---

## 16. INTEGRATION WITH PRIME TILE ENGINE

### 15.1 Work Unit Structure
```cpp
struct WorkUnit {
    __int128 powerOf;        // Grid size = 2^powerOf
    __int128 startTile;      // Inclusive
    __int128 endTile;        // Exclusive
    int singerCount;         // Threads for this unit
    string computeMethod;    // "Gear", "blindPrime", etc.
    __int128 weaverData;     // Continuation state
};
```

### 15.2 Result Structure
```cpp
struct ResultUnit {
    __int128 workUnitId;
    vector<__int128> primes;      // Found primes
    vector<byte> tileData;        // Serialized tiles
    __int128 primeCount;
    __int128 computeTimeMs;
    string guestId;
    bool verified;                // Host-verified flag
};
```

### 15.3 Handoff Points
```cpp
// Host → Guest (send work)
send(connSocket, serialize(workUnit), ...);

// Guest → Host (send results)
send(connSocket, serialize(resultUnit), ...);

// Host verifies
for (prime : result.primes) {
    if (!PrimeOne.verifyPrime(prime)) {
        // Reject, request re-compute
    }
}
```

---

## 17. KNOWN BUGS & TECHNICAL DEBT

### 17.1 Compilation Errors (Blocking Build)
| Error | Location | Fix |
|-------|----------|-----|
| `MAKEWORD` undeclared | 9742, 13107, 17282, 18233, 18543 | `#include <winsock2.h>` |
| `hint.sin_addr.s_addr` invalid | 9761, 13118, 17298, 18565 | Use `in_addr` struct |
| `inet_ntoa` arg type | 9762, 13119, 17299, 18566 | Pass `in_addr` not `uint32_t` |
| `MAX_COMPUTERNAME_LENGTH` | 9888, 17386 | `#include <windows.h>` |
| `ZeroMemory` | 9894, 17392 | `#include <windows.h>` |
| `GetComputerName` | 9898, 17394 | `#include <windows.h>` |
| `INET_ADDRSTRLEN` | 9913, 17402 | `#include <ws2tcpip.h>` |
| `VK_RETURN`, `keybd_event` | 11042 | `#include <windows.h>` |
| `DISPLAY_DEVICE` | 8562, 8575 | `#include <windows.h>` |
| `UINT`, `HINSTANCE`, `LPSTR` | 8612-8613 | `#include <windows.h>` |
| `GetCurrentProcessId` | 14767, 17601 | `#include <windows.h>` |
| `OpenProcess`, `PROCESS_ALL_ACCESS` | 14768 | `#include <windows.h>` |
| `CloseHandle` | 14773, 17605, 17610 | `#include <windows.h>` |
| `TH32CS_SNAPTHREAD`, `CreateToolhelp32Snapshot` | 17592 | `#include <tlhelp32.h>` |
| `THREADENTRY32`, `Thread32First/Next` | 17595-17607 | `#include <tlhelp32.h>` |
| `OpenThread`, `THREAD_ALL_ACCESS` | 17603 | `#include <windows.h>` |
| `GetTickCount` | 12352 | `#include <windows.h>` |
| `GetSystemInfo`, `SYSTEM_INFO` | 16657-16658 | `#include <windows.h>` |
| `LPVOID`, `SIZE_T`, `BYTE` | 16659-16663 | `#include <windows.h>` |
| `WriteProcessMemory` | 16674 | `#include <windows.h>` |
| `AllocConsole`, `SetConsoleTitle` | 12248, 12254 | `#include <windows.h>` |
| `GetConsoleWindow`, `GetDesktopWindow` | 11985, 11992 | `#include <windows.h>` |
| `GetWindowRect`, `SetWindowPos` | 11993, 12002 | `#include <windows.h>` |
| `HWND_TOP`, `SWP_SHOWWINDOW` | 12002 | `#include <windows.h>` |

### 17.2 Logic Bugs
1. **Multiple WSAStartup** without WSACleanup
2. **Blocking sockets** without timeouts
3. **No heartbeat** - dead guests not detected
4. **Work not requeued** on guest disconnect
5. **Hardcoded port 5678** in constructor vs 54767 in batch files
6. **Unique ID generation** not shown (global variable)

### 17.3 Architecture Debt
- Conduit logic mixed with prime computation
- No protocol versioning
- No graceful degradation
- Single-threaded host accept loop (should use IOCP/epoll)
- No IPv6 support

---

## 18. REFACTORING ROADMAP

### 18.1 Phase 1: Fix Compilation (Critical)
- [ ] Add missing Windows headers (`winsock2.h`, `windows.h`, `ws2tcpip.h`, `tlhelp32.h`)
- [ ] Fix `sin_addr` usage with `in_addr` struct
- [ ] Fix `inet_ntoa` argument type
- [ ] Add `WSACleanup()` calls
- [ ] Define missing constants

### 18.2 Phase 2: Protocol Robustness (High)
- [ ] Implement message framing (length prefix)
- [ ] Add heartbeat/keepalive (30s interval)
- [ ] Implement work requeue on disconnect
- [ ] Add connection timeout (10s connect, 60s idle)
- [ ] Implement graceful shutdown protocol

### 18.3 Phase 3: Security (High)
- [ ] Integrate libssh for encrypted channels
- [ ] Add HMAC message authentication
- [ ] Implement host/guest certificate verification
- [ ] Add rate limiting

### 18.4 Phase 4: Scalability (Medium)
- [ ] Replace blocking accept with IOCP (Windows) / epoll (Linux)
- [ ] Implement work stealing for load balancing
- [ ] Add compression for large tile transfers
- [ ] Support UDP for heartbeat (lower overhead)

### 18.5 Phase 5: Observability (Medium)
- [ ] Structured logging (JSON)
- [ ] Metrics export (Prometheus)
- [ ] Distributed tracing (OpenTelemetry)
- [ ] Health check endpoint

### 18.6 Phase 6: Cross-Platform (Low)
- [ ] Abstract socket API (Boost.Asio or custom)
- [ ] Implement Linux build with same protocol
- [ ] Add IPv6 dual-stack support
- [ ] WebSocket gateway for web clients

---

## 19. TESTING SPECIFICATIONS

### 19.1 Unit Tests
| Component | Test Cases |
|-----------|------------|
| `conduitClass` constructor | Port binding, invalid ports |
| `weaverBegin` | Host/Guest mode selection |
| `conduit_win_host` | Bind, listen, accept, multi-client |
| `conduit_win_guest` | Connect, reconnect, timeout |
| `realm_conduit_win_guest` | Async completion, cancellation |
| Serialization | `__int128` round-trip, `vector<byte>` integrity |

### 19.2 Integration Tests
- Host + 1 Guest (local)
- Host + 4 Guests (local)
- Host + Guests (LAN)
- Guest disconnect during work
- Host restart with guest reconnect
- Large prime transfer (>1MB)

### 19.3 Stress Tests
- 100 concurrent guests
- 1GB prime data transfer
- 24-hour continuous operation
- Network partition simulation

---

## 20. COMPLETE COMMAND REFERENCE

### 20.1 Host Commands
```cmd
# Minimal host
PrimeOne.exe -m 8 -p 54767

# Full host
PrimeOne.exe -m 8 -p 54767 -ip 0.0.0.0 -c 8 -f quickPrime -x Gear -w h

# Batch file
primeone8host - 54767.bat
```

### 20.2 Guest Commands
```cmd
# Minimal guest
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -w g

# Full guest
PrimeOne.exe -m 9 -p 54767 -ip 192.168.1.100 -c 4 -f quickPrime -x Gear -w g

# Batch file (new window)
primeone9guestsShow - 54767.bat
```

### 20.3 Diagnostic Commands (from menu)
```
# In interactive mode:
8 → Enter host mode → 3 (show IP config)
9 → Enter guest mode → 3 (show IP config)
```

---

## 21. FUTURE PROTOCOL EVOLUTION

### 21.1 Version 2 Protocol (Planned)
```protobuf
message WorkRequest {
  uint64 session_id = 1;
  uint32 power_of = 2;
  uint64 start_tile = 3;
  uint64 end_tile = 4;
  ComputeMethod method = 5;
  bytes continuation_state = 6;
}

message WorkResponse {
  uint64 session_id = 1;
  uint64 work_unit_id = 2;
  repeated bytes primes = 3;  // Serialized __int128
  bytes tile_data = 4;
  uint32 compute_time_ms = 5;
  GuestStatus status = 6;
}

message Heartbeat {
  uint64 session_id = 1;
  uint32 guests_connected = 2;
  uint64 primes_found = 3;
  double primes_per_sec = 4;
}
```

### 21.2 Transport Options
- **TLS/SSL** via libssh (current dependency)
- **QUIC** for 0-RTT reconnection
- **WebSocket** for browser guests
- **gRPC** for structured RPC

---

*End of Feature Document 04: Network Conduit System*  
*Next: 05_GPU_CUDA_ACCELERATION.md*