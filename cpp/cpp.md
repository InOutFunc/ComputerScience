# rvalue

[i++](#i++)

## i++

```c++
void fun(int &k)
fun(k++); // error
fun(++k); // good
```

k++是右值，无法绑定到int &上。++k是左值。

[Why fun(k++) is wrong, but fun(++k) is ok? [duplicate]](https://stackoverflow.com/questions/63212957/why-funk-is-wrong-but-funk-is-ok)

https://stackoverflow.com/questions/371503/why-is-i-considered-an-l-value-but-i-is-not