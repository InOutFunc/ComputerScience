## values

[What are rvalues, lvalues, xvalues, glvalues, and prvalues?](https://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues)

## const reference and lvalue

[Const reference and lvalue [duplicate\]](https://stackoverflow.com/questions/22845167/const-reference-and-lvalue)

 

来自 <https://stackoverflow.com/questions/22845167/const-reference-and-lvalue> 

 

[Literal initialization for const references](https://stackoverflow.com/questions/2088259/literal-initialization-for-const-references)

 

来自 <https://stackoverflow.com/questions/2088259/literal-initialization-for-const-references> 

## Rvalue Reference is Treated as an Lvalue?

[Rvalue Reference is Treated as an Lvalue?](https://stackoverflow.com/questions/28483250/rvalue-reference-is-treated-as-an-lvalue)

 

来自 <https://stackoverflow.com/questions/28483250/rvalue-reference-is-treated-as-an-lvalue> 

## What is move semantics?

[What is move semantics?](https://stackoverflow.com/questions/3106110/what-is-move-semantics)

 

来自 <https://stackoverflow.com/questions/3106110/what-is-move-semantics> 

## perfect forwarding

[Perfect forwarding - what's it all about? [duplicate\]](https://stackoverflow.com/questions/6829241/perfect-forwarding-whats-it-all-about)

## move

\#include <iostream> #include <utility> #include <vector> #include <string> int main() { std::string str = "Hello"; std::vector<std::string> v; // uses the push_back(const T&) overload, which means // we'll incur the cost of copying str v.push_back(str); std::cout << "After copy, str is \"" << str << "\"\n"; // uses the rvalue reference push_back(T&&) overload, // which means no strings will be copied; instead, the contents // of str will be moved into the vector. This is less // expensive, but also means str might now be empty. v.push_back(std::move(str)); std::cout << "After move, str is \"" << str << "\"\n"; std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1] << "\"\n"; } void push_back( T&& value );

在 v.push_back(std::move(str));后，为什么str变为""了？value引用到了"Hello"上吗，那"Hello"又是什么？这条语句中“移动”体现在哪儿？

str是个左值，默认从堆上分配内存，从而持有值"Hello"。

vector<T>::push_back有2个重载函数，分别对应左值对象和右值对象：

void push_back( const T& value )

void push_back(T&& value )

采用左值对象的方法默认是拷贝构造函数，从而copy str的内容，所以实参value的值不会影响str的值。而采用右值对象的方法，默认是用移动语义，会将str内部的堆指针交换到新对象实参value上，也就是移动的过程，省略了拷贝的开销，最终结果就是v[1]持有原来str的内容，而str由于堆指针被交换了，导致为空。

std::move只是简单的将左值引用强转成右值引用，从而push_back可以当做移动语义来进行操作。

std::string的左值、右值构造函数（对应拷贝、移动构造函数）如下：

basic_string( const basic_string& other );

basic_string( basic_string&& other ) noexcept;

正解~std::move只是一个类型强转，要配合移动构造才能产生内存转移的效果

## 深入浅出c++11右值引用

[**腾讯技术工程**](https://www.zhihu.com/org/teng-xun-ji-zhu-gong-cheng)

已认证的官方帐号

 

https://zhuanlan.zhihu.com/p/107445960

## 总结

1、**R-value references****：引用** **binding to variable**

https://www.learncpp.com/cpp-tutorial/15-2-rvalue-references/

 

**a:** **L-values and r-values**

l-values and r-values are actually not properties of values, but rather, properties of expressions.

 

Every expression in C++ has two properties: a type (which is used for type checking), and a **value category** (which is used for certain kinds of syntax checking, such as whether the result of the expression can be assigned to).

 

However, later, the const keyword was added to the language, and l-values were split into two sub-categories: modifiable l-values, which can be changed, and non-modifiable l-values, which are const.

 

It’s simplest to think of an **r-value** as “everything that is not an l-value”. This notably includes literals (e.g. 5), temporary values (e.g. x+1), and anonymous objects (e.g. Fraction(5, 2)). r-values are typically evaluated for their values, have expression scope (they die at the end of the expression they are in), and cannot be assigned to. 

 

b:**L-value references**

L-value references can only be initialized with modifiable l-values.

 

L-value references to const objects can be initialized with l-values and r-values alike. However, those values can’t be modified.

 

c:**R-value references**

An r-value reference is a reference that is designed to be initialized with an r-value (only).

R-values references cannot be initialized with l-values.

 

R-value references have two properties that are useful. First, r-value references extend the lifespan of the object they are initialized with to the lifespan of the r-value reference (l-value references to const objects can do this too). Second, non-const r-value references allow you to modify the r-value!

 

**d:****R-value references as function parameters**

R-value references are more often used as function parameters. This is most useful for function overloads when you want to have different behavior for l-value and r-value arguments.

As you can see, when passed an l-value, the overloaded function resolved to the version with the l-value reference. When passed an r-value, the overloaded function resolved to the version with the r-value reference (this is considered a better match than a l-value reference to const).

| 2    | int &&ref{ 5 };  fun(ref); |
| ---- | -------------------------- |
|      |                            |

Although variable ref has type *r-value reference to an integer*, it is actually an l-value itself (as are all named variables).

 

e: **Returning an r-value reference**

You should almost never return an r-value reference, for the same reason you should almost never return an l-value reference. In most cases, you’ll end up returning a hanging reference when the referenced object goes out of scope at the end of the function.

 

**Quiz time**

1) State which of the following lettered statements will not compile:

 

| 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20 | int main()  {  int x{};     //  l-value references  int &ref1{ x }; // A  int &ref2{ 5 }; // B     const int &ref3{ x }; // C  const int &ref4{ 5 }; // D     //  r-value references  int &&ref5{ x }; // E  int &&ref6{ 5 }; // F     const int &&ref7{ x }; // G  const int &&ref8{ 5 }; // H  return 0;  } |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                                              |                                                              |

[**Hide Solution**](javascript:void(0))

B, E, and G won’t compile.

 

2、

[Literal initialization for const references](https://stackoverflow.com/questions/2088259/literal-initialization-for-const-references)

So you can write code like this:

void f( const string & s ) {
 }

f( "foobar" );

Although strictly speaking what is actually happening here is not the literal being bound to a const reference - instead a temprary string object is created:

string( "foobar" );

and this nameless string is bound to the reference.

Note that it is actually quite unusual to create non-parameter reference variables as you are doing - the main purpose of references is to serve as function parameters and return values.

 

3、

[What is move semantics?](https://stackoverflow.com/questions/3106110/what-is-move-semantics)

1、Let's start with a very simple string class which only holds a pointer to a heap-allocated block of memory:

2、I am going to defer writing the assignment operator and only implement the destructor and the copy constructor for now:

3、

string a(x);                  // Line 1
 string b(x + y);                // Line 2
 string c(some_function_returning_a_string());  // Line 3

Note that only in the first line where we copy x is this deep copy really necessary, because we might want to inspect x later and would be very surprised if x had changed somehow. 

The arguments in lines 2 and 3 are not lvalues, but rvalues, because the underlying string objects have no names, so the client has no way to inspect them again at a later point in time.

4、

C++0x introduces a new mechanism called "rvalue reference" which, among other things, allows us to detect rvalue arguments via function overloading.

5、

  string(string&& that)  // string&& is an rvalue reference to a string
   {
     data = that.data;
     that.data = nullptr;
   }

6、

  string& operator=(string that)
   {
     std::swap(data, that.data);
     return *this;
   }
 };

So if you say a = b, the *copy constructor* will initialize that (because the expression b is an lvalue), and the assignment operator swaps the contents with a freshly created, deep copy. That is the very definition of the copy and swap idiom -- make a copy, swap the contents with the copy, and then get rid of the copy by leaving the scope. Nothing new here.

But if you say a = x + y, the *move constructor* will initialize that (because the expression x + y is an rvalue), so there is no deep copy involved, only an efficient move. that is still an independent object from the argument, but its construction was trivial, since the heap data didn't have to be copied, just moved. It wasn't necessary to copy it because x + y is an rvalue, and again, it is okay to move from string objects denoted by rvalues.

7、

To summarize, the copy constructor makes a deep copy, because the source must remain untouched. The move constructor, on the other hand, can just copy the pointer and then set the pointer in the source to null. It is okay to "nullify" the source object in this manner, because the client has no way of inspecting the object again.

 

4、

[What is move semantics?](https://stackoverflow.com/questions/3106110/what-is-move-semantics)

1、introduction

Turning expensive copies into cheap moves. 

Implementing safe "move-only" types; that is, types for which copying does not make sense, but moving does. Examples include locks, file handles, and smart pointers with unique ownership semantics.

2、what is a move

To move an object means to transfer ownership of some resource it manages to another object.

The copy constructor of auto_ptr probably looks something like this (somewhat simplified):

auto_ptr(auto_ptr& source)  // note the missing const
 {
   p = source.p;
   source.p = 0;  // now the source no longer owns the object
 }

3、

Dangerous and harmless moves

The dangerous thing about auto_ptr is that what syntactically looks like a copy is actually a move. 

auto_ptr<Shape> a(new Triangle);  // create triangle
 auto_ptr<Shape> b(a);       // move a into b
 double area = a->area();      // undefined behavior

But auto_ptr is not *always* dangerous. Factory functions are a perfectly fine use case for auto_ptr:

auto_ptr<Shape> make_triangle()
 {
   return auto_ptr<Shape>(new Triangle);
 }

auto_ptr<Shape> c(make_triangle());   // move temporary into c
 double area = make_triangle()->area();  // perfectly safe

Note how both examples follow the same syntactic pattern:

auto_ptr<Shape> variable(expression);
 double area = expression->area();

So what is the difference between the expressions a and make_triangle()? Aren't they both of the same type? Indeed they are, but they have different *value categories*.

4、

Value categories

a is an example of an *lvalue*, whereas make_triangle() is an example of an *rvalue*.

Moving from lvalues such as a is dangerous, because we could later try to call a member function via a, invoking undefined behavior. On the other hand, moving from rvalues such as make_triangle() is perfectly safe, because after the copy constructor has done its job, we cannot use the temporary again. 

 

An rvalue of class type is an expression whose evaluation creates a temporary object. Under normal circumstances, no other expression inside the same scope denotes the same temporary object.

 

Rvalue references

 If C++ had language support to distinguish lvalue arguments from rvalue arguments, we could either completely forbid moving from lvalues, or at least make moving from lvalues *explicit* at call site, so that we no longer move by accident.

 

C++11's answer to this problem is *rvalue references*. An rvalue reference is a new kind of reference that only binds to rvalues, and the syntax is X&&. The good old reference X& is now known as an *lvalue reference*. (Note that X&& is *not* a reference to a reference; there is no such thing in C++.)

![img](file:///C:\Users\C00518~1\AppData\Local\Temp\msohtmlclip1\02\clip_image001.png)

 

Implicit conversions

 

void some_function(std::string&& r);

some_function("hello world");

 

Move constructors

A useful example of a function with an X&& parameter is the *move constructor* X::X(X&& source). Its purpose is to transfer ownership of the managed resource from the source into the current object.

Now comes the interesting part, the move constructor:

  unique_ptr(unique_ptr&& source)  // note the rvalue reference
   {
     ptr = source.ptr;
     source.ptr = nullptr;
   }

unique_ptr<Shape> a(new Triangle);
 unique_ptr<Shape> b(a);         // error
 unique_ptr<Shape> c(make_triangle());  // okay

The second line fails to compile, because a is an lvalue, but the parameter unique_ptr&& source can only be bound to rvalues. This is exactly what we wanted; dangerous moves should never be implicit. The third line compiles just fine, because make_triangle() is an rvalue. The move constructor will transfer ownership from the temporary to c. Again, this is exactly what we wanted.

 

[Difference between the move assignment operator and move constructor?](https://stackoverflow.com/questions/29971205/difference-between-the-move-assignment-operator-and-move-constructor)

[What's the difference between assignment operator and copy constructor?](https://stackoverflow.com/questions/11706040/whats-the-difference-between-assignment-operator-and-copy-constructor)

Move assignment operators

 

The last missing piece is the move assignment operator. Its job is to release the old resource and acquire the new resource from its argument:

  unique_ptr& operator=(unique_ptr&& source)  // note the rvalue reference
   {
     if (this != &source)  // beware of self-assignment
     {
       delete ptr;     // release the old resource

ptr = source.ptr;  // acquire the new resource
       source.ptr = nullptr;
     }
     return *this;
   }

 

Moving from lvalues

This name is a bit unfortunate, because std::move simply casts an lvalue to an rvalue; it does *not* move anything by itself. It merely *enables* moving.Maybe it should have been named std::cast_to_rvalue or std::enable_move, but we are stuck with the name by now.

unique_ptr<Shape> a(new Triangle);
 unique_ptr<Shape> b(a);       // still an error
 unique_ptr<Shape> c(std::move(a));  // okay

Moving out of functions

unique_ptr<Shape> make_triangle()
 {
   return unique_ptr<Shape>(new Triangle);
 }     \-----------------------------/
          |
          | temporary is moved into c
          |
          v
 unique_ptr<Shape> c(make_triangle());

Perhaps surprisingly, automatic objects (local variables that are not declared as static) can also be *implicitly* moved out of functions:

unique_ptr<Shape> make_square()
 {
   unique_ptr<Shape> result(new Square);
   return result;  // note the missing std::move
 }

 Nobody could possibly complain afterward that result had changed somehow; when control flow is back at the caller, result does not exist anymore! For that reason, C++11 has a special rule that allows returning automatic objects from functions without having to write std::move.

unique_ptr<Shape>&& flawed_attempt()  // DO NOT DO THIS!
 {
   unique_ptr<Shape> very_bad_idea(new Square);
   return std::move(very_bad_idea);  // WRONG!
 }

Moving into members

class Foo
 {
   unique_ptr<Shape> member;

public:

Foo(unique_ptr<Shape>&& parameter)
   : member(parameter)  // error
   {}
 };

A named rvalue reference is an lvalue, just like any other variable.

class Foo
 {
   unique_ptr<Shape> member;

public:

Foo(unique_ptr<Shape>&& parameter)
   : member(std::move(parameter))  // note the std::move
   {}
 };

Special member functions

 

X::X(const X&);       // copy constructor
 X& X::operator=(const X&);  // copy assignment operator
 X::~X();           // destructor

X::X(X&&);          // move constructor
 X& X::operator=(X&&);    // move assignment operator

 

Forwarding references ([previously](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4164.pdf) known as *Universal references*)

 

Consider the following function template:

template<typename T>
 void foo(T&&);

You might expect T&& to only bind to rvalues, because at first glance, it looks like an rvalue reference. As it turns out though, T&& also binds to lvalues:

foo(make_triangle());  // T is unique_ptr<Shape>, T&& is unique_ptr<Shape>&&
 unique_ptr<Shape> a(new Triangle);
 foo(a);         // T is unique_ptr<Shape>&, T&& is unique_ptr<Shape>&

If the argument is an rvalue of type X, T is deduced to be X, hence T&& means X&&. This is what anyone would expect. But if the argument is an lvalue of type X, due to a special rule, T is deduced to be X&, hence T&& would mean something like X& &&. But since C++ still has no notion of references to references, the type X& && is *collapsed* into X&. This may sound confusing and useless at first, but reference collapsing is essential for *perfect forwarding* (which will not be discussed here).

 

T&& is not an rvalue reference, but a forwarding reference. It also binds to lvalues, in which case T and T&& are both lvalue references.

 

Implementation of move

Now that you understand reference collapsing, here is how std::move is implemented:

template<typename T>
 typename std::remove_reference<T>::type&&
 move(T&& t)
 {
   return static_cast<typename std::remove_reference<T>::type&&>(t);
 }

move accepts any kind of parameter thanks to the forwarding reference T&&, and it returns an rvalue reference. 

 

The std::remove_reference<T>::type meta-function call is necessary because otherwise, for lvalues of type X, the return type would be X& &&, which would collapse into X&.

 

4、In C++, what is a temporary object, and how are they different from rvalues?

https://www.quora.com/In-C-what-is-a-temporary-object-and-how-are-they-different-from-rvalues

 

5、

[What are the main purposes of using std::forward and which problems it solves?](https://stackoverflow.com/questions/3582001/what-are-the-main-purposes-of-using-stdforward-and-which-problems-it-solves)

Putting these together gives us "perfect forwarding":

template <typename A>
 void f(A&& a)
 {
   E(static_cast<A&&>(a)); 
 }

When f receives an lvalue, E gets an lvalue. When f receives an rvalue, E gets an rvalue. Perfect.

And of course, we want to get rid of the ugly. static_cast<T&&> is cryptic and weird to remember; let's instead make a utility function called forward, which does the same thing:

std::forward<A>(a);
 // is the same as
 static_cast<A&&>(a);

 