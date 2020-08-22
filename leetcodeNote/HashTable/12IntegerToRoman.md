# 整数到罗马数字

## 思想

将可能的数字列出来，一个一个减去。同时将数字对应的罗马字符拼接上。

## 数字表和罗马符号

```c++
vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
```

## `val`表一个一个遍历

```c++
for (int i = 0; i < val.size(); i++) {
    while (num >= val[i]) {
        num -= val[i];
        res += str[i];
    }
}
```

