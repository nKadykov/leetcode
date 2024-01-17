#include <iostream>
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
    void recursion(TreeNode* root, string& result) {
        if(!root) {
            return;
        }
        result += to_string(root->val);
        if(root->left != nullptr || root->right != nullptr) {
            result += "(";
            recursion(root->left, result);
            result += ")";
        }
        if(root->right != nullptr) {
            result += "(";
            recursion(root->right, result);
            result += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        string result;
        if(!root) {
            return "";
        }
        recursion(root, result);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node13 = new TreeNode(4);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(3);
    TreeNode* node23 = new TreeNode(4);
    root2->left = node21;
    root2->right = node22;
    node21->right = node23;

    Solution solution;

    string solution1 = solution.tree2str(root1);
    string solution2 = solution.tree2str(root2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}