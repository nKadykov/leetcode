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
    vector<vector<vector<TreeNode*>>> dp;
    vector<TreeNode*> uniqueBinaryTree(int i, int n) {
        if(i > n) {
            return {nullptr};
        }
        if(i == n) {
            return {new TreeNode(i)};
        }
        if(dp[i][n].size() > 0) {
            return dp[i][n];
        }
        vector<TreeNode*> result;
        for(int j = i; j <= n; j++) {
            vector<TreeNode*> left = uniqueBinaryTree(i, j - 1);
            vector<TreeNode*> right = uniqueBinaryTree(j + 1, n);
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(j, l, r);
                    result.push_back(root);
                }
            }
        }
        return dp[i][n] = result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        dp.assign(n + 1, vector(n + 1, vector<TreeNode*>()));
        return uniqueBinaryTree(1, n);
    }
};

void printTree(TreeNode* root) {
    cout << root->val << ' ';
    if(root->left) {
        printTree(root->left);
    }
    if(root->right) {
        printTree(root->right);
    }
}

int main() {
    int n1 = 3;
    int n2 = 1;

    Solution solution;

    vector<TreeNode*> solution1 = solution.generateTrees(n1);
    vector<TreeNode*> solution2 = solution.generateTrees(n2);

    for(auto x : solution1) {
        printTree(x);
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        printTree(x);
        cout << '\n';
    }

    return 0;
}