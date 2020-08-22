# 移除元素

## 思路

快指针遍历数组，将不需要移除的元素放入到slow指向的数组。

## 新建slow数组

```c++
while (fast < size) {
    if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
    }
    fast++;
}
return slow;
```

