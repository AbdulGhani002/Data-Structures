cmake_minimum_required(VERSION 3.10)

# Project name
project(StackTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the directories
include_directories(include)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(runTests test/test_stack.cpp)

# Link the Google Test libraries and pthread (required by GTest)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

