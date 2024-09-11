aux_source_directory(problem3100 problem3100_src)
aux_source_directory(problem3200 problem3200_src)
aux_source_directory(problem3300 problem3300_src)
aux_source_directory(problem3400 problem3400_src)
aux_source_directory(problem3500 problem3500_src)
aux_source_directory(problem3600 problem3600_src)
aux_source_directory(problem3700 problem3700_src)
aux_source_directory(problem3800 problem3800_src)
aux_source_directory(problem3900 problem3900_src)
aux_source_directory(problem4000 problem4000_src)
add_executable(session4000 ${problem3100_src} ${problem3200_src} ${problem3300_src} ${problem3400_src} ${problem3500_src}
                           ${problem3600_src} ${problem3700_src} ${problem3800_src} ${problem3900_src} ${problem4000_src})

target_link_libraries(session4000 gtest_main gtest pthread util)