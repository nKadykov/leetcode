#include <iostream>
#include <vector>
#include <unordered_map>

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
    int countPairs(TreeNode* root, int distance) {
        std::unordered_map<TreeNode*, std::vector<TreeNode*>> map;
        std::vector<TreeNode*> leaves;
        findLeaves(root, {}, leaves, map);
        int result = 0;
        for(int i = 0; i < leaves.size(); ++i) {
            for(int j = i + 1; j < leaves.size(); ++j) {
                std::vector<TreeNode*> vector_i = map[leaves[i]];
                std::vector<TreeNode*> vector_j = map[leaves[j]];
                for(int k = 0; k < std::min(vector_i.size(), vector_j.size()); k++) {
                    if(vector_i[k] != vector_j[k]) {
                        int dist = vector_i.size() - k + vector_j.size() - k;
                        if(dist <= distance)
                            result++;
                        break;
                    }
                }
            }
        }
        return result;
    }
private:
    void findLeaves(TreeNode* node, const std::vector<TreeNode*>& trail, std::vector<TreeNode*>& leaves, std::unordered_map<TreeNode*, std::vector<TreeNode*>>& map) {
        if(!node)
            return;
        std::vector<TreeNode*> temp(trail);
        temp.push_back(node);
        if(!node->left && !node->right) {
            map[node] = temp;
            leaves.push_back(node);
            return;
        }
        findLeaves(node->left, temp, leaves, map);
        findLeaves(node->right, temp, leaves, map);
    }
};

int main() {
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(2, nullptr, node13);
    TreeNode* head1 = new TreeNode(1, node11, node12);
    int distance1 = 3;
    

    TreeNode* node26 = new TreeNode(7);
    TreeNode* node25 = new TreeNode(6);
    TreeNode* node24 = new TreeNode(5);
    TreeNode* node23 = new TreeNode(4);
    TreeNode* node22 = new TreeNode(3, node25, node26);
    TreeNode* node21 = new TreeNode(2, node23, node24);
    TreeNode* head2 = new TreeNode(1, node21, node22);
    int distance2 = 3;

    Solution solution;

    int solution1 = solution.countPairs(head1, distance1);
    int solution2 = solution.countPairs(head2, distance2);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';

    return 0;
}