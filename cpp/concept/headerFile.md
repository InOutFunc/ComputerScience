## bits/stdc++.h

It is basically a header file that also includes every standard library and STL include file. The only purpose I can see for it would be for testing and education.

[How does #include  work in C++? [duplicate\]](https://stackoverflow.com/questions/25311011/how-does-include-bits-stdc-h-work-in-c)

## variable definition in header files

头文件中不要定义变量，免得在被多个源文件包含时，编译报错

可以通过在一个cpp文件中定义，然后在.h文件中extern声明，其它文件include该头文件

一个更好的方法是，定义一个函数来获取该变量，从而可以减少extern的使用

 

[Variable definition in header files](https://stackoverflow.com/questions/2216765/variable-definition-in-header-files)

## #include guards

\#ifndef HEADERFILE_H
 \#define HEADERFILE_H

 

\#endif

防止头文件重复包含

## why have header files and .cpp files

通用编程规范：头文件是模块或文件的对外接口，头文件的设计体现了大部分的系统设计。

 

[Why have header files and .cpp files? [closed\]](https://stackoverflow.com/questions/333889/why-have-header-files-and-cpp-files)

## <header> "header"

[What is the difference between #include  and #include “filename”?](https://stackoverflow.com/questions/21593/what-is-the-difference-between-include-filename-and-include-filename)

 

\#include <filename>按照系统设计的顺序查找

\#include "filename"先在当前目录查找、然后按照系统设计的顺序查找

 

cpp -v查看顺序

当然也可以添加头文件查询路径

 

$ EXPORT CPATH=hdr1:hdr2

$ cpp -v

...

\#include <...> search starts here:

hdr1

hdr2

/usr/local/include

...

If you combine CPATH with -I flags, -I takes precedence:

$ EXPORT CPATH=hdr1:hdr2

$ cpp -Ihdr3 -v

...

\#include <...> search starts here:

hdr3

hdr1

hdr2

/usr/local/include

...

https://commandlinefanatic.com/cgi-bin/showarticle.cgi?article=art026