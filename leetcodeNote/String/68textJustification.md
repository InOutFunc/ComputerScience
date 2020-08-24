# 文本左右对齐

## 分析

1. 遍历words中的字符，以该字符为起点遍历一行可以放下的字符
2. 计算该行的平均space和多余的extra。若是最后一行space为1，extra为0
3. 将该行数据填充

## 循环

```cpp
for (int i = 0, j; i < words.size(); i = j) {
    // i: 每行从第i个word开始
    // j: 新的一行是第j个word
}
```

## 计算每行的长度

```cpp
int width = 0;
for (j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; j++) {
    width += words[j].size();
}
```

## 计算每行平均空格和多余空格

```cpp
int space = 1;
int extra = 0;
if (j - i != 1 && j != words.size()) {
    space = (maxWidth - width) / (j - i - 1);
    extra = (maxWidth - width) % (j - i - 1);
}
```

## 获取每行内容

```cpp
string line(words[i]);
for (int k = i + 1; k < j; k++) {
    line += string(space, ' ');
    if (extra-- > 0) {
        line += " ";
    }
    line += words[k]
}
line += string(maxWidth - line.size(), ' '); // 非最后一行只有一个元素
```

## 获取res

```cpp
res.push_back(line);
```