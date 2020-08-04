# rvalue目录

[i++](#i++)







## i++

```c++
void fun(int &k)
fun(k++); // error
fun(++k); // good
```

k++是右值，无法绑定到int &上。++k是左值。

[1]: https://stackoverflow.com/questions/63212957/why-funk-is-wrong-but-funk-is-ok
[2]: https://stackoverflow.com/questions/371503/why-is-i-considered-an-l-value-but-i-is-not