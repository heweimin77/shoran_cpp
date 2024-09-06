aux_source_directory(problem2100 problem2100_src)
aux_source_directory(problem2200 problem2200_src)
aux_source_directory(problem2300 problem2300_src)
aux_source_directory(problem2400 problem2400_src)
aux_source_directory(problem2500 problem2500_src)
aux_source_directory(problem2600 problem2600_src)
aux_source_directory(problem2700 problem2700_src)
aux_source_directory(problem2800 problem2800_src)
aux_source_directory(problem2900 problem2900_src)
aux_source_directory(problem3000 problem3000_src)

add_executable(session3000 ${problem2100_src} ${problem2200_src} ${problem2300_src} ${problem2400_src} ${problem2500_src}
                           ${problem2600_src} ${problem2700_src} ${problem2800_src} ${problem2900_src} ${problem3000_src})
target_link_libraries(session3000 gtest_main gtest pthread util)
