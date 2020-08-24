# 移除重复元素II

## 分析

1 1 1 2 2 3

cur指向的是已排好部分的后面一位。

若num和cur - 2相同，则必定重复了

cur < 2时，必定不会重复

```cpp
for (int num : nums) {
    if (cur < 2 || num > nums[cur - 2]) {
        nums[cur++] = num;
    }
}
return cur; // 因为cur++了，下标+1就是个数了
```



