# Integration Note for project_eternal_launcher

There are two ways to integrate the `casual-pre-loader` C++ rewrite into the launcher: via CLI execution or direct DLL linking.

## Option 1: CLI Execution (Recommended for robustness)

The C++ executable accepts command-line arguments similar to the original Python script but with standard flags.

**Command:**
```bash
casual_pre_loader_cpp.exe --tf2-path "C:\Path\To\TF2" --config "config.json"
```

**Capture Output:**
The tool writes structured logs to `stdout`. The launcher should capture standard output to display progress bars or status messages.

Example output lines:
```text
[INFO] Scanning mods...
[INFO] Found 12 mods.
[INFO] Processing particle_fix.vpk...
```

## Option 2: Direct C++ API

If the launcher is written in C++ or supports C-bindings (FFI), you can link against the library.

**Include Header:**
```cpp
#include "casual_pre_loader.h"
```

**Usage:**
```cpp
PreloaderConfig config;
config.tf2Path = "C:\\Path\\To\\TF2";
config.modPaths.push_back("C:\\MyMods");

int result = RunPreloader(&config);
if (result != 0) {
    // Handle error
}
```

This method runs the preloader in the same process, so ensure exception safety boundary is handled if using the C++ classes directly. The `RunPreloader` C-API function catches internal exceptions and returns an error code.
