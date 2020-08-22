# 群组错位词

## 思路

```c++
  aet: ["ate","eat","tea"],
  ant: ["nat","tan"],
  abt: ["bat"]
```

对每个字符串，排序，将排序后的字符串作为`key`，原字符串作为`value`加入到`hash table`中。最后从`hash table`中读出`vector<vector<string>>`;

## 遍历存入哈希表

```c++
for (const auto &item : strs) {
    string key = item;
    sort(key.begin(), key.end());
    hash[key].push_back(item);
}
```

## 读取结果

```c++
for (const auto &item : hash) {
    res.push_back(item.second);
}
```



