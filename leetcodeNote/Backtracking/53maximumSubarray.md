# 最大子数组

## 思路

```cpp
dp[i]：以i结尾的最大sum;
dp[i] = nums[i]; dp[i - 1] <= 0;
dp[i] = nums[i] + dp[i - 1];
```

## dp

```cpp
vector<int> dp(nums.size(), 0);
dp[0] = 0;
for (int i = 1; i < nums.size(); i++) {
    if (dp[i - 1] <= 0) {
        dp[i] = nums[i];
    } else {
        dp[i] = nums[i] + dp[i - 1];
    }
}
```

## get max

```cpp
return *max_element(begin(dp), end(dp));
```

