#include <iostream>
#include <algorithm>
using namespace std;

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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* l1 = new TreeNode(2);
    TreeNode* r1 = new TreeNode(3);
    TreeNode* r2 = new TreeNode(4);
    root->left = l1;
    root->right = r1;
    r1->right = r2;
    
    Solution solution;

    int solution1 = solution.maxDepth(root);

    cout << solution1;

    return 0;
}