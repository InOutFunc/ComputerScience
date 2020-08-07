#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) {
            return res;
        }
        dfs(res, "", num, target, 0, 0, 0);
        return res;
    }
    
private:
    void dfs(vector<string> &res, string path, string num, int target, int pos, long eval, long multed) {
        if (pos == num.size()) {
            if (target == eval) {
                res.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (i != pos && num[pos] == '0') {
                break;
            }
            string curStr = num.substr(pos, i - pos + 1);
            long cur = stol(curStr);
            if (pos == 0) {
                dfs(res, path + curStr, num, target, i + 1, cur, cur);
            } else {
                dfs(res, path + "+" + curStr, num, target, i + 1, eval + cur, cur);
                dfs(res, path + "-" + curStr, num, target, i + 1, eval - cur, -cur);
                dfs(res, path + "*" + curStr, num, target, i + 1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
};

int main()
{
    string num("123");
    int target = 6;
    Solution sol;
    vector<string> res = sol.addOperators(num, target);

    return 0;
}