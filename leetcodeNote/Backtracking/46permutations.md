# 排列

判断是否可以搜索

```c++
if (std::find(cur.begin(), cur.end(), nums[i]) != cur.end())
```

## 搜索

```c++
void dfs(const vector<itn> &nums, vector<int> &cur, vector<vector<int>> &res)
{
    if (cur.size() == nums.size()) {
        res.push_back(cur);
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (find(cur.begin(), cur.end(), nums[i])) {
                continue;
            }
            cur.push_back(nums[i]);
            dfs(nums, cur, res);
            cur.pop_back();
        }
    }
}
```

