# 正则表达式匹配

## 算法

```c++
f[i][j]: if s[0..i-1] matches p[0..j-1];
if p[j - 1] != '*'
    f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1];
if p[j - 1] == '*'
    x* 0 time, f[i][j - 2];
	x* >= 1 times, x*x: s[i - 1] == x && f[i - 1][j]
```

## 定义`dp`

```c++
vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
```

## 初始状态

```c++
s和p都为空串：
    f[0][0] = true;
s不为空，s为空：
    f[i][0] = false;
s为空，p不为空：
    f[0][j] = j > 1 && p[j - 1] == '*' && f[0][j - 2];
```

## 状态转移方程

```c++
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] != '*') {
            f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        } else {
            f[i][j] = f[i][j - 2] || (f[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        }
    }
}
```

