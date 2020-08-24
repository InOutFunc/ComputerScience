#include <algorithm>
#include <stdint.h>
#include <vector>

using namespace std;

struct A {
    uint64_t id;
    uint8_t *buff;
};

void Release(A *&a) {
    if (a != nullptr) {
        // delete [] reinterpret_cast<uint8_t *>(a);
        delete [] a->buff;
        a = nullptr;
    }
}

int main()
{
    vector<A *> rspList;
    A a;
    a.id = 1;
    a.buff = new uint8_t(1);
    rspList.push_back(&a);
    for_each(rspList.begin(), rspList.end(), [](auto &elem) {
        Release(elem);
    });

    return 0;
}