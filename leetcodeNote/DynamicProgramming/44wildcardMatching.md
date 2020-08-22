# 外卡匹配

## 分析

1、`dp[i][j]`表示`s`中前`i`个字符组成的子串和`p`中前`j`个字符组成的子串是否能匹配

2、`s`为空，`p`为连续的星号

3、状态转移方程：

```c++
1、p[j - 1]和s[i - 1]相等;
2、p[j - 1] = '*';
3、p[j - 1]和s[i - 1]不相等;
```

## 动态规划表

```c++
vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));
dp[0][0] = true;
```

## 初始状态

```c++
for (int j = 1; j <= pSize; j++) {
    if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 1];
    }
}
```

## 状态转移

```c++
for (int i = 1; i <= sSize; i++) {
    for (int j = 1; j <= pSize; j++) {
        if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
            dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        } else if (p[j - 1] != s[i - 1]) {
            dp[i][j] = false;
        }
    }
}

return dp[sSize][pSize];
```

