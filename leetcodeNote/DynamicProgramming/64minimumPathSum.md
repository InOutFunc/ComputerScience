# 最小路径和

## 分析

```cpp
dp[i][j]: i, j上的最小路径和;
dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
```

## 初始状态

```cpp
dp[0][0] = grid[0][0];
dp[0][j] = dp[0][j - 1] + grid[0][j];
dp[i][0] = dp[i - 1][0] + grid[i][0];
```

## 状态转移

```cpp
for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]
    }
}
```

## 返回值

```cpp
return dp[m - 1][n - 1];
```



