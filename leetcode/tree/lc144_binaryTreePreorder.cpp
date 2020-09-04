#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, 1));
        vector<int> res;
        while (!st.empty()) {
            auto tmp = st.top();
            st.pop();
            if (tmp.first == nullptr) {
                continue;
            }
            if (tmp.second == 1) {
                st.push(make_pair(tmp.first, 0));
                st.push(make_pair(tmp.first->right, 1));
                st.push(make_pair(tmp.first->left, 1));
            } else if (tmp.second == 0) {
                res.push_back(tmp.first->val);
            }
        }
        return res;
    }
    
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node2.left = &node3;
    node1.right = &node2;

    Solution sol;
    vector<int> res = sol.preorderTraversal(&node1);

    return 0;
}