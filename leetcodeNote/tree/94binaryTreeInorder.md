# 二叉树中序遍历

## 分析

1. 中序遍历左子树
2. 根
3. 中序遍历右子树

标准的分支思想

## 递归

```cpp
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}

void inorder(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
```

## 栈

```cpp
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (!s.empty() || p != nullptr) {
        if (p != nullptr) {
            s.push(p);
            p = p->next;
        } else {
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }
    
    return res;
}
```

