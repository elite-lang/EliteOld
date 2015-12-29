默认语法文档     {#md-default-lang-ref}
============

[TOC]


虽然ELite语言是一门语法可变的语言，但为了方便开发者使用，我们还是开发了默认的常用语法和可选的语言扩展包，这些都可以根据您的实际项目进行修改配置，本章将会介绍Elite语言的默认语言和将其作为基本的通用编程语言使用方法。


\section lang-ref-intro 语法简介

这是一款类C语言语法，使用C语言的用户可以很方便的适应这种写法，当然，Elite默认语法也有一些小的不同。
下面是一段Hello World代码示例：

	int main() {
		hello();
		return 0;
	}

	void hello() {
		printf("hello world ～ Elite !");
	}

和C语言一样，基本的函数定义语法，并且printf函数都是原生的C语言函数。

我们注意到一个细节，Elite是一种非前向声明型语言，任何一个函数，只需要您定义过，它就能够在任意位置被找到，原因是我们使用了多遍扫描技术，我们会有单独的趟去处理结构体和函数的声明问题。

不过需要注意的是，函数内部并非是无需前向声明的，函数内部变量的定义和C语言是一致的，并且也拥有作用域的概念。


\section lang-ref-basic 基本语法结构


\subsection lang-ref-basic-control 控制流程

Elite默认语法提供类似C语言的`if-else`，`while`，`for`，`return`等基本控制语句
使用方式和C语言几乎一致：

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

\subsection lang-ref-basic-types 类型系统

#### 基本类型

Elite提供基本的C语言类型，默认内置的类型有以下：
| 类型名    | 描述          |
| -----  | ----        |
| void   | 空类型         |
| int    | 64位整形       |
| float  | 单精度浮点型      |
| double | 双精度浮点型      |
| byte   | 8位字节        |
| char   | 8位C语言字符类型   |
| wchar  | 32位多国语言宽字符型 |

还提供标准int类型集：
| 类型名    | 描述       |
| -----  | ----     |
| int8   | 8位有符号整形  |
| int16  | 16位有符号整形 |
| int32  | 32位有符号整形 |
| int64  | 64位有符号整形 |
| uint8  | 8位无符号整形  |
| uint16 | 16位无符号整形 |
| uint32 | 32位无符号整形 |
| uint64 | 64位无符号整形 |


#### 复合类型

使用struct结构体，可以像C语言一样，轻松定义复合类型

	struct pair {
		int x;
		int y;
	}

然而复合类型在使用时，是以C语言指针的形式使用的，一般我们不推荐直接在一个复合类型中嵌入复合类型对象，而是直接嵌入引用：

	struct Node {
		int data;
		Node next;
	}

这里的Node，是指向结构体的指针，而非直接嵌入该结构体成员，所以上面的代码是能够正确使用的。
如果您希望嵌入结构体成员时，请在类型名使用`*`符号，这个特性适合C语言风格的结构体继承。（目前不安全的特性）

	struct Node {
		*DataSet dataset;
		Node next;
	}

	struct DataSet {
		int count;
		char[] data;
	}

复合类型的使用，和C语言类似，是使用`.`运算符进行的：

	int dot(pair a, pair b) {
		int k = a.x + b.y;
		printf("k = %d\n", k);
		return k;
	}


#### 数组类型

和C语言不同，Elite默认语言里原生支持变长数组类型，数组类型均为堆分配的数组指针。

	int[] g = new int[10];
	g[0] = 1;

该数组可以在调用C函数时，直接作为C数组传入

同时，支持二维数组及高维数组：

	int[][] g = new int[10][5];

Elite和C数组最大的不同，在于Elite数组中记录有每一维的长度信息，这个长度信息是存放在数组地址前面的字节中，内存布局如下：

![Elite数组内存布局]()



\subsection lang-ref-basic-memory 内存管理

Elite的内存管理是可配置的，首先Elite语言本身支持C语言的内存管理，使用malloc和free封装后的接口，new和delete，使用方式和C++几乎一致。

可以new单独的对象

	struct Person {
		char[] name;
		int age;
	}

	int main() {
		Person person = new Persion;
		return 0;
	}

也可以构建数组或对象数组

	int main() {
		Person[] persons = new Persion[20];
		return 0;
	}


使用后的内存，需要使用delete语句手动释放。

	delete person;		// 释放单个指针
	delete[] persons;   // 释放数组指针

\section lang-ref-macro 强大的宏机制

Elite语言内置了类似lisp风格的宏，拥有强大的表达能力，很多情况下，无需改变语法结构，已经能够让您自定义许多常见语法。

宏的使用示例如下：


	void print(int k) {
		@for_n (i, k) {
			printf("hello-%d\n", i);
		}
	}

	defmacro for_n (p, size, code)  {
		for (int p = 1; p <= size; p = p+1)
			code;
	}

	int main() {
		print(5);
		return 0;
	}


和函数不同的是，宏使用`defmacro`关键字定义，是一个编译时函数，运行时不会再存在宏，通过宏，我们能够实现许多自定义的语法。
例如上面例子中的`for_n`宏，我们只需简要的包装一下，接口正确的翻译。

宏的调用要显式的使用`@`符。

宏调用的基本格式为：

	@ <宏符号名> <参数列表>

宏的语法十分独特，由于宏调用的宽泛性，我们支持在宏运算符后加如下几种结构，作为参数列表中的参数：

- 括号表示式 形如：`( 元素, 元素 )` ， 每一个元素都会作为一个参数
- id标识符 	任意一个字符串， 会单独作为一个参数
- 大括号表达式 形如：`{ ... code ... }`，往往是一个代码段，整体作为一个参数

