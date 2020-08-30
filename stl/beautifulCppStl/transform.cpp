#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;

    vector<TreeNode*> nodeList = {&node1, &node2, &node3};
    vector<int> vals = {1, 3, 2};
    for (int i = 0; i < vals.size(); i++) {
        nodeList[i]->val = vals[i];
        // nodeList[i]->val = vals[i] * 2;
    }

    return 0;
}