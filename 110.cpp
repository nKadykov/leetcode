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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return check(root, height);
    }
    bool check(TreeNode* root, int& height) {
        if(root == NULL) {
            height = -1;
            return true;
        }
        int right = 0;
        int left = 0;
        if(!check(root->left, left) || !check(root->right, right)) {
            return false;
        }
        if(abs(right - left) > 1) {
            return false;
        }
        height = 1 + max(right, left);
        return true;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    TreeNode* root1r1 = new TreeNode(20);
    TreeNode* root1l1 = new TreeNode(9);
    TreeNode* root1l1l2 = new TreeNode(15);
    TreeNode* root1l1r2 = new TreeNode(7);
    root1->right = root1r1;
    root1->left = root1l1;
    root1l1->left = root1l1l2;
    root1l1->right = root1l1r2;

    Solution solution;

    bool solution1 = solution.isBalanced(root1);

    cout << solution1 << '\n';

    return 0;
}
