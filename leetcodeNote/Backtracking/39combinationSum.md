# 组合和

## 分析

搜索的过程中，每个数字可以重复

因为是组合，以3开始搜时，2不可以再搜索了

因为可以重复，以3开始搜时，可以接着搜索3

## `dfs`

```c++
dfs(candidates, 0, cur, target, res);
candidates: 获取搜索的内容;
0: 可以搜索的内容的起点;
cur: 存储当前搜索到的内容;
target: 还剩下的数目;
res: 最终结果;
```

## 搜索

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
            cur.push_back(candidates[i]);
            dfs(candidates, i, cur, target - candidates[i], res);
            cur.pop_back();
        }
    }
}
```

