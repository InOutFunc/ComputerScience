# 合并区间

## 区间排序

```cpp
sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
})
```

## 初始化res

```cpp
res.push_back(intervals[0]);
```

## 区间和res不重合

```cpp
for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i].front() > res.back().back()) {
        res.push_back(intervals[i]);
    }
}
```

## 区间和res重合并且没有被包含

```cpp
else {
    if (res.back().back() < intervals[i].back()) {
        res.back().back() = intervals[i].back();
    }
}
```