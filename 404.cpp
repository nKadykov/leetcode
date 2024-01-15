#include <iostream>
#include <vector>
#include <string>
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
    void countSum(TreeNode* root, int& sum) {
        if(root->left) {
            if(!root->left->left && !root->left->right) {
                sum += root->left->val;
            }
            countSum(root->left, sum);
        }
        if(root->right) {
            countSum(root->right, sum);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        countSum(root, sum);
        return sum;
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

    Solution solution;

    int solution1 = solution.sumOfLeftLeaves(root1);
    int solution2 = solution.sumOfLeftLeaves(root2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}