## 序列化和反序列化

## istringstream

```cpp
>>
```

## ostringstream

```cpp
<<
```

## serialize

```cpp
string serialize(TreeNode *root)
{
    ostringstream out;
    serialize(root, out);
    return out.str();
}
```

## serialize dfs

```cpp
void serialize(TreeNode *root, ostringstream &out)
{
    if (root != nullptr) {
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}
```

## deserialize

```cpp
TreeNode *deserialize(string data)
{
    istringstream in(data);
    return deserialize(in);
}
```

## deserialize dfs

```cpp
TreeNode *deserialize(istringstream &in)
{
    string val;
    in >> val;
    if (val == "#") {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}
```



