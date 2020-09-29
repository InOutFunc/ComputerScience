## const变量

Note1: 一般的变量的定义不要放到头文件中、如果该头文件被多个编译单元包含、则会有重复定义错误

 

Q: 在两个头文件中定义了名字相同的const变量、没有报错

Ans: const变量在不同的编译单元会有不同的命令空间

Ref: 

[Define constant variables in C++ header](https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header)

来自 <https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header> 

 

a.h:

Const int a = 1;

b.h:

Const int a = 2;

在a.h和b.h中定义两个const a是ok的。

 

a.cpp:

\#include "a.h"

b.cpp:

\#include "a.h"

两个不同的cpp同时包含也是ok的。

## const参数、函数接口

在函数接口中char*和const char *需要保持一致

char *和uint8_t *有区别、但此处的错误是const

## char * const mutable

Char *a = b mutable pointer to a mutable string

 

Const char *a = b mutable pointer to a immutable string

 

Char *const a = b immutalbe pointer to an mutable string

 

Const char * const a =b immutable pointer to an immutable string

 

区别在于：a能否指向其它内存、以及a指向的内存能否修改

 

Ref:

[Difference between char* and const char*?](https://stackoverflow.com/questions/9834067/difference-between-char-and-const-char)

 

来自 <https://stackoverflow.com/questions/9834067/difference-between-char-and-const-char> 

 

 

[C++ Const Usage Explanation](https://stackoverflow.com/questions/5598703/c-const-usage-explanation)

https://isocpp.org/wiki/faq/const-correctness

## for range based loop

在基于range的for loop中、

for (const auto &item : container)

为什么使用const auto、和const int一样

## const 对象

设计的意图：

const对象指不被修改的对象、只能调用const成员函数、这样达成一致、是合理的。

难点：

分辨出一个对象是否const对象

set container的元素就是const的、The value of the elements in a set cannot be modified once in the container (the elements are always const), but they can be inserted or removed from the container.

 

Ref:

[error: passing xxx as 'this' argument of xxx discards qualifiers](https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers)

 

来自 <https://stackoverflow.com/questions/5973427/error-passing-xxx-as-this-argument-of-xxx-discards-qualifiers> 

## const修饰变量

函数参数中不改变的变量使用const修饰

 

For range based loop使用const修饰

 

可读性、引用传参时防止变量被修改

## const成员函数

const成员函数不能改变成员变量的值、在调用时成员变量作为参数传值可以

[What is meant with “const” at end of function declaration? [duplicate\]](https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration)