# 回文数字

## 思路

将数字切割成两半，后半逆序，看两半是否相同。多的一位在后半部分。

## 判断

```c++
if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
}
```

## 取出前半部分和后半部分

```c++
while (x > revertNum) {
    revertNum = revertNum * 10 + x % 10;
    x /= 10;
}
```

## 判断

```c++
return x == revertNum || x == revertNum / 10;
```