# 第一个和最后一个位置

## lower_bound

```c++ 
int lower_bound(vector<int> &nums, int target)
{
    if (nums.empty()) {
        return -1;
    }
    int left = 0;
    int right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

## 第一个位置和最后一个位置后面一个

```c++
int idx1 = lower_bound(nums, target);
int idx2 = lower_bound(nums, target + 1) - 1;
```

## 边界

```c++
if (idx1 == -1 || idx1 == nums.size() || nums[idx1] != target) {
    return {-1, -1};
}
return {idx1, idx2};
```

