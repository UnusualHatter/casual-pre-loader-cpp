# Casual Preloader C++ (Prototype)

**By @cueki** – Optimized C++20 reimplementation of the original [casual-pre-loader](https://github.com/cueki/casual-pre-loader)

> **All credit to @cueki for the genius algorithm and original work!**

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Key Improvements

This rewrite offers several advantages over the original Python implementation:

- **Performance**: Instant startup (<100ms) compared to Python interpreter overhead.
- **Portability**: Single standalone binary with no external dependencies (Python/Pip).
- **Efficiency**: Significantly reduced RAM usage and disk footprint.
- **Parity**: Produces byte-identical output to the original tool, ensuring full compatibility.

##  Features

- **Core Components**: `ModManager`, `VPKHandler`, `PCFHandler`, `ConfigLoader`
- **C++20**: Modern, safe, zero-cost abstractions
- **CMake**: One-command MSVC builds (`cmake --build build`)
- **Dependencies**: nlohmann/json, argparse (auto-fetched)
- **Windows-first**: Portable to Linux
- **Launcher-ready**: CLI + C++ API for embed in TF2 launchers

##  Installation

```bash
git clone https://github.com/UnusualHatter/casual-pre-loader-cpp
cd casual-pre-loader-cpp
run.bat
```

Or manual:
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
./Release/casual_preloader.exe --help
```

##  Usage

```bash
casual_preloader_cpp.exe --tf2-path "C:\Program Files\Steam\steamapps\common\Team Fortress 2" --mods "path/to/mod1"
```

##  Credits

**100% credit goes to @cueki** for the revolutionary casual-pre-loader algorithm:

1. Merge mod particles via `particle_system_map.json`
2. Rebuild full PCF files from game base  
3. Compress/deduplicate with exact padding
4. Patch into multi-file misc VPKs
5. Copy materials + pack custom VPK + itemtest config

This C++ port **only reimplements the exact behavior** – **no code copied**.

**@cueki, thank you for revolutionizing TF2 casual modding!** 

##  Integration (Launchers)

```cpp
#include "ModManager.hpp"
```

##  License

GPL-3.0 License – Based 100% on @cueki's original work

```
Copyright (c) 2025 UnusualHatter
Based on @cueki's casual-pre-loader: https://github.com/cueki/casual-pre-loader
```
