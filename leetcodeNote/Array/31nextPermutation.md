# 下一个排列

## 思路

13521

从后往前找，521是这三个数能组成的最大的数

从521中找到第一个比3大的数，交换位置。

剩下的数是从大到小的，反转一下即可

## 找到第一个比前一个数小的下标

```c++
int n = nums.size();
int k = 0;
int l = 0;
for (k = n - 2; k >= 0; k--) {
    if (nums[k] < nums[k + 1]) {
        break;
    }
}
```

## 321这种情况

```c++
if (k < 0) {
    reverse(nums.begin(), nums.end());
}
```

## 找到要交换的位置

```c++
for (l = n - 1; l > k; l--) {
    if (nums[l] > nums[k]) {
        break;
    }
}
swap(nums[k], nums[l]);
reverse(nums.begin() + k + 1, nums.end());
```

