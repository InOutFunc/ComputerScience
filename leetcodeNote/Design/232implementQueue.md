# 用栈实现队列

# shiftStack()

```cpp
void shiftStack()
{
    while (!input.empty()) {
        output.push(input.top());
        input.pop();
    }
}
```



## push

```cpp
void push(int x)
{
    input.push(x);
}
```



## pop

```cpp
if (output.empty()) {
    shiftStack();
}
int tmp = output.top();
output.pop();
return tmp;
```



## peek()

```cpp
int peek()
{
    if (output.empty()) {
        shiftStack();
    }
    return output.top();
}
```



## empty()

```cpp
bool empty()
{
    return input.empty() && output.empty();
}
```



