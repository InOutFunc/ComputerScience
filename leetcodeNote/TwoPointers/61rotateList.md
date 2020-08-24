# 旋转链表

## 分析

1. 将链表首位相连
2. 计算指针需要移动的数量
3. 断开链表

## 计算链表长度

```cpp
ListNode *cur = head;
int n = 1;
while (cur->next != nullptr) {
    cur = cur->next;
    n++;
}
```

## 连接链表首位

```cpp
cur->next = head;
```

## 计算需要移动的位置

```cpp
// 1 2 3 4 5
// k = 2
// 4 5 1 2 3
int m = n - k % n;
```

## 移动m到新head的前一个

```cpp
for (int i = 0; i < m; i++) {
    cur = cur->next;
}
```

## 断开链表

```cpp
ListNode *newHead = cur->next;
cur->next = nullptr;
return newHead;
```

