@echo off
echo Building project for Windows (MSVC)...

:: Create the build directory for Windows
if not exist build\windows (
    mkdir build\windows
)

:: Navigate to the build directory
cd build\windows

:: Run CMake and build the project
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_CXX_COMPILER=cl ..\..
if %errorlevel% neq 0 (
    echo CMake configuration failed!
    exit /b %errorlevel%
)

cmake --build . --config Release
if %errorlevel% neq 0 (
    echo Build failed!
    exit /b %errorlevel%
)

echo Build completed successfully!
pause