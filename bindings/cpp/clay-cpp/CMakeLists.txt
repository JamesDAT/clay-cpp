# Using version 3.24 to allow for c++20 modules
cmake_minimum_required(VERSION 3.24)
project(Clay VERSION 1.0 LANGUAGES CXX)

# C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Scan src for source files, and scan include/clay for header files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/clay/*.h
)

add_library(Clay ${SOURCES})

# public headers
target_include_directories(Clay
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# single header file output
set(SINGLE_HEADER_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/single_include)
file(MAKE_DIRECTORY ${SINGLE_HEADER_OUTPUT_DIR})

# Export Clay
install(TARGETS Clay
    EXPORT ClayConfig
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)

# Export configuration for find_package
install(EXPORT ClayConfig DESTINATION cmake)