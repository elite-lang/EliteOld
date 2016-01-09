项目测试       {#md-test}
==============

[TOC]

测试是项目可靠和稳定的保障，目前测试用例尚不完善，欢迎帮忙完善测试代码，编写更全的测试用例。

@section unit-test 单元测试


项目使用google test进行测试, 使用前请先安装好google test框架

@subsection test-install-gtest Ubuntu安装google test
在项目目录执行:

	sudo sh ./scripts/install_gtest.sh


@subsection test-open 开启测试

用cmake配置时, 添加参数:

	cd build
	cmake -DBUILD_TEST=ON ..
	make

或者直接:

	make test

即可


@subsection test-dev 编写测试用例

每个子项目下的`test`目录是专门存放测试用例和测试数据的:

~~~cpp
	// EstringTest.cpp
	#include <gtest/gtest.h>
	#include "estring.h"

	#define __ESTRING_TEST__(name) TEST(EstringTest_##name, name)

	__ESTRING_TEST__(Construction)
	{
		estring str("您好");
		string hello("您好");
		estring str2(hello);
	}
~~~


@section full-test 集成测试

@subsection full-test-run 运行集成测试

集成测试需要依赖python2，请提前自行安装好python解释器。

然后在项目文件夹下执行

	./EliteTest/full-test/run_test.py

即可运行集成测试。


@subsection full-test-dev 编写集成测试用例

一个集成测试是由源代码、期待的正确输出结果两部分组成，需要时，还可以增加文件读入。
源码需要统一命名为`test.elite`，正确的输出结果统一命名为test.out

full_test目录下可以放任意名称的文件夹作为该测试用例的名字。
