#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        int mask = 0;

        for (int i : nums) {
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x2 &= mask;
            x1 &= mask;
        }

        return x1;
    }
};

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    Solution sol;
    int ret = sol.singleNumber(nums);

    return 0;
}