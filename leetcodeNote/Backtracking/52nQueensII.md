# n皇后II

## dfs

```cpp
void dfs(vector<int> &pos, int row, int &res)
{
    int n = pos.size();
    if (row == n) {
        res++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(pos, row, col)) {
            pos[row] = col;
            dfs(pos, row + 1, res);
            pos[row] = -1;
        }
    }
}
```

## isValid

```cpp
bool isValid(vector<int> &pos, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if (col == pos[i] || (row - col == i - pos[i] || (row + col) == (i + pos[i]))) {
            return false;
        }
    }
    return true;
}
```

