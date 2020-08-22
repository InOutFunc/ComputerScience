# 最长公共前缀

## 求最短串的长度

```c++
int minLen = strs[0].size();
for (int i = 1; i < strs.size(); i++) {
    minLen = std::min(minLen, strs[i].size());
}
```

## 比较每一位是否相同

```c++
for (int i = 0; i < minLen; i++) {
    for (int j = 1; j < strs.size(); j++) {
        if (strs[0][i] != strs[j][i]) {
            return res;
        }
    }
    res.push_back(strs[0][i]);
}
```

