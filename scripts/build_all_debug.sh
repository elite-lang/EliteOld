#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:23:31
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-10 12:09:58

# 整体构建脚本


cd ./scripts
./makeln.sh
cd ../

cd ./Lex/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make lex
cd ../../

cd ./LR_Scanner/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make scanner
cd ../../

cd ./RedApple/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make red
cd ../../

cd ./MetaScriptRunner/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make meta
cd ../../

cd ./Builder/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make builder
cd ../../


mkdir ./build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
cd ..
