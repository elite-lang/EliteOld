#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:23:31
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-12 09:41:40

# 整体构建脚本


cd ./scripts
./makeln.sh
cd ../

cd ./Lex/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make lex -j8
cd ../../

cd ./LR_Scanner/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make scanner -j8
cd ../../

cd ./RedApple/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make red -j8
cd ../../

cd ./MetaScriptRunner/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make meta -j8
cd ../../

cd ./Builder/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make builder -j8
cd ../../


mkdir ./build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
cd ..
