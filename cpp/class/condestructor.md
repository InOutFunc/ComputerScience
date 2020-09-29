Every destructor *down* gets called no matter what. virtual makes sure it starts at the top instead of the middle.

 

来自 <https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors> 

 

**The order is:**

1. Base constructor
2. Derived     constructor
3. Derived     destructor
4. Base     destructor

 

来自 <https://stackoverflow.com/questions/654428/what-is-the-order-in-which-the-destructors-and-the-constructors-are-called-in-c>

1、父类非虚、子类虚

子类对象指针：都会调用

[In delete b], if the static type of the object to be deleted is different from its dynamic type, the static type shall be a base class of the dynamic type of the object to be deleted and **the static type shall have a virtual destructor or the behavior is undefined**.

 

来自 <https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors> 

父类对象指针：从middle开始、只执行base destructor、内存泄漏

 

父类指针指向子类对象、当析构函数时虚函数时、将调用子类析构函数



1、

[No Virtual constructors but virtual destructor](https://stackoverflow.com/questions/9923959/no-virtual-constructors-but-virtual-destructor)

 

来自 <https://stackoverflow.com/questions/9923959/no-virtual-constructors-but-virtual-destructor> 

There is no point in virtual constructor - you declare exactly what type is created, and it is well known in compile time. 

 

Virtual destructors are important to prevent memory leaks, and monitor the system.

2

**Can I overload the destructor for my class?** 

No.

You can have only one destructor for a class Fred. It’s always called Fred::~Fred(). It never takes any parameters, and it never returns anything.

You can’t pass parameters to the destructor anyway, since you [never explicitly call a destructor](https://isocpp.org/wiki/faq/dtors#dont-call-dtor-on-local) (well, [*almost* never](https://isocpp.org/wiki/faq/dtors#placement-new)).

来自 <https://isocpp.org/wiki/faq/dtors#cant-overload-dtors> 

3 copy constructor

Copy Constructor in C++

 

来自 <https://www.geeksforgeeks.org/copy-constructor-in-cpp/> 

 

浅拷贝

4 subclass copy constructor

Copy Constructor in C++

Copy constructor的主要作用还是给对象的成员赋值、只是参数变成了另一个对象。

来自 <https://www.geeksforgeeks.org/copy-constructor-in-cpp/> 

 

**11.4** **—** **Constructors and initialization of derived classes**

 

来自 <https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/> 

 

 

When do we use Initializer List in C++?

 

来自 <https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/> 

 

Derived( const Derived &d ) : Base(d)
 {      //^^^^^^^ change this to Derived. Your code is using Base
   std::cout << "copy constructor\n";
 }

 

来自 <https://stackoverflow.com/questions/9309577/how-to-declare-copy-constructor-in-derived-class-without-default-construcor-in> 

Base d调用基类的拷贝构造函数、将子类对象赋值给基类引用。

 

5、子类拷贝构造不调用父类拷贝构造

 

6、成员变量的初始化顺序

先初始化基类的、按成员变量出现的顺序初始化

 ## 构造函数调用

[When is the constructor called?](https://stackoverflow.com/questions/4934737/when-is-the-constructor-called)

 

\1. myClass class1;
 \2. myClass* class1;
 \3. myClass* class1 = new myClass;

## 子类析构函数

子类析构函数不需要加virtual、若父类是virtual,则默认是virtual

[Are explicitly declared destructors needed in the derived classes?](https://stackoverflow.com/questions/21766854/are-explicitly-declared-destructors-needed-in-the-derived-classes)

## virtual and pure virtual function

Virtual主要用于多态、pure virtual主要用于抽象类

 

[Difference between a virtual function and a pure virtual function [duplicate\]](https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function)

 

来自 <https://stackoverflow.com/questions/2652198/difference-between-a-virtual-function-and-a-pure-virtual-function> 

 

[Virtual/pure virtual explained](https://stackoverflow.com/questions/1306778/virtual-pure-virtual-explained)

 

来自 <https://stackoverflow.com/questions/1306778/virtual-pure-virtual-explained> 

 

https://zhuanlan.zhihu.com/p/37331092

## 继承、析构函数

**C++类有继承时，析构函数必须为虚函数**

PmsEidToNetconf

AlibabaPmsEidToNetconf

## 调用时间

对象消亡时调用

