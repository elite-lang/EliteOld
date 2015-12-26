[![Travis](https://travis-ci.org/elite-lang/Elite.svg?branch=master)](https://travis-ci.org/elite-lang/Elite)
[![Build status](https://ci.appveyor.com/api/projects/status/vrg2p8onq4xrdep6?svg=true)](https://ci.appveyor.com/project/sunxfancy/elite)
[![codecov.io](https://codecov.io/github/elite-lang/Elite/coverage.svg?branch=master)](https://codecov.io/github/elite-lang/Elite?branch=master)

# Elite - 精锐编译器

[![Join the chat at https://gitter.im/elite-lang/Elite](https://badges.gitter.im/elite-lang/Elite.svg)](https://gitter.im/elite-lang/Elite?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Elite是一款脚本化驱动的编译器，一般的编程语言，语法是固定的，只能使用有限的表达方式，而Elite的语法并非固定，而是由脚本配置而成的，如果需要，随时都可以自由更改。

这个特点，使得Elite非常容易自由开发，成为一款领域专业语言（DSL），在自由配置后，方便地表达专业的相关内容。


## 编译安装

clone全部仓库，注意添加`--recursive`参数来下载全部子项目
```
git clone --depth=1 --recursive git@github.com:elite-lang/Elite.git 
```

本项目是在Ubuntu14.04 64位系统下开发的，依赖cmake-2.8, LLVM-3.6和glibmm-2.4、giomm-2.4, flex-2.5 bison-3.0
lua  oolua  dyncall

```
sudo apt-get install cmake llvm-3.6-dev libglibmm-2.4-dev flex bison libedit-dev 
```

修复ubuntu源中LLVM-3.6的bug:
```
	sudo sh ./scripts/fix_ubuntu_llvm.sh
```

然后在项目根目录下执行：
```
make release
```
即可编译整个项目

或者手动进行如下步骤：
```
mkdir build && cd build
cmake ..   //cmake配置
make deps  //下载并构建依赖项目 
make       //构建项目
```



## 配置环境变量

项目不会向系统添加任何文件，希望使用环境变量配置，将编译器添加到PATH目录中，并且ELITE_HOME也确保编译器能够找到默认的词法、语法配置文件
```
# for elite 
export ELITE_HOME=【您的Elite仓库地址】
export PATH=$ELITE_HOME/bin:$ELITE_HOME/tools:$PATH
```


## 入门教程

elite的语法非常简洁，是类似C语言的强类型语言，并且函数和类型都不需要前向声明，拥有基于结构体的类型系统，由于是使用RedApple作为后端，所以两者的语法几乎完全一致

目前支持的语法特性有：

* 全局函数，无需声明
* 简单的类型系统，支持int、float、double和结构体struct
* 简化的指针，所有结构体变量声明的都是指针
* 支持常量字符串
* for while if 等逻辑控制语句
* import 其他文件
* meta元数据和反射调用
* 用户自定义宏

示例代码：
```
void hello(int k, int g) {
	int y = k + g;
	printf("%d\n", y);
	if (k + g < 5) printf("right\n");
}	


void go(int k) {
	int a = 0;
	while (a < k) {
		printf("go-%d\n", a);
		a = a + 1;
	}
}

void print(int k) {
	for (int i = 0; i < 10; i = i+1) {
		printf("hello-%d\n",i);
	} 
}


void main() {
	printf("hello world\n");
	hello(1,2);
	print(9);
}
```


反射调用：
```
void print(int k) {
	printf("hello-%d\n",k);
}

void main() {
	FunctionCall("print", 5);
}

```

自定义宏的使用：
```
void print(int k) {
	@for_n (i, k) {
		printf("hello-%d\n", i);
	}
}

defmacro for_n (p, size, code)  {
	for (int p = 1; p <= size; p = p+1)
		code;
}


void main() {
	FunctionCall("print", 5);
}
```

## Elite项目结构

Elite分为如下几个模块：

- Lex 自动机模式的词法分析器，支持Unicode
- LR_Scanner 语法分析器，易于配置使用并自带缓存功能的分析器，使用LALR(1)算法，表达能力强
- RedApple 多遍宏处理功能的后端代码生成器，使用LLVM作为机器码生成平台，并且能够生成元数据
- RedApple/Runtime 代码运行时库，支持反射调用
- Elite/Builder Elite的项目构建工具
- Elite/MetaScriptRunner Elite的元脚本处理工具，使用Lua作为脚本引擎
- EliteShow Elite语言的中间过程展示工具，使用Electron作为GUI框架，方便查看编译过程


![](doc/编译系统工作流程.png)
