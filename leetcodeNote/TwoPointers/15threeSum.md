# 三数之和

## 思想

先排序，固定一个数，然后在后面的数中查找。每次固定的数不同，因此不会重复。

## 初始判断

```c++
sort(nums.begin(), nums.end());
if (nums.empty() || nums.back() < 0 || nums.front() > 0) {
    return {};
}
```

## 固定数

```c++
for (int k = 0; k < nums.size() - 2; k++) {
    if (nums[k] > 0) {
        break;
    }
    if (k > 0 && nums[k] == nums[k - 1]) {
        continue;
    }
    int target = 0 - nums[k];
    int i = k + 1;
    int j = nums.size() - 1;
}
```

## 双指针

```c++
while (i < j) {
    if (nums[i] + nums[j] == target) {
        res.push_back({nums[k], nums[i], nums[j]});
        while (i < j && nums[i] == nums[i + 1]) i++;
        while (i < j && nums[j] == nums[j - 1]) j--;
        i++;
        j--;
    } else if (nums[i] + nums[j] < target) {
        i++;
    } else if (nums[i] + nums[j] > target) {
        j--;
    }
}
```





