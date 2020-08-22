# 最长回文子串

## 思想

`dp[i][j]`表示s(i ~ j)是否是回文串

## 初始状态

```c++
for (int i = 0; i < size; i++) {
    dp[i][i] = true;
}
for (int i = 0; i < size - 1; i++) {
    dp[i][i + 1] = (s[i] == s[i + 1]);
}
```

## 状态转移方程

```c++
for (int k = 2; k < size; k++) { // k表示下标差
    for (int i = 0; i < size - k; i++) {
        dp[i][i + k] = (s[i] == s[i + k]) && dp[i + 1][i + k - 1];
    }
}
```

## 取出最大值

```c++
for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
        if (dp[i][j] && (j - i + 1) > max) {
            max = j - i + 1;
            start = i;
            end = j;
        }
    }
}
return s.substr(start, max);
```

