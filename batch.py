import os
import sys

def execute(cmd):
    print(cmd)
    os.system(cmd)
def create_session(x):
    cmd = 'mkdir session' + str(x);
    execute(cmd)

    for i in range(x - 900, x + 100, 100):
        execute(cmd + '/problem' + str(i))

def create_cmake(x):
    for i in range(x - 900, x + 100, 100):
        print('aux_source_directory(problem{} problem{}_src)'.format(i, i))

    print('add_executable(session{}'.format(x), end='')
    for i in range(x - 900, x + 100, 100):
        print(' ${{problem{}_src}}'.format(i), end='')
    print(')')
    print()
    print('target_link_libraries(session{} gtest_main gtest pthread util)'.format(x))

if __name__ == '__main__':
    #create_session(4000)
    create_cmake(4000)