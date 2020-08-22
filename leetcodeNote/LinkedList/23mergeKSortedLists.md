# 合并k个有序链表

## 合并两个有序链表递归

```c++
终止条件;
if (l1 == nullptr) {
    return l2;
}
if (l2 == nullptr) {
    return l1;
}
分治法;
if (l1->val <= l2->val) {
    l1->next = merge(l1->next, l2);
    return l1;
} else if (l1->val > l2->val) {
    l2->next = merge(l1, l2->next);
    return l2;
}
```



## 俩俩合并

```c++
for (int i = 1; i < lists.size(); i++) {
    lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
}
return lists.back();
```



