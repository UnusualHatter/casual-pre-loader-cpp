@echo off
setlocal enabledelayedexpansion

set "SOURCE_DIR=%~dp0cpp_src"
set "BUILD_DIR=%SOURCE_DIR%\build"

if not exist "%SOURCE_DIR%" (
    echo Error: cpp_src directory not found.
    exit /b 1
)

if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
)

pushd "%BUILD_DIR%"

echo Configuring CMake...
cmake ..
if %errorlevel% neq 0 (
    echo CMake configuration failed.
    popd
    exit /b %errorlevel%
)

echo Building Project...
cmake --build . --config Release
if %errorlevel% neq 0 (
    echo Build failed.
    popd
    exit /b %errorlevel%
)

echo Running Application...
cd Release

set "TF2_PATH=%~1"
if "%TF2_PATH%"=="" (
    set /p "TF2_PATH=Enter path to TF2 installation (e.g. C:\Program Files (x86)\Steam\steamapps\common\Team Fortress 2): "
)

if "%TF2_PATH%"=="" (
    casual_pre_loader_cpp.exe
) else (
    casual_pre_loader_cpp.exe --tf2-path "%TF2_PATH%"
)

popd

endlocal
