#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {} 
};

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        bool right;
        bool left;
        if(!root->right && !root->left) {
            if(root->val == 0) {
                return false;
            }
            if(root->val == 1) {
                return true;
            }
        }
        right = evaluateTree(root->right);
        left = evaluateTree(root->left);
        if(root->val == 2) {
            return right || left;
        }
        if(root->val == 3) {
            return right && left;
        }
        return false;
    }
};

int main() {
    TreeNode* node14 = new TreeNode(1);
    TreeNode* node13 = new TreeNode(0);
    TreeNode* node12 = new TreeNode(3, node13, node14);
    TreeNode* node11 = new TreeNode(1);
    TreeNode* head1 = new TreeNode(2, node11, node12);

    TreeNode* head2 = new TreeNode(0);

    Solution solution;

    bool solution1 = solution.evaluateTree(head1);
    bool solution2 = solution.evaluateTree(head2);

    std::cout.setf(std::ios::boolalpha);
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}