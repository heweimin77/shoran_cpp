# shoran_cpp
## gtest
sudo apt-get install libgtest-dev  
/usr/include/gtest/gtest.h  
静态库：/lib/x86_64-linux-gnu/libgtest.a 和 /lib/x86-64-linux-gnu/libgtest_main.a

## CMake
wget https://cmake.org/files/v3.23/cmake-3.23.0.tar.gz  
tar -zxvf cmake-3.23.0.tar.gz  
./configure
make -j32
sudo make install  
sudo update-alternatives --install /usr/bin/cmake  cmake /usr/local/bin/cmake  1 –force  

## TODO
