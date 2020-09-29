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