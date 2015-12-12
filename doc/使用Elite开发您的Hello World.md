使用Elite开发您的Hello World
===========================

一个hello world是多么的鼓舞人心！

首先，您需要安装Elite编译器，在bin目录下生成有elite程序，如果您想从源码编译安装，那么您需要参考文档中的：项目构建

在首次安装好后，您需要配置环境变量：

```
# for elite 
export ELITE_HOME=【您的Elite仓库地址】
export PATH=$ELITE_HOME/bin:$ELITE_HOME/tools:$PATH
```

## 编写hello.elite

```
void hello() {
	printf("hello world");
}

void main() {
	hello();
}
```

## 执行编译命令

```
	elite -i hello.elite
```

`-i`参数是目前唯一能用的编译参数，指定编译某一个文件，日后我们会开发一次编译整个目录

于是我们会看到生成的`hello.bc`和元数据`meta.bc`

如果您不需要使用反射的话，可用直接使用`llc`工具，将其编译成`.o`文件：
```
	llc hello.bc -filetype=obj
```

最后一步链接，可用使用gcc或ld进行链接：
```
	gcc hello.o -o hello
```

即可生成最后的目标程序，执行一下看看效果吧：

```
	./hello
```