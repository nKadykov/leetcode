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
    int moves = 0;
    int dfs(TreeNode* node) {
        if(!node) {
            return 0;
        }
        int left_excess = dfs(node->left);
        int right_excess = dfs(node->right);
        moves += abs(left_excess) + abs(right_excess);
        return node->val + left_excess + right_excess - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};

int main() {
    TreeNode* node12 = new TreeNode(0);
    TreeNode* node11 = new TreeNode(0);
    TreeNode* root1 = new TreeNode(3, node11, node12);

    TreeNode* node22 = new TreeNode(0);
    TreeNode* node21 = new TreeNode(3);
    TreeNode* root2 = new TreeNode(0, node21, node22);

    Solution solution;

    int solution1 = solution.distributeCoins(root1);
    int solution2 = solution.distributeCoins(root2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}