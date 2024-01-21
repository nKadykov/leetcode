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
    void inputValues(TreeNode* root, vector<int>& numbers) {
        numbers.push_back(root->val);
        if(root->left) {
            inputValues(root->left, numbers);
        }
        if(root->right) {
            inputValues(root->right, numbers);
        }
    }
    void newTree(TreeNode* root, vector<int> numbers, int index) {
        if(index == numbers.size()) {
            return;
        }
        TreeNode* node = new TreeNode(numbers[index]);
        root->right = node;
        if((index + 1) < numbers.size()) {
            newTree(node, numbers, index + 1);
        }
        return;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> numbers;
        if(!root) {
            return root;
        }
        inputValues(root, numbers);
        sort(numbers.begin(), numbers.end());
        TreeNode* newRoot = new TreeNode(numbers[0]);
        newTree(newRoot, numbers, 1);
        return newRoot;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(5);
    TreeNode* node11 = new TreeNode(3);
    TreeNode* node12 = new TreeNode(6);
    TreeNode* node13 = new TreeNode(2);
    TreeNode* node14 = new TreeNode(4);
    TreeNode* node15 = new TreeNode(8);
    TreeNode* node16 = new TreeNode(1);
    TreeNode* node17 = new TreeNode(7);
    TreeNode* node18 = new TreeNode(9);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->right = node15;
    node13->left = node16;
    node15->left = node17;
    node15->right = node18;

    TreeNode* root2 = new TreeNode(5);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* node22 = new TreeNode(7);
    root2->left = node21;
    root2->right = node22;

    Solution solution;

    TreeNode* solution1 = solution.increasingBST(root1);
    TreeNode* solution2 = solution.increasingBST(root2);

    while(solution1->right) {
        cout << solution1->val << ' ';
        solution1 = solution1->right;
    }
    cout << '\n';
    while(solution2->right) {
        cout << solution2->val << ' ';
        solution2 = solution2->right;
    }

    return 0;
}