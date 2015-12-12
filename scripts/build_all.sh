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
make lex -j8
cd ../../

cd ./LR_Scanner/build
cmake ..
make scanner -j8
cd ../../

cd ./RedApple/build
cmake ..
make red -j8
cd ../../

cd ./MetaScriptRunner/build
cmake ..
make meta -j8
cd ../../

cd ./Builder/build
cmake ..
make builder -j8
cd ../../


./scripts/build.sh
