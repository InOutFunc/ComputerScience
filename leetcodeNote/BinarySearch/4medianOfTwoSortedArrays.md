# 两个排序数组的中点

[Tr](https://www.youtube.com/watch?v=LPFhl65R7ww)

[discuss](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))

## 划分

```c++
      left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[n-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[m-1]
```

left_part为空时，`A[i] = A[0]，A[i - 1] = A[-1]`。

left_part为整个数组时，`A[i] = A[n]，A[i - 1] = A[n - 1]`。

## 确定循环变量

因为`A[0]`和`A[n]`都要取到，因此`int l = 0; int r = n1`

这里是要找到确定的数，`while (l <= r)`

`i = (l + r) / 2`，

为了奇数和偶数统一，`j = (n1 + n2 + 1) / 2 - i`

## trick

提前将边界条件计算出，避免后续计算时再去判断

```c++
maxLx = (i == 0) ? INT_MIN : nums1[i - 1];
minRx = (i == n1) ? INT_MAX : nums1[i];

maxLy = (j == 0) ? INT_MIN : nums2[j - 1];
minRy = (j == n2) ? INT_MAX : nums2[j];
```

## 二分判断

```c++
满足条件：
if (maxLx <= minRy && maxLy <= minRx) {
	if ((n1 + n2) % 2 == 0) {
        return (std::max(maxLx, maxLy) + std::min(minRx, minRy)) / 2.0;
    } else {
        return std::max(maxLx, maxLy);
    }
}
i在i的左边：
else if (maxLx > minRy) {
    r = i - 1;
}
i在i的右边:
else (maxLy > minRx) {
    l = i + 1;
}
```

