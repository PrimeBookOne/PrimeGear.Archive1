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
