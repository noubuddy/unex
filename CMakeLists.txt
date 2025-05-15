cmake_minimum_required(VERSION 3.16)
project(unex C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define directories
set(INCLUDES_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
set(SOURCE_DIRECTORY "${PROJECT_SOURCE_DIR}/src")

# Add include directories
include_directories(${INCLUDES_DIRECTORY})

# Collect source files
file(GLOB_RECURSE PROJECT_HEADERS
        "${INCLUDES_DIRECTORY}/*.h"
        "${INCLUDES_DIRECTORY}/*.hpp"
)

file(GLOB_RECURSE PROJECT_SOURCES
        "${SOURCE_DIRECTORY}/*.c"
        "${SOURCE_DIRECTORY}/*.cpp"
)

# Create static library
add_library(${PROJECT_NAME} STATIC
        ${PROJECT_HEADERS}
        ${PROJECT_SOURCES}
)

# Set include directories for the target
target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${INCLUDES_DIRECTORY}
)
