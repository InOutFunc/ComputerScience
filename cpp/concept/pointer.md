## delete []

当需要使用delete []时、使用了delete并不会造成内存泄漏、而是未定义的行为

[Valgrind does not report memory leak on “delete array”](https://stackoverflow.com/questions/10586076/valgrind-does-not-report-memory-leak-on-delete-array)

## references and pointers

通常情况下引用是指针的语法糖

[C++: Why do you need references when you have pointers? [duplicate\]](https://stackoverflow.com/questions/10781661/c-why-do-you-need-references-when-you-have-pointers)

 

引用是受限的指针、因为受限所以更安全

[What are the differences between a pointer variable and a reference variable in C++?](https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in)

## delete any pointer?

No. Only delete what you new.

Int a = 5;

Int * b = &a;

a是int变量、会被自动清理。b是int *变量、也会被自动清理

 

Int * b = new int(5)

…

Delete b;

B = nullptr;

5是new出来的、在堆中、不会自动清理掉、需要手动delete掉。delete后记得赋值为nullptr, 不然就是野指针了。忘记delete应该也不会有太大关系、一个int变量也占用不了多少空间。。。

 

注意和int * b = new int[5]的区别、后者是array。

 

不是new出来的内存、不在堆中、因此也不需要delete。

## uintptr_t

uintptr_t is an unsigned integer type that is capable of storing a data pointer.

 

[What is uintptr_t data type](https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type)

## smart pointer

[What is a smart pointer and when should I use one?](https://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one)

1. A class     that wraps a 'raw' c++ pointer

A smart pointer is a class that wraps a 'raw' (or 'bare') C++ pointer, to manage the lifetime of the object being pointed to. There is no single smart pointer type, but all of them try to abstract a raw pointer in a practical way.

 

2

A smart pointer by comparison defines a policy as to when the object is destroyed. You still have to create the object, but you no longer have to worry about destroying it.

```cpp
SomeSmartPtr<MyObject> ptr(new MyObject());
ptr->DoSomething(); // Use the object in some way.
// Destruction of the object happens, depending 
// on the policy the smart pointer class uses.
// Destruction would happen even if DoSomething() 
// raises an exception
```

Auto_ptr不再使用

Shared_ptr循环引用时、无法析构。Weak_ptr不会有循环引用问题。

```cpp
#include <memory> // and others
#include <bits/stdc++.h>
using namespace std;

using namespace std;
class B; // forward declaration 
// for clarity, add explicit destructor to see that they are not called
class A { public: shared_ptr<B> b; ~A() {cout << "~A()" << endl; } };  
class B { public: shared_ptr<A> a; ~B() {cout << "~B()" << endl; } };   
class D; // forward declaration 
// for clarity, add explicit destructor to see that they are not called
class C { public: shared_ptr<D> d; ~C() {cout << "~C()" << endl; } };  
class D { public: weak_ptr<C> c; ~D() {cout << "~D()" << endl; } };   
int main()
{
    shared_ptr<A> x(new A);  //x->b share_ptr is default initialized
    x->b = make_shared<B>(); // you can't do "= new B" on shared_ptr                      
    x->b->a = x;
    cout << x.use_count() << endl;  
    shared_ptr<C> y(new C);  //x->b share_ptr is default initialized
    y->d = make_shared<D>(); // you can't do "= new B" on shared_ptr                      
    y->d->c = y;
    cout << y.use_count() << endl;  
    return 0;
}  
```

1、auto_ptr. unique_ptr. shared_ptr. weak_ptr

矛盾：两个指针指向同一个对象、试图释放两次

```cpp
auto_ptr<string> ps (new string("I reigned lonely as a cloud."));
auto_ptr<string> vocation;
vocation = ps;
```

程序试图删除同一个对象两次，一次是ps过期时，另一次是vocation过期时。要避免这种问题，方法有多种

* 建立所有权(ownership)概念，对于特定的对象，只能有一个智能指针可拥有它。这就是auto_ptr和unique_ptr的策略，unique_ptr更严格
* 创建智能更高的指针，跟踪引用特定对象的智能指针数，称为引用计数(reference counting)。最后一个指针过期时，才调用delete。这是shared_ptr采用的策略

1. unique_ptr优于auto_ptr

```cpp
auto_ptr<string> p1(new string("auto"));
auto_ptr<string> p2;
p2 = p1;
```

试图使用p1时报错

```cpp
unique_ptr<string> p3(new string("auto"));
unique_ptr<string> p4;
p4 = p3;
```

编译时就报错



或者转移所有权后、重新赋值

```cpp
using namespace std;
unique_ptr<string> ps1, ps2;
ps1 = demo("uniquely special");
ps2 = move(ps1); // enable assignment
ps1 = demo(" and more");
cout << *ps2 << *ps1 << endl;
```

Unique_ptr，如果赋值时是右值就无所谓了，因为赋值后右值本来就不会使用了

## RAII

[What is meant by Resource Acquisition is Initialization (RAII)?](https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii)

It's a really terrible name for an incredibly powerful concept, and perhaps one of the number 1 things that C++ developers miss when they switch to other languages. There has been a bit of a movement to try to rename this concept as **Scope-Bound Resource Management**, though it doesn't seem to have caught on just yet.

## Make_shared and shared_ptr

[Difference in make_shared and normal shared_ptr in C++](https://stackoverflow.com/questions/20895648/difference-in-make-shared-and-normal-shared-ptr-in-c)

 

1.

Shared_ptr<Object> p1 = make_shared<Object>("foo");

Shared_ptr<Object> p2(new Object("foo"));

 

2.

std::shared_ptr manages two entities:

- the     control block (stores meta data such as ref-counts, type-erased deleter,     etc)
- the object     being managed

 

3.

Make_shared performs a single heap-allocation accounting for the space necessary for both the control block and the data.

 

New Object("foo") invokes a heap-allocation for the managed data

Shared_ptr constructor performs another one for the control block