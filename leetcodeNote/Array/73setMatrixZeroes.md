# 矩阵赋零

## 分析

1. 判断第一列是否有0
2. 判断第一行是否有0
3. 判断第i行和第j列是否需要清零(i > 0, j > 0)，记录在第0行和第0列上
4. 除去第0行和第0列元素清零
5. 第0列清0
6. 第0行清0

## 判断第0列是否有0

```cpp
for (int i = 0; i < m; i++) {
    if (matrix[i][0] == 0) {
        colZero = true;
    }
}
```

## 判断第0行是否有0

```cpp
for (int j = 0; j < n; j++) {
    if (matrix[0][j] == 0) {
        rowZero = true;
    }
}
```

## 判断第i行和第j列是否有0

```cpp
for (int i = 1; i < m; i++) {
    for (int j = 1; j < m; j++) {
        if (matrix[i][j] == 0) {
            matrix[0][j] = 0; // 不仅起记录作用，还将本身更新了
            matrix[i][0] = 0;
        }
    }
}
```

## 更新

```cpp
for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0 || matrix[i][0] == 0) {
            matrix[i][j] == 0;
        } 
    }
}
```

## 更新第0行

```cpp
if (rowZero) {
    for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
    }
}
```

## 更新第0列

```cpp
if (colZero) {
    for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
    }
}
```





