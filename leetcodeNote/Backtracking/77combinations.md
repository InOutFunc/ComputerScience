# 组合

## 分析

```cpp
结果: vector<vector<int>> &combinations;
搜索：vector<int> combination;
层数: int k;
可搜索范围: int n;
可搜索范围：int start;
```

## dfs

```cpp
void combine(vector<vector<int>> &combinations, vector<int> &combination, int start, int n, int k)
```

## 搜索

```cpp
if (k == 0) {
    combinations.push_back(combination);
    return;
}
for (int i = start; i <= n; i++) {
    combination.push_back(i);
    combine(combinations, combination, i + 1, n, k - 1);
    combination.pop_back();
}
```