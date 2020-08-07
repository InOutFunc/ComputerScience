#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    Node* cloneG(Node* node, unordered_map<Node*, Node*>& visited)
    {
        if (node == nullptr)
            return node;
        
        if (visited.find(node) != end(visited))
            return visited[node];
        
        Node* nd = new Node(node->val);
        visited[node] = nd;
        
        for (const auto& c : node->neighbors)
            nd->neighbors.push_back(cloneG(c, visited));
        
        return nd;
    }
        
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return cloneG(node, visited);
    }
};

int main()
{
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n4);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n4);
    n4.neighbors.push_back(&n1);
    n4.neighbors.push_back(&n3);

    Solution sol;
    Node *ret = sol.cloneGraph(&n1);

    return 0;

}