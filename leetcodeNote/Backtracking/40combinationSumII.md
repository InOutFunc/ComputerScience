# 组合和II

## 分析

同一个数字只能用一次

不可重复

## 搜索过程

```c++
void dfs(const vector<int> &candidates, int start, vector<int> &cur, int target, vector<vector<int>> &res)
{
    if (target < 0) {
        return;
    }
    if (target == 0) {
        res.push_back(cur);
    } else {
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            dfs(candidates, i + 1, cur, target - candidates[i], res);
            cur.pop_back();
        }
    }
}
```

`i > start`当在下一层时，可以与前面相同

`candidates[i] == candidates[i - 1]`表示同一层只有第一个有效

