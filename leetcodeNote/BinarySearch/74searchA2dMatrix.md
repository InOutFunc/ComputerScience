# 搜索二维矩阵

## 分析

```cpp
row行第一个数一维下标：row * cols;
row行最后一个数一维下标: row * cols + cols - 1;

一维下标转换为二维下标：
(row * cols) / cols = row;
(row * cols) % cols = 0;

(row * cols + cols - 1) / cols = row;
(row * cols + cols - 1) % cols = cols - 1;
```

## 二分查找

```cpp
int left = 0;
int right = m * n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (matrix[mid / n][mid % n] == target) {
        return true;
    } else if (matrix[mid / n][mid % n] > target) {
        right = mid - 1;
    } else {
        left = mid + 1;
    }
}
return false;
```

