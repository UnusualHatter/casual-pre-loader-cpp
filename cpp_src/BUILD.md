# Build Guide for casual_pre_loader_cpp

## Prerequisites
- **C++ Compiler**: MSVC (Visual Studio 2019/2022) or MinGW w/ GCC 10+
- **CMake**: Version 3.20 or later

## Building on Windows (Visual Studio)

1. Open a terminal (PowerShell or Command Prompt).
2. Navigate to the `cpp_src` directory.
3. Run CMake to generate build files:
   ```powershell
   cmake -S . -B build
   ```
4. Build the project:
   ```powershell
   cmake --build build --config Release
   ```
5. The executable will be located in `build/Release/casual_pre_loader_cpp.exe`.

## Building on Windows (MinGW)

1. Open a terminal.
2. Navigate to the `cpp_src` directory.
3. Run CMake:
   ```bash
   cmake -S . -B build -G "MinGW Makefiles"
   ```
4. Build:
   ```bash
   cmake --build build
   ```

## Running Tests
Run the tests using CTest from the build directory:
```powershell
cd build
ctest -C Release
```
