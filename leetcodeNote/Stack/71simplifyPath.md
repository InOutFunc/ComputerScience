# 简化路径

## 分析

1. 从path中按/分割读，若是""或者"."，则什么都不操作
2. 若是".."，并且v中不为空，pop()
3. 若是路径，则push()

## 变量定义

```cpp
string t;
istringstream ss(path);
stack<string> v;
```

## 读取内容

```cpp
while (getline(ss, t, '/')) {
	if (t == "" || t == ".") {
        continue;
    }
    if (t == ".." && !v.empty()) {
        v.pop();
    } else if (t != "..") {
        v.push(t);
    }
}
```

## 从栈中重建路径

```cpp
while (!v.empty()) {
    res = "/" + v.top() + res;
    v.pop();
}
```

## 边界返回

```cpp
return res.empty() ? "/" : res;
```

