#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        function(root, nodes);
        return nodes;
    }
    void function(TreeNode* node, vector<int>& nodes) {
        if(node == nullptr) {
            return;
        }
        function(node->left, nodes);
        nodes.push_back(node->val);
        function(node->right, nodes);
    }
};

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node2->right = node3;

    Solution solution;

    vector<int> solution1 = solution.inorderTraversal(node1);

    for(auto& x : solution1)
        cout << x << ' ';

    return 0;
}