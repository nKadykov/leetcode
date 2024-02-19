#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(9);
    TreeNode* node12 = new TreeNode(20);
    TreeNode* node13 = new TreeNode(15);
    TreeNode* node14 = new TreeNode(7);
    root1->left = node11;
    root1->right = node12;
    node12->left = node13;
    node12->right = node14;

    TreeNode* root2 = new TreeNode(1);

    TreeNode* root3 = new TreeNode();

    Solution solution;

    vector<vector<int>> solution1 = solution.levelOrder(root1);
    vector<vector<int>> solution2 = solution.levelOrder(root2);
    vector<vector<int>> solution3 = solution.levelOrder(root3);

    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution3) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}