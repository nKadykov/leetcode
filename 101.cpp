#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(left) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        if(left->val != right->val)
            return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(2);
    root->left = l1;
    root->right = r1;

    Solution solution;

    bool solution1 = solution.isSymmetric(root);

    cout << solution1;

    return 0;
}