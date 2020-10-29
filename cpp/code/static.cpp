#include <iostream>

using namespace std;

class A {
public:
    static int num;
};

int A::num;

int main()
{
    A a;
    A::num = 1;
    cout << a.num;
    cout << A::num;
}