#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty()) {
            return {};
        }
        sort(str.begin(), str.end());
        vector<string> res;
        vector<bool> used(str.size());
        dfs(str, "", res, used);
        return res;
    }
    
private:
    void dfs(string str, string cur, vector<string> &res, vector<bool> &used)
    {
        if (cur.size() == str.size()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < str.size(); i++) {
            if (used[i] || (i - 1 >= 0 && !used[i - 1] && str[i] == str[i - 1])) {
                continue;
            }
            cur.push_back(str[i]);
            used[i] = true;
            dfs(str, cur, res, used);
            used[i] = false;
        }
    }
};

int main()
{
    string str("ab");
    Solution sol;
    vector<string> res;
    res = sol.Permutation(str);
    return 0;
}