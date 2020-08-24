# 不同的路径

## 分析

`dp[i][j]`：到达`i, j`的路径数

`dp[m - 1][n - 1]`：到达右下方的路径数

## 初始状态

```cpp
dp[0 ~ n - 1][0] = 1;
dp[0][0 ~ n - 1] = 1;
```

## 状态转移

```cpp
for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
}
```

## 结果

```cpp
return dp[m - 1][n - 1];
```





