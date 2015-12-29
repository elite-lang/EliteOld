项目测试       {#md-test}
==============

[TOC]

测试是项目可靠和稳定的保障，目前测试用例尚不完善，欢迎帮忙完善测试代码，编写更全的测试用例。

\section unit-test 单元测试


项目使用google test进行测试, 使用前请先安装好google test框架

\subsection test-install-gtest Ubuntu安装google test
在项目目录执行:

	sudo sh ./scripts/install_gtest.sh


\subsection test-open 开启测试

用cmake配置时, 添加参数:

	cd build
	cmake -DBUILD_TEST=ON ..
	make

或者直接:

	make test

即可


\subsection test-dev 编写测试用例

每个子项目下的`test`目录是专门存放测试用例和测试数据的:

~~~~~{cpp}
	// EstringTest.cpp
	#include <gtest/gtest.h>
	#include "estring.h"

	#define __ESTRING_TEST__(name) TEST(EstringTest_##name, name)

	__ESTRING_TEST__(Construction)
	{
		
	}
~~~~~


\section full-test 集成测试



