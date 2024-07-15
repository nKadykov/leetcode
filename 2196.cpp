#include <iostream>
#include <vector>
#include <unordered_set>
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
    TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
        std::unordered_set<int> children_set;
        std::unordered_map<int, std::pair<int, int>> children_hashmap;
        for(auto& description : descriptions) {
            int parent = description[0];
            int child = description[1];
            bool is_left = description[2] == 1;
            if(children_hashmap.find(parent) == children_hashmap.end()) {
                children_hashmap[parent] = {-1, -1};
            }
            children_set.insert(child);
            if(is_left) {
                children_hashmap[parent].first = child;
            } else {
                children_hashmap[parent].second = child;
            }
        }
        int head_val;
        for(auto& [parent, children] : children_hashmap) {
            if(children_set.find(parent) == children_set.end()) {
                head_val = parent;
                break;
            }
        }
        return constructTree(head_val, children_hashmap);
    }
private:
    TreeNode* constructTree(int current_val, std::unordered_map<int, std::pair<int, int>>& children_hashmap) {
        TreeNode* new_node = new TreeNode(current_val);
        if(children_hashmap.find(current_val) != children_hashmap.end()) {
            auto& children = children_hashmap[current_val];
            if(children.first != -1) {
                new_node->left = constructTree(children.first, children_hashmap);
            }
            if(children.second != -1) {
                new_node->right = constructTree(children.second, children_hashmap);
            }
        }
        return new_node;
    }
};

int main() {
    std::vector<std::vector<int>> descriptions1 {
        {20,15,1},
        {20,17,0},
        {50,20,1},
        {50,80,0},
        {80,19,1}
    };
    std::vector<std::vector<int>> descriptions2 {
        {1,2,1},
        {2,3,0},
        {3,4,1}
    };

    Solution solution;

    TreeNode* solution1 = solution.createBinaryTree(descriptions1);
    TreeNode* solution2 = solution.createBinaryTree(descriptions2);

    return 0;
}