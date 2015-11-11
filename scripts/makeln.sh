#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:21:24
# @Last Modified by:   sxf
# @Last Modified time: 2015-11-11 13:00:28

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


