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
    int result = 0;
    int tilt(TreeNode* root) {
        int left = (root->left ? tilt(root->left) : 0);
        int right = (root->right ? tilt(root->right) : 0);
        result += abs(left - right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        result = 0;
        if(root) {
            tilt(root);
        }
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(3);
    root1->left = node11;
    root1->right = node12;

    TreeNode* root2 = new TreeNode(4);
    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(9);
    TreeNode* node23 = new TreeNode(3);
    TreeNode* node24 = new TreeNode(5);
    TreeNode* node25 = new TreeNode(7);
    root2->left = node21;
    root2->right = node22;
    node21->left = node23;
    node21->right = node24;
    node22->right = node25;

    TreeNode* root3 = new TreeNode(21);
    TreeNode* node31 = new TreeNode(7);
    TreeNode* node32 = new TreeNode(14);
    TreeNode* node33 = new TreeNode(1);
    TreeNode* node34 = new TreeNode(1);
    TreeNode* node35 = new TreeNode(2);
    TreeNode* node36 = new TreeNode(2);
    TreeNode* node37 = new TreeNode(3);
    TreeNode* node38 = new TreeNode(3);;
    root3->left = node31;
    root3->right = node32;
    node31->left = node33;
    node31->right = node34;
    node32->left = node35;
    node32->right = node36;
    node33->left = node37;
    node33->right = node38;

    Solution solution;

    int solution1 = solution.findTilt(root1);
    int solution2 = solution.findTilt(root2);
    int solution3 = solution.findTilt(root3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}