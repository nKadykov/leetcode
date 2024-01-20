#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> difference;
    vector<int> numbers;
    void insertValues(TreeNode* root) {
        numbers.push_back(root->val);
        if(root->left) {
            insertValues(root->left);
        }
        if(root->right) {
            insertValues(root->right);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) {
            return 0;
        }
        insertValues(root);
        for(int i = 0; i < numbers.size() - 1; i++) {
            for(int j = i + 1; j < numbers.size(); j++) {
                difference.push_back(abs(numbers[j] - numbers[i]));
            }
        }
        sort(difference.begin(), difference.end());
        return difference[0];
    }
};

int main() {
    TreeNode* root1 = new TreeNode(4);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(6);
    TreeNode* node13 = new TreeNode(1);
    TreeNode* node14 = new TreeNode(3);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* node21 = new TreeNode(0);
    TreeNode* node22 = new TreeNode(48);
    TreeNode* node23 = new TreeNode(12);
    TreeNode* node24 = new TreeNode(49);
    root2->left = node21;
    root2->right = node22;
    node22->left = node23;
    node22->right = node24;

    Solution solution;

    int solution1 = solution.minDiffInBST(root1);
    int solution2 = solution.minDiffInBST(root2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}