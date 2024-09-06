aux_source_directory(problem1100 problem1100_src)
aux_source_directory(problem1200 problem1200_src)
aux_source_directory(problem1300 problem1300_src)
aux_source_directory(problem1400 problem1400_src)
aux_source_directory(problem1500 problem1500_src)
aux_source_directory(problem1600 problem1600_src)
aux_source_directory(problem1700 problem1700_src)
aux_source_directory(problem1800 problem1800_src)
aux_source_directory(problem1900 problem1900_src)
aux_source_directory(problem2000 problem2000_src)

add_executable(session2000 ${problem1100_src} ${problem1200_src} ${problem1300_src} ${problem1400_src} ${problem1500_src}
                           ${problem1600_src} ${problem1700_src} ${problem1800_src} ${problem1900_src} ${problem2000_src})
target_link_libraries(session2000 gtest_main gtest pthread util)
