## 寻找数据流的中位数

## priority_queue

```cpp
const_reference top() const;
void push(const value_type &value);
void pop();
```

## 成员

```cpp
priority_queue<long> small;
最大堆、存着数据流中较小的一半
priority_queue<long> large;
最大堆、存着数据流中较大的一半、但是存的是相反数
```

## findMedian()

```cpp
double findMedian()
{
    if (small.size() > large.size()) {
        return small.top();
    }
    return (small.top() - large.top()) / 2.0;
}
```

## addNum

```cpp
新加的数需要放入small中比较，才能取出需要放入到large中。这样small和large才是合法的最大堆。
void add(int num)
{
    small.push(num);
    large.push(-small.top());
    small.pop();
}
需要保持small和large相等或者大于1
if (small.size() < large.size()) {
    small.push(-large.top());
    large.pop():
}
```

