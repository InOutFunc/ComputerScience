# 查找插入的位置

## lower_bound

```cpp
int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= target) {
            r = mid;
        } else if (nums[mid] < target) {
            l = mid + 1;
        }
    }
    return l;
}
```

