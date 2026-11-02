# PrimeOne Build System - Summary

## Completed Work

### 1. Spreadsheet Conversion (100% Complete)
- **1,623 total .xlsm files** converted to C++ across 4 years
  - 2022: 65 files
  - 2023: 509 files  
  - 2024: 384 files
  - 2025: 665 files
- Output: `/workspace/app/lol.dance/extracted_by_year/`

### 2. GearSlice Evolution Analysis (Complete)
- Created `resume_gearslice.sh` - analysis engine with:
  - `--slice` - Extract structural slices
  - `--analyze` - Deep pattern analysis
  - `--catalog` - Build signature catalogs
  - `--evolution` - Cross-year comparison
- Generated evolution reports for all years
- Enhanced steering guide: `cross_year_evolution_v2.md` (484 lines)
- 8 automation scripts for ongoing maintenance

### 3. Wine Build System (Created)
- Script: `/workspace/app/lol.dance/wine_build_primeone.sh`
- Features:
  - Parses Code::Blocks `.cbp` project file
  - Sets up Wine prefix with Windows SDK stubs
  - Supports native Linux build (with Windows header stubs)
  - Supports Wine + MinGW-w64 cross-compilation
  - Proper handling of paths with spaces

## Build Status

### Native Linux Build (g++)
**Status**: Compilation fails with 100+ errors
- Missing Windows headers (winsock2, ws2tcpip, d3d9, wbemidl, etc.)
- Type mismatches with `std::byte` (cannot multiply by int, assign from int)
- Ambiguous `pow()` overloads with `__int128`
- Missing return statements in non-void functions
- Uses Windows-specific types (DISPLAY_DEVICE, HWND, HINSTANCE, etc.)

### Wine + MinGW-w64 Build (x86_64-w64-mingw32-g++)
**Status**: Same compilation errors as native
- MinGW doesn't provide full Windows SDK
- Requires extensive Windows API stubbing
- Code uses MSVC-specific extensions (`__int128`, `#pragma comment`)

### Running Pre-built Windows Executable
**Status**: Fails - GUI application needs display server
- `PrimeOne.exe` exists in project (9.1 MB)
- Requires X11/Wayland display for window creation
- Container is headless (no display)

## Root Cause
The PrimeOne codebase (20,000+ lines in main.cpp) is **Windows-specific**:
- Written for MSVC (Visual Studio) on Windows
- Uses Windows SDK headers and libraries
- Uses MSVC extensions (`__int128`, structured exception handling)
- DirectX 9, CUDA, Windows networking, COM, WMI integration
- GUI application with WinMain, window procedures

## Recommendations

### Option 1: Build on Windows (Recommended)
- Use Code::Blocks with MinGW-w64 on Windows
- Or Visual Studio with MSVC
- All required SDKs available natively

### Option 2: Port to Cross-Platform
- Abstract Windows APIs behind platform layer
- Replace `__int128` with `boost::multiprecision::cpp_int` or custom
- Replace Windows networking with Boost.Asio or similar
- Replace DirectX/CUDA with cross-platform alternatives
- Separate GUI from core logic

### Option 3: Use Existing Binary
- The pre-built `PrimeOne.exe` (9.1 MB) exists and runs on Windows
- Can run on Linux via Wine with virtual display (Xvfb)
- Or use Windows VM/remote desktop

## Files Created
```
/workspace/app/lol.dance/
├── primeonecpp_resume.sh      # Original conversion script
├── resume_gearslice.sh        # GearSlice analysis engine
├── wine_build_primeone.sh     # Wine build system
├── extract_function.sh        # Extract functions from C++
├── extract_class.sh           # Extract classes
├── repair_base_classes.sh     # Fix inheritance
├── compare_milestones.sh      # Compare versions
├── delta_extract.sh           # Extract deltas
├── validate_incorporation.sh  # Validate changes
├── tag_milestone.sh           # Tag milestones
├── run_gearslice_pipeline.sh  # Full pipeline
└── gearslice_analysis/
    ├── cross_year_evolution_v2.md
    └── */*.json, *.md
```

## Key Insight
The GearSlice analysis revealed this is a **prime number computation engine** with:
- Tile-based prime generation algorithms
- Networked distributed computing (host/guest conduits)
- GPU acceleration via CUDA
- Windows GUI for visualization
- Persistent state management

The code is highly specialized and Windows-coupled. Cross-platform build requires significant refactoring, not just header stubbing.
