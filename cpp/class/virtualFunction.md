## 虚函数

1. 做什么

```cpp
base: virtual fun();
derive: fun();
```

`basePointer->fun`根据指针所指、执行不同的函数。只能在运行时决定

2. 虚函数表

每个*class*有一个虚函数表，表中放着一堆指向虚函数的指针。每个*class object*有一个`vptr`指针，指向虚函数表，一般是4字节。

指针在实质上是一个内存地址，内存地址的长度跟`cpu`的寻址有关

3. 构造函数不能有纯虚函数，父类先构造，此时纯虚函数还没有实现
4. Effective C++ 37：不要重写父类函数的默认参数

来自 <https://harttle.land/2015/09/04/effective-cpp-37.html> 

[C++ inherit a function with different default argument values](https://stackoverflow.com/questions/27903218/c-inherit-a-function-with-different-default-argument-values)

## 纯虚、虚基类

1、构造函数调用虚函数或纯虚函数

因构造函数调用虚函数是静态联编，即调用的是它自己类的虚函数。在此调用的是纯虚函数，它只被说明，而未定义

 

2、抽象类不能定义对象

抽象类相当于是对类的引用性声明，所以它只能定义该类的指针和引用，而不能定义它的对

 

3、纯虚函数可以有函数体

When a function is declared pure virtual, it simply means that this function cannot get called *dynamically*, through a virtual dispatch mechanism.

 

来自 <https://stackoverflow.com/questions/5481941/c-pure-virtual-function-have-body> 

 

4、虚基类

Class B : virtual public A

菱形继承时、只有一个



6、静态成员函数不能是virtual的

Many say it is not possible, I would go one step further and say it is not meaningfull.

A static member is something that does not relate to any instance, only to the class.

A virtual member is something that does not relate directly to any class, only to an instance.

So a static virtual member would be something that does not relate to any instance or any class.

 

来自 <https://stackoverflow.com/questions/1820477/c-static-virtual-members> 

1. 单选题 以下关于抽象类的描述正确的是 (   )

D （A原因不明，B是不可以，D对所以C错）抽象类如果把纯虚函数都实现了的话，那它就不是抽象类了。抽象基类的纯虚函数必须由派生类实现。所以C是错误的。

A. 不能实例化指向抽象类对象的指针或引用

B. 可以实例化抽象类对象

C. 抽象类的纯虚函数的实现可以由自身给出，也可以由派生类给出

D. 抽象类的纯虚函数的实现由派生类给出

 

7、指向抽象类的指针和引用

A reference to an abstract class is just like a pointer to an abstract class: it needs to reference an object of some non-abstract subclass of the abstract class.

 

来自 <https://stackoverflow.com/questions/5019046/reference-to-abstract-class> 

## 函数未定义

基类的虚析构函数也需要实现、只有纯虚函数才不需要实现

 

[“undefined reference” to Virtual Base class destructor [duplicate\]](https://stackoverflow.com/questions/13444800/undefined-reference-to-virtual-base-class-destructor)





