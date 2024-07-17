#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>

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
    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) {
        std::unordered_map<int, TreeNode*> result_map;
        std::unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        result_map[root->val] = root;
        std::function<void(TreeNode*, TreeNode*, bool)> recursion = [&](TreeNode* parent, TreeNode* current_node, bool is_left) {
            if(current_node == nullptr)
                return;
            recursion(current_node, current_node->left, true);
            recursion(current_node, current_node->right, false);
            if(to_delete_set.find(current_node->val) != to_delete_set.end()) {
                if(result_map.find(current_node->val) != result_map.end())
                    result_map.erase(current_node->val);
                if(parent) {
                    if(is_left)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                if(current_node->left)
                    result_map[current_node->left->val] = current_node->left;
                if(current_node->right)
                    result_map[current_node->right->val] = current_node->right;
            }
        };
        recursion(nullptr, root, false);
        std::vector<TreeNode*> result;
        for(auto& pair : result_map)
            result.push_back(pair.second);
        return result;
    }
};

int main() {
    TreeNode* node16 = new TreeNode(7);
    TreeNode* node15 = new TreeNode(6);
    TreeNode* node14 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node12 = new TreeNode(3, node15, node16);
    TreeNode* node11 = new TreeNode(2, node13, node14);
    TreeNode* head1 = new TreeNode(1, node11, node12);
    std::vector<int> to_delete1 {3,5};

    TreeNode* node23 = new TreeNode(3);
    TreeNode* node22 = new TreeNode(4);
    TreeNode* node21 = new TreeNode(2, nullptr, node23);
    TreeNode* head2 = new TreeNode(1, node21, node22);
    std::vector<int> to_delete2 {3};

    Solution solution;

    std::vector<TreeNode*> solution1 = solution.delNodes(head1, to_delete1);
    std::vector<TreeNode*> solution2 = solution.delNodes(head2, to_delete2);

    return 0;
}