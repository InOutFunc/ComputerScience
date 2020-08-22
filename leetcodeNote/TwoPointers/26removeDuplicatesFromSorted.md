# 在排序数组中去重



## 思路

`cur`遍历数组

`pre`指向新数组最后一个元素，由于数组是排序的，也可以起到判断重复的作用

## 判重

```c++
while (cur < n) {
    if (nums[pre] == nums[cur]) {
        cur++;
    }
}
```

## 增加新元素

```c++
while (cur < n) {
    if (nums[pre] == nums[cur]) {
        cur++;
    } else {
        nums[++pre] = nums[cur++];
    }
}
```

## 返回个数

```c++
return nums.empty() ? 0 : (pre + 1);
```

