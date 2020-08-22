# 电话号码组合

## 搜索过程

每层的搜索都是该层数字对应的字符串

## `dfs`功能

```c++
dfs(res, digits, current, lettersMap);
res是存储最终结果的;
current表示搜索到某一层;
digits和lettersMap合起来确定搜索的方式;
```

## 终止条件

```c++
void dfs(vector<string> &res, string &digits, string &current, map<char, string> &lettersMap)
{
    if (current.size() == digits.size()) {
        res.push_back(current);
        return;
    }
}
```

## 回溯

```c++
for (char ch : lettersMap[digits[current.size()]]) {
    current.push_back(ch);
    dfs(res, digits, current, lettersMap);
    current.pop_back();
}
```

