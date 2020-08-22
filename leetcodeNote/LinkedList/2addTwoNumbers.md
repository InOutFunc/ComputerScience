# 链表的操作技巧

[list](https://zhuanlan.zhihu.com/p/58216817)

[刷完31道链表题的一点总结](https://zhuanlan.zhihu.com/p/66295137)

## 同时遍历2个链表

只要有一个没遍历完，就接着遍历

`while (l1 != nullptr || l2 != nullptr)`

如何更新`l1`和`l2`

``` c++
l1 = (l1 == nullptr ? nullptr : l1->next); 
l2 = (l2 == nullptr ? nullptr : l2->next);
```

## 如何求和

取出`l1`和`l2`的值

```c++
sum += (l1 == nullptr ? 0 : l1->val);
sum += (l2 == nullptr ? 0 : l2->val);
sum += carry;

cur->next = new ListNode(sum);
```

## 边界条件

判断结束时候的`carry`

