## 单变量构造函数使用explicit

防止编译器隐式转换

```cpp
class Foo
 {
 public:
  // single parameter constructor, can be used as an implicit conversion
  Foo (int foo) : m_foo (foo) 
  {
  }

int GetFoo () { return m_foo; }

private:
  int m_foo;
 };

 

void DoBar (Foo foo)
 {
  int i = foo.GetFoo ();
 }

 

int main ()
 {
  DoBar (42);
 }
```

Foo构造函数会隐式将42转成Foo对象、DoBar可以正确调用。

若Foo构造函数加上explicit修饰符、DoBar(42）会报错、需要DoBar(Foo(42))

 

Ref:

[What does the explicit keyword mean?](https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean)

 

来自 <https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean> 