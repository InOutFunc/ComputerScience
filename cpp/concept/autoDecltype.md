## function template

template <typename T>

Void f(ParamType param)

 

f(expr)

从expr中推导出ParamType和T

 

Const int& rx = x;

A reference-to-const (const reference in short) doesn't mean that only const objects can be bound. It means that the object can not be modified through the reference.

What is not allowed would be to bind a non-const reference to a const object, because such reference could be used to modify the object which would break the constness. Const int x = 1; Int &rx = x;

 

Reference and pointer

 

 

Char *a = b mutable pointer to a mutable string

 

 

Const char *a = b mutable pointer to a immutable string

Const int& rx = x;

 

Char *const a = b immutalbe pointer to an mutable string

 

Const char * const a = b immutable pointer to an immutable string