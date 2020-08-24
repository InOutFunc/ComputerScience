# 加一

## 分析

1. 从后往前加，如果不是9则加1返回，如果是9则变为0
2. 如果遍历完没有返回，则说明全是9。前面补一个1后面全是0

## 遍历

```cpp
for (int i = digits.size() - 1; i >= 0; i--) {
    if (digits[i] < 9) {
        digits[i]++;
        return digits;
    }
    digits[i] = 0;
}
```

## 返回

```cpp
vector<int> res(digits.size() + 1, 0);
res[0] = 1;

return res;
```

