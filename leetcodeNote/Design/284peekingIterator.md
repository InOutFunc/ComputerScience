## 顶端迭代器

## Iterator

```cpp
class Iterator {
    struct Data;
    Data *data;
    int next();
    bool hasNext() const;
}
```

## peeking Iterator

```cpp
int next()
{
    return Iterator::next();
}

bool hasNext() const
{
    return Iterator::hasNext();
}

int peek()
{
    return Iterator(*this).next();
}
```



