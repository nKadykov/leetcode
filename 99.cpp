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
    void change(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if(!root) {
            return;
        }
        change(root->left, prev, first, second);
        if(prev) {
            if(root->val < prev->val) {
                if(!first) {
                    first = prev;
                }
                second = root;
            }
        }
        prev = root;
        change(root->right, prev, first, second);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        change(root, prev, first, second);
        swap(first->val, second->val);
        return;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(3);
    TreeNode* node12 = new TreeNode(2);
    root1->left = node11;
    node11->right = node12;

    TreeNode* root2 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* node22 = new TreeNode(4);
    TreeNode* node23 = new TreeNode(2);
    root2->left = node21;
    root2->right = node22;
    node22->left = node23;

    Solution solution;

    solution.recoverTree(root1);
    solution.recoverTree(root2);

    return 0;
}