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
    vector<int> nodes;
    void validation(TreeNode* root) {
        if(root->left) {
            validation(root->left);
        }
        nodes.push_back(root->val);
        if(root->right) {
            validation(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        validation(root);
        for(int i = 0; i < nodes.size() - 1; i++) {
            if(nodes[i] >= nodes[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(2);
    TreeNode* node11 = new TreeNode(1);
    TreeNode* node12 = new TreeNode(3);
    root1->left = node11;
    root1->right = node12;

    TreeNode* root2 = new TreeNode(5);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* node22 = new TreeNode(4);
    TreeNode* node23 = new TreeNode(3);
    TreeNode* node24 = new TreeNode(6);
    root2->left = node21;
    root2->right = node22;
    node22->left = node23;
    node22->right = node24;

    Solution solution;

    bool solution1 = solution.isValidBST(root1);
    bool solution2 = solution.isValidBST(root2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}