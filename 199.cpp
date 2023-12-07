#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> numbers;
        solve(root, result, numbers, 0);
        return result;
    }
    void solve(TreeNode* root, vector<int>& result, unordered_map<int, int>& numbers, int n) {
        if(!root) {
            return;
        }
        if(!numbers[n]) {
            numbers[n] = 1;
            result.push_back(root->val);
        }
        solve(root->right, result, numbers, n + 1);
        solve(root->left, result, numbers, n + 1);
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node14 = new TreeNode(5);
    root1->left = node11;
    root1->right = node12;
    node11->right = node13;
    node12->right = node14;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* node21 = new TreeNode(3);
    root2->left = node21;

    TreeNode* root3 = new TreeNode;

    Solution solution;

    vector<int> solution1 = solution.rightSideView(root1);
    vector<int> solution2 = solution.rightSideView(root2);
    vector<int> solution3 = solution.rightSideView(root3);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto y : solution2) {
        cout << y << ' ';
    }
    cout << '\n';
    for(auto z : solution3) {
        cout << z << ' ';
    }
    return 0;
}