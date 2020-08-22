## 跳跃游戏

## 分析

将最后一个位置标记为truePos，从后向前扫描，若扫描到的位置可以到达truePos，则更新该位置为truePos。因为前面的元素若能到之前的truePos，则更能到达更新后的truePos。

## greedy

```cpp
int truePos = nums.size() - 1;
for (int i = nums.size() - 2; i >= 0; i--) {
    if (nums[i] + i >= truePos) {
        truePos = i;
    }
}
```

## return

```cpp
return truePos == 0;
```