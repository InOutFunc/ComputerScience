[return value of operator overloading in C++](https://stackoverflow.com/questions/2337213/return-value-of-operator-overloading-in-c)

 

Some operators return by value, some by reference. In general, an operator whose result is a new value (such as +, -, etc) must return the new value by value, and an operator whose result is an existing value, but modified (such as <<, >>, +=, -=, etc), should return a reference to the modified value.

 

std::ostream& operator<< (std::ostream& lhs, const MyType& rhs)
 {
  // Do whatever to put the contents of the rhs object into the lhs stream
  return lhs;
 }

cout << x << y