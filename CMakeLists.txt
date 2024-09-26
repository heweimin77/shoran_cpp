cmake_minimum_required(VERSION 3.20)
project(shoran_cpp VERSION 1.0.1 DESCRIPTION "shoran leetcode")

# /usr/include/gtest/gtest.h
#include_directories("/usr/include/gtest")
# /usr/lib/x86_64-linux-gnu/libgtest.a
# /usr/lib/x86_64-linux-gnu/libgtest_main.a
#link_directories("/usr/src/googletest/googletest/")
include_directories($ENV{CPP_INCLUDE})
link_directories($ENV{CPP_LIB})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -g0")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -g0")

aux_source_directory(util util_src)
add_library(util STATIC ${util_src}
        util/ListNode.cpp
        util/ListNode.h
        util/DictTree.cpp
        util/DictTree.h
        util/StringHash.cpp
        util/StringHash.h)
include_directories(${PROJECT_SOURCE_DIR}/util)

aux_source_directory(interview interview_src)
add_executable(interview ${interview_src})
target_link_libraries(interview gtest_main gtest pthread util)

aux_source_directory(lcp lcp_src)
add_executable(lcp ${lcp_src})
target_link_libraries(lcp gtest_main gtest pthread util)

aux_source_directory(todo todo_src)
add_executable(todo ${todo_src})
target_link_libraries(todo gtest_main gtest pthread util)

add_subdirectory(session1000)
add_subdirectory(session2000)
add_subdirectory(session3000)
add_subdirectory(session4000)


