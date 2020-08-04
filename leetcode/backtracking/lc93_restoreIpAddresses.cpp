#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> cur;
        dfs(s, 0, 0, cur, res);
        return res;
    }
    
    void dfs(const string &s, int index, int level, vector<string> &cur, vector<string> &res)
    {
        if (level == 4 && index != s.size()) {
            return;
        }
        if (level == 4 && index == s.size()) {
            string tmp;
            for (int i = 0; i < cur.size() - 1; i++) {
                tmp.append(cur[i])
                   .append(".");
            }
            tmp.append(cur[3]);
            res.push_back(tmp);
            return;
        } else {
            for (int i = 1; i < 4; i++) {
                if (index + i > s.size()) {
                    break;
                }
                if (!isValid(s.substr(index, i))) {
                    break;
                }
                cur.push_back(s.substr(index, i));
                index += i;
                level++;
                cout << s << " " << index << level << endl;
                dfs(s, index, level, cur, res);
                level--;
                index -= i;
                cur.pop_back();
                
            }
        }
    }
    
    bool isValid(string s)
    {
        if (stoi(s) < 0 || stoi(s) > 255) {
            return false;
        }
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        return true;
    }
};

int main()
{
    string s("0000");
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    return 0;
}