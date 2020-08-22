# 两个整数相除

## 思路

16 / 3 = 4 * 3 + 1 * 3

每次循环都重新开始除

## 边界

```c++
if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
}
```

## 绝对值和符号

```c++
int sign = divident > 0 ^ divisor > 0 ? - 1 : 1;
long dvd = labs(dividend);
long dvs = labs(divisor);
```

## 更新`dvd`

```c++
while (dvd >= dvs) {
    ...;
    dvd -= temp;
    res += m;
}
```

## 移位除

```c++
while (dvd >= dvs) {
    long temp = dvs;
    int m = 1;
    while ((temp << 1) <= dvd) {
        temp <<= 1;
        m <<= 1;
    }
    dvd -= temp;
    res += m;
}
```

## 结果

```c++
return sign * ans;
```

