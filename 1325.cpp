#include <iostream>

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) {
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if(!root->left && !root->right && root->val == target) {
            return nullptr;
        }
        return root;
    }
};

int main() {
    TreeNode* node15 = new TreeNode(4);
    TreeNode* node14 = new TreeNode(2);
    TreeNode* node13 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3, node14, node15);
    TreeNode* node11 = new TreeNode(2, node13, nullptr);
    TreeNode* root1 = new TreeNode(1);
    int target1 = 2;

    TreeNode* node24 = new TreeNode(2);
    TreeNode* node23 = new TreeNode(3);
    TreeNode* node22 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(3, node23, node24);
    TreeNode* root2 = new TreeNode(1, node21, node22);
    int target2 = 3;

    TreeNode* node33 = new TreeNode(2);
    TreeNode* node32 = new TreeNode(2, node33, nullptr);
    TreeNode* node31 = new TreeNode(2, node32, nullptr);
    TreeNode* root3 = new TreeNode(1, node31, nullptr);
    int target3 = 3;

    Solution solution;

    TreeNode* solution1 = solution.removeLeafNodes(root1, target1);
    TreeNode* solution2 = solution.removeLeafNodes(root2, target2);
    TreeNode* solution3 = solution.removeLeafNodes(root3, target3);

    return 0;
}