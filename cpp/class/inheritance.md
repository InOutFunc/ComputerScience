1、

Multiple Inheritance in C++

 

来自 <https://www.geeksforgeeks.org/multiple-inheritance-in-c/> 

 

Test.A::Func();

 

2、多继承中虚基类可以保证只有一份变量

菱形继承

## Virtual base class

 A
 / \
 B  C
 \ /
  D

 

D中的成员只会有来自A的一份。

 

[In C++, what is a virtual base class?](https://stackoverflow.com/questions/21558/in-c-what-is-a-virtual-base-class)

[virtual inheritance [duplicate\]](https://stackoverflow.com/questions/419943/virtual-inheritance)

## 场景决定

根据实际场景来决定父类成员变量的属性和继承的方式。

在pms的场景中、明显是在父类中定义成员变量和一些预期的操作、在子类中针对该成员变量增加一些特有的操作。

因此是public继承、protected成员变量