# zigzag变换

## 思想

最外层从`i`开始遍历，相当于每一轮开始的起点

```c++
while (i < n)
```

内层第一个遍历从上往下

```c++
for (int pos = 0; pos < numRows && i < n; pos++) {
    vec[pos] += s[i++]
}
```

第二个遍历从下往上

```c++
for (int pos = numRows - 2; pos >= 1 && i < n; pos--) {
    vec[pos] += s[i++];
}
```

从三个`string`中读出结果

```c++
for (const auto &str : vec) {
    res += str;
}
```