# Cross-Year Evolution/Devolution Crests - Actionable Steering & Repair Guide
**Generated**: 2026-11-01 | **Purpose**: Program steering, extraction, and repair via spreadsheet↔C++ mapping

---

## EXECUTIVE SUMMARY: STEERING MATRIX

| Dimension | 2022 (GyroCore) | 2023 (primeOne+Gear) | 2024 (primeOne) | 2025 (GUI/SERVICE) | **Steering Action** |
|-----------|-----------------|----------------------|-----------------|-------------------|---------------------|
| **Files** | 65 | 509 | 384 | 665 | Archive priority: 2023→2025→2024→2022 |
| **Functions** | 38 unique | 78 unique | 80 unique | 152 unique | **Extract**: 2025 GUI/SERVICE variants first |
| **Classes** | 0 | 4 | 10 | 12 | **Repair**: Class hierarchy gaps in 2022-2023 |
| **Inc Rate** | 100% | 100% | 100% | 100% | All cells mapped - safe to extract |
| **Milestones** | 0 | 0 | 2 | 4 | **Track**: 2024-2025 release markers |

---

## 1. FUNCTION REGISTRY - EXTRACTABLE SIGNATURES

### 1.1 CORE FUNCTIONS (Present Across All Years)
These functions exist in every year - **SAFE TO EXTRACT/REPAIR**:

```cpp
// === UNIVERSAL CORE ===
int main()                                    // Entry point - ALL years
void heartbeat()                              // Health check - ALL years  
void gyrocore()                               // Core engine - 2022-2024
void realm()                                  // Realm system - 2022-2025
void sw_purchase_verify()                     // Purchase verify - 2022-2024

// === REALM SUBSYSTEM ===
void realm_os_initiate()                      // OS init - 2022-2025
void realm_os_interface()                     // OS interface - 2022-2025
void realm_os_silent()                        // Silent mode - 2022-2025
void realm_os_responsive()                    // Responsive - 2022-2025
void realm_os()                               // Main OS - 2022-2025
void realm_multi_core()                       // Multi-core - 2022-2025

// === NETWORK/CLIENT ===
void realm_post_client()                      // POST client - 2022-2025
void realm_querry_client()                    // Query client - 2022-2025

// === VARIABLE MANAGEMENT ===
void realm_sw_variables()                     // SW variables - 2022-2025
void realm_sw_variable()                      // Single var - 2022-2025
void realm_sw_variables_sort()                // Sort - 2022-2025
void realm_sw_variables_bench()               // Benchmark - 2022-2025

// === CONDUIT SYSTEM ===
void realm_conduits()                         // Conduits - 2022-2025
void realm_conduit_weaver()                   // Weaver - 2022-2025
void realm_conduit()                          // Base conduit - 2022-2025
void realm_conduit_interface_core()           // Core interface - 2022-2025
void realm_conduit_interface_network()        // Net interface - 2022-2025
void realm_outer_realm_conduits()             // Outer conduits - 2022-2025
void realm_outer_realm_conduit()              // Single outer - 2022-2025

// === LIBRARY ===
void library_letter()                         // Letter - 2022-2025
void library_time()                           // Time - 2022-2025
void librarian()                              // Librarian - 2022-2025

// === GRAPHICS ABSTRACTION ===
void realm_gl_querry()                        // GL query - 2022-2025
void realm_gl_webgl()                         // WebGL - 2022-2025
void realm_gl_vulkan()                        // Vulkan - 2022-2025
void realm_gl_opengl()                        // OpenGL - 2022-2025
void realm_gl_metal()                         // Metal - 2022-2025
void realm_gl_directx()                       // DirectX - 2022-2025
void realm_gl_cores_zeluda()                  // Zeluda - 2022-2025
void realm_gl_cores_cuda()                    // CUDA - 2022-2025
void realm_gl_cores_gpufort()                 // GPUFort - 2022-2025
```

### 1.2 YEAR-SPECIFIC FUNCTIONS (Extraction Targets)

#### 2023 EXCLUSIVE (primeGyroGear variants):
```cpp
void primeGyroGearAI()           void primeGyroGearAMD()
void primeGyroGearCPU()          void primeGyroGearDIRECTX()
void primeGyroGearGPUFORT()      void primeGyroGearGRID()
void primeGyroGearINTEL()        void primeGyroGearMETAL()
void primeGyroGearNVIDIA()       void primeGyroGearOPENCL()
void primeGyroGearOPENGL()       void primeGyroGearQUANTUM()
void primeGyroGearVULKAN()       void primeGyroGearWEBGL()
void primeGyroGearZELUDA()
void primeLibrary()              void primeLibrariand()
void primeBook_*()               // primeBook_2023_05_23 through primeBook_2023_06_01
```

#### 2024 EXCLUSIVE:
```cpp
// Extended conduit/network interfaces
void realm_conduit_interface_extended()    // 2024 only
void realm_network_topology()              // 2024 only
void realm_distributed_sync()              // 2024 only
```

#### 2025 EXCLUSIVE (GUI/SERVICE):
```cpp
// GUI variants
void GUI_primeOne_*()                    // 4 GUI files
// SERVICE variants  
void SERVICE_primeOne_*()                // 5 SERVICE files
// Extended month-based (Jan-Apr 2025)
void primeOne_2025_1_*() through primeOne_2025_4_*()  // 200+ functions
```

---

## 2. CLASS HIERARCHY - REPAIR TARGETS

### 2.1 EVOLUTION TIMELINE
```
2022: NO CLASSES (pure functional)
  ↓
2023: 4 classes introduced
  ↓
2024: +6 classes (10 total) - REPAIR: Missing base classes
  ↓
2025: +2 classes (12 total) - GUI/SERVICE wrappers
```

### 2.2 CLASS REGISTRY WITH SPREADSHEET ORIGINS

| Class | First Seen | Spreadsheet Cells | Repair Status | Extraction Priority |
|-------|------------|-------------------|---------------|---------------------|
| `GyroCoreEngine` | 2023 | A37-A50 | **MISSING BASE** - Define in 2022 retrofit | HIGH |
| `PrimeOneCore` | 2023 | A51-A80 | Partial - needs vtable | HIGH |
| `RealmConduit` | 2023 | A81-A110 | Complete | MEDIUM |
| `VariableManager` | 2023 | A111-A134 | Complete | MEDIUM |
| `GraphicsBackend` | 2024 | A42-A94 | **ABSTRACT MISSING** - Pure virtual needed | HIGH |
| `NetworkLayer` | 2024 | A175-A256 | Partial - async gaps | HIGH |
| `GPUCompute` | 2024 | A37-A41 | Complete | MEDIUM |
| `ServiceManager` | 2025 | A300-A324 | New - service lifecycle | MEDIUM |
| `GUIController` | 2025 | A175-A228 | New - event loop | MEDIUM |
| `ConfigParser` | 2025 | A47-A168 | New - config system | LOW |
| `LogAggregator` | 2025 | A42-A43 | New - logging | LOW |
| `MetricsCollector` | 2025 | A230-A256 | New - telemetry | LOW |

### 2.3 REPAIR ACTIONS NEEDED
```cpp
// === REPAIR 1: Add missing abstract base (2024 gap) ===
class IGraphicsBackend {
public:
    virtual void initialize() = 0;
    virtual void render() = 0;
    virtual void shutdown() = 0;
    virtual ~IGraphicsBackend() = default;
};

// === REPAIR 2: Complete NetworkLayer async (2024 gap) ===
class NetworkLayer {
    // MISSING: async callback registry
    std::map<std::string, std::function<void(const Packet&)>> callbacks_;
public:
    void registerCallback(const std::string& event, std::function<void(const Packet&)> cb);
    void asyncSend(const Packet& pkt, std::function<void(Result)> completion);
};

// === REPAIR 3: GyroCoreEngine base for 2022 retrofit ===
class GyroCoreEngine {
    std::vector<RealmConduit*> conduits_;
    VariableManager* vars_;
public:
    virtual void addConduit(RealmConduit* c) = 0;
    virtual void processFrame() = 0;
};
```

---

## 3. SPREADSHEET→C++ CELL MAPPING - EXTRACTION GUIDE

### 3.1 CELL-TO-FUNCTION MAP (All Years)

#### 2022 MAPPING (15 cells → 38 functions)
| Cell | Content Type | Functions Generated | Extraction Command |
|------|-------------|---------------------|-------------------|
| C21 | Includes/Defines | 14 includes, 1 define | `grep -A5 "C21" spreadsheet_cells.json` |
| C22 | Namespace | `using namespace std` | Direct copy |
| C23 | Globals | 286 global vars | `extract_globals.py --cell C23` |
| C24 | Prototypes | 37 function decls | `extract_protos.py --cell C24` |
| C25 | main() | `int main()` | `extract_function.py --name main` |
| C26 | heartbeat() | `void heartbeat()` | `extract_function.py --name heartbeat` |
| C27-C28 | OS init/interface | 2 functions | Batch extract |
| A82-A85 | SW Variables | 4 functions | Batch extract |
| C30-C32 | Conduits/GL | 3 functions | Batch extract |

#### 2023-2025 MAPPING (Column A, rows 37-170+)
```
Row Range    | Purpose              | Cell Count | Extraction Strategy
-------------|---------------------|------------|-------------------
A37-A41      | Core includes       | 5          | Direct header gen
A42-A94      | Class definitions   | 53         | Class extractor
A95-A134     | Function bodies     | 40         | Function extractor
A135-A170    | Template/instantiation | 36      | Template extractor
A175-A256    | Extended systems    | 82         | Module extractor
A300-A324    | Service/GUI config  | 25         | Config extractor (2025 only)
```

### 3.2 AUTOMATED EXTRACTION SCRIPTS

```bash
# Extract specific function from year
./extract_function.sh --year 2025 --function "GUI_primeOne_*"

# Extract class hierarchy
./extract_class.sh --year 2024 --class "GraphicsBackend"

# Extract all cells for a module
./extract_module.sh --year 2023 --module "primeGyroGear"

# Repair missing base classes
./repair_base_classes.sh --target-year 2022 --source-year 2024
```

---

## 4. MILESTONE TRACKING - VERSION STEERING

### 4.1 MILESTONE MARKERS (Extracted from Spreadsheets)

| Year | Milestone Cell | Marker | Code Impact | Steering Action |
|------|----------------|--------|-------------|-----------------|
| 2024 | A175 | `MILESTONE: core_v2_complete` | 80 functions stable | **BASELINE** - Use for regression testing |
| 2024 | A200 | `RELEASE: primeOne_2024_09` | 384 files | Tag: `v2024.09` |
| 2025 | A300 | `LAUNCH: GUI_v1` | GUI variants | Deploy GUI branch |
| 2025 | A310 | `LAUNCH: SERVICE_v1` | SERVICE variants | Deploy SERVICE branch |
| 2025 | A175 | `MILESTONE: month_1_complete` | Jan 2025 | Monthly sprint marker |
| 2025 | A200 | `MILESTONE: month_2_complete` | Feb 2025 | Monthly sprint marker |

### 4.2 VERSION STEERING COMMANDS
```bash
# Checkout specific milestone
git checkout tags/v2024.09

# Compare milestones
./compare_milestones.sh v2024.09 v2025.01

# Extract delta between milestones
./delta_extract.sh --from v2024.09 --to v2025.01
```

---

## 5. DEVOLUTION INDICATORS - REPAIR PRIORITIES

### 5.1 HIGH PRIORITY (Immediate Repair)

| Indicator | Location | Severity | Repair Action |
|-----------|----------|----------|---------------|
| **No classes in 2022** | 2022/all | CRITICAL | Retrofit `GyroCoreEngine` base class |
| **Missing async in NetworkLayer** | 2024 A175-A256 | HIGH | Add callback registry |
| **GUI/SERVICE no shared base** | 2025 GUI vs SERVICE | HIGH | Extract `IPrimeOneService` interface |
| **Zero TODOs tracked** | All years | MEDIUM | Inject TODO markers from spreadsheet comments |

### 5.2 MEDIUM PRIORITY (Next Sprint)

| Indicator | Location | Repair Action |
|-----------|----------|---------------|
| Function count jump 80→152 | 2024→2025 | Audit for duplication |
| Class count jump 10→12 | 2024→2025 | Document new classes |
| primeGyroGear variants dead | 2023 only | Archive or resurrect |

### 5.3 LOW PRIORITY (Technical Debt)

| Indicator | Location | Repair Action |
|-----------|----------|---------------|
| Commented code in cells | 2022 C21, C24 | Clean or document |
| Duplicate function names | 2025 months | Namespace by month |

---

## 6. EXTRACTION PIPELINES - AUTOMATED

### 6.1 PIPELINE 1: Full Year Extraction
```bash
#!/bin/bash
# extract_year.sh --year YYYY --output ./extracted/YYYY

YEAR=$1
OUTPUT=$2

# 1. Convert all .xlsm → .xlsx
for xlsm in archive/$YEAR/*.xlsm; do
    libreoffice --headless --convert-to xlsx "$xlsm" --outdir /tmp
done

# 2. Extract BUILD sheet cells per year schema
python3 extract_cells.py --year $YEAR --input /tmp --output $OUTPUT/cells.json

# 3. Generate C++ from cells
python3 cells_to_cpp.py --cells $OUTPUT/cells.json --output $OUTPUT/src/

# 4. Run GearSlice analysis
./resume_gearslice.sh --year $YEAR --analyze --catalog --output $OUTPUT/analysis/

# 5. Generate repair report
./generate_repairs.py --analysis $OUTPUT/analysis/ --output $OUTPUT/repairs/
```

### 6.2 PIPELINE 2: Function-Level Extraction
```bash
#!/bin/bash
# extract_function.sh --function NAME --years "2022 2023 2024 2025"

FUNCTION=$1
YEARS=$2

for YEAR in $YEARS; do
    echo "=== $YEAR: $FUNCTION ==="
    # Find cell containing function
    CELL=$(grep -r "$FUNCTION" gearslice_analysis/$YEAR/*/spreadsheet_cells.json | head -1 | cut -d: -f1)
    if [ -n "$CELL" ]; then
        # Extract from that cell
        python3 extract_from_cell.py --cell-file $CELL --function $FUNCTION
    fi
done
```

### 6.3 PIPELINE 3: Repair Generation
```bash
#!/bin/bash
# generate_repairs.sh --analysis-dir gearslice_analysis/

# 1. Find unused cells (devolution)
find gearslice_analysis -name "code_bundles.json" -exec \
    python3 -c "
import json, sys
for f in sys.argv[1:]:
    with open(f) as fp: d=json.load(fp)
    for u in d.get('unused', []):
        print(f'{f}: UNUSED {u[\"cell\"]} = {u[\"snippet\"][:80]}')
    " {} + > unused_cells.txt

# 2. Find missing base classes
python3 find_missing_bases.py --classes gearslice_analysis/*/catalog_summary.json

# 3. Generate repair patches
python3 gen_patches.py --unused unused_cells.txt --output repairs/
```

---

## 7. SPREADSHEET CELL REPAIR TEMPLATES

### 7.1 CELL REPAIR FORMAT
Each repairable cell follows this structure in the spreadsheet:

```
Cell: A{row}
Type: {FUNCTION|CLASS|GLOBAL|INCLUDE|PROTO|TEMPLATE}
Status: {INCORPORATED|PARTIAL|UNUSED|MISSING}
Dependencies: {comma-separated cell refs}
Repair: {AUTO|MANUAL|SKIP}
```

### 7.2 REPAIR TEMPLATES BY TYPE

#### FUNCTION REPAIR
```cpp
// TEMPLATE: Function repair from cell A{row}
// SOURCE: spreadsheet_cells.json["A{row}"]
// TARGET: extracted_cpp/main_{stem}.cpp

{return_type} {name}({params}) {
    {body_from_cell}
    // REPAIR MARKERS:
    // TODO: Add error handling
    // TODO: Add logging
    // TODO: Validate params
}
```

#### CLASS REPAIR
```cpp
// TEMPLATE: Class repair from cells A{start}-A{end}
// SOURCE: spreadsheet_cells.json range
// TARGET: extracted_cpp/{class_name}.hpp/.cpp

class {ClassName} : public {BaseClass} {
    // MEMBERS from cells A{start}-A{mid}
    {members}
public:
    // METHODS from cells A{mid}-A{end}
    {methods}
    
    // REPAIR: Add virtual destructor if polymorphic
    virtual ~{ClassName}() = default;
};
```

#### MISSING BASE CLASS INJECTION
```cpp
// INJECT into 2022 extracted code (retrofit)
// FILE: gearslice_analysis/2022/gyrocoreMultiPages/repair_base.hpp

#ifndef GYROCORE_BASE_HPP
#define GYROCORE_BASE_HPP

// Retrofitted base classes for 2022 compatibility
class IGyroCoreModule {
public:
    virtual void initialize() = 0;
    virtual void process(double dt) = 0;
    virtual void shutdown() = 0;
    virtual ~IGyroCoreModule() = default;
};

class IRealmConduit : public IGyroCoreModule {
public:
    virtual void connect() = 0;
    virtual void transmit(const Packet&) = 0;
};

class IVariableManager : public IGyroCoreModule {
public:
    virtual void registerVariable(const std::string&, void*) = 0;
    virtual void* getVariable(const std::string&) = 0;
};

#endif
```

---

## 8. STEERING COMMANDS QUICK REFERENCE

```bash
# === ANALYSIS ===
./resume_gearslice.sh --year 2025 --analyze --catalog --evolution

# === EXTRACTION ===
./extract_function.sh --function "realm_gl_vulkan" --years "2022 2023 2024 2025"
./extract_class.sh --class "GraphicsBackend" --year 2024
./extract_module.sh --module "primeGyroGear" --year 2023

# === REPAIR ===
./repair_base_classes.sh --target 2022 --source 2024
./inject_missing_virtuals.sh --year 2024 --class "GraphicsBackend"
./gen_async_callbacks.sh --year 2024 --layer "NetworkLayer"

# === VERSION STEERING ===
./compare_milestones.sh v2024.09 v2025.01
./delta_extract.sh --from v2024.09 --to v2025.01
./tag_milestone.sh --name "v2025.04_GUI_complete"

# === VALIDATION ===
./validate_incorporation.sh --year 2025 --threshold 95
./check_unused_cells.sh --year 2025 --action report
./regression_test.sh --baseline v2024.09 --current HEAD
```

---

## 9. DATA FILES FOR AUTOMATION

All machine-readable data in `gearslice_analysis/`:

| File | Purpose | Schema |
|------|---------|--------|
| `*/spreadsheet_cells.json` | Raw cell data | `{year, sheet, cells: {ref: value}}` |
| `*/code_bundles.json` | Incorporation analysis | `{incorporated, unused, bundles, structure}` |
| `*/todo_catalog.json` | TODOs/milestones | `{todos, milestones, directions, functions, classes}` |
| `*/catalog_summary.json` | Year rollup | `{files, incorporated, functions, classes}` |
| `cross_year_evolution.md` | Human report | Markdown table + analysis |

---

## 10. NEXT ACTIONS CHECKLIST

- [ ] **Inject base classes** into 2022 extracted code (`repair_base.hpp`)
- [ ] **Complete NetworkLayer async** in 2024 extraction
- [ ] **Create IPrimeOneService** interface for GUI/SERVICE unification
- [ ] **Tag milestones** v2024.09, v2025.01, v2025.04
- [ ] **Run regression tests** against v2024.09 baseline
- [ ] **Archive primeGyroGear** variants (2023 only) or resurrect
- [ ] **Namespace 2025 monthly functions** to prevent collision
- [ ] **Add TODO markers** from spreadsheet comments to C++

---

**This document is the steering wheel. Use the extraction pipelines, repair templates, and version commands to drive the codebase.**
