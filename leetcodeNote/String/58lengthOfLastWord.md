# 最后一个单词

## 去掉尾部的空格

```cpp
while (tail >= 0 && s[tail] == ' ') {
    tail--;
}
```

## 遍历到空格截止

```cpp
while (tail >= 0 && s[tail] != ' ') {
    tail--;
    res++;
}
```

