## interger promotion

[integer promotion in c](https://stackoverflow.com/questions/44455248/integer-promotion-in-c)

First snippet:

si16 x, pt;
 si32 speed;
 u16 length;
 x = (speed*pt)/length;

Second one:

x = pt + length;

 

If an int can represent all values of the original type (as restricted by the width, for a bit-field), the value is converted to an int; otherwise, it is converted to an unsigned int. These are called the integer promotions. All other types are unchanged by the integer promotions.

 

Where "otherwise, it is converted to an unsigned int" is in practice only used in one particular special case, namely where the smaller integer type unsigned short has the same size as unsigned int. In that case it will remain unsigned.

 

Apart from that special case, all small integer types will always get promoted to (signed) int regardless of their signedness.

 

speed is signed 32, it will not get promoted. ptr will get integer promoted to int (signed 32). The result of speed*ptr will have type int.

length will get integer promoted to int. The division will get carried out with operands of type int and the resulting type will be int.

The result will get converted to signed 16 as it is assigned to x (lvalue conversion during assignment).

 

x = pt + length; is similar, here both operands of + will get promoted to int before addition and the result will afterwards get converted to signed 16.

[Implicit type promotion rules](https://stackoverflow.com/questions/46073295/implicit-type-promotion-rules)

Example 1)

Why does this give a strange, large integer number and not 255?

unsigned char x = 0;
 unsigned char y = 1;
 printf("%u\n", x - y); 

 

This is why example 1 in the question fails. Both unsigned char operands are promoted to type int, the operation is carried out on type int, and the result of x - y is of type int. Meaning that we get -1 instead of 255 which might have been expected. The compiler may generate machine code that executes the code with 8 bit instructions instead of int, but it may not optimize out the change of signedness. Meaning that we end up with a negative result, that in turn results in a weird number when printf("%u is invoked. Example 1 could be fixed by casting the result of the operation back to type unsigned char.

 

Example 2)

Why does this give "-1 is larger than 0"?

unsigned int a = 1;
 signed int b = -2;
 if(a + b > 0)
  puts("-1 is larger than 0");

 

This is the reason why a + b in example 2 gives a strange result. Both operands are integers and they are at least of rank int, so the integer promotions do not apply. The operands are not of the same type - a is unsigned int and b is signed int. Therefore the operator b is temporarily converted to type unsigned int. During this conversion it loses the sign information and ends up as a large value.

 

Example 3)

Why does changing the type in the above example to short fix the problem?

unsigned short a = 1;
 signed short b = -2;
 if(a + b > 0)
  puts("-1 is larger than 0"); // will not print

 

The reason why changing type to short in example 3 fixes the problem, is because short is a small integer type. Meaning that both operands are integer promoted to type int which is signed. After integer promotion, both operands have the same type (int), no further conversion is needed. And then the operation can be carried out on a signed type as expected.

 

(These examples were intended for a 32 or 64 bit computer with 16 bit short.)

 

[Type conversion - unsigned to signed int/char](https://stackoverflow.com/questions/17312545/type-conversion-unsigned-to-signed-int-char)

\#include <stdio.h>

int main() {
   signed char a = -5;
   unsigned char b = -5;
   int c = -5;
   unsigned int d = -5;

if (a == b)
     printf("\r\n char is SAME!!!");
   else
     printf("\r\n char is DIFF!!!");

if (c == d)
     printf("\r\n int is SAME!!!");
   else
     printf("\r\n int is DIFF!!!");

return 0;
 }

char is DIFF!!! int is SAME!!!

if( (int)-5 == (int)251 )

so the integer promotions do not apply. Instead, they are balanced by *the usual arithmetic conversions*, which state that if two operands have the same "rank" (size) but different signedness, the signed operand is converted to the same type as the unsigned one. You end up with

if( (unsigned int)-5 == (unsigned int)-5)

 

**C - Type Casting**

https://www.tutorialspoint.com/cprogramming/c_type_casting.htm

 