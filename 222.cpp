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
    void recursion(TreeNode* root, int& result) {
        if(root->left) {
            result++;
            recursion(root->left, result);
        }
        if(root->right) {
            result++;
            recursion(root->right, result);
        }
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int result = 1;
        recursion(root, result);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node14 = new TreeNode(5);
    TreeNode* node15 = new TreeNode(6);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->left = node15;

    TreeNode* root2;

    TreeNode* root3 = new TreeNode(1);

    Solution solution;

    int solution1 = solution.countNodes(root1);
    int solution2 = solution.countNodes(root2);
    int solution3 = solution.countNodes(root3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}