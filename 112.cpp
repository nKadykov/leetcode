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
    bool hasPathSum(TreeNode* root, const int targetSum) {
        if(!root) {
            return false;
        }
        if(!root->left && !root->right) {
            return (targetSum == root->val);
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(5);
    TreeNode* root1r1 = new TreeNode(4);
    TreeNode* root1r1r2 = new TreeNode(11);
    TreeNode* root1r1r2l3 = new TreeNode(2);
    TreeNode* root1r1r2r3 = new TreeNode(7);
    TreeNode* root1l1 = new TreeNode(8);
    TreeNode* root1l1r2 = new TreeNode(13);
    root1->right = root1r1;
    root1->left = root1l1;
    root1r1->right = root1r1r2;
    root1r1r2->right = root1r1r2r3;
    root1r1r2->left = root1r1r2l3;
    root1l1->right = root1l1r2;
    int targetSum1 = 22;

    Solution solution;

    bool solution1 = solution.hasPathSum(root1, targetSum1);

    cout << solution1;

    return 0;
}