#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.empty()) {
            return;
        }
        int sum = 0;
        for (const auto &item : data) {
            sum ^= item;
        }
        
        int index = 0;
        while ((sum & 1) == 0) {
            sum = sum >> 1;
            index += 1;
        }
        
        int n1 = 0;
        int n2 = 0;
        for (const auto &item : data) {
            if (IsOne(item, index)) {
                n1 ^= item;
            } else {
                n2 ^= item;
            }
        }
        
        *num1 = n1;
        *num2 = n2;
        
        return;
    }
    
private:
    bool IsOne(int item, int index)
    {
        item = item >> index;
        return item & index == 1;
    }
};

int main()
{
    int test = 2 ^ 4 ^ 3 ^ 6 ^ 3 ^ 2 ^ 5 ^ 5;
    bool t2 = ((test & 1) == 0);
    vector<int> num = {1, 1, 3, 6};
    int *n1;
    int *n2;
    Solution sol;
    sol.FindNumsAppearOnce(num, n1, n2);
    return 0;
}