#include <iostream>
#include <vector>
#include <cstring>
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
    void output(TreeNode* root, string leaf, vector<string>& result) {
        string temp;
        temp = to_string(root->val);
        if(leaf.size() != 0) {
            leaf += "->";
            leaf += temp;
        }
        else {
            leaf += temp;
        }
        if(root->right) {
            output(root->right, leaf, result);
        }
        if(root->left) {
            output(root->left, leaf, result);
        }
        if(!root->right && !root->left) {
            result.push_back(leaf);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result; 
        output(root, "", result);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node13 = new TreeNode(5);
    root1->left = node11;
    root1->right = node12;
    node11->right = node13;

    TreeNode* root2 = new TreeNode(1);

    Solution solution;

    vector<string> solution1 = solution.binaryTreePaths(root1);
    vector<string> solution2 = solution.binaryTreePaths(root2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}