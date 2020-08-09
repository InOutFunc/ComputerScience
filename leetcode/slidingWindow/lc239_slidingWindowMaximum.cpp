#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res; // 最大值结果
        deque<int> q; // 当前有用的下标

        for (int i = 0; i < nums.size(); i++) {
            // 
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // 从index k - 1开始，每个数都要push进nums里
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }

        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 1, 2, 0, 5};
    int k = 3;
    vector<int> res = sol.maxSlidingWindow(nums, k);

    return 0;
}