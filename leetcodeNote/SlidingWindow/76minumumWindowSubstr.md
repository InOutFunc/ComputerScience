# 最小窗口子串

## 分析

1. 哈希表存储子串
2. 遍历字符串，若字符有效，则count--。哈希表--。
3. 若子串匹配到了，更新minStart和minLen
4. 从左边缩小窗口，直到不包含子串

## 统计子串字符

```cpp
unordered_map<char, int> m;
for (auto c : t) {
    m[c]++;
}
```

## 遍历字符

```cpp
while (end < size) {
    if (m[s[end]] > 0) {
        count--;
    }
    m[s[end]]--;
    end++;
}
```

## 更新start和minLen

```cpp
while (counter == 0) {
    if (end - start < minLen) {
        minStart = start;
        minLen = end - start;
    }
}
```

## 缩小窗口

```cpp
m[s[start]]++;
if (m[s[start]] > 0) {
    counter++;
}
start++;
```

## 返回

```cpp
if (minLen != INT_MAX) {
    return s.substr(minStart, minLen);
}
return "";
```

