# 编辑距离

## 分析

```cpp
dp[i][j]: s1[i - 1]变成s2[j - 1]的最小距离;
insert最后一位相同的: dp[i][j] = dp[i][j - 1] + 1;
delete最后一位: dp[i][j] = dp[i - 1][j] + 1;
replace最后一位: dp[i][j] = dp[i - 1][j - 1];
```

## 初始状态

```cpp
horse -> ros
/*
h - ""
ho - ""
horse - ""
"" - r
"" - ro
"" - ros
*/
for (int i = 1; i <= m; i++) {
    dp[i][0] = i;
}
for (int j = 1; j <= n; j++) {
    dp[0][j] = j;
}
```

## 状态转移方程

```cpp
// 从最外层向里面处理
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        } else {
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i], dp[j - 1])) + 1;
        }
    }
}

return dp[m][n];
```

