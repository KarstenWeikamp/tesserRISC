cmake_minimum_required(VERSION 3.10)
project(tesserRISC)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/../include)

# Gather all source files from the 'src' directory
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/../src/*.cpp")

# Add compiler flags for debug mode
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Find Packages
find_package(Catch2 3 REQUIRED)
# Setup Catch2 Testing Environment
file(GLOB CATCH_TESTS "*.cpp")

# Exclude src/main.cpp from ${SOURCES}
list(FILTER SOURCES EXCLUDE REGEX "../src/main.cpp")

add_executable(tests ${CATCH_TESTS} ${SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)