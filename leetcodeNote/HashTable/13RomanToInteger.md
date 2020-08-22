# 罗马字符转整数

## 思想

和整数转罗马字符本质上一致。整数可以直接将40， 90等表示出来。而罗马字符的40和90是2个字符，因此需要特殊判断下。

## 原始结构

```c++
for (int i = s.size() - 1; i >= 0; i--) {
    char c = s[i];
    switch (c) {
        case 'I' :
            res += 1;
            break;
        case 'V' :
            res += 5;
            break;
        case 'X' :
            res += 10;
            break;
        case 'L' :
            res += 50;
            break;
        case 'C' :
            res += 100;
            break;
        case 'D' :
            res += 500;
            break;
        case 'M' :
            res += 1000;
            break;
    }
}
```

加上40，90等情况

```c++
for (int i = s.size() - 1; i >= 0; i--) {
    char c = s[i];
    switch (c) {
        case 'I' :
            res += (res >= 5 ? -1 : 1);
            break;
        case 'V' :
            res += 5;
            break;
        case 'X' :
            res += 10 * (res >= 50 ? -1 : 1);
            break;
        case 'L' :
            res += 50;
            break;
        case 'C' :
            res += 100 * (res >= 500 ? -1 : 1);
            break;
        case 'D' :
            res += 500;
            break;
        case 'M' :
            res += 1000;
            break;
    }
}
```

