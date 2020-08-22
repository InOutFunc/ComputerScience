# 解数独

## 搜索方法

从每个空格开始搜，搜下一个空格。

每个空格可以填1-9，填入时需要校验是否合法

## 判断某个位置填入数字

```c++
bool isValid(vector<vector<char>> &board, int r, int c, char d)
{
    for (int row = 0; row < 9; row++) {
        if (board[row][c] == d) {
            return false;
        }
    }
    for (int col = 0; col < 9; col++) {
        if (board[r][col] == d) {
            return false;
        }
    }
    for (int row = (r / 3) * 3; row < (r / 3 + 1) * 3; row++) {
        for (int col = (c / 3) * 3; col < (c / 3 + 1) * 3; col++) {
            if (board[row][col] == d) {
                return false;
            }
        }
    }
    return ture;
}
```

## 回溯搜索

```c++
bool solve(vector<vector<char>> &board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char d = '1'; d <= '9'; d++) {
                    if (isValid(board, r, c, d)) {
                        board[r][c] = d;
                        if (solve(board)) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }
    return false;
}
```



