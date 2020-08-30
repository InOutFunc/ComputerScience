## 恢复二叉搜索树

## 分析

1. 以中序遍历的顺序存储节点指针和节点的值
2. 排序节点的值
3. 将排序后的节点的值依次填入到节点指针中

## 中序遍历

```cpp
void inorder(TreeNode *root, vector<TreeNode *> &list, vector<int> &vals)
{
    if (root == nullptr) {
        return;
    }
    inorder(root->left, list, vals);
    list.push_back(root);
    val.push_back(root->val);
    inorder(root->right, list, vals);
}
```

## 排序

```cp
sort(begin(vals), end(vals));
```

## 填值

```cpp
for (int i = 0; i < vals.size(); i++) {
    list[i]->val = vals[i];
}
```

