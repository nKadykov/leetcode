#include <iostream>
#include <set>
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
    void pushNumbers(TreeNode* root, set<int>& values) {
        if(!root) {
            return;
        }
        values.insert(root->val);
        pushNumbers(root->left, values);
        pushNumbers(root->right, values);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> values;
        pushNumbers(root, values);
        if(values.size() > 1) {
            return *(++(values.begin()));
        }
        return -1;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(2);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(5);
    TreeNode* node14 = new TreeNode(7);
    root1->left = node11;
    root1->right = node12;
    node12->left = node13;
    node12->right = node14;

    TreeNode* root2 = new TreeNode(2);
    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(2);
    root2->left = node21;
    root2->right = node22;

    Solution solution;

    int solution1 = solution.findSecondMinimumValue(root1);
    int solution2 = solution.findSecondMinimumValue(root2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}