# 实现strStr()

## 思路

遍历haystack的每个元素，看该元素开始的子串是否符合条件

## 边界条件

```c++
if (needle.empty()) {
    return 0;
}
int m = haystack.size();
int n = needle.size();
if (m < n) {
    return -1;
}
for (int i = 0; i <= m - n; i++)
```

## 按位判断

```c++
for (int i = 0; i <= m - n; i++) {
    int j = 0;
    for (int j = 0; j < n; j++) {
        if (haystack[i + j] != needle[j]) {
            break;
        }
    }
    if (j == n) {
        return i;
    }
}
return -1;
```

