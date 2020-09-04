# 二叉树的先序遍历

## 分析

1. 根节点
2. 先序遍历左子树
3. 先序遍历右子树

## 递归

```cpp
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    dfs(root, nodes);
    return nodes);
}

void dfs(TreeNode *root, vector<int> &res)
{
    if (root == nullptr) {
        return;
    }
    res.push_back(root->val);
    dfs(root->left, res);
    dfs(root->right, res);
}
```

## 迭代

```cpp
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *p = root;
    while (!st.empty() || p != nullptr) {
        if (p != nullptr) {
            st.push(p);
            res.push_back(p->val);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
}
```

