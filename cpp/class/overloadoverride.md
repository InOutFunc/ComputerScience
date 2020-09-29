## 重载

1. const

virtual void display() const、是重载而不是重写、

2. pointer

将根据指针的类型来决定调用函数、而不是指向对象的类型。



1、类型匹配

精确匹配、像精度高的匹配

 

**7.6** **—** **Function overloading**

 

来自 <https://www.learncpp.com/cpp-tutorial/76-function-overloading/comment-page-1/#comments> 

 

**How function calls are matched with overloaded functions**

 

1) A match is found. The call is resolved to a particular overloaded function.（精准匹配、提升、转换、自定义）

2) No match is found. The arguments can not be matched to any overloaded function.（都不能匹配上）

3) An ambiguous match is found. The arguments matched more than one overloaded function.（2个转换匹配、或者2个自定义匹配上）

 

1 exact match

2 promotion

3 standard conversion

4 user-defined conversion

 

**Ambiguous matches: matches multiple candidates via standard conversion or user-defined conversion**

1 all standard conversions are considered equal

2 all user-defined conversions are considered equal

 

 

2、name hiding

In C++, there is a concept called [*name hiding*](http://publib.boulder.ibm.com/infocenter/comphelp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8a.doc%2Flanguage%2Fref%2Fname_hiding.htm). Basically, a function or class name is "hidden" if there is a function/class of the same name in a nested scope. This prevents the compiler from "seeing" the hidden name.

 

来自 <https://stackoverflow.com/questions/4438281/calling-a-function-overloaded-in-several-namespaces-from-inside-one-namespace> 

 

[Hide, overload or overwrite in C++](https://stackoverflow.com/questions/25517709/hide-overload-or-overwrite-in-c)

 

来自 <https://stackoverflow.com/questions/25517709/hide-overload-or-overwrite-in-c> 

 

1.当函数 foo 在同一个作用域中存在两个或者多个版本（具有不同签名）时，就称 foo 函数被“重载”了；

2.当基类中的一个 virtual 函数在派生类中也存在，并且它们具有相同的签名和返回类型时，就称派生类中的版本“重写”（或“覆盖”）了基类中的版本；

3.派生类中的成员函数，会隐藏基类中与之同名的全部函数。如果出现这种情况，则：

- a. 只有派生类的函数可以被直接调用
- b.     必须要使用类作用域解析运算符“::”显示地调用基类函数。

 

作者：赵者也

链接：https://www.jianshu.com/p/b01094fb2c72

来源：简书

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

 

namespace中的隐藏也和class一致：

1、当内层中没有外层函数的同名（同名就行）函数时、外层函数的作用域可以到达内层、也就是没有被隐藏。

2、有同名函数时、作用域在外层、被隐藏了