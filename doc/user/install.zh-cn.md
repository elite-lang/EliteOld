安装教程  	{#md-install}
==========

[TOC]


@section ins-precompiled 使用预编译版

如果您仅仅是想使用Elite去开发应用程序，那么推荐您下载我们预编译好的版本

下载页：

仅仅需要您配置好环境变量即可，Mac & Linux：

	// for elite
	export ELITE_HOME=【您的Elitei安装目录】
	export PATH=$ELITE_HOME/bin:$PATH


Windows用户：





@section ins-compile 从源码编译安装

首先，从源码编译安装能够提供给您更丰富的自定义功能，您可以通过修改配置，使用不同的版本。而且自行编译安装，您可以任意修改任何默认配置代码和添加删除功能，这对于开发人员和需要定制化软件的人员更为方便。

首先预先您使用git clone完整的项目仓库，请注意使用`--recursive`参数来下载全部子项目：

	git clone --depth=1 --recursive git@github.com:elite-lang/Elite.git


@subsection ins-linux Linux环境下的编译

#### 开发环境和依赖项

本项目是在Ubuntu14.04 64位系统下开发的，依赖以下开发库：

- cmake-2.8
- LLVM-3.6
- flex-2.5
- bison-3.0
- lua-5.2
- oolua-2.0
- dyncall-0.8

Ubuntu14.04 用户可以直接使用如下命令从源中安装以上软件包：

	sudo apt-get install cmake llvm-3.6-dev libglibmm-2.4-dev flex bison libedit-dev

ubuntu源中LLVM-3.6的CMake脚本存在bug，如果您安装了llvm-3.6-dev后cmake项目时仍找不到LLVM，那么请执行下面的脚本修复:

	sudo sh ./scripts/fix_ubuntu_llvm.sh


#### 编译选项

默认Release编译时，只需要您在项目根目录下执行：

	make release


或者您可以手动自行配置编译参数：

	mkdir build && cd build
	cmake ..   		//cmake配置
	make deps  		//下载并构建依赖项目
	make elite      //构建项目


可选的编译参数有：

| 参数             | 描述         | 默认参数  |
| ---              | ---         | ---   |
| CMAKE_BUILD_TYPE | 构建类型     | Debug |
| BUILD_TEST       | 是否构建测试 | OFF   |
| COVERAGE_FLAG    | 覆盖率测试   | OFF   |


使用时可以如下添加到CMake指令后

	cmake -DCMAKE_BUILD_TYPE=Release



@subsection ins-mac MacOSX环境下的编译

Mac下的编译方式同样为CMake，构建方式也完全一致，仅仅是依赖项的安装有所区别。

#### 依赖项和工具







@subsection ins-windows Windows环境下的编译

Windows下支持使用VS2013及以上版本，不建议使用MinGW和Cygwin等兼容平台。
