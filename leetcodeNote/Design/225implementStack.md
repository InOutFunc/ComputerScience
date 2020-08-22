## 用队列来实现栈

## stack

```c++
reference top(); // 栈顶
void pop();
void push(const value_type &value);
bool empty() const;
```

## queue

```cpp
reference front(); // 队首
void pop();
void push(const value_type &value);
bool empty() const;
```

## bool empty()

```cpp
bool empty()
{
    return q.empty();
}
```

## int top()

```cpp
int top()
{
    return q.front()
}
```

## int pop()

```cpp
int pop()
{
    int tmp = q.front();
    q.pop();
    return tmp;
}
```

## void push(int x)

```cpp
void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}
```

