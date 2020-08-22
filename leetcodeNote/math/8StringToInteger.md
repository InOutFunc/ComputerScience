# 字符串转整数

## 跳过开头的空格

```c++
while (i < n && str[i] == ' ') {
    i++;
}
```

## 是否有正负号

```c++
if (i < n && (str[i] == '+' || str[i] == '-')) {
    sign = (str[i++] == '+') ? 1 : -1;
}
```

## 按顺序读取数字

```c++
while (i < n && str[i] >= '0' && str[i] <= '9') {
    if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    base = 10 * base + (str[i++] - '0');
}

INT_MAX: +~47;
INT_MIN: -~48;
```

最大的整数可以表示到7，因此；判断中用>7。若是负数，-~48到溢出都是INT_MIN。若是正数，溢出是INT_MAX。

