# 最近最少使用页面置换缓存器

## 分析

1、操作

get: 成功或者失败

put: 存在、不存在（超容量）

2、成员变量

容量：int cap;

key-value存储：list<pair<int, int>> l；会时刻更新顺序

key-(key-value)::iterator：unordered_map<int, list<pair<int, int>>::iterator> m；方便通过key找到list中的pair对。

## 初始化容量

```c++
LRUCache (int capacity) {
    cap = capacity;
}
```

## 放置操作

```c++
void put(int key, int value)
{
    auto it = m.find(key);
    if (it != m.end()) {
        l.erase(it->second);
    }
    l.push_front(make_pair(key, value));
    m[key] = l.begin();
    
    if (m.size() > cap) {
        int k = l.rbegin()->first;
        l.pop_back();
        m.erase(k);
    }
}
```

## 查询操作

```c++
int get(int key)
{
    auto it = m.find(key);
    if (it == m.end()) {
        return -1;
    }
    l.splice(l.begin(), l, it->second);
    return it->second->second;
}
```

