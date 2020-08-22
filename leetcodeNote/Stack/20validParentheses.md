# 合法的括号

## 思路

相邻的右括号和左括号必须配对，且左括号在右括号前面。

顺序扫描，若是左括号，则加入栈中，若是右括号则和栈中的第一个配对

## 左括号

```c++
for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
        st.push(c);
    }
}
```

## 右括号

```c++
for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
        st.push(c);
    } else {
        if (st.empty()) {
            return false;
        }
        if (c == ')' && st.top() != '(') {
            return false;
        }
        if (c == '}' && st.top() != '{') {
            return false;
        }
        if (c == ']' && st.top() != '[') {
            return false;
        }
        st.pop();
    }
}
return st.empty();
```



