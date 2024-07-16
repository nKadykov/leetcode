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
    std::string getDirections(TreeNode* root, int start_value, int dest_value) {
        std::string start_node, dest_node;
        find(root, start_value, start_node);
        find(root, dest_value, dest_node);
        while(!start_node.empty() && !dest_node.empty() && start_node.back() == dest_node.back()) {
            start_node.pop_back();
            dest_node.pop_back();
        }
        return std::string(start_node.size(), 'U') + std::string(rbegin(dest_node), rend(dest_node));
    }
private:
    bool find(TreeNode* node, int val, std::string& path) {
        if(node->val == val)
            return true;
        if(node->left && find(node->left, val, path))
            path.push_back('L');
        else if(node->right && find(node->right, val, path))
            path.push_back('R');
        return !path.empty();
    }
};

int main() {
    TreeNode* node15 = new TreeNode(4);
    TreeNode* node14 = new TreeNode(6);
    TreeNode* node13 = new TreeNode(3);
    TreeNode* node12 = new TreeNode(2, node14, node15);
    TreeNode* node11 = new TreeNode(1, node13, nullptr);
    TreeNode* head1 = new TreeNode(5, node11, node12);
    int start_value1 = 3;
    int dest_value1 = 6;

    TreeNode* node21 = new TreeNode(1);
    TreeNode* head2 = new TreeNode(2, node21, nullptr);
    int start_value2 = 2;
    int dest_value2 = 1;

    Solution solution;

    std::string solution1 = solution.getDirections(head1, start_value1, dest_value1);
    std::string solution2 = solution.getDirections(head2, start_value2, dest_value2);

    std::cout << solution1 << '\n';
    std::cout << solution2;

    return 0;
}