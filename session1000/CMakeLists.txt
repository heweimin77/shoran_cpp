#aux_source_directory(problem100 problem100_src)
set(problem100_src problem100/p003lengthOfLongestSubstring.cpp)

add_executable(session1000 ${problem100_src})
target_link_libraries(session1000 gtest_main gtest pthread)
