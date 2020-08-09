#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a[1] < 0) {
                m.insert(-a[1]);
            } else {
                m.erase(m.find(a[1]));
            }
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12},
                                    {15, 20, 10}, {19, 24, 8}};
    Solution sol;
    vector<vector<int>> res = sol.getSkyline(buildings);
    return 0;
}