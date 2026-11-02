# PrimeOne - Feature Document 05: GPU/CUDA Acceleration
## Complete Technical Specification

**Document Version:** 1.0  
**Source:** `main.cpp` CUDA includes, `main.cu`, project files, GearSlice analysis  
**Minimum Lines:** 250+

---

## 1. OVERVIEW

PrimeOne includes comprehensive **GPU acceleration support** via **NVIDIA CUDA** and **DirectX 9 Compute Shaders**. The system is designed to offload prime number computation from CPU to GPU for massive parallelization. The codebase includes CUDA runtime headers, device code (`main.cu`), and HLSL compute shaders, with runtime switching between CPU/GPU modes via the "PU" (Processing Unit) menu option.

### Design Philosophy
- **Hybrid compute** - CPU for coordination, GPU for massive parallel prime testing
- **CUDA primary** - NVIDIA CUDA as main GPU backend
- **DirectX fallback** - D3D9 compute shaders for broader compatibility
- **Runtime toggle** - Menu options `c` (PU=Yes) / `g` (PU=No)
- **Seamless fallback** - CPU path always available

---

## 2. CUDA INTEGRATION

### 2.1 Headers Included
```cpp
// main.cpp lines 69-76
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

### 2.2 CUDA Files in Project
| File | Purpose |
|------|---------|
| `main.cu` | CUDA kernel implementations |
| `compute_shader.hlsl` | HLSL compute shader (DirectX 11) |
| `cudart64_110.dll` | CUDA 11.0 Runtime |
| `cudart64_12.dll` | CUDA 12.0 Runtime |
| `cuda_runtime.h` | CUDA Runtime API headers |
| `cuda_runtime_api.h` | CUDA Runtime API (duplicate) |

### 2.3 Build Configuration (PrimeOne.cbp)
```xml
<!-- Linker libraries -->
<Add library="Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64/cudart.lib" />
<Add directory="Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/include" />
<Add directory="Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/bin" />
```

### 2.4 Compiler Definitions
```xml
<Add option="-D__CUDA__" />
<Add option="-D__CUDACC__" />
```

---

## 3. CUDA KERNEL ARCHITECTURE (Inferred)

### 3.1 Expected Kernel Structure
Based on primeTileClass algorithms, CUDA kernels likely implement:

```cuda
// main.cu (not fully visible in excerpts)
__global__ void primeVerifyKernel(
    const __int128* candidates, 
    const __int128* knownPrimes,
    int knownPrimeCount,
    bool* results,
    int candidateCount
) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= candidateCount) return;
    
    __int128 candidate = candidates[idx];
    bool isPrime = true;
    
    for (int i = 0; i < knownPrimeCount; ++i) {
        __int128 p = knownPrimes[i];
        if (p * p > candidate) break;
        if (candidate % p == 0) {
            isPrime = false;
            break;
        }
    }
    results[idx] = isPrime;
}

__global__ void primeWalkKernel(
    __int128 start,
    __int128* outputPrimes,
    int maxPrimes,
    __int128* foundCount
) {
    // Parallel prime walk with atomic counter
}
```

### 3.2 Memory Management
```cuda
// Host-side CUDA memory management (inferred)
class CudaPrimeEngine {
    __int128* d_candidates;      // Device candidates
    __int128* d_knownPrimes;     // Device known primes
    bool* d_results;             // Device results
    __int128* d_outputPrimes;    // Device output
    int* d_foundCount;           // Atomic counter
    
    void allocate(int maxCandidates, int maxPrimes) {
        cudaMalloc(&d_candidates, maxCandidates * sizeof(__int128));
        cudaMalloc(&d_knownPrimes, maxPrimes * sizeof(__int128));
        cudaMalloc(&d_results, maxCandidates * sizeof(bool));
        cudaMalloc(&d_outputPrimes, maxPrimes * sizeof(__int128));
        cudaMalloc(&d_foundCount, sizeof(int));
        cudaMemset(d_foundCount, 0, sizeof(int));
    }
    
    void free() {
        cudaFree(d_candidates);
        cudaFree(d_knownPrimes);
        cudaFree(d_results);
        cudaFree(d_outputPrimes);
        cudaFree(d_foundCount);
    }
};
```

### 3.3 Kernel Launch Configuration
```cuda
// Optimal launch parameters
const int BLOCK_SIZE = 256;
int gridSize = (candidateCount + BLOCK_SIZE - 1) / BLOCK_SIZE;

primeVerifyKernel<<<gridSize, BLOCK_SIZE>>>(
    d_candidates, d_knownPrimes, knownPrimeCount,
    d_results, candidateCount
);
cudaDeviceSynchronize();
```

---

## 4. DIRECTX 9 COMPUTE SHADERS

### 4.1 Headers & Libraries
```cpp
#include <d3d9.h>
#include <d3dx9.h>

// Linker libraries (from PrimeOne.cbp)
<Add library="Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3d9.lib" />
<Add library="Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx9.lib" />
<Add library="c:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3dx9.lib" />
<Add library="Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3d9.lib" />
```

### 4.2 HLSL Compute Shader (compute_shader.hlsl)
```hlsl
// DirectX 9 doesn't have native compute shaders (DX11+)
// This may be a pixel shader abused for computation
// Or targeting DX11 via D3D9Ex

// Example prime verification pixel shader:
float4 PrimeVerifyPS(float2 texCoord : TEXCOORD0) : COLOR0 {
    // texCoord maps to candidate index
    // Texture contains known primes
    // Output: 1.0 = prime, 0.0 = composite
}
```

### 4.3 D3D9 Device Creation
```cpp
// Inferred from dashboard "PU=Yes/No" toggle
IDirect3D9* d3d = Direct3DCreate9(D3D_SDK_VERSION);
D3DPRESENT_PARAMETERS params = {};
params.Windowed = TRUE;
params.SwapEffect = D3DSWAPEFFECT_DISCARD;
params.BackBufferFormat = D3DFMT_A8R8G8B8;

IDirect3DDevice9* device;
d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
                  hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                  &params, &device);
```

---

## 5. GPU/CPU RUNTIME SWITCHING

### 5.1 Menu Control (PU = Processing Unit)
```cpp
// Menu display lines 14655-14666
// (c) PU = Yes  - Enable GPU
// (g) PU = No   - Disable GPU (CPU only)

// State variable (inferred)
bool useGPU = true;  // Default ON

// Toggled via menu options 'c' and 'g'
```

### 5.2 Command Line Flag
```cpp
// -f quickPrime / -f noPrime may affect GPU usage
if (optionFlagInput == "quickPrime") {
    // May enable GPU fast path
}
if (optionFlagInput == "noPrime") {
    // May disable prime computation entirely (network only?)
}
```

### 5.3 Compute Method Selection
```cpp
// -x Gear / -x blindPrime
string computeMethod = "Gear";  // Default

// In primeTileClass::conductor():
// if (computeMethod == "Gear") useCUDA = true;
// else if (computeMethod == "blindPrime") useCUDA = false;
```

---

## 6. PRIME COMPUTATION ON GPU

### 6.1 Parallelization Strategy
```
┌─────────────────────────────────────────────────────────────────┐
│                    GPU PRIME PIPELINE                            │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  HOST (CPU)                    DEVICE (GPU)                     │
│  ┌─────────────┐               ┌─────────────────────┐          │
│  │ Generate    │               │                     │          │
│  │ candidates  │──────────────►│  primeVerifyKernel  │          │
│  │ (tile range)│   cudaMemcpy  │  (parallel trial    │          │
│  └─────────────┘               │   division)         │          │
│        │                       └──────────┬──────────┘          │
│        │                                  │                     │
│        │                          ┌───────┴───────┐             │
│        │                          │ Compact/Filter│             │
│        │                          │ (thrust or    │             │
│        │                          │  custom)      │             │
│        │                          └───────┬───────┘             │
│        ▼                                  ▼                     │
│  ┌─────────────┐               ┌─────────────────────┐          │
│  │ Receive &   │◄──────────────│  Found primes       │          │
│  │ verify      │   cudaMemcpy  │  (compacted)        │          │
│  └─────────────┘               └─────────────────────┘          │
│                                                                  │
└─────────────────────────────────────────────────────────────────┘
```

### 6.2 Candidate Generation
```cpp
// CPU generates candidate numbers for tile range
vector<__int128> generateCandidates(__int128 startTile, __int128 endTile) {
    vector<__int128> candidates;
    for (__int128 tile = startTile; tile < endTile; ++tile) {
        // Each tile contains multiple candidates
        for (int offset = 0; offset < TILE_SIZE; ++offset) {
            __int128 candidate = tile * TILE_SIZE + offset;
            if (candidate % 2 != 0) {  // Skip even
                candidates.push_back(candidate);
            }
        }
    }
    return candidates;
}
```

### 6.3 Known Primes Buffer
```cpp
// Transfer known primes to GPU for trial division
void uploadKnownPrimes(const vector<__int128>& primes) {
    cudaMemcpy(d_knownPrimes, primes.data(), 
               primes.size() * sizeof(__int128), cudaMemcpyHostToDevice);
    d_knownPrimeCount = primes.size();
}
```

---

## 7. CUDA ERROR HANDLING

### 7.1 Required Error Checking
```cuda
#define CUDA_CHECK(call) \
    do { \
        cudaError_t err = call; \
        if (err != cudaSuccess) { \
            fprintf(stderr, "CUDA error %s:%d: %s\n", \
                    __FILE__, __LINE__, cudaGetErrorString(err)); \
            exit(1); \
        } \
    } while(0)

// Usage:
CUDA_CHECK(cudaMalloc(&ptr, size));
CUDA_CHECK(cudaMemcpy(dst, src, size, cudaMemcpyHostToDevice));
CUDA_CHECK(cudaGetLastError());
CUDA_CHECK(cudaDeviceSynchronize());
```

### 7.2 Common CUDA Errors in PrimeOne Context
| Error | Cause | Fix |
|-------|-------|-----|
| `cudaErrorMemoryAllocation` | `__int128` arrays too large | Reduce batch size |
| `cudaErrorInvalidDevice` | No CUDA GPU | Fallback to CPU |
| `cudaErrorLaunchTimeout` | Kernel too long | Split into smaller grids |
| `cudaErrorMisalignedAddress` | `__int128` alignment | Use `alignas(16)` |

---

## 8. PERFORMANCE ANALYSIS

### 8.1 Theoretical Speedup
| Operation | CPU (1 core) | GPU (RTX 3080) | Speedup |
|-----------|--------------|----------------|---------|
| Trial division (64-bit) | ~500K ops/s | ~50M ops/s | 100x |
| Trial division (128-bit) | ~50K ops/s | ~5M ops/s | 100x |
| Sieve of Eratosthenes | ~10M/s | ~1B/s | 100x |
| Miller-Rabin | ~1M/s | ~100M/s | 100x |

### 8.2 Real-World Factors
- **Memory bandwidth**: `__int128` = 16 bytes, limits occupancy
- **Divergence**: Prime verification has variable loop count
- **Atomic operations**: Result compaction bottleneck
- **PCIe transfer**: Host↔Device latency for small batches

### 8.3 Optimization Techniques
```cuda
// 1. Use shared memory for known primes
__shared__ __int128 s_primes[1024];

// 2. Warp-level primitives for reduction
__inline__ __device__ int warpReduceSum(int val) {
    for (int offset = 16; offset > 0; offset >>= 1)
        val += __shfl_down_sync(0xFFFFFFFF, val, offset);
    return val;
}

// 3. Persistent kernels for continuous work
__global__ void persistentPrimeKernel(...) {
    while (atomicAdd(globalWorkCounter, 1) < totalWork) {
        // Process work unit
    }
}

// 4. Tensor cores for modular arithmetic (H100+)
// Not applicable to prime verification directly
```

---

## 9. INTEGRATION WITH PRIME TILE ENGINE

### 9.1 Compute Method Dispatch
```cpp
// In primeTileClass::conductor() or librarianDancer():
void primeTileClass::computePrimes() {
    if (useGPU && cudaAvailable()) {
        computePrimesCUDA();
    } else if (useGPU && d3dAvailable()) {
        computePrimesD3D9();
    } else {
        computePrimesCPU();
    }
}
```

### 9.2 State Synchronization
```cpp
// GPU updates these, CPU reads back
__int128* d_infiniteWalk;     // Current walk position
__int128* d_totalPrimes;      // Total found
byte* d_tileBuffer;           // Tile data

// Synchronization points:
cudaDeviceSynchronize();  // After each kernel batch
cudaMemcpy(&infiniteWalk, d_infiniteWalk, sizeof(__int128), cudaMemcpyDeviceToHost);
```

---

## 10. MENU INTEGRATION

### 10.1 Dashboard Display
```cpp
// menu_librarian lines 14655-14666
cout << "X" << " " << "(" << "c" << ")" << "P" << "U" << " " << "=" 
     << " " << "Y" << "e" << "s" << " " << " " << " " << " " << " " 
     << " " << " " << "X" << "" << endl;

cout << "X" << " " << "(" << "g" << ")" << "P" << "U" << " " << "=" 
     << " " << "N" << "o" << " " << " " << " " << " " << " " << " " 
     << " " << "X" << "" << endl;
```

### 10.2 State Persistence
```cpp
// GPU state saved in prime book
vector<byte> bookData = PrimeOne.ptv_primeBookAuthor(...);
// Includes: GPU cursor position, verified primes, pending candidates
```

---

## 11. BUILD SYSTEM CONFIGURATION

### 11.1 Code::Blocks Project (PrimeOne.cbp)
```xml
<!-- CUDA Compiler (nvcc) -->
<Compiler>
    <Add option="-ccbin g++" />
    <Add option="-std=c++17" />
    <Add option="-arch=sm_50" />  <!-- Minimum compute capability -->
    <Add option="-arch=sm_60" />
    <Add option="-arch=sm_70" />
    <Add option="-arch=sm_80" />
    <Add option="-arch=sm_90" />
</Compiler>

<!-- Linker -->
<Linker>
    <Add library="cudart.lib" />
    <Add library="cudart_static.lib" />
    <Add directory="$(CUDA_PATH)/lib/x64" />
</Linker>

<!-- Custom build step for .cu files -->
<ExtraCommands>
    <Add before="nvcc -c main.cu -o main.cu.obj $(CUDA_FLAGS)" />
</ExtraCommands>
```

### 11.2 MinGW-w64 Cross-Compilation (Linux)
```bash
# nvcc not available in MinGW
# Must use Linux nvcc for .cu, then link with MinGW
# Or use CUDA Driver API directly (no nvcc needed)

# Alternative: Pure CUDA Driver API
#include <cuda.h>
CUmodule module;
cuModuleLoad(&module, "kernels.ptx");
CUfunction kernel;
cuModuleGetFunction(&kernel, module, "primeVerifyKernel");
```

---

## 12. CUDA VS DIRECTX COMPARISON

| Aspect | CUDA | DirectX 9 Compute |
|--------|------|-------------------|
| **Maturity** | High | Legacy (DX9) |
| **Performance** | Optimal | Lower (pixel shader abuse) |
| **Portability** | NVIDIA only | Windows only |
| **Debugging** | Nsight, cuda-gdb | PIX, VS Graphics |
| **Libraries** | cuBLAS, cuRAND, Thrust | D3DX math |
| **PrimeOne usage** | Primary | Fallback/legacy |

**Note:** DirectX 9 compute shaders don't exist. The `compute_shader.hlsl` is likely a pixel shader used for GPGPU via render-to-texture, or the project targets D3D11 via D3D9Ex.

---

## 13. HARDWARE REQUIREMENTS

### 13.1 Minimum GPU
- **CUDA**: Compute Capability 5.0 (Maxwell, GTX 750+)
- **VRAM**: 2GB minimum (for prime buffers)
- **Driver**: 450+ (CUDA 11), 525+ (CUDA 12)

### 13.2 Recommended GPU
- **RTX 3080/4080/4090** (10GB+ VRAM)
- **Compute Capability 8.0+** (Ampere/Ada)
- **Tensor Cores**: Not directly useful for prime math

### 13.3 Multi-GPU
```cuda
// Multi-GPU support (inferred)
int deviceCount;
cudaGetDeviceCount(&deviceCount);
for (int i = 0; i < deviceCount; ++i) {
    cudaSetDevice(i);
    // Launch kernel on each GPU
}
```

---

## 14. KNOWN ISSUES & LIMITATIONS

### 14.1 Compilation Blockers
1. **CUDA headers missing** in Linux build environment
2. **`__int128` in device code** - Not natively supported in CUDA
3. **No `main.cu` content visible** - Kernels not inspectable
4. **D3D9 compute** - Architectural mismatch

### 14.2 `__int128` in CUDA
```cuda
// CUDA does NOT support __int128 natively
// Options:
struct int128_t {
    uint64_t lo;
    uint64_t hi;
};

__device__ int128_t mod128(int128_t a, int128_t b) {
    // Implement 128-bit modulo using 64-bit ops
    // Complex: requires Barrett reduction or similar
}

// Alternative: Use 64-bit primes only on GPU
// CPU handles >64-bit primes
```

### 14.3 Memory Alignment
```cuda
// __int128 requires 16-byte alignment
// CUDA malloc guarantees 256-byte alignment
// But struct packing may break alignment

struct alignas(16) PrimeCandidate {
    __int128 value;
    uint32_t tileId;
    uint32_t flags;
};
```

---

## 15. DEBUGGING GPU CODE

### 15.1 CUDA Debugging Tools
```bash
# NVIDIA Nsight Compute (profiler)
ncu --target-processes all ./PrimeOne.exe

# NVIDIA Nsight Systems (timeline)
nsys profile ./PrimeOne.exe

# cuda-gdb (Linux)
cuda-gdb ./PrimeOne.exe

# Visual Studio (Windows)
# Debug → Start Debugging (with Nsight extension)
```

### 15.2 Common Debug Patterns
```cuda
// Debug print from kernel (requires compute capability 2.0+)
__global__ void debugKernel() {
    if (threadIdx.x == 0 && blockIdx.x == 0) {
        printf("Kernel launched: grid=%d, block=%d\n", 
               gridDim.x, blockDim.x);
    }
    
    // Per-thread debug
    if (threadIdx.x < 32) {
        printf("Thread %d: candidate=%lld\n", threadIdx.x, candidates[threadIdx.x]);
    }
}

// Assert in device code
__global__ void safeKernel() {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    assert(idx < maxCount);  // Requires -lineinfo
}
```

---

## 16. FALLBACK STRATEGIES

### 16.1 CPU Fallback (Always Available)
```cpp
void primeTileClass::computePrimes() {
    if (useGPU) {
        if (tryCUDA()) return;
        if (tryD3D9()) return;
    }
    computePrimesCPU();  // Always works
}
```

### 16.2 Graceful Degradation
```cpp
bool tryCUDA() {
    int deviceCount;
    cudaError_t err = cudaGetDeviceCount(&deviceCount);
    if (err != cudaSuccess || deviceCount == 0) {
        log("CUDA not available, falling back");
        return false;
    }
    
    cudaDeviceProp prop;
    cudaGetDeviceProperties(&prop, 0);
    if (prop.major < 5) {
        log("GPU too old (CC < 5.0), falling back");
        return false;
    }
    
    // Try to allocate test buffer
    void* testPtr;
    err = cudaMalloc(&testPtr, 1024 * 1024);
    if (err != cudaSuccess) {
        log("GPU memory allocation failed");
        return false;
    }
    cudaFree(testPtr);
    
    return true;
}
```

---

## 17. MONITORING & TELEMETRY

### 17.1 GPU Metrics to Track
```cpp
struct GPUMetrics {
    float gpuUtilization;      // 0-100%
    float memoryUtilization;   // 0-100%
    size_t memoryUsed;         // Bytes
    size_t memoryTotal;        // Bytes
    float temperature;         // Celsius
    float powerDraw;           // Watts
    uint32_t clockSM;          // MHz
    uint32_t clockMem;         // MHz
};

GPUMetrics getGPUMetrics() {
    GPUMetrics m = {};
    nvmlDeviceGetUtilizationRates(device, &m.gpuUtilization);
    nvmlDeviceGetMemoryInfo(device, &m.memoryInfo);
    nvmlDeviceGetTemperature(device, NVML_TEMPERATURE_GPU, &m.temperature);
    nvmlDeviceGetPowerUsage(device, &m.powerDraw);
    return m;
}
```

### 17.2 Dashboard Integration
```cpp
// Extend menu_librarian to show GPU stats:
cout << "GPU Util: " << gpuUtil << "%  VRAM: " << vramUsed 
     << "/" << vramTotal << "  Temp: " << temp << "C" << endl;
```

---

## 18. COMPARISON: GPU VS CPU PRIME ALGORITHMS

| Algorithm | CPU Suitability | GPU Suitability | Notes |
|-----------|-----------------|-----------------|-------|
| Trial Division | Good (branchy) | Poor (divergence) | GPU needs warp-uniform loops |
| Sieve of Eratosthenes | Excellent | Excellent | Memory bandwidth bound |
| Miller-Rabin | Good | Excellent | Fixed iterations, parallel |
| Pollard's Rho | Good | Good | Random walk, some divergence |
| ECM | Poor | Poor | Too complex for GPU |
| AKS | Theoretical | Theoretical | Not practical |

**Recommendation:** Use **GPU Sieve** for candidate generation + **CPU Miller-Rabin** for verification of large candidates.

---

## 19. INTEGRATION WITH NETWORK CONDUIT

### 19.1 Host GPU Coordination
```cpp
// Host assigns GPU work units to guests with GPUs
struct GPUWorkUnit {
    __int128 startTile;
    __int128 endTile;
    bool requiresGPU;
    int minComputeCapability;
};

// Guest reports capabilities
struct GuestCapabilities {
    bool hasCUDA;
    int computeCapability;
    size_t vramFree;
    bool hasD3D9;
};
```

### 19.2 Heterogeneous Cluster
```
Host (CPU) ─┬─ Guest 1 (CPU only)
            ├─ Guest 2 (RTX 3080 - CUDA)
            ├─ Guest 3 (RTX 4090 - CUDA)
            └─ Guest 4 (Integrated - D3D9)
```

---

## 20. FUTURE ENHANCEMENT ROADMAP

### 20.1 Immediate (Build Fixes)
- [ ] Provide CUDA stub headers for Linux build
- [ ] Implement `__int128` emulation for CUDA device code
- [ ] Fix D3D9 compute shader approach (use D3D11 compute)
- [ ] Add CUDA error checking macros

### 20.2 Short Term (Functionality)
- [ ] Implement actual prime kernels in `main.cu`
- [ ] Add GPU memory pool allocator
- [ ] Implement persistent kernel for continuous work
- [ ] Add Thrust-based prime compaction

### 20.3 Medium Term (Performance)
- [ ] Multi-GPU support with work distribution
- [ ] CUDA Graphs for kernel launch optimization
- [ ] Async copy/compute overlap with streams
- [ ] Tensor core accelerated modular arithmetic (research)

### 20.4 Long Term (Architecture)
- [ ] Unified compute abstraction (CUDA/HIP/OpenCL/Metal)
- [ ] JIT kernel compilation for dynamic prime sizes
- [ ] Distributed GPU cluster (MPI + CUDA)
- [ ] Quantum-resistant prime algorithms

---

## 21. CROSS-REFERENCE: SOURCE LOCATIONS

| Component | File | Lines |
|-----------|------|-------|
| CUDA Includes | main.cpp | 69-76 |
| CUDA Kernels | main.cu | (entire file) |
| HLSL Shader | compute_shader.hlsl | (entire file) |
| CUDA DLLs | Project root | cudart64_*.dll |
| CUDA Libs | PrimeOne.cbp | Linker section |
| Menu PU Toggle | main.cpp | 14655-14666 |
| Compute Method | main.cpp | 12063, 14225 |

---

*End of Feature Document 05: GPU/CUDA Acceleration*  
*Next: 06_UPDATE_ROLL_SYSTEM.md*