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
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) {
            return true;
        }
        if(root == NULL || subRoot == NULL) {
            return false;
        }
        if(root->val != subRoot->val) {
            return false;
        }
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) {
            return true;
        }
        if(root == NULL) {
            return false;
        }
        if(check(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(4);
    TreeNode* node12 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(1);
    TreeNode* node14 = new TreeNode(2);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    TreeNode* subRoot1 = new TreeNode(4);
    TreeNode* subNode11 = new TreeNode(1);
    TreeNode* subNode12 = new TreeNode(2);
    subRoot1->left = subNode11;
    subRoot1->right = subNode12;

    TreeNode* root2 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(4);
    TreeNode* node22 = new TreeNode(5);
    TreeNode* node23 = new TreeNode(1);
    TreeNode* node24 = new TreeNode(2);
    TreeNode* node25 = new TreeNode(0);
    root2->left = node21;
    root2->right = node22;
    node21->left = node23;
    node21->right = node24;
    node24->left = node25;
    TreeNode* subRoot2 = new TreeNode(4);
    TreeNode* subNode21 = new TreeNode(1);
    TreeNode* subNode22 = new TreeNode(2);
    subRoot2->left = subNode21;
    subRoot2->right = subNode22;

    Solution solution;

    bool solution1 = solution.isSubtree(root1, subRoot1);
    bool solution2 = solution.isSubtree(root2, subRoot2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}