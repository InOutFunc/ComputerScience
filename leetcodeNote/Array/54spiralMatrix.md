# 旋转矩阵

## 分析

```cpp
剩余有效方块通过startRow, endRow, startCol, endCol四个变量表示;
遍历的方向通过dir变量表示
```

## 变量定义

```cpp
int startRow = 0;
int endRow = matrix.size() - 1;
int startCol = 0;
int endCol = matrix[0].size() - 1;
int dir = 0;
```

## 遍历搜索

```cpp
while (startRow <= endRow && startCol <= endCol)
{
    switch(dir) {
        case 0:
            for (int col = startCol; col <= endCol; col++) {
                res.push_back(matrix[startRow][col]);
            }
            startRow++;
            break;
        case 1:
            for (int row = startRow; row <= endRow; row++) {
                res.push_back(matrix[row][endCol]);
            }
            endCol--;
            break;
        case 2:
            for (int col = endCol; col >= startCol; col--) {
                res.push_back(matrix[endRow][col]);
            }
            endRow--;
            break;
        case 3:
            for (int row = endRow; row >= startRow; row--) {
                res.push_back(matrix[row][startCol]);
            }
            startCol++;
            break;
    }
    dir = (dir + 1) % 4;
}
```

