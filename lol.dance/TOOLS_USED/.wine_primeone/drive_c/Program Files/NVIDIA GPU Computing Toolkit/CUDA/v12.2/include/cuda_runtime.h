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
