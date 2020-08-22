# 全排列序列

## 阶乘

```cpp
vector<int> f(n, 1);
for (int i = 1; i < n; i++) {
    f[i] = i * f[i - 1];
}
```

