# 包含所有单词的子串

## 思路

遍历字符串，以每个遍历到的元素为起点取子串，看是否符合条件。

## 边界条件

```c++
if (s.empty() || words.empty()) {
    return {};
}
```

## `words`的组成存入哈希表

```c++
int n = words.size();
int len = words[0].size();
unordered_map<string, int> wordCnt;
for (auto &word : words) {
    ++wordCnt[word];
}
```

## 遍历每个元素

```c++
for (int i = 0; i <= (int)s.size() - n * len; i++) {
    
}
```

## 内层判断

```c++
for (int i = 0; i <= (int)s.size() - n * len; i++) {
    unordered_map<string, int> strCnt;
    int j = 0;
    for (j = 0; j < n; j++) {
        string t = s.substr(i + j * len, len);
        if (wordCnt.count(t) == 0) {
            break;
        }
        ++strCnt[t];
        if (strCnt[t] > wordCnt[t]) {
            break;
        }
    }
    // 非break出来的
    if (j == n) {
        res.push_back(i);
    }
}
return res;
```

