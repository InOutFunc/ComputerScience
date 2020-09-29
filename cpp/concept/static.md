## static variable and header file

1、static变量定义在头文件中

每份编译单元都有一个单独的变量、因此不会冲突、单每个编译单元不会共享该变量了。通过extern可以共享该变量、但一个更好的方法是通过函数来获取定义在cpp中的数组。

 

Ref:

[Static variables in C++](https://stackoverflow.com/questions/3698043/static-variables-in-c)

## static variable and function

C语言有两种static变量

一种是函数局部作用域的，生命周期长，作用域局限于函数作用域内部，不晚于函数第一次调用的时候初始化。通常用于统计函数调用次数等。

另一种是文件局部作用域的，是file local的，可以实现文件级别的数据封装，功能等同于C++里的匿名命名空间。

C++里类有static成员变量，代表这个变量是类所有而非某个对象所有。

Ref: https://www.zhihu.com/question/22705286

 

 

定义静态函数的好处：

<1> 其他文件中可以定义相同名字的函数，不会发生冲突

https://www.jianshu.com/p/f413ba3b2728

 

 

A static variable inside a function keeps its value between invocations.

A static global variable or a function is "seen" only in the file it's declared in

[What does “static” mean in C?](https://stackoverflow.com/questions/572547/what-does-static-mean-in-c)

 

 

If it's in a namespace scope (i.e. outside of functions and classes), then it can't be accessed from any other translation unit.

If it's a variable *in a function*, it can't be accessed from outside of the function, just like any other local variable. (this is the local they mentioned)

class members have no restricted scope due to static, but can be addressed from the class as well as an instance (like std::string::npos).

 

A static member function differs from a regular member function in that it can be called without an instance of a class, 

[The static keyword and its various uses in C++](https://stackoverflow.com/questions/15235526/the-static-keyword-and-its-various-uses-in-c)

## the location of static variable in memory

Where your statics go depends on whether they are *zero-initialized*. *zero-initialized* static data goes in [.BSS (Block Started by Symbol)](http://en.wikipedia.org/wiki/.bss), *non-zero-initialized* data goes in [.DATA](http://en.wikipedia.org/wiki/Data_segment)

[share](https://stackoverflow.com/a/93411/7036316)[edit](https://stackoverflow.com/posts/93411/edit)follow[flag](https://stackoverflow.com/questions/93039/where-are-static-variables-stored-in-c-and-c#)

 

[Where are static variables stored in C and C++?](https://stackoverflow.com/questions/93039/where-are-static-variables-stored-in-c-and-c)

## template static member

https://www.geeksforgeeks.org/templates-and-static-variables-in-c/