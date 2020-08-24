# 爬楼梯

## 分析

```cpp
dp[i]: 爬上i + 1的方法数;
dp[i] = dp[i - 1] + dp[i - 2];
```

## 初始状态

```cpp
dp[0] = 1;
dp[1] = 2;
```

## 状态转移

```cpp
for (int i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
return dp[n - 1];
```

