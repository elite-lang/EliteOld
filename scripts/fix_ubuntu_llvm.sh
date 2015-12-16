#!/bin/sh
# @Author: sxf
# @Date:   2015-12-15 18:41:10
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-16 13:12:22


cp -f ./scripts/fix_ubuntu/LLVMConfig.cmake /usr/share/llvm-3.6/cmake/LLVMConfig.cmake

# 这段脚本的主要目的是修复ubuntu源里面llvm包的一个bug, 会造成llvm的cmake文件找不到
# 如果您也使用ubuntu开发, 您可以在项目目录下执行: ./scripts/fix_ubuntu_llvm.sh 修复问题
