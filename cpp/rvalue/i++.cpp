#include <iostream>

using std::cout;

void fun(int &k)
{
    cout << k;
}

int main()
{
    int k = 1;
    // fun(k++); // error
    fun(++k); // good

    return 0;
}