# 无重复字符最长子串

[fucking algorithm](https://github.com/labuladong/fucking-algorithm)

## 窗口

左右指针之间的元素放入窗口中，因为要计算元素的数量，因此使用`map`来存储。

```c++
while (right < s.size()) {
    window[s[right]]++;
    right++;
}
```

## 窗口无重复

在每次讲right加入后，要判断window中window[right]是否重复。通过右移left来缩小窗口。

```c++
while (window[s[right - 1]] > 1) {
    windown[s[left]]--;
    left++;
}
```

每次遍历right都更新最大值

```c++
res = std::max(ret, right - left); // right已经++了
```

