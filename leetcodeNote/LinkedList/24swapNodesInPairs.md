# 交换链表节点

## 终止条件

要确保有两个节点可以进行交换

## 技巧

`pre`指向要交换的节点前面

`first`指向第一个节点

`second`指向第二个节点

## 交换

```c++
while(pre->next && pre->next->next) {
    ListNode *first = pre->next;
    ListNode *second = first->next;
    // pre first second third
    pre->next = second;
    first->next = second->next;
    second->next = first;
    
    pre = first;
    
}
```

