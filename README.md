# EEM0040: OpenCV homeworks C++ template

- Program entry point is `src/main.cpp`

- Built on Ubuntu 22.04 WSL

Required:
- Opencv `sudo apt install libopencv-dev`
- [CMake](https://cmake.org/download/) *3.12 minimum*
    - Ubuntu repository: https://apt.kitware.com/
- GCC or other c++ capable compiler: `sudo apt install build-essential`

Building:
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`