#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sorted_arr.size() - 1);
    }
private:
    std::vector<TreeNode*> sorted_arr;

    void inorderTraverse(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        inorderTraverse(root->left);
        sorted_arr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if(start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = sorted_arr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};

int main() {
    TreeNode* node13 = new TreeNode(4);
    TreeNode* node12 = new TreeNode(3, nullptr, node13);
    TreeNode* node11 = new TreeNode(2, nullptr, node12);
    TreeNode* root1 = new TreeNode(1, nullptr, node11);

    TreeNode* node22 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(1);
    TreeNode* root2 = new TreeNode(2, node11, node12);

    Solution solution;

    TreeNode* solution1 = solution.balanceBST(root1);
    TreeNode* solution2 = solution.balanceBST(root2);

    return 0;
}