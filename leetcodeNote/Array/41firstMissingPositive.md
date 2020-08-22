# 第一个缺失的正数

## 思路

遍历数组，在该位置上不断交换，直到该位置不满足条件为止。

每次都是为了将`nums[i]`换到正确的位置，因此当`nums[i]`不需要换时终止

```c++
num[i] <= 0;
nums[i] > n;
nums[i] == nums[nums[i] - 1];
```

## 遍历交换

```c++
for (int i = 0; i < n; i++) {
    while (nums[i] > 0 && nums[i] <= n && nums[i] == nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
    }
}
```

## 查找缺失

```c++
for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1) {
        return i + 1;
    }
}
return n + 1;
```

