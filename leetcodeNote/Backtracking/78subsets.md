# 子集

## 分析

```cpp
结果: vector<vector<int>> &res;
搜索子集：vector<int> &cur;
搜索空间：const vector<int> &nums;
搜索范围：int start;
```

## dfs

```cpp
void dfs(const vector<int> &nums, int start, vector<int> &cur, vector<vector<int>> &res)
```

## 搜索

```cpp
res.push_back(cur);
for (int i = start; i < nums.size(); i++) {
    cur.push_back(nums[i]);
    dfs(nums, i + 1, cur, res);
    cur.pop_back();
}
```