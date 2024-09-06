cmake_minimum_required(VERSION 3.16)
project(shoran_cpp VERSION 1.0.1 DESCRIPTION "shoran leetcode")

# /usr/include/gtest/gtest.h
#include_directories("/usr/include/gtest")
# /usr/lib/x86_64-linux-gnu/libgtest.a
# /usr/lib/x86_64-linux-gnu/libgtest_main.a
#link_directories("/usr/src/googletest/googletest/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -g0")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -g0")

add_subdirectory(session1000)

