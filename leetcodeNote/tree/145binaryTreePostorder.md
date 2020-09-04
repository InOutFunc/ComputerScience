## 二叉树的后续遍历

## 分析

1. 后续遍历左子树
2. 后续遍历右子树
3. 根节点

## 递归

```cpp
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    dfs(root, nodes);
    return nodes;
}

void dfs(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) {
        return;
    }
    dfs(root->left, res);
    dfs(root->right, res);
    res.push_back(root->val);
}
```

##  迭代

