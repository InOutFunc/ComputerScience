# 全排列II

## 判断同一个是否使用

```c++
if (used[i])
```

 ## 同一层不要相同

```c++
if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
```

## 搜索

```c++
void dfs(const vector<int> &nums, vector<int> &cur, vector<bool> &used, vector<vector<int>> &res)
{
    if (cur.size() == nums.size()) {
        res.push_back(cur);
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            used[i] = true;
            res.push_back(nums[i]);
            dfs(nums, cur, used, res);
            res.pop_back();
            used[i] = false;
        }
    }
}
```



