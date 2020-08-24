## 单词搜索

## 分析

```cpp
1. 以每个字母为起点进行搜索;
结果：return bool;
搜索子集: int &level, string word
搜索空间: const vector<vector<char>> &board;
搜索范围：int i, int j, int rows, int cols, vector<bool> &visited;
```

## dfs

```cpp
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        if (dfs(board, visited, level, word, i, j, rows, cols)) {
            return true;
        }
    }
}
```

## 剪枝

```cpp
if ( i < 0 || i >= rows || j < 0 || j >= rows) {
    return false;
}
```

## 回溯

```cpp
if (visited[j + i * cols] || (board[i][j] != word[level - 1])) {
    return false;
}
```

## 搜索

```cpp
if (level == word.size() && board[i][j] == word[level - 1]) {
    return true;
}
level++;
visited[j + i * cols] = true;
bool res = dfs(board, visited, level, word, i - 1, j, rows, cols) ||
    	   dfs(board, visited, level, word, i + 1, j, rows, cols) ||
    	   dfs(board, visited, level, word, i, j - 1, rows, cols) ||
    	   dfs(board, visited, level, word, i, j + 1, rows, cols);
level--;
visited[j + i * cols] = false;
return res;
```



