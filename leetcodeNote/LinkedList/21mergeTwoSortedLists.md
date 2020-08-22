## 合并两个有序链表

## 思路

l1, l2指向两个链表，会一直更新。

dummy是新链表的头结点，cur指向新链表的尾节点

## 终止条件

```c++
while (l1 && l2) {
    
}
cur->next = l1 ? l1 : l2;
```

## 合并list

```c++
if (l1->val > l2->val) {
    cur->next = l2;
    l2 = l2->next;
} else if (l1->val <= l2->val) {
    cur->next = l1;
    l1 = l1->next;
}
cur = cur->next;
```

