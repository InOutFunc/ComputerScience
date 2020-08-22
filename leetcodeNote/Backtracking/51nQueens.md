# n皇后

## 思路

按行来搜索，每次搜索有9种选择。

## dfs

```c++
void dfs(int curRow, vector<string> &cur, vector<vector<string>> &res)
{
    
}
```

## 终止条件

```c++
void dfs(int curRow, vector<string> &cur, vector<vector<string>> &res)
{
    if (curRow == cur.size()) {
        res.push_back(cur);
        return;
    }
}
```

## 搜索

```c++
for (int i = 0; i < n; i++) {
    if (isValid(cur, curRow, i)) {
        cur[curRow][i] = 'Q';
        dfs(curRow + 1, cur, res);
        cur[curRow][i] = '.';
    }
}
```

# 校验合法性

```cpp
bool isValid(vector<string> &cur, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if (cur[i][col] = 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (cur[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i > = 0 && j < cur.size(); --i, ++j) {
        if (cur[i][j] == 'Q') {
            return false;
        }
    }
    
}
```

只校验`row`的上半部分