# 添加和查找单词-数据结构设计

## TrieNode节点

```cpp
struct TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &a : child) {
            a = nullptr;
        }
    }
}
```

## 构造函数

```cpp
WordDictionary()
{
    root = new TrieNode();
}
```

## add

```cpp
void addWord(string word)
{
    TrieNode *p = root;
    for (auto &a : word) {
        int i = a - 'a';
        if (p->child[i] == nullptr) {
            p->child[i] = new TrieNode();
        }
        p = p->child[i];
    }
    p->isWord = true;
}
```

## dfs

```cpp
bool search(string word)
{
    return searchWord(word, root, 0);
}
```

## 搜索

```cpp
bool searchWord(string &word, TrieNode *p, int i)
{
    if (i == word.size()) {
        return p->isWord;
    }
    if (word[i] == '.') {
        for (auto &a : p->child) {
            if (a && searchWord(word, a, i + 1)) {
                return true;
            }
        }
        return false;
    } else {
        return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
    }
}
```

