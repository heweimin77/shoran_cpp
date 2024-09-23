import os
import sys


def changeTestName():
    global cmd
    tag = "Lcp"
    for x in fname[4:]:
        if '0' <= x <= '9':
            tag += x
        else:
            break
    tag += "Test"
    # sed -i 's/TestSolution/P2401Test/g' p2401.longestNiceSubarray.cpp
    cmd = "sed -i 's/TestSolution/" + tag + "/g' " + folder + fname
    print(cmd)
    os.system(cmd)


if __name__ == '__main__':
    # args = sys.argv
    # if len(args) < 2:
    #     print("usage: rename.py folder")
    #     exit(0)
    #folder = args[1]
    folder = './session1000/problem100/'
    if folder[-1] != '/': folder += '/'
    for root, dirs, files in os.walk(folder):
        for fname in files:
            if fname[4] != '.':
                nname = fname[:4] + '.' + fname[4:]
                cmd = "mv " + folder + fname + " " + folder + nname
                print(cmd)
                os.system(cmd)
            #changeTestName()