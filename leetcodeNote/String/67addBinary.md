# 二进制数相加

## 分析

1. 前面补0，两数长度相同。
2. 加数和被加数根据剩余长度来判断
3. 结束时判断进位

## 变量

```cpp
int m = a.size() - 1;
int n = b.size() - 1;
int carry = 0;
string res;
```

## 循环

```cpp
while (m >= 0 || n >= 0) {
    
}
```

## 加数

```cpp
int addend = (m >= 0 ? a[m--] - '0' : 0);
int augend = (n >= 0 ? b[n--] - '0' : 0);
int sum = addend + augend + carry;
```

## 更新

```cpp
carry = sum / 2;
sum = sum % 2;
res = to_string(sum) + res;
```

## 最后是否进位

```cpp
if (carry > 0) {
    res = to_string(carry) + res;
}
return res;
```

