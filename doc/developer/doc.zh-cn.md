文档构建       {#md-doc}
=========

[TOC]


本项目文档是使用 [doxygen] 工具构建的，全部文档内容使用Markdown和代码内注释进行编写。本章将介绍如何维护本系列文档，以及本机构建文档的方法。

@section doc-install 安装doxygen工具

对于ubuntu和darwin的用户，非常方便，使用控制台即可轻松安装。windows用户和其他版本linux系统请从官网下载安装包。

ubuntu：

    sudo apt-get install doxygen

darwin：

1. Press Command+Space and type Terminal and press enter/return key.
2. Run in Terminal app:

        ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null

    and press enter/return key. Wait for the command to finish.

3. Run: `brew install doxygen`

其他系统：

[前往官网下载](https://www.stack.nl/~dimitri/doxygen/download.html)

@section doc-build 构建项目文档

项目文档的构建非常简单，首先在安装好 [doxygen]，并确认其指令能够在命令行下使用后，在构建项目时的build文件夹内，执行：

    make doc

我们会在`build/doc`路径下构建，并将生成后的html文件放置到build目录外层的`build-doc/html`目录下，由于该文件夹下文件数目过多，建议直接用浏览器输入绝对路径访问：

    file:///%绝对路径%/Elite/build-doc/html/zh-cn/index.html

即可查看刚刚生成的中文版文档。英文版文档则去掉路径中的`zh-cn`即可查看

    file:///%绝对路径%/Elite/build-doc/html/index.html

@section learn-how-to-use 学习如何使用doxygen

可以查看doxygen的手册来了解: [doxygen文档]



@section proj-doxygen 本项目的文档编写规范

本系列文档是中英双语版，`*.zh-cn.md`为中文版，`*.en.md`为英文版。

目前英文版文档还没有开始构建，欢迎英语好的朋友帮忙进行翻译。


注释风格：

~~~cpp
    /**
     * @brief 设置解释器生成中间变量的目录，设置后自动打印中间过程
     *
     * @param path 设置路径，设置为NULL或不设置则不打印过程
     */
    static void setDebugFilePath(const char* path);
~~~

注释统一编写到头文件中，尽量不要在cpp文件中编写重要的注释。

cpp中常用的注释往往是遇到了可能的漏洞，或TODO标记，使用示例：

~~~cpp
    /// FIXME: 这个位置可能产生XXX漏洞
    /// TODO: 日后可以添加相关的XXX信息
~~~




[doxygen]: http://www.doxygen.org/
[doxygen文档]: https://www.stack.nl/~dimitri/doxygen/manual/index.html
