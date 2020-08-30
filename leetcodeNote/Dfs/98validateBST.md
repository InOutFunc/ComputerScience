# 验证二叉搜索树

## 分析

分治：`(root->val > min  && root->val < max) && dfs(root->left, min, root->val) && dfs(root->right, root->val, max);`

终止：`root == nullptr`

## dfs

```cpp
bool isValidBST(TreeNode *root)
{
    return dfs(root, LONG_MIN, LONG_MAX);
}

bool dfs(TreeNode *root, long min, long max)
{
    if (root == nullptr) {
        return true;
    }
    return (root->val > min && root->val < max) && dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
}
```

