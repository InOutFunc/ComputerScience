#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        TreeNode *dummy = new TreeNode(-1);
        TreeNode *pre = dummy;
        while (!st.empty()) {
            TreeNode *node = st.top().first;
            int entry = st.top().second;
            st.pop();
            if (node == nullptr) {
                continue;
            }
            if (entry == 0) {
                st.push({node->right, 0});
                st.push({node->left, 0});
                st.push({node, 1});
            }
            if (entry == 1) {
                cout << "1" << node->val << endl;
                pre->right = node;
                pre = node;
            }
        }
    }
};

int main()
{
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node6(6);
    TreeNode node2(2, &node3, &node4);
    TreeNode node5(5, nullptr, &node6);
    TreeNode node1(1, &node2, &node5);
    Solution sol;
    sol.flatten(&node1);
    
    return 0;
}