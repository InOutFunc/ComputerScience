# 旋转图片

## 按行上下交换

```c++
for (int row = 0; row < rows / 2; row++) {
    swap(matrix[row], matrix[rows - row - 1]);
}
```

## 按对角线交换

```c++
for (int i = 0; i < rows; i++) {
    for (int j = i + 1; j < cols; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
}
```

