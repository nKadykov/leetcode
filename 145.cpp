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
    void function(TreeNode* root, vector<int>& result) {
        if(root->left) {
            function(root->left, result);
        }
        if(root->left) {
            result.push_back(root->left->val);
        }
        if(root->right) {
            function(root->right, result);
        }
        if(root->right) {
            result.push_back(root->right->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return {};
        }
        function(root, result);
        result.push_back(root->val);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    root1->right = node11;
    node11->left = node12;

    TreeNode* root2;

    TreeNode* root3 = new TreeNode(1);

    Solution solution;

    vector<int> solution1 = solution.postorderTraversal(root1);
    vector<int> solution2 = solution.postorderTraversal(root2);
    vector<int> solution3 = solution.postorderTraversal(root3);


    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution3) {
        cout << x << ' ';
    }

    return 0;
}