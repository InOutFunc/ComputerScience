#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        string res = out.str();
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
private:
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
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main()
{
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n1(1);
    n3.left = &n4;
    n3.right = &n5;
    n1.left = &n2;
    n1.right = &n3;

    Codec codec;
    string tmp = codec.serialize(&n1);
    TreeNode *root = codec.deserialize(tmp);

    return 0;
}