#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty() || intervals[0].empty()) {
            return res;
        }
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].front() > res.back().back()) {
                res.push_back(intervals[i]);
            } else {
                if (res.back().back() < intervals[i].back()) {
                    res.back().back() = intervals[i].back();
                }
            }
        }
        
        return res;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution sol;
    vector<vector<int>> res = sol.merge(intervals);

    return 0;
}