#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<int> used(nums.size());
        vector<vector<int>> res;
        divide(nums, cur, used, res, 0);
        return res;
    }

private:
    void divide(vector<int> &nums, vector<int> &cur, vector<int> &used, vector<vector<int>> &res, int start)
    {
        if (cur.size() > nums.size()) {
            return;
        }
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            if (used[i] == 1) {
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = 1;
            divide(nums, cur, used, res, start + 1);
            used[i] = 0;
            cur.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.subsets(nums);

    return 0;
}