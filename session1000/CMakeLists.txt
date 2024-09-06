aux_source_directory(problem100 problem100_src)
aux_source_directory(problem200 problem200_src)
aux_source_directory(problem300 problem300_src)
aux_source_directory(problem400 problem400_src)
aux_source_directory(problem500 problem500_src)
aux_source_directory(problem600 problem600_src)
aux_source_directory(problem700 problem700_src)
aux_source_directory(problem800 problem800_src)
aux_source_directory(problem900 problem900_src)
aux_source_directory(problem1000 problem1000_src)

add_executable(session1000 ${problem100_src} ${problem200_src} ${problem300_src} ${problem400_src} ${problem500_src}
        ${problem600_src} ${problem700_src} ${problem800_src} ${problem900_src} ${problem1000_src})

target_link_libraries(session1000 gtest_main gtest pthread)
