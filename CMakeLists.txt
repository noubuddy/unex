cmake_minimum_required(VERSION 3.16)
project(unex C CXX)

option(BUILD_CPP "Build CPP" ON)

file(GLOB_RECURSE PROJECT_HEADERS "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE PROJECT_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c" "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.inl")

add_library(${PROJECT_NAME} STATIC ${PROJECT_HEADERS} ${PROJECT_SOURCES})

add_compile_definitions(UNEX_USE_SHORT_TYPES UNEX_USE_LONG_TYPES UNEX_USE_CPP_TYPES)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(BUILD_CPP)
    target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_CPP)

    set_target_properties(${PROJECT_NAME} PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS OFF
    )
endif()