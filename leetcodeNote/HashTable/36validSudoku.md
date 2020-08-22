# 有效的数独

## 思路

对每一个有效的数字，判断其所在的行、列和块是否重复

通过该行该数字、该列该数字和该块该数字的数量来判断

## 哈希表

```c++
vector<vector<int>> rows(9, vector<int>(9));
vector<vector<int>> cols(9, vector<int>(9));
vector<vector<vector>>> blocks(9, vector<vector<int>>(9, vector<int>(9)));
```

通过值来判断关联

## 遍历每点判断

```c++
for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.') {
            int number = board[r][c] - '1';
            if (rows[r][number]++) {
                return false;
            }
            if (cols[c][number]++) {
                return false;
            }
            if (blocks[r / 3][c / 3][number]++) {
                return false;
            }
        }
    }
}
return true;
```

