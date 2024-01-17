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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr) {
            return root1 ? root1 : root2;
        }
        root1 -> val += root2 -> val;
        root1 -> left = mergeTrees(root1 -> left , root2 ->left);
        root1 -> right = mergeTrees(root1 -> right , root2 -> right);
        return root1;
    }
};

int main() {
    TreeNode* root11 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(3);
    TreeNode* node12 = new TreeNode(2);
    TreeNode* node13 = new TreeNode(5);
    root11->left = node11;
    root11->right = node12;
    node11->left = node13;
    TreeNode* root12 = new TreeNode(2);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* node22 = new TreeNode(3);
    TreeNode* node23 = new TreeNode(4);
    TreeNode* node24 = new TreeNode(7);
    root12->left = node21;
    root12->right = node22;
    node21->right = node23;
    node22->right = node24;

    TreeNode* root21 = new TreeNode(1);
    TreeNode* root22 = new TreeNode(1);
    TreeNode* node41 = new TreeNode(2);
    root22->left = node41;

    Solution solution;

    TreeNode* solution1 = solution.mergeTrees(root11, root12);
    TreeNode* solution2 = solution.mergeTrees(root21, root22);

    return 0;
}