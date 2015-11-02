#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:23:31
# @Last Modified by:   sxf
# @Last Modified time: 2015-11-02 15:02:24

# 整体构建脚本

cd ./scripts
./makeln.sh
cd ../

cd ./Lex
./build.sh
cd ../

cd ./LR_Scanner
./build.sh
cd ../

cd ./RedApple
./build.sh
cd ../

mkdir ./build
cd ./build
cmake ..
make
cd ../