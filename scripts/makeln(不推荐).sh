#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:21:24
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-10 11:40:36

# 这个sh脚本是用来生成各个项目依赖库的软链接的

cd ..

# for LR_Scanner
ln -s -T ../../Lex/include         ./LR_Scanner/lib/lex_include     
ln -s -t ./LR_Scanner/lib/         ../../Lex/build/liblex.a

# for Builder
ln -s -T ../../Lex/include         ./Builder/lib/lex
ln -s -t ./Builder/lib/            ../../Lex/build/liblex.a
ln -s -T ../../LR_Scanner/includes ./Builder/lib/scanner
ln -s -t ./Builder/lib/            ../../LR_Scanner/build/libscanner.a
ln -s -T ../../MetaScriptRunner/include   ./Builder/lib/meta
ln -s -t ./Builder/lib/   		   ../../MetaScriptRunner/build/libmeta.a
ln -s -T ../../RedApple/includes   ./Builder/lib/redapple
ln -s -t ./Builder/lib/   ../../RedApple/build/libred.a

# for MetaScriptRunner
ln -s -T ../../Lex/include         ./MetaScriptRunner/lib/lex
ln -s -t ./MetaScriptRunner/lib/   ../../Lex/build/liblex.a
ln -s -T ../../LR_Scanner/includes ./MetaScriptRunner/lib/scanner
ln -s -t ./MetaScriptRunner/lib/   ../../LR_Scanner/build/libscanner.a
ln -s -T ../../RedApple/includes   ./MetaScriptRunner/lib/redapple
ln -s -t ./MetaScriptRunner/lib/   ../../RedApple/build/libred.a

# for Main
ln -s -t ./extlib/                 ../Lex/build/liblex.a    
ln -s -T ../Lex/include            ./extlib/lex
ln -s -t ./extlib/                 ../LR_Scanner/build/libscanner.a
ln -s -T ../LR_Scanner/includes    ./extlib/scanner
ln -s -t ./extlib/                 ../RedApple/build/libred.a
ln -s -T ../RedApple/includes      ./extlib/redapple
ln -s -t ./extlib/                 ../Builder/build/libbuilder.a
ln -s -T ../Builder/include        ./extlib/builder
ln -s -t ./extlib/   		       ../MetaScriptRunner/build/libmeta.a
ln -s -T ../MetaScriptRunner/include   ./extlib/meta


mkdir ./build
mkdir ./Lex/build
mkdir ./LR_Scanner/build
mkdir ./MetaScriptRunner/build
mkdir ./Builder/build
mkdir ./RedApple/build
