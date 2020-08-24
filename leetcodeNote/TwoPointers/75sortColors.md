# 颜色排序

## 分析

1. [left, right]是还没有排好序的
2. 遍历数组，若当前元素是0，则和left交换。0是排好的，left需要加1。left在right右边，不可能是2，因此index也需要加1。
3. 若当前元素是2，则和right交换。right--。

## 双指针

```cpp
int left = 0;
int right = nums.size() - 1;
int index = 0;
// invariants: A[0..lo-1] are less than pivot 1, A[lo..i-1] equal, A[hi+1..end] greater
```

## 遍历

```cpp
while (index <= right) {
    if (nums[index] == 0) {
        swap(nums[left], nums[index]);
        left++;
        index++;
    } else if (nums[index] == 2) {
        swap(nums[right], nums[index]);
        right--;
    } else {
        index++;
    }
}
```