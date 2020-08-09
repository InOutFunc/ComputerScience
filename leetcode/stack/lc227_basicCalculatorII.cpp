#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        long res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0') {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            } 
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main()
{
    string s("3+2*2");
    Solution sol;
    int res = sol.calculate(s);

    return 0;
}