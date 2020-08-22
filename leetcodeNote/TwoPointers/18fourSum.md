## 四数之和

## 固定前面两个数

```c++
for (int i = 0; i < n - 3; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
    }
    for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
            continue;
        }
        int left = j + 1;
        int right = n - 1;
    }
}
```

## 双指针搜索

```c++
while (left < right) {
    int sum = nums[i] + nums[j] + nums[left] + nums[right];
    if (sum == target) {
        res.push_back({nums[i], nums[j], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (right > left && nums[right] == nums[right - 1]) right--;
        left++;
        right--;
    } else if (sum < target) {
        left++;
    } else if (sum > target) {
        right--;
    }
}
```

