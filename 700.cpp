#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) {
            return NULL;
        }
        if(root->val == val) {
            return root;
        }
        else if(root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};

int main() {
    TreeNode* root1 = new TreeNode(4);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(7);
    TreeNode* node13 = new TreeNode(1);
    TreeNode* node14 = new TreeNode(3);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    int val1 = 2;

    TreeNode* root2 = new TreeNode(4);
    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(7);
    TreeNode* node23 = new TreeNode(1);
    TreeNode* node24 = new TreeNode(3);
    root2->left = node21;
    root2->right = node22;
    node21->left = node23;
    node21->right = node24;
    int val2 = 2;

    Solution solution;

    TreeNode* solution1 = solution.searchBST(root1, val1);
    TreeNode* solution2 = solution.searchBST(root2, val2);

    return 0;
}