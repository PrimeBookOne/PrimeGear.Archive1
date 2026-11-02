#!/bin/bash
# wine_build_primeone.sh - Build PrimeOne using Wine + MinGW-w64 (Code::Blocks project)

set -euo pipefail

WORKSPACE="/workspace/app"
PROJECT_DIR="${WORKSPACE}/PB1/PrimeBook.CPP/PrimeOne"
CBP_FILE="${PROJECT_DIR}/PrimeOne.cbp"
WINE_PREFIX="${WINE_PREFIX:-${WORKSPACE}/.wine_primeone}"
BUILD_DIR="${BUILD_DIR:-${PROJECT_DIR}/build_wine}"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

log() { echo -e "${GREEN}[BUILD]${NC} $*"; }
warn() { echo -e "${YELLOW}[WARN]${NC} $*"; }
err() { echo -e "${RED}[ERROR]${NC} $*"; }
info() { echo -e "${BLUE}[INFO]${NC} $*"; }

usage() {
    cat << 'USAGE'
wine_build_primeone.sh - Build PrimeOne via Wine + MinGW-w64

USAGE:
    ./wine_build_primeone.sh [OPTIONS]

OPTIONS:
    --setup             Setup Wine prefix and install dependencies
    --build             Build the project (Debug target)
    --clean             Clean build artifacts
    --rebuild           Clean and rebuild
    --run               Run the built executable
    --native            Force native Linux build (default: try native first)
    --wine              Force Wine + MinGW build
    --prefix PATH       Wine prefix path (default: .wine_primeone)
    --build-dir PATH    Build directory (default: PrimeOne/build_wine)
    --help              Show this help
USAGE
}

DO_SETUP=false
DO_BUILD=false
DO_CLEAN=false
DO_RUN=false
FORCE_NATIVE=false
FORCE_WINE=false

while [[ $# -gt 0 ]]; do
    case $1 in
        --setup) DO_SETUP=true ;;
        --build) DO_BUILD=true ;;
        --clean) DO_CLEAN=true ;;
        --run) DO_RUN=true ;;
        --rebuild) DO_CLEAN=true; DO_BUILD=true ;;
        --native) FORCE_NATIVE=true ;;
        --wine) FORCE_WINE=true ;;
        --prefix) WINE_PREFIX="$2"; shift ;;
        --build-dir) BUILD_DIR="$2"; shift ;;
        --help) usage; exit 0 ;;
        *) err "Unknown option: $1"; usage; exit 1 ;;
    esac
    shift
done

if [[ "$DO_SETUP" == false && "$DO_BUILD" == false && "$DO_CLEAN" == false && "$DO_RUN" == false ]]; then
    usage
    exit 1
fi

# ============================================================================
# WINE PREFIX SETUP
# ============================================================================
setup_wine_prefix() {
    log "Setting up Wine prefix: $WINE_PREFIX"
    
    export WINEPREFIX="$WINE_PREFIX"
    export WINEARCH=win64
    
    wineboot --init 2>/dev/null || true
    sleep 3
    
    if ! command -v winetricks &> /dev/null; then
        log "Installing winetricks..."
        cd /tmp
        wget -q https://raw.githubusercontent.com/Winetricks/winetricks/master/src/winetricks
        chmod +x winetricks
        mv winetricks /usr/local/bin/ 2>/dev/null || cp winetricks /usr/local/bin/
    fi
    
    log "Installing Windows components via winetricks..."
    winetricks -q vcrun2019 vcrun2022 corefonts 2>&1 | tail -20 || warn "Some winetricks failed (non-fatal)"
    
    if ! command -v x86_64-w64-mingw32-g++ &> /dev/null; then
        log "Installing MinGW-w64..."
        apt-get update && apt-get install -y mingw-w64 2>&1 | tail -10
    fi
    
    local dirs=(
        "$WINE_PREFIX/drive_c/PrimeOne"
        "$WINE_PREFIX/drive_c/PrimeOne/cppcodec"
        "$WINE_PREFIX/drive_c/PrimeOne/curl"
        "$WINE_PREFIX/drive_c/PrimeOne/libssh"
        "$WINE_PREFIX/drive_c/PrimeOne/libminiupnpc"
        "$WINE_PREFIX/drive_c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/bin"
        "$WINE_PREFIX/drive_c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/include"
        "$WINE_PREFIX/drive_c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Include"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Lib/x64"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Lib/x86"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64"
        "$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86"
        "$WINE_PREFIX/drive_c/Users/Shark/vcpkg/installed/x64-windows/include"
        "$WINE_PREFIX/drive_c/Users/Shark/vcpkg/installed/x64-windows/lib"
    )
    
    for dir in "${dirs[@]}"; do
        mkdir -p "$dir"
    done
    
    log "Copying project files to Wine prefix..."
    cp -r "$PROJECT_DIR"/* "$WINE_PREFIX/drive_c/PrimeOne/" 2>/dev/null || true
    
    create_stub_libraries
    
    log "Wine prefix setup complete"
}

create_stub_libraries() {
    log "Creating stub libraries for missing Windows SDKs..."
    
    local cuda_inc="$WINE_PREFIX/drive_c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/include"
    local cuda_lib="$WINE_PREFIX/drive_c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64"
    
    cat > "$cuda_inc/cuda_runtime.h" << 'CUDA_EOF'
#ifndef CUDA_RUNTIME_H
#define CUDA_RUNTIME_H
#include <stddef.h>
#include <stdint.h>
typedef enum cudaError { cudaSuccess = 0 } cudaError_t;
typedef struct CUstream_st *cudaStream_t;
typedef struct CUevent_st *cudaEvent_t;
cudaError_t cudaMalloc(void**, size_t);
cudaError_t cudaFree(void*);
cudaError_t cudaMemcpy(void*, const void*, size_t, int);
cudaError_t cudaGetLastError(void);
const char* cudaGetErrorString(cudaError_t);
int cudaGetDeviceCount(int*);
cudaError_t cudaSetDevice(int);
cudaError_t cudaDeviceSynchronize(void);
#endif
CUDA_EOF
    
    echo "INPUT(-lcudart)" > "$cuda_lib/cudart.lib"
    
    local dx_inc="$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Include"
    local dx_lib64="$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Lib/x64"
    local dx_lib32="$WINE_PREFIX/drive_c/Program Files (x86)/Microsoft DirectX SDK/June 2010/Lib/x86"
    
    cat > "$dx_inc/d3d9.h" << 'DX_EOF'
#ifndef D3D9_H
#define D3D9_H
#include <stdint.h>
typedef struct IDirect3D9 IDirect3D9;
typedef struct IDirect3DDevice9 IDirect3DDevice9;
typedef struct IDirect3DSurface9 IDirect3DSurface9;
typedef struct IDirect3DTexture9 IDirect3DTexture9;
#define D3D_SDK_VERSION 32
#define D3DADAPTER_DEFAULT 0
#define D3DDEVTYPE_HAL 1
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING 0x00000020
IDirect3D9* Direct3DCreate9(uint32_t);
#endif
DX_EOF
    
    echo "INPUT(-ld3d9)" > "$dx_lib64/d3d9.lib"
    echo "INPUT(-ld3dx9)" > "$dx_lib64/d3dx9.lib"
    echo "INPUT(-ld3d9)" > "$dx_lib32/d3d9.lib"
    echo "INPUT(-ld3dx9)" > "$dx_lib32/d3dx9.lib"
    
    local kit_inc="$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um"
    local kit_lib64="$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64"
    local kit_lib32="$WINE_PREFIX/drive_c/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86"
    
    cat > "$kit_inc/SetupAPI.h" << 'SETUP_EOF'
#ifndef SETUPAPI_H
#define SETUPAPI_H
#include <windows.h>
#include <stdint.h>
typedef void* HDEVINFO;
typedef struct _SP_DEVINFO_DATA { DWORD cbSize; } SP_DEVINFO_DATA;
BOOL SetupDiGetClassDevsExA(LPCGUID, LPCSTR, HWND, DWORD, HDEVINFO, LPCSTR, PVOID);
BOOL SetupDiEnumDeviceInfo(HDEVINFO, DWORD, PSP_DEVINFO_DATA);
BOOL SetupDiGetDeviceRegistryPropertyA(HDEVINFO, PSP_DEVINFO_DATA, DWORD, PDWORD, PBYTE, DWORD, PDWORD);
BOOL SetupDiDestroyDeviceInfoList(HDEVINFO);
#endif
SETUP_EOF
    
    echo "INPUT(-lsetupapi)" > "$kit_lib64/SetupAPI.Lib"
    echo "INPUT(-lsetupapi)" > "$kit_lib32/SetupAPI.Lib"
    
    mkdir -p "$WINE_PREFIX/drive_c/Users/Shark/vcpkg/installed/x64-windows/include"
    mkdir -p "$WINE_PREFIX/drive_c/Users/Shark/vcpkg/installed/x64-windows/lib"
    
    log "Stub libraries created"
}

# ============================================================================
# PARSE CODE::BLOCKS PROJECT
# ============================================================================
parse_cbp() {
    log "Parsing Code::Blocks project: $CBP_FILE"
    
    if [[ ! -f "$CBP_FILE" ]]; then
        err "CBP file not found: $CBP_FILE"
        exit 1
    fi
    
    python3 << 'PYEOF'
import xml.etree.ElementTree as ET
import sys
import os
import json
import shlex

cbp_file = os.environ.get("CBP_FILE", "")
build_dir = os.environ.get("BUILD_DIR", "")
project_dir = os.environ.get("PROJECT_DIR", "")

tree = ET.parse(cbp_file)
root = tree.getroot()

project = root.find("Project")
if project is None:
    print("No Project element found")
    sys.exit(1)

compiler_opts = []
include_dirs = []
linker_opts = []
libraries = []
lib_dirs = []
units = []

for opt in project.findall(".//Compiler/Add"):
    option = opt.get("option")
    directory = opt.get("directory")
    if option:
        compiler_opts.append(option)
    if directory:
        directory = directory.replace("C:/", "Z:/").replace("C:\\", "Z:\\").replace("\\", "/")
        include_dirs.append(directory)

for opt in project.findall(".//Linker/Add"):
    option = opt.get("option")
    library = opt.get("library")
    directory = opt.get("directory")
    if option:
        linker_opts.append(option)
    if library:
        library = library.replace("C:/", "Z:/").replace("C:\\", "Z:\\").replace("\\", "/")
        libraries.append(library)
    if directory:
        directory = directory.replace("C:/", "Z:/").replace("C:\\", "Z:\\").replace("\\", "/")
        lib_dirs.append(directory)

for unit in project.findall(".//Unit"):
    filename = unit.get("filename")
    if filename and filename.endswith((".cpp", ".c", ".cu")):
        units.append(filename)

output_name = "PrimeOne.exe"
for target in project.findall(".//Target"):
    title = target.get("title")
    if title == "Debug":
        out_elem = target.find("Option[@name='output']")
        if out_elem is not None:
            output_name = out_elem.get("value", "PrimeOne.exe")

config = {
    "compiler_opts": compiler_opts,
    "include_dirs": include_dirs,
    "linker_opts": linker_opts,
    "libraries": libraries,
    "lib_dirs": lib_dirs,
    "units": units,
    "output_name": output_name
}

with open(os.path.join(build_dir, "build_config.json"), "w") as f:
    json.dump(config, f, indent=2)

print(f"Parsed: {len(compiler_opts)} compiler opts, {len(include_dirs)} includes, {len(libraries)} libs, {len(units)} units")
for u in units:
    print(f"  Source: {u}")
PYEOF
}

# ============================================================================
# BUILD WITH WINE + MINGW (using properly quoted paths)
# ============================================================================
build_with_wine() {
    log "Building PrimeOne with Wine + MinGW-w64..."
    
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    
    export CBP_FILE="$CBP_FILE"
    export BUILD_DIR="$BUILD_DIR"
    export PROJECT_DIR="$PROJECT_DIR"
    parse_cbp
    
    # Generate build script with proper quoting for paths with spaces
    python3 << 'PYEOF'
import json
import os
import shlex

with open(os.path.join(os.environ["BUILD_DIR"], "build_config.json")) as f:
    config = json.load(f)

compiler_opts = config["compiler_opts"]
include_dirs = config["include_dirs"]
linker_opts = config["linker_opts"]
libraries = config["libraries"]
lib_dirs = config["lib_dirs"]
units = config["units"]

cxx = "x86_64-w64-mingw32-g++"
std = "-std=c++17"
opts = " ".join(compiler_opts)

# Quote include paths that contain spaces
quoted_includes = []
for inc in include_dirs:
    quoted_includes.append(f'-I{shlex.quote(inc)}')
includes = " ".join(quoted_includes)

ld_opts = " ".join(linker_opts)

# Quote library paths that contain spaces
quoted_libs = []
for lib in libraries:
    quoted_libs.append(shlex.quote(lib))
libs = " ".join(quoted_libs)

quoted_lib_paths = []
for libdir in lib_dirs:
    quoted_lib_paths.append(f'-L{shlex.quote(libdir)}')
lib_paths = " ".join(quoted_lib_paths)

src_files = " ".join(f"../{unit}" for unit in units)
output = config["output_name"]

cmd_parts = [cxx, std]
cmd_parts.extend(compiler_opts)
for inc in include_dirs:
    cmd_parts.append(f'-I{shlex.quote(inc)}')
cmd_parts.append(src_files)
cmd_parts.extend(['-o', output])
for libdir in lib_dirs:
    cmd_parts.append(f'-L{shlex.quote(libdir)}')
cmd_parts.extend(linker_opts)
for lib in libraries:
    cmd_parts.append(shlex.quote(lib))

# Write build script using array for proper quoting
with open(os.path.join(os.environ["BUILD_DIR"], "build.sh"), "w") as f:
    f.write("#!/bin/bash\n")
    f.write(f"cd {shlex.quote(os.environ['BUILD_DIR'])}\n")
    f.write("set -euo pipefail\n")
    f.write("cmd=(\n")
    for part in cmd_parts:
        f.write(f"    {shlex.quote(part)}\n")
    f.write(")\n")
    f.write('"${cmd[@]}" 2>&1 | tee build.log\n')

os.chmod(os.path.join(os.environ["BUILD_DIR"], "build.sh"), 0o755)

# Also print the command for debugging
print("Build script generated with proper quoting")
print(f"Command parts: {len(cmd_parts)}")
PYEOF
    
    log "Running Wine build..."
    cd "$BUILD_DIR"
    ./build.sh 2>&1 | tee build.log
    
    if [[ -f "PrimeOne.exe" ]]; then
        log "Wine build successful: PrimeOne.exe"
        ls -la PrimeOne.exe
    else
        err "Wine build failed - PrimeOne.exe not found"
        cat build.log
        exit 1
    fi
}

# ============================================================================
# NATIVE LINUX BUILD (with Windows header stubs)
# ============================================================================
build_native_linux() {
    log "Building PrimeOne natively on Linux (with Windows stubs)..."
    
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    
    export CBP_FILE="$CBP_FILE"
    export BUILD_DIR="$BUILD_DIR"
    export PROJECT_DIR="$PROJECT_DIR"
    parse_cbp
    
    python3 << 'PYEOF'
import json
import os

with open(os.path.join(os.environ["BUILD_DIR"], "build_config.json")) as f:
    config = json.load(f)

compiler_opts = config["compiler_opts"]
include_dirs = config["include_dirs"]
linker_opts = config["linker_opts"]
libraries = config["libraries"]
lib_dirs = config["lib_dirs"]
units = config["units"]

linux_compiler_opts = []
for opt in compiler_opts:
    if not any(x in opt for x in ["-mwindows", "/SUBSYSTEM"]):
        linux_compiler_opts.append(opt)

linux_compiler_opts.extend([
    "-D__linux__",
    "-D_WIN32_WINNT=0x0600",
    "-DUNICODE",
    "-D_UNICODE",
    "-pthread",
    "-fopenmp"
])

linux_includes = []
for inc in include_dirs:
    inc = inc.replace("Z:/", "/").replace("Z:\\", "/")
    if "/PrimeOne/" in inc:
        linux_includes.append(inc.replace("Z:/PrimeOne/", "/workspace/app/PB1/PrimeBook.CPP/PrimeOne/"))
    elif "/cppcodec" in inc:
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/PrimeOne/cppcodec")
    elif "/curl/include" in inc:
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/curl/include")
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/curl/include/curl")
    elif "/libssh/include" in inc:
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/libssh/include")
    elif "/libminiupnpc" in inc:
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/libminiupnpc")
    elif "/jsoncpp" in inc:
        linux_includes.append("/workspace/app/PB1/PrimeBook.CPP/jsoncpp/include")
    elif inc.startswith("/workspace/") or inc.startswith("/usr/"):
        linux_includes.append(inc)

linux_includes.append("/usr/include")
linux_includes.append("/usr/local/include")

# Create Windows header stubs in build directory
stub_inc = os.path.join(os.environ["BUILD_DIR"], "win_stubs")
os.makedirs(stub_inc, exist_ok=True)

# winsock2.h stub
with open(os.path.join(stub_inc, "winsock2.h"), "w") as f:
    f.write("""#ifndef WINSOCK2_H
#define WINSOCK2_H
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
typedef unsigned int SOCKET;
#define INVALID_SOCKET (-1)
#define SOCKET_ERROR (-1)
#define SD_RECEIVE 0
#define SD_SEND 1
#define SD_BOTH 2
int WSAStartup(unsigned short, void*);
int WSACleanup(void);
SOCKET socket(int, int, int);
int closesocket(SOCKET);
int connect(SOCKET, const struct sockaddr*, int);
int send(SOCKET, const char*, int, int);
int recv(SOCKET, char*, int, int);
int select(int, void*, void*, void*, struct timeval*);
int ioctlsocket(SOCKET, long, unsigned long*);
unsigned long htonl(unsigned long);
unsigned short htons(unsigned short);
unsigned long ntohl(unsigned long);
unsigned short ntohs(unsigned short);
const char* inet_ntoa(struct in_addr);
int inet_pton(int, const char*, void*);
#endif
""")

# ws2tcpip.h stub
with open(os.path.join(stub_inc, "ws2tcpip.h"), "w") as f:
    f.write("""#ifndef WS2TCPIP_H
#define WS2TCPIP_H
#include <winsock2.h>
#include <netdb.h>
int getaddrinfo(const char*, const char*, const void*, void**);
void freeaddrinfo(void*);
int getnameinfo(const void*, int, char*, int, char*, int, int);
#endif
""")

# windows.h stub (minimal)
with open(os.path.join(stub_inc, "windows.h"), "w") as f:
    f.write("""#ifndef WINDOWS_H
#define WINDOWS_H
#include <stdint.h>
#include <stddef.h>
typedef void* HANDLE;
typedef void* HWND;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uintptr_t WPARAM;
typedef intptr_t LPARAM;
typedef intptr_t LRESULT;
typedef uint16_t WORD;
typedef const char* LPCSTR;
typedef const wchar_t* LPCWSTR;
typedef char* LPSTR;
typedef wchar_t* LPWSTR;
#define WINAPI __stdcall
#define CALLBACK __stdcall
#define IN
#define OUT
#define OPTIONAL
#define MAX_PATH 260
#define TRUE 1
#define FALSE 0
#define NULL 0
#endif
""")

# winbase.h stub
with open(os.path.join(stub_inc, "winbase.h"), "w") as f:
    f.write("""#ifndef WINBASE_H
#define WINBASE_H
#include <windows.h>
#define INFINITE 0xFFFFFFFF
#define WAIT_OBJECT_0 0
#define WAIT_TIMEOUT 258
typedef struct _OVERLAPPED { void* Internal; void* InternalHigh; uint32_t Offset; uint32_t OffsetHigh; HANDLE hEvent; } OVERLAPPED;
BOOL CloseHandle(HANDLE);
DWORD WaitForSingleObject(HANDLE, DWORD);
HANDLE CreateEventA(void*, int, int, const char*);
BOOL SetEvent(HANDLE);
BOOL ResetEvent(HANDLE);
#endif
""")

# d3d9.h stub
with open(os.path.join(stub_inc, "d3d9.h"), "w") as f:
    f.write("""#ifndef D3D9_H
#define D3D9_H
#include <stdint.h>
typedef struct IDirect3D9 IDirect3D9;
typedef struct IDirect3DDevice9 IDirect3DDevice9;
typedef struct IDirect3DSurface9 IDirect3DSurface9;
typedef struct IDirect3DTexture9 IDirect3DTexture9;
#define D3D_SDK_VERSION 32
#define D3DADAPTER_DEFAULT 0
#define D3DDEVTYPE_HAL 1
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING 0x00000020
IDirect3D9* Direct3DCreate9(uint32_t);
#endif
""")

# wbemidl.h stub
with open(os.path.join(stub_inc, "wbemidl.h"), "w") as f:
    f.write("""#ifndef WBEMIDL_H
#define WBEMIDL_H
#include <windows.h>
typedef void* IWbemLocator;
typedef void* IWbemServices;
typedef void* IEnumWbemClassObject;
typedef void* IWbemClassObject;
#define WBEM_INFINITE 0xFFFFFFFF
HRESULT CoCreateInstance(void*, void*, DWORD, void*, void**);
HRESULT CoInitializeEx(void*, DWORD);
void CoUninitialize(void);
#endif
""")

# conio.h stub
with open(os.path.join(stub_inc, "conio.h"), "w") as f:
    f.write("""#ifndef CONIO_H
#define CONIO_H
int _kbhit(void);
int _getch(void);
#endif
""")

# process.h stub
with open(os.path.join(stub_inc, "process.h"), "w") as f:
    f.write("""#ifndef PROCESS_H
#define PROCESS_H
#include <stdint.h>
typedef uintptr_t _beginthreadex_proc_type;
uintptr_t _beginthreadex(void*, unsigned, _beginthreadex_proc_type, void*, unsigned, unsigned*);
void _endthreadex(unsigned);
#define _beginthread(func, stack, arg) _beginthreadex(NULL, stack, func, arg, 0, NULL)
#endif
""")

# Wbemcli.h stub
with open(os.path.join(stub_inc, "Wbemcli.h"), "w") as f:
    f.write("""#ifndef WBEMCLI_H
#define WBEMCLI_H
#include <wbemidl.h>
#endif
""")

# TlHelp32.h stub
with open(os.path.join(stub_inc, "TlHelp32.h"), "w") as f:
    f.write("""#ifndef TLHELP32_H
#define TLHELP32_H
#include <windows.h>
#include <stdint.h>
typedef struct tagPROCESSENTRY32 { DWORD dwSize; DWORD cntUsage; DWORD th32ProcessID; uintptr_t th32DefaultHeapID; DWORD th32ModuleID; DWORD cntThreads; DWORD th32ParentProcessID; LONG pcPriClassBase; DWORD dwFlags; char szExeFile[MAX_PATH]; } PROCESSENTRY32;
HANDLE CreateToolhelp32Snapshot(DWORD, DWORD);
BOOL Process32First(HANDLE, PROCESSENTRY32*);
BOOL Process32Next(HANDLE, PROCESSENTRY32*);
#endif
""")

# iphlpapi.h stub
with open(os.path.join(stub_inc, "iphlpapi.h"), "w") as f:
    f.write("""#ifndef IPHLPAPI_H
#define IPHLPAPI_H
#include <winsock2.h>
#include <stdint.h>
typedef struct _IP_ADAPTER_INFO { struct _IP_ADAPTER_INFO* Next; char ComboIndex[256]; char AdapterName[256]; char Description[128]; UINT AddressLength; BYTE Address[8]; DWORD Index; UINT Type; UINT DhcpEnabled; char CurrentIpAddress[16]; char IpAddressList[100]; char GatewayList[100]; char DhcpServer[100]; BOOL HaveWins; char WinsServer[100]; DWORD LeaseObtained; DWORD LeaseExpires; } IP_ADAPTER_INFO;
DWORD GetAdaptersInfo(IP_ADAPTER_INFO*, PULONG);
#endif
""")

# SetupAPI.h stub
with open(os.path.join(stub_inc, "SetupAPI.h"), "w") as f:
    f.write("""#ifndef SETUPAPI_H
#define SETUPAPI_H
#include <windows.h>
typedef void* HDEVINFO;
typedef struct _SP_DEVINFO_DATA { DWORD cbSize; } SP_DEVINFO_DATA;
BOOL SetupDiGetClassDevsExA(void*, void*, HWND, DWORD, HDEVINFO, void*, void*);
BOOL SetupDiEnumDeviceInfo(HDEVINFO, DWORD, void*);
BOOL SetupDiGetDeviceRegistryPropertyA(HDEVINFO, void*, DWORD, DWORD*, void*, DWORD, DWORD*);
BOOL SetupDiDestroyDeviceInfoList(HDEVINFO);
#endif
""")

# winternl.h stub
with open(os.path.join(stub_inc, "winternl.h"), "w") as f:
    f.write("""#ifndef WINTERNL_H
#define WINTERNL_H
#include <windows.h>
typedef struct _PEB { BYTE Reserved1[2]; BYTE BeingDebugged; BYTE Reserved2[1]; void* Reserved3[2]; void* Ldr; void* ProcessParameters; } PEB;
typedef struct _TEB { void* Reserved1[12]; PEB* ProcessEnvironmentBlock; } TEB;
#endif
""")

# comdef.h stub
with open(os.path.join(stub_inc, "comdef.h"), "w") as f:
    f.write("""#ifndef COMDEF_H
#define COMDEF_H
#include <windows.h>
#define _com_error HRESULT
#define _bstr_t const char*
#endif
""")

# Mstcpip.h stub
with open(os.path.join(stub_inc, "Mstcpip.h"), "w") as f:
    f.write("""#ifndef MSTCPIP_H
#define MSTCPIP_H
#include <winsock2.h>
#define SIO_KEEPALIVE_VALS _WSAIOW(IOC_VENDOR, 4)
struct tcp_keepalive { uint32_t onoff; uint32_t keepalivetime; uint32_t keepaliveinterval; };
#endif
""")

# Iptypes.h stub
with open(os.path.join(stub_inc, "Iptypes.h"), "w") as f:
    f.write("""#ifndef IPTYPES_H
#define IPTYPES_H
#include <winsock2.h>
#include <stdint.h>
typedef struct _IP_ADDR_STRING { struct _IP_ADDR_STRING* Next; char IpAddress[16]; char IpMask[16]; DWORD Context; } IP_ADDR_STRING;
typedef struct _IP_ADAPTER_INFO { struct _IP_ADAPTER_INFO* Next; char ComboIndex[256]; char AdapterName[256]; char Description[128]; UINT AddressLength; BYTE Address[8]; DWORD Index; UINT Type; UINT DhcpEnabled; char CurrentIpAddress[16]; IP_ADDR_STRING IpAddressList; IP_ADDR_STRING GatewayList; IP_ADDR_STRING DhcpServer; BOOL HaveWins; IP_ADDR_STRING WinsServer; DWORD LeaseObtained; DWORD LeaseExpires; } IP_ADAPTER_INFO;
#endif
""")

# Wbemidl.h already created above

linux_includes.insert(0, stub_inc)

linux_libs = []
for lib in libraries:
    lib_lower = lib.lower()
    if "ws2_32" in lib_lower:
        pass
    elif "curl" in lib_lower and lib.endswith(".a"):
        linux_libs.append(lib)
    elif "cudart" in lib_lower:
        pass
    elif "d3d9" in lib_lower or "d3dx9" in lib_lower:
        pass
    elif "setupapi" in lib_lower:
        pass
    elif "wbemuuid" in lib_lower:
        pass
    elif "iphlpapi" in lib_lower:
        pass
    elif "libssh" in lib_lower and lib.endswith(".a"):
        linux_libs.append(lib)
    elif lib.endswith(".a"):
        linux_libs.append(lib)

linux_lib_dirs = []
for libdir in lib_dirs:
    libdir = libdir.replace("Z:/", "/").replace("Z:\\", "/")
    if "/PrimeOne/" in libdir:
        linux_lib_dirs.append(libdir.replace("Z:/PrimeOne/", "/workspace/app/PB1/PrimeBook.CPP/PrimeOne/"))
    elif "/curl/lib" in libdir:
        linux_lib_dirs.append("/workspace/app/PB1/PrimeBook.CPP/curl/lib")
    elif "/libssh/lib" in libdir:
        linux_lib_dirs.append("/workspace/app/PB1/PrimeBook.CPP/libssh/lib")
    elif "/libminiupnpc" in libdir:
        linux_lib_dirs.append("/workspace/app/PB1/PrimeBook.CPP/libminiupnpc")
    elif libdir.startswith("/workspace/") or libdir.startswith("/usr/"):
        linux_lib_dirs.append(libdir)
    else:
        linux_lib_dirs.append(libdir)

src_files = " ".join(f"../{unit}" for unit in units)
output = "PrimeOne_linux"

cxx = "g++"
std = "-std=c++17"
opts = " ".join(linux_compiler_opts)
includes = " ".join(f"-I{dir}" for dir in linux_includes)
lib_paths = " ".join(f"-L{dir}" for dir in linux_lib_dirs)
libs = " ".join(linux_libs)

cmd = f"{cxx} {std} {opts} {includes} {src_files} -o {output} {lib_paths} {libs} -lrt -ldl -lpthread -lcurl -lssl -lcrypto"

print(f"Linux Compiler: {cxx}")
print(f"Sources: {src_files}")
print(f"Includes count: {len(linux_includes)}")
print(f"Libs: {libs}")
print(f"")
print(f"FULL COMMAND:")
print(cmd)

with open(os.path.join(os.environ["BUILD_DIR"], "build_linux.sh"), "w") as f:
    f.write("#!/bin/bash\n")
    f.write(f"cd {os.environ['BUILD_DIR']}\n")
    f.write(f"{cmd}\n")

os.chmod(os.path.join(os.environ["BUILD_DIR"], "build_linux.sh"), 0o755)
PYEOF
    
    log "Running native Linux build..."
    cd "$BUILD_DIR"
    ./build_linux.sh 2>&1 | tee build_linux.log
    
    if [[ -f "PrimeOne_linux" ]]; then
        log "Native Linux build successful: PrimeOne_linux"
        ls -la PrimeOne_linux
    else
        warn "Native build failed - trying Wine build instead"
        if [[ "$FORCE_NATIVE" == true ]]; then
            err "Native build failed and --native forced"
            exit 1
        fi
        build_with_wine
    fi
}

# ============================================================================
# CLEAN
# ============================================================================
clean_build() {
    log "Cleaning build directory: $BUILD_DIR"
    rm -rf "$BUILD_DIR"
    log "Clean complete"
}

# ============================================================================
# RUN
# ============================================================================
run_executable() {
    local exe="$BUILD_DIR/PrimeOne.exe"
    local linux_exe="$BUILD_DIR/PrimeOne_linux"
    
    if [[ -f "$linux_exe" ]]; then
        log "Running native Linux executable..."
        cd "$BUILD_DIR"
        ./PrimeOne_linux
    elif [[ -f "$exe" ]]; then
        log "Running Windows executable via Wine..."
        export WINEPREFIX="$WINE_PREFIX"
        cd "$BUILD_DIR"
        wine64 PrimeOne.exe
    else
        err "No executable found. Run --build first."
        exit 1
    fi
}

# ============================================================================
# MAIN
# ============================================================================
main() {
    log "PrimeOne Wine Build System"
    log "Project: $PROJECT_DIR"
    log "Wine Prefix: $WINE_PREFIX"
    log "Build Dir: $BUILD_DIR"
    
    if [[ "$DO_CLEAN" == true ]]; then
        clean_build
    fi
    
    if [[ "$DO_SETUP" == true ]]; then
        setup_wine_prefix
    fi
    
    if [[ "$DO_BUILD" == true ]]; then
        if [[ "$FORCE_WINE" == true ]]; then
            build_with_wine
        else
            build_native_linux
        fi
    fi
    
    if [[ "$DO_RUN" == true ]]; then
        run_executable
    fi
    
    log "Done!"
}

main "$@"
