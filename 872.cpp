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
    void pushValues(TreeNode* root, vector<int>& leaf) {
        if(!root->left && !root->right) {
            leaf.push_back(root->val);
        }
        if(root->left) {
            pushValues(root->left, leaf);
        }
        if(root->right) {
            pushValues(root->right, leaf);
        }
        return;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return true;
        }
        if(!root1 || !root2) {
            return false;
        }
        vector<int> leafs1;
        vector<int> leafs2;
        pushValues(root1, leafs1);
        pushValues(root2, leafs2);
        if(leafs1.size() != leafs2.size()) {
            return false;
        }
        for(int i = 0; i < leafs1.size(); i++) {
            if(leafs1[i] != leafs2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root11 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(5);
    TreeNode* node12 = new TreeNode(1);
    TreeNode* node13 = new TreeNode(6);
    TreeNode* node14 = new TreeNode(2);
    TreeNode* node15 = new TreeNode(9);
    TreeNode* node16 = new TreeNode(8);
    TreeNode* node17 = new TreeNode(7);
    TreeNode* node18 = new TreeNode(4);
    root11->left = node11;
    root11->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->left = node15;
    node12->right = node16;
    node14->left = node17;
    node14->right = node18;
    TreeNode* root12 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(5);
    TreeNode* node22 = new TreeNode(1);
    TreeNode* node23 = new TreeNode(6);
    TreeNode* node24 = new TreeNode(7);
    TreeNode* node25 = new TreeNode(4);
    TreeNode* node26 = new TreeNode(2);
    TreeNode* node27 = new TreeNode(9);
    TreeNode* node28 = new TreeNode(8);
    root12->left = node21;
    root12->right = node22;
    node21->left = node23;
    node21->right = node24;
    node22->left = node25;
    node22->right = node26;
    node26->left = node27;
    node26->right = node28;

    TreeNode* root21 = new TreeNode(1);
    TreeNode* node31 = new TreeNode(2);
    TreeNode* node32 = new TreeNode(3);
    root21->left = node31;
    root21->right = node32;
    TreeNode* root22 = new TreeNode(1);
    TreeNode* node41 = new TreeNode(3);
    TreeNode* node42 = new TreeNode(2);
    root22->left = node41;
    root22->right = node42;

    Solution solution;

    bool solution1 = solution.leafSimilar(root11, root12);
    bool solution2 = solution.leafSimilar(root21, root22);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}