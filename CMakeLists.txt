cmake_minimum_required(VERSION 3.16)

project(FileSystemSim)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically gather all .cpp files in the directory
file(GLOB SOURCES
    "*.cpp"
)

# Create the executable
add_executable(FileSystemSim ${SOURCES})