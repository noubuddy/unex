cmake_minimum_required(VERSION 3.16)
project(unex_example C CXX)

# Set C++ standard to match the library
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the path to the unex library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/.. ${CMAKE_CURRENT_BINARY_DIR}/unex)

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Add include directory
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Link against unex library
target_link_libraries(${PROJECT_NAME} PRIVATE unex)

# Add compile definitions to match the library settings
target_compile_definitions(${PROJECT_NAME} PRIVATE
        UNEX_USE_SHORT_TYPES
        UNEX_USE_LONG_TYPES
        UNEX_USE_CPP_TYPES
)
