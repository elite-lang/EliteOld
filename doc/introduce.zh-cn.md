Elite项目简介
===============

Elite是一款编译器，同时也具有编译器生成器的功能，提供类似 [yacc] 和 [lex]的功能，能够解析用户自定义语法，并生成使用LALR分析法的编译器，做到了灵活多遍的语法形式。后端则依托 [LLVM] 项目，实现了编译到llvm字节码的功能，并通过调用llvm工具链，最终生成机器码或通过jit解释执行。

## Elite语言特性

1. 为用户保留了语法配置脚本、词法配置脚本接口，用来让用户自定义语言。
2. 使用lua作为元脚本，这是运行在编译器上的脚本，可以控制编译动作和编译器的工作方式。
3. 使用 [LLVM] 作为后端代码生成器和跨平台的中间语言。生成的LLVM的bc文件( [LLVM-IR] )，可以被打包成Elite的程序库。
4. Elite是一门带有元数据的语言，拥有运行时环境，可以支持反射调用等功能。
5. Elite拥有原生调用C函数的功能，可以和C库无缝链接到一起，生成最终的可执行程序。
6. Elite拥有强大的宏支持，可以像lisp一样对代码在编译时进行处理
7. Elite是编译型语言，生成的可执行程序是原生的，不依赖虚拟机。
8. ELite也可以实现脚本化和Jit，但该部分还在开发中
9. ELite是多遍翻译的语言，无需前向声明

## Elite项目的结构

Elite项目为了实现可自定义语法这一特性，自行开发了词法分析器、语言分析器、后端代码生成器等组件，通过宏翻译机制，控制代码的生成。

宏翻译是Elite项目中关键的概念，词法分析器和语法分析器，有点像lex和bison，但它们是脚本化的，更加灵活，语法翻译的配置脚本类似下面的：

	<while_state> = "while" "(" <expr:exp> ")" <statement:s> 
	                {{ return makeList(newIDNode("while"), exp, s); }}
	              ;


这是一条while语句，语言动作要去控制生成一棵语法树，而这个语法树是类似lisp风格的，由宏组织而成的结构：

	(while (exp-state...) (statement...))


这样的结构，能够被后端代码生成器识别，然后正确的翻译成一条语句


## 跨平台支持

我们的项目从一开始就考虑了跨平台的问题，Windows、Macos、Linux下都可以开发，支持VS2013版以后，gcc4.8以后，clang3.0以后，都可以开发我们的项目。

## 开发工具和语言

主要使用的语言是C++11，还附带嵌入式lua，部分GUI项目是用js开发的。
项目最初是在Ubuntu14.04的环境下开发的，目前Linux下的开发较多，其他系统的环境的工具链需要使用时手动配置一下。
主要的开发工具是clang套件和llvm套件。大部分依赖项我们都已经设置好git仓库地址，编译时会自动下载并编译。

[yacc]: http://dinosaur.compilertools.net/yacc/ "yacc"
[lex]: http://dinosaur.compilertools.net/lex/ "lex" 
[LLVM]: http://llvm.org/ "LLVM"
[LLVM-IR]: http://llvm.org/docs/LangRef.html "LLVM-IR"