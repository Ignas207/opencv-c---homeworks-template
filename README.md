# EEM0040: OpenCV homeworks C++ template

- Video processing starts in `src/processing.cpp` **ProcessVideo**
- Image processing starts in `src/processing.cpp` **ProcessImage**

---

## Ubuntu WSL build

- Built on Ubuntu 22.04 WSL
  - *Also works on native!*

### Required:
- Opencv `sudo apt install libopencv-dev`
- [CMake](https://cmake.org/download/) *3.12 minimum*
    - Ubuntu repository: https://apt.kitware.com/
- GCC or other c++ capable compiler: `sudo apt install build-essential`

### Building:
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

---

## Windows native build

- Built on Windows 10
  
Required:
- Clang: `winget install LLVM.LLVM`
- [CMake](https://cmake.org/download/) `winget install Kitware.CMake`
- Ninja build: `winget install Ninja-build.Ninja`
- [OpenCV](https://opencv.org/releases/)
  - If you chose another extraction location than `C:/opencv`, make sure to adjust `OPENCV_MAIN_DIR` in `CMakeLists.txt`!

### Building

1. `mkdir build`
2. `cd build`
3. `cmake .. -G Ninja -D CMAKE_BUILD_TYPE="Debug" -D CMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang++.exe" -D CMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -D CMAKE_RC_COMPILER="C:/Program Files/LLVM/bin/llvm-rc.exe`
4. `ninja`

#### Some observations

- **Debug** builds on Windows are slow to run. Thus, configure a **release build**:
  - `cmake .. -G Ninja -D CMAKE_BUILD_TYPE="Release" -D CMAKE_CXX_COMPILER="C:/Program Files/LLVM/bin/clang++.exe" -D CMAKE_C_COMPILER="C:/Program Files/LLVM/bin/clang.exe" -D CMAKE_RC_COMPILER="C:/Program Files/LLVM/bin/llvm-rc.exe"`

