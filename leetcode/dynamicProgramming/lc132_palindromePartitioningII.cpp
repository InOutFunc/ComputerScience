#include <bits/stdc++.h>

using namespace std;

int minCut(string s)
{
    int n = s.size();
    vector<int> min(n);
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1));

    for (int i = 0; i < n; i++) {
        min[i] = i;
        for (int j = 0; j <= i; j++) {
            if (s[j] == s[i] && (j + 1 > i - 1 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
                min[i] = (j == 0 ? 0 : std::min(min[i], min[j - 1] + 1));
            }
        }
    }
    return min[n - 1];
}

int main()
{
    string s("aab");
    int res = minCut(s);
    return 0;
}