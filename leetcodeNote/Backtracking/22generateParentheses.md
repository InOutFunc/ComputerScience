# 生成括号

## 搜索方式

每一层可以选择(，或者)。

left表示还剩下的(， right表示还剩下的)。

在left == 0和right == 0是结束

## 结束条件

```c++
if (left == 0 && right == 0) {
    res.push_back(cur);
    return;
}
```

## 每层的搜索

```c++
if (left > 0) {
    cur.push_back('(');
    dfs(res, cur, left - 1, right);
    cur.pop_back();
}
if (right > left) {
    cur.push_back(')');
    dfs(res, cur, left, right - 1);
    cur.pop_back();
}
```

