# shoran_cpp
## gtest
### Linux
```
sudo apt-get install libgtest-dev  
/usr/include/gtest/gtest.h  
静态库：/lib/x86_64-linux-gnu/libgtest.a 和 /lib/x86-64-linux-gnu/libgtest_main.a
```
### Windows
#### Prepare
1. 下载googletest并编译
可以直接使用clion来编译googletest
github for https://github.com/google/googletest
```
git clone git@github.com:google/googletest.git
mkdir build
cd build
```
2. 增加系统路径与环境变量
* CPP_INCLUDE: 头文件的路径
* CPP_LIB: 静态库的路径

3. 修改CMakeLists.txt增加引用新路径与环境变量
```
include_directories($ENV{CPP_INCLUDE})
link_directories($ENV{CPP_LIB})
```

## CMake
```
wget https://cmake.org/files/v3.23/cmake-3.23.0.tar.gz  
tar -zxvf cmake-3.23.0.tar.gz  
./configure
make -j32
sudo make install  
sudo update-alternatives --install /usr/bin/cmake  cmake /usr/local/bin/cmake  1 –force  
```

## TODO
