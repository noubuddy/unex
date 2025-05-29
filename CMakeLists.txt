cmake_minimum_required(VERSION 3.16)
project(unex C CXX)

### Compile definitions
# use short basic type names
add_compile_definitions(UNEX_USE_SHORT_TYPES)
# use long basic types names
add_compile_definitions(UNEX_USE_LONG_TYPES)
# use cpp types
add_compile_definitions(UNEX_USE_CPP_TYPES)
###

### Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
###

### Set CPP standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
###

### Define directories
set(INCLUDES_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_DIRECTORY "${PROJECT_SOURCE_DIR}/src")
###

### Add include directories
include_directories(${INCLUDES_DIRECTORY})
###

### Collect source files
file(GLOB_RECURSE PROJECT_HEADERS
        "${INCLUDES_DIRECTORY}/*.h"
        "${INCLUDES_DIRECTORY}/*.hpp"
)

file(GLOB_RECURSE PROJECT_SOURCES
        "${SOURCE_DIRECTORY}/*.c"
        "${SOURCE_DIRECTORY}/*.cpp"
        "${SOURCE_DIRECTORY}/*.inl"
)
###

### Create static library
add_library(${PROJECT_NAME} STATIC
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCES}
)
###

### Set include directories for the target
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${INCLUDES_DIRECTORY}
)
###