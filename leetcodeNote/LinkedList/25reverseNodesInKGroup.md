# 反转k个nodes

## 思路

1、计算出nodes的个数

2、剩余nodes个数不小于k

3、pre指向要反转的k个nodes前面一个node，cur后面的节点要插入到pre后面，

## 计算nodes个数

```c++
while (cur = cur->next) {
    num++;
}
```

## 进行k nodes转换

```c++
while (num >= k) {
    
}
```

## 移位

```c++
cur = pre->next;
for (int i = 1; i < k; i++) {
    // pre cur t node
    ListNode *t = cur->next;
    cur->next = t->next;
    t->next = pre->next;
    pre->next = t;
}
pre = cur;
num -= k;
```

