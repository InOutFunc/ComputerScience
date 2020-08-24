# 开根号

## 分析

1. 边界到x / 2 + 1即可
2. 先找到第一个n * n > x的点，然后返回n - 1，也就是upper_bound

## upper_bound

```cpp
int left = 0;
int right = x / 2 - 1;
while (left < right) {
    int mid = left + (right - left) / 2;
    if (mid > x / mid) {
        right = mid;
    } else {
        left = mid + 1;
    }
}
return left - 1;
```