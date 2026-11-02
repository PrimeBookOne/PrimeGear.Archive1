#define __STDC_WANT_SECURE_LIB__ 0
#include <iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>

__global__ void parallelKernel() {

    int x =int(blockIdx.x);
    int y = int(blockDim.x);
    int z = int(threadIdx.x);
 //   int threadId = blockIdx.x * blockDim.x + threadIdx.x;
  int threadId = x * y * z;
    // Perform parallel computation using threadId
    // ...

    // Example: Print the threadId
    printf("Thread ID: %d\n", threadId);
}

int main() {
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);

    for (int device = 0; device < deviceCount; ++device) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, device);

        std::cout << "Device " << device << ": " << deviceProp.name << std::endl;

      //  dim3 blockSize(int(deviceProp.maxThreadsPerBlock));
      //  dim3 gridSize(deviceProp.maxGridSize[0]);

      dim3 blockSize(static_cast<unsigned int>(deviceProp.maxThreadsPerBlock));
dim3 gridSize(static_cast<unsigned int>(deviceProp.maxGridSize[0]));





        parallelKernel<<<gridSize, blockSize>>>();
        cudaDeviceSynchronize();

        cudaError_t error = cudaGetLastError();
        if (error != cudaSuccess) {
            std::cerr << "CUDA error: " << cudaGetErrorString(error) << std::endl;
        }
    }

    cudaDeviceReset();  // Added to ensure proper cleanup and device reset

    return 0;
}
