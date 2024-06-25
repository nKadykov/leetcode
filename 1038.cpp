#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
private:
    int sum = 0;

    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }
};

int main() {
    TreeNode* node18 = new TreeNode(8);
    TreeNode* node17 = new TreeNode(3);
    TreeNode* node16 = new TreeNode(7, nullptr, node18);
    TreeNode* node15 = new TreeNode(5);
    TreeNode* node14 = new TreeNode(2, nullptr, node17);
    TreeNode* node13 = new TreeNode(0);
    TreeNode* node12 = new TreeNode(6, node15, node16);
    TreeNode* node11 = new TreeNode(1, node13, node14);
    TreeNode* root1 = new TreeNode(4, node11, node12); 

    TreeNode* node21 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(0, nullptr, node21);

    Solution solution;

    TreeNode* solution1 = solution.bstToGst(root1);
    TreeNode* solution2 = solution.bstToGst(root2);

    return 0;
}