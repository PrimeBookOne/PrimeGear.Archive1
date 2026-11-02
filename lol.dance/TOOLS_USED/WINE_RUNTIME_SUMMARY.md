# PrimeOne Wine Runtime - Working Configuration

## ✅ WORKING: Console Version (PrimeOne3236.exe)

**Command:**
```bash
cd /workspace/app/.wine_primeone/drive_c/PrimeOne
script -q -c "/usr/lib/wine/wine64 PrimeOne3236.exe" /dev/null
```

**Or use the wrapper script:**
```bash
/workspace/app/run_primeone_wine.sh
```

**Why it works:**
- `PrimeOne3236.exe` is a **CONSOLE** subsystem executable (verified with `file`)
- `script` provides a pseudo-terminal (pty) that Wine recognizes as a valid console
- `GetConsoleWindow()` returns valid handle when run under `script`
- App sets console title "PrimeBookGear", hides cursor, clears screen in loop

**Observed behavior:**
- ANSI escape codes emitted: `]0;PrimeBookGear` (set title), `[?25l` (hide cursor), `[K` (clear line)
- Runs continuously (appears to be waiting for input or running prime computation)
- No "Failed to get console window handle" error

## ❌ NOT WORKING: GUI Version (PrimeOne.exe / PrimeOneGui.exe)

**Issues:**
- GUI subsystem executables - no console allocated by default
- Code calls `GetConsoleWindow()` which returns NULL for GUI apps
- Even with Xvfb, the console handle is not available
- Would need to either:
  1. Rebuild as CONSOLE subsystem (`/SUBSYSTEM:CONSOLE` in linker)
  2. Call `AllocConsole()` before `GetConsoleWindow()`
  3. Use Wine's `wineconsole` with proper backend

## 📦 Wine Environment Setup (Complete)

**Installed packages:**
- `wine64` (10.0~repack-6)
- `wine32:i386` (10.0~repack-6) - for wineconsole
- `winbind` - for ntlm_auth
- `xvfb` - virtual framebuffer
- `mingw-w64` - cross-compiler (for building)

**Wine prefix:** `/workspace/app/.wine_primeone`
- Contains full project copy with libraries (curl, libssh, libminiupnpc)
- Windows SDK stubs in `win_stubs/` (winsock2.h, ws2tcpip.h, windows.h, d3d9.h, etc.)
- CUDA headers/libs stubs
- DirectX SDK stubs
- Windows Kits stubs

## 🔨 Build Status (Still Blocked)

**Native Linux (g++)**: 100+ errors
- Missing Windows types (HWND, HINSTANCE, DISPLAY_DEVICE, etc.)
- `std::byte` type mismatches (can't multiply by int, assign from int)
- Ambiguous `pow(__int128)` overloads
- Missing return statements in non-void functions
- MSVC extensions (`__int128`, `#pragma comment`)

**Wine + MinGW-w64**: Same errors
- MinGW doesn't provide full Windows SDK
- Requires extensive API stubbing beyond headers

## 🎯 Recommendation

**For running:** Use the console version with `script` wrapper - it works now!

**For building:** Requires Windows (Code::Blocks/MinGW or Visual Studio) or significant porting effort:
1. Replace `__int128` with portable alternative
2. Fix `std::byte` usage (use `uint8_t` or explicit casts)
3. Abstract Windows APIs behind platform layer
4. Separate console/GUI code paths

## Files Created
```
/workspace/app/run_primeone_wine.sh      # Working console runner
/workspace/app/run_primeone_gui.sh       # GUI runner (needs fix)
/workspace/app/lol.dance/wine_build_primeone.sh  # Build system
/workspace/app/.wine_primeone/           # Wine prefix with stubs
```
