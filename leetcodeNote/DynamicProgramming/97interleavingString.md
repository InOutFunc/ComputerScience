# 交织相错的字符串

## 分析

1. `dp[i][j]`表示`s1[i - 1]`和`s2[j - 1]`是否可以组成`s3[i + j - 1]`
2. s2为空时，`dp[i][0]`由`dp[i - 1][0]`决定
3. s1为空时，`dp[0][j]`由`dp[0][j - 1]`决定
4. s1和s2均不为空时，s3最后一个要么和s1相同，要么和s2相同

## 边界条件

```cpp
if ((s1.size() + s2.size()) != s3.size()) {
    return false;
}
```

## 定义dp

```cpp
vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
```

## 初始状态

```cpp
dp[0][0] = true;
for (int i = 1; i <= s1.size(); i++) {
    dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
}
for (int j = 1; j <= s2.size(); j++) {
    dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
}
```

## 状态转移

```cpp
for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
    }
}
```

## 返回值

```cpp
return dp[s1.size()][s2.size()];
```

