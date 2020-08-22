# 字典树

## 节点

```cpp
class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &item : child) {
            item = nullptr;
        }
    }
};
```

每个节点有一个数组指针，哪些不为nullptr，就表示该层哪些位置有节点。节点的值由位置来确定。

bool isWord表示是否是最后一个节点。最后一个节点数组指针全部为空。

## 初始化

```cpp
Trie()
{
    root = new TrieNode();
}
```

## insert

```cpp
void insert(string word)
{
    TrieNode *p = root;
    for (auto &item : word) {
        int i = item - 'a';
        if (p->child[i] == nullptr) {
            p->child[i] = new TrieNode();
        }
        p = p->child[i];
    }
    p->isWord = true;
}
```

## search

```cpp
bool search(string word)
{
    TrieNode *p = root;
    for (auto &item : word) {
        int i = item - 'a';
        if (p->child[i] == nullptr) {
            return false;
        }
        p = p->child[i];
    }
    return p->isWord;
}
```

##  start With

```cpp
bool startWith(string prefix)
{
    TrieNode *p = root;
    for (auto &item : prefix) {
        int i = item - 'a';
        if (p->child[i] == nullptr) {
            return false;
        }
        p = p->child[i];
    }
    return true;
}
```



