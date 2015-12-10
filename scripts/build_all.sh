#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:23:31
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-10 12:09:56

# 整体构建脚本


cd ./scripts
./makeln.sh
cd ../

cd ./Lex/build
cmake ..
make lex
cd ../../

cd ./LR_Scanner/build
cmake ..
make scanner
cd ../../

cd ./RedApple/build
cmake ..
make red
cd ../../

cd ./MetaScriptRunner/build
cmake ..
make meta
cd ../../

cd ./Builder/build
cmake ..
make builder
cd ../../


./build.sh