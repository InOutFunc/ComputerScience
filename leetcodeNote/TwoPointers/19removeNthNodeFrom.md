# 从末尾移除第n个链表节点

## 思想

通过快慢指针，快指针指向末尾元素时，慢指针指向要删除节点的前一个

##  `dummy node`

```c++
ListNode *dummyNode = new ListNode(0);
dummyNode->next = head;
ListNode *slow = dummyNode;
ListNode *fast = dummyNode;
```

## 快指针先移动`n`

```c++
while (n--) {
    fast = fast->next;
}
此时快慢指针相差n，若快指针移动到末尾为1，慢指针就是n + 1
```

## 同时移动

```c++
while (fast->next != nullptr) {
    fast = fast->next;
    slow = slow->next;
}
终止条件是fast->next为nullptr，此时fast在最后一个节点
```

## 移除下一个节点

```c++
slow->next = slow->next->next;
```



