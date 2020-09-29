## sscanf_s

功能：格式化读

int sscanf_s( const char *buffer, const char *format [, argument ] ... );

 

来自 <https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l?view=vs-2019> 

 

 

\#include <bits/stdc++.h>using namespace std;

int main()

{

  char x1[16] = {0};

  uint16_t x2;

  uint16_t x3;

  char x4;

  uint16_t x5;

  string str = "ABC-1-1-D1";

  int ret = sscanf_s(str.c_str(), "%[A-Z]-%hu-%hu-%c%hu", x1, sizeof(x1), &x2, &x3, &x4, sizeof(x4), &x5);

  if (ret != 5) {

​    cout << "sscanf_s error";

​    return 0;

  }

  cout << string(x1) << x2 << x3 << x4 << x5;

  return 0;

}

output: ABC11D1

改变str为ABC-1-1-D1-1-1-1

output: ABC11D1

改变str为1-ABC-1-1-D1-1-1-1

output: sscanf_s error

主要用来处理字节流的：和平台的数据交互是通过字节流来的、通过一些字节流的处理函数来处理、和平常的处理无异、无非就是增删读写。而且这里的增删读写、就真的只是这样的了。

## Sprintf_s

int sprintf_s( char *buffer, size_t sizeOfBuffer, const char *format, ... );

 

来自 <https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l?view=vs-2019> 

 

 

功能：格式化存

\#include <bits/stdc++.h>using namespace std;

int main()

{

  uint16_t x1 = 1;

  uint8_t x3 = 3;

  uint8_t x4 = 4;

  char str[30] = "x1=%hu,x2=0xff,x3=%u,x4=%u";

  int ret = sprintf_s(str, 30, "x1=%hu,x2=0xff,x3=%u,x4=%u", x1, x3, x4);

  cout << ret << string(str);

  return 0;

}

output:22x1=1,x2=0xff,x3=3,x4=4，格式串的长度

改变char str[30]=""

output:22x1=1,x2=0xff,x3=3,x4=4，格式串的长度

改变char str[]="111"

output:22x1=1a，格式串的长度，str长度不够

## Specifier for uint

不同类型对应的占位符

[What is the format specifier for unsigned short int?](https://stackoverflow.com/questions/8699812/what-is-the-format-specifier-for-unsigned-short-int)

