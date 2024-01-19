#include <iostream>
#include <unordered_set>
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
    unordered_set<int> values;
    bool checkNumber(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        if(checkNumber(root->left, k)) {
            return true;
        }
        int val = root->val;
        if(values.find(k - val) != values.end()) {
            return true;
        }
        values.insert(val);
        if(checkNumber(root->right, k)) {
            return true;
        }
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return checkNumber(root, k);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(5);
    TreeNode* node11 = new TreeNode(3);
    TreeNode* node12 = new TreeNode(6);
    TreeNode* node13 = new TreeNode(2);
    TreeNode* node14 = new TreeNode(4);
    TreeNode* node15 = new TreeNode(7);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->right = node15;
    int k1 = 9;

    TreeNode* root2 = new TreeNode(5);
    TreeNode* node21 = new TreeNode(3);
    TreeNode* node22 = new TreeNode(6);
    TreeNode* node23 = new TreeNode(2);
    TreeNode* node24 = new TreeNode(4);
    TreeNode* node25 = new TreeNode(7);
    root2->left = node21;
    root2->right = node22;
    node21->left = node23;
    node21->right = node24;
    node22->right = node25;
    int k2 = 28;

    Solution solution;

    bool solution1 = solution.findTarget(root1, k1);
    bool solution2 = solution.findTarget(root2, k2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}