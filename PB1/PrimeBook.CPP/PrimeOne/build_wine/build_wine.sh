#!/bin/bash
# Build PrimeOne using Wine + MinGW-w64 from the project directory with local paths

set -euo pipefail

cd /workspace/app/PB1/PrimeBook.CPP/PrimeOne

export WINEPREFIX=/workspace/app/.wine_primeone

# Use local paths that exist in the Wine prefix
x86_64-w64-mingw32-g++ \
    -std=c++17 \
    -g \
    -Wall \
    -fexceptions \
    -I"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/include" \
    -Icurl/include \
    -Icurl/include/curl \
    -Icppcodec \
    -Ilibminiupnpc \
    -Ilibssh/include \
    main.cpp \
    -o PrimeOne.exe \
    -L"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.2/lib/x64" \
    -Lcurl/lib \
    -Llibminiupnpc \
    -Llibssh/lib/x64 \
    -lws2_32 \
    -lcurl \
    -lcudart \
    -ld3d9 \
    -ld3dx9 \
    -lsetupapi \
    curl/lib/libcurl.a \
    libssh/lib/x64/libssh.a \
    libssh/lib/x64/ssh.lib \
    2>&1 | tee build_wine/build.log

