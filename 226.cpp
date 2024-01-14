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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(4);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(7);
    TreeNode* node13 = new TreeNode(1);
    TreeNode* node14 = new TreeNode(3);
    TreeNode* node15 = new TreeNode(6);
    TreeNode* node16 = new TreeNode(9);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->left = node15;
    node12->right = node16;

    TreeNode* root2 = new TreeNode(2);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* node22 = new TreeNode(3);
    root2->left = node21;
    root2->right = node22;

    TreeNode* root3;

    Solution solution;

    TreeNode* solution1 = solution.invertTree(root1);
    TreeNode* solution2 = solution.invertTree(root2);
    TreeNode* solution3 = solution.invertTree(root3);

    return 0;
}