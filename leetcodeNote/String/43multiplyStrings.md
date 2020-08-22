# 字符串相乘

## 思路

```c++
    8 9  <- num2
    7 6  <- num1
-------
    5 4
  4 8
  6 3
5 6
-------
6 7 6 4
```

1、乘积的长度不会超过两个数字的长度之和。

2、错位相加

## 如何更新

每次更新`high`和`low`两个位置上的`val`值，因为每次相乘增加的两位数在`high`和`low`两个位置，

`low`位置上是重新赋值，`high`位置上是加，可能会大于10。在后面一轮中会进位。

## 遍历

```c++
for (int i = m - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
        
    }
}
```

## 相乘

```c++
int mul = (nums[i] - '0') * (nums[j] - '0');
int high = i + j;
int low = i + j + 1;
```

## 更新

```c++
int sum = mul + val[low];
val[high] += sum / 10;
val[low] = sum % 10;
```

## 生成字符串

```c++
for (int i = 0; i < val.size(); i++) {
    if (val[i] != 0 || !res.empty()) {
        res.push_back(val[i] + '0');
    }
}
```

0不能出现在开头

## 边界

```c++
return res.empty() ? "0" : res;
```



