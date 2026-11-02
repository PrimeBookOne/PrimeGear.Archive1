#!/bin/bash
cd /workspace/app/PB1/PrimeBook.CPP/PrimeOne/build_wine
set -euo pipefail
cmd=(
    x86_64-w64-mingw32-g++
    -std=c++17
    -g
    -Wall
    -fexceptions
    '-I'"'"'Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/bin'"'"''
    '-I'"'"'Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/include'"'"''
    -IZ:/Users/Shark/Desktop/gyro.cpp.2023/curl/bin
    -IZ:/Users/Shark/Desktop/gyro.cpp.2023/curl/include
    -I../curl/include
    -I../curl/include/curl
    -Icppcodec
    -IZ:/Users/Shark/vcpkg/installed/x64-windows/include/
    -Ilibminiupnpc
    -I../libssh/include/libssh
    ../main.cpp
    -o
    PrimeOne.exe
    '-L'"'"'Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64'"'"''
    -L../curl/lib
    -LZ:/Users/Shark/vcpkg/installed/x64-windows/lib
    -Llibminiupnpc
    -lws2_32
    -lcurl
    ''"'"'Z:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64/cudart.lib'"'"''
    ''"'"'Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3d9.lib'"'"''
    ''"'"'Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64/d3dx9.lib'"'"''
    ''"'"'c:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3dx9.lib'"'"''
    ''"'"'Z:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x86/SetupAPI.Lib'"'"''
    ''"'"'Z:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64/SetupAPI.Lib'"'"''
    ../curl/lib/libcurl.a
    ''"'"'Z:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x86/d3d9.lib'"'"''
    ../libssh/lib/x64/libssh.a
    ../libssh/lib/x64/ssh.lib
)
"${cmd[@]}" 2>&1 | tee build.log
