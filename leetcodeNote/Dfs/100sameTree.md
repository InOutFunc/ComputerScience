# 相同的树

## 分析

分治：`p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)`

终止条件: `p == nullptr || q == nullptr`

## ## dfs

```cpp
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr || q == nullptr) {
        return p == q;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```



