1、做什么

在编译时嵌入代码而不是函数调用

 

define和inline有什么区别？

 

来自 <https://www.nowcoder.com/questionTerminal/2f04608344924b929d6a09dc00166d3b> 

 

2、如何定义

通常定义在头文件中、定义时加上Inline

[Why are C++ inline functions in the header?](https://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header)

 

来自 <https://stackoverflow.com/questions/5057021/why-are-c-inline-functions-in-the-header/5057065#5057065> 

 

3、何时使用inline

**inline** - this function will be defined in multiple translation units, don't worry about it. The linker needs to make sure all translation units use a single instance of the variable/function.

 

来自 <https://stackoverflow.com/questions/1759300/when-should-i-write-the-keyword-inline-for-a-function-method> 

 

4、c++FAQ

https://isocpp.org/wiki/faq/inline-functions#overview-inline-fns

 

5、the use of inline nowadays

https://stackoverflow.com/questions/5971736/c-inline-function