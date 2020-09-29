## 赋值运算符和拷贝构造

注意区分初始化操作和赋值操作、初始化时调用拷贝构造、赋值时调用赋值运算符

https://www.zhihu.com/question/47982867

 

A aa;
 A a = aa; //copy constructor

 

A aa;
 A a;   // default constructor
 a = aa; // assignment operator

 

You could replace copy construction by default construction plus assignment, but that would be less efficient.

[What's the difference between assignment operator and copy constructor?](https://stackoverflow.com/questions/11706040/whats-the-difference-between-assignment-operator-and-copy-constructor)

 

无需纠结、它们的作用只有一个、就是创建新的对象。区别在于创建的方式不同

## 成员变量是对象、拷贝构造

调用每个成员类的拷贝构造

[C++ implicit copy constructor for a class that contains other objects](https://stackoverflow.com/questions/1810163/c-implicit-copy-constructor-for-a-class-that-contains-other-objects)



