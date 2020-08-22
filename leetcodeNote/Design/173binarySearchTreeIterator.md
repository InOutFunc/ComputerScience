# 173 二叉搜索树迭代器

## 分析

root节点的左节点一路加进栈中，然后取栈中第一个Node，取到该node说明该node的左子树没有了，取完后将其右子树按同样的方式加入

# 左边内容全部加入

```c++
void pushAll(TreeNode *node)
{
    while (node != nullptr) {
        nodeStack.push(node);
        node = node->left;
    }
}
```

## 初始化root

```c++
BSTIterator(TreeNode *root)
{
    pushAll(root);
}
```

## 判断是否末尾

```cpp
bool hasNext()
{
    return !nodeStack.empty();
}
```

## 下一个元素

```cpp
int next()
{
    TreeNode *tmp = nodeStack.top();
    nodeStack.pop();
    pushAll(tmp->right);
    return tmp->val;
}
```

