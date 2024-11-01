cmake_minimum_required(VERSION 3.10)
project(FastArrayStack)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(FastArrayStack FastArrayStack.cpp)

add_executable(FastArrayStackTest tests/FastArrayStackTest.cpp)
target_link_libraries(FastArrayStackTest gtest_main FastArrayStack)

include(GoogleTest)
gtest_discover_tests(FastArrayStackTest)