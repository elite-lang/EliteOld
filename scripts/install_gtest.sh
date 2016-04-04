#!/bin/sh
# @Author: sxf
# @Date:   2015-12-16 18:31:22
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-16 18:32:56

cd /usr/src/
git clone --depth=1 https://github.com/google/googletest.git
cd googletest
cmake -E make_directory build
cmake -E chdir build cmake ..
cmake --build build
cp build/googlemock/gtest/libgtest* /usr/local/lib/
rm -rf build
