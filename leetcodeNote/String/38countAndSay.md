# 计数和读法

## 思路

1、初始是1，读n-1次

2、遍历要读的数字的元素，以该元素为开始

3、获得该元素重复的数量

## 初始和读n-1次

```c++
string res = "1";
while (--n) {
    
}
return res;
```

## 遍历要读的元素

```c++
string cur = "";
for (int i = 0; i < res.size(); i++) {
    
}
res = cur;
```

## 获取重复

```c++
int count = 1;
while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
    count++;
    i++;
}
cur += to_string(count) + res[i];
```



