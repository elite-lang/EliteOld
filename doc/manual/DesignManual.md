Design Manual - RedApple Compiler

RedApple is a fast, usable, C Style Compiler Infrastructure. It can work independently as a little compiler, but also can be an embedding compiler library.

## Core Features

RedApple supports the following features:

1. Global Functions without Prior Declaration
2. Common Type System
3. Simplified Pointer
4. Constant Fields
5. Control Flow Statements
6. Metadata and Reflection
7. User Macros

Maybe a demo source code will show these features intuitively:

```C
int main() {
    // here we used the metadata to call
    // the 'print' function with its name
    FunctionCall("print", 5);
    return 0;
}


// user macro can make your grammar
// here we receved three parameters
defmacro for_n (p, size, code)  {
    for (int p = 1; p <= size; p = p+1)
        code;
}

void print(int k) {
    // call the user macro, i and k are two parameters,
    // the block '{}' is a parameter in its entirety.
    @for_n (i, k) {
        printf("hello-%d\n", i);
    }
}

```



At now, we will discuss the design and how to make it.

## Introduce

![](cp.svg)


## Lexical Analysis and Parsing

To make a simple lexical analyzer, we used Flex, an unix utility which can generate lexical analyzer.
