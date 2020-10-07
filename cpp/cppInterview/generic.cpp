#include <iostream>

// using namespace std;

template <class T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout << max(1, 2) << std::endl;
    std::cout << max(1.1f, 2.2f) << std::endl;
    std::cout << max(1.11l, 2.22l) << std::endl;
    std::cout << max('a', 'c') << std::endl;
    std::cout << max<double>(1, 2.0) << std::endl;
    return 0;
}