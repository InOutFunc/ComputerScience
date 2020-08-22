# 最相近的三数之和

## 思想

固定一个数字循环，在这个数后面的`nums`中使用双指针法，更新最小距离

## 初始最小值

```c++
int delta = nums[0] + nums[1] + nums[2] - target;
```

## 固定最小值

```c++
for (int i = 0; i < nums.size() - 2; i++) {
    int start = i + 1;
    int end = nums.size() - 1;
}
```

## 双指针更新最小距离

```c++
while (start < end) {
    int newDelta = nums[i] + nums[start] + nums[end] - target;
    if (newDelta == 0) {
        return target;
    }
    if (std::abs(delta) > std::abs(newDelta)) {
        delta = newDelta;
    }
    if (newDelta < 0) {
        start++;
    } else if (newDelta > 0) {
        end--;
    }
}
```





