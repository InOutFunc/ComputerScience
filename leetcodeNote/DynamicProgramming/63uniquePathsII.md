# 不同的路径II

## 分析

`dp[i][j]`：i - 1， j - 1的不同路径数

```cpp
dp[i][j] = (num[i][j] != 0 ? 0 : dp[i - 1][j] + dp[i][j - 1]);
```

## 合法性

```cpp
if (o.empty() || o[0].empty() || o[0][0] == 1) {
    return 0;
}
```

# dp

```cpp
vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
```

## `dp[1][1]`

```cpp
dp[1][1] = dp[0][1] + dp[1][0];
so:
dp[0][1] = 1 or dp[1][0] = 1;
```

## 状态转移方程

```cpp
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (o[i - 1][j - 1] != 0) {
            continue;
        }
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
}
return dp[m][n];
```

