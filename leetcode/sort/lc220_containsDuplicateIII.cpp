#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) {
                m.erase(nums[j++]);
            }
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) {
                return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 1};
    int k = 1;
    int t = 2;
    Solution sol;
    bool res = sol.containsNearbyAlmostDuplicate(nums, k, t);

    return 0;
}