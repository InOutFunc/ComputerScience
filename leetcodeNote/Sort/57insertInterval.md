# 插入区间

## 按顺序将在newInterval左边的区间放入res中

```cpp
while (cur < n && intervals[cur][1] < newInterval[0]) {
    res.push_back(intervals[cur++]);
}
```

## 不在newInterval区间右边，则更新

```cpp
while (cur < n && intervals[cur][0] <= newInterval[1]) {
    newInterval[0] = min(newInterval[0], intervals[cur][0]);
    newInterval[1] = max(newInterval[1], intervals[cur][1]);
    cur++;
}
```

## newInterval放入res

```cpp
res.push_back(newInterval);
```

## 剩余部分放入res

```cpp
while (cur < n) {
    res.push_back(intervals[cur++]);
}
return res;
```

