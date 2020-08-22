# 最小栈

## 分析

方法：

push：

pop：注意stack.pop()返回值是void

top:

getMIn：返回栈中的最小值

变量：

stack<int> s1：存储正常的栈

stack<int> s2：存当前最小值

## push

```c++
void push(int x)
{
    s1.push(x);
    if (s2.empty() || x <= x2.top()) {
        s2.push(x);
    }
}
```

# pop

```c++
void pop()
{
    if (s1.top() == s2.top()) {
        s2.pop();
    }
    s1.pop();
}
```

# top

```c++
int top()
{
    return s1.top();
}
```

# getMin

```c++
int getMin()
{
    return s2.top();
}
```

