cmake_minimum_required(VERSION 3.24)
project(ClayBasic VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all source files in the src/ directory
file(GLOB_RECURSE EXAMPLE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Define the example executable
add_executable(ClayBasic ${EXAMPLE_SOURCES})

add_subdirectory(../../clay-cpp ../../clay-cpp/build)

target_link_libraries(ClayBasic Clay)