# 合法的数字

## 初始状态

```cpp
int curState = 1;
```

## 转移方式

```cpp
for (auto c : s) {
    if (c >= '0' && c <= '9') {
        transition = "digit";
    } else if (c == '-' || c == '+') {
        transition = "sign";
    } else if (c == ' ') {
        transition = "blank";
    } else if (c == '.') {
        transition = "dot";
    } else if (c == 'e') {
        transition = "e";
    } else {
        return false;
    }
}
```

## 当前状态查找转移方式

```cpp
auto it = states[curState].find(transition);
if (it == states[curState].end()) {
    return false;
} else {
    curState = it->second;
}
```

## 状态转移表

```cpp
static vector<unordered_map<string, int>> states = {
    {}, // state 0
}
state 1: nothing;
blank, 1; sign, 2; digit, 3; dot, 4;

state 2: +;
digit, 3; dot, 4;

state 3: +1; // . is dif with 1.
digit, 3; dot, 5; e, 6; blank 9;

state 4: .;
digit, 5;

state 5: .4;
digit, 5; e, 6; blank 9;

state 6: .4e;
sign 7; digit 8;

state 7: .4e-;
digit 8;

state 8: .4e-1;
digit 8; blank 9;

state 9;
blank 9;
```

## 结束状态判断

```cpp
if (curState == 3 || curState == 5 || curState == 8 || curState = 9) {
    return true;
} else {
    return false;
}
```

