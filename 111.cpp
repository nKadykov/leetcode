#include <iostream>
#include <algorithm>
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
    int check(TreeNode* node) {
        if(!node) {
            return 0;
        }
        if(!node->right && !node->left) {
            return 1;
        }
        if(!node->left) {
            return check(node->right) + 1;
        }
        if(!node->right) {
            return check(node->left) + 1;
        }
        int l = check(node->left);
        int r = check(node->right);
        return min(l, r) + 1;
    }
    int minDepth(TreeNode* root) {
        return check(root);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    TreeNode* root1l1 = new TreeNode(9);
    TreeNode* root1r1 = new TreeNode(20);
    TreeNode* root1r1l2 = new TreeNode(15);
    TreeNode* root1r1r2 = new TreeNode(7);
    root1->left = root1l1;
    root1->right = root1r1;
    root1r1->left = root1r1l2;
    root1r1->right = root1r1r2;

    Solution solution;

    int solution1 = solution.minDepth(root1);

    cout << solution1;

    return 0;
}