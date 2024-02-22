cmake_minimum_required(VERSION 3.10)
project(tesserRISC)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Gather all source files from the 'src' directory
file(GLOB SOURCES "src/*.cpp")

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Add compiler flags for debug mode
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")