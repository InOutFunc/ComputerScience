# 存储雨水

## 思路

从左右两端往中间扫，求每个单元格上能存储多少水量。

1、计算左还是右

计算小的那个

2、为什么另一边不会漏

因为既然可以走到这一步，右边肯定存在比左边`maxLeft`要大或等于，否则走不到这一步

## 计算左边

```c++
while (left < right) {
    if (A[left] <= A[right]) {
        if (A[left] >= maxLeft) {
            maxLeft = A[left];
        } else {
            sum += maxLeft - A[left];
        }
        left++;
    }
}
```

## 计算右边

```c++
else {
    if(A[right] >= maxRight) {
        maxRight = A[right];
    } else {
        sum += maxRight - A[right];
    }
    right--;
}
```

