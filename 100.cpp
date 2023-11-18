#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *q = new TreeNode(1);
    TreeNode *q1 = new TreeNode(2);
    TreeNode *q2 = new TreeNode(3);
    p->left = p1;
    p->right = p2;
    q->left = q1;
    q->right = q2;

    Solution solution;

    bool solution1;

    solution1 = solution.isSameTree(p, q);

    cout << solution1;

    return 0;
}