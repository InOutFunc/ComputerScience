#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    auto it = rotate(begin(a), begin(a) + 2, end(a));
    int res = *it;

    return 0;
}