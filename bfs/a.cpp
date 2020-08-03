#include <iostream>
#include <vector>

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
    void levelOrderHelper(vector<vector<int>> &res, TreeNode* root, int depth)
    {
        if(root==NULL)
            return;
        if(depth==res.size())
            res.push_back({});
        res[depth].push_back(root->val);
        levelOrderHelper(res, root->left, depth+1);
        levelOrderHelper(res, root->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> res;
        levelOrderHelper(res, root, 0);
        return res;
    }
};

int main()
{
    TreeNode node33(15);
    TreeNode node34(7);
    TreeNode node21(9);
    TreeNode node22(20, &node33, &node34);
    TreeNode node11(3, &node21, &node22);
    Solution sol;
    vector<vector<int>> res = sol.levelOrder(&node11);

    return 0;
}