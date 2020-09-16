# 问题 + 思路 + 算法 + 技巧

# for loop

```cpp
1;
for (int i = 0, j = cols - 1; i < row && j >= 0;) {
    
}

for (int i = 0; i < row;) {
    for (int j = cols - 1; j >= 0;) {
        
    }
}
```

一中是单层循环，循环由两个变量i, j同时控制

二中是双层循环，外层由i控制，内层由j控制

## back to front

```cpp
2;
for (int i = length - 1, j = newLen - 1; i >= 0 && j >= 0;) {
    if (str[i] == ' ') {
        str[j--] = '0';
        str[j--] = '2';
        str[j--] = '%';
        i--;
    } else {
        s[j--] = s[i--];
    }
}
```

## stack

```cpp
3;
while (head != nullptr) {
    st.push(head->val);
    head = head->next;
}
while (!st.empty()) {
    res.push_back(st.top());
    st.pop();
}
```

## vector with index

```cpp
4;
TreeNode *divide(const vector<int> &pre, int pLeft, int pRight, const vector<int> &vin, int vLeft, int vRight)
{
    root->left = divide(pre, pLeft + 1, pLeft + leftCnt, vin, vLeft, i - 1);
    root->right = divide(pre, pRight - rightCnt + 1, pRight, vin, i + 1, vRight);
}
```

# 4