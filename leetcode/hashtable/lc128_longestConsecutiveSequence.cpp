#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        
        int res = 0;
        int count = 0;
        
        for (const auto &num : nums) {
            if (uset.find(num - 1) != uset.end()) {
                cout << num << endl;
                continue;
            }
            count = 0;
            while (uset.find(num + count) != uset.end()) {
                count++;
            }
            
            res = max(res, count);
        }
        return res;
    }
};

int main()
{
    vector<int> num = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int res = sol.longestConsecutive(num);

    return 0;
}