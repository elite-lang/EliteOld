#!/bin/sh
# @Author: sxf
# @Date:   2015-11-02 13:21:24
# @Last Modified by:   sxf
# @Last Modified time: 2015-11-02 14:28:39

# 这个sh脚本是用来生成各个项目依赖库的软链接的

cd ..
ln -s ../../Lex/build/liblex.a ./LR_Scanner/lib/liblex.a
ln -s ../Lex/build/liblex.a    ./extlib/liblex.a
ln -s ../../Lex/include        ./LR_Scanner/lib/lex_include
ln -s ../Lex/include           ./extlib/lex
ln -s ../LR_Scanner/build/libscanner.a ./extlib/libscanner.a
ln -s ../LR_Scanner/includes 		   ./extlib/scanner
ln -s ../RedApple/build/libred.a	   ./extlib/libred.a
ln -s ../RedApple/includes			   ./extlib/redapple
