#include <iostream>
#include <vector>
#include <stack>
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
public:
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto it = st.top();
            st.pop();
            TreeNode* node= it;
            if(node->right) {
                st.push(node->right);
            }
            if(node->left) {
                st.push(node->left);
            }
            if(!st.empty()) {
                node->right = st.top();
            }
            node->left = NULL;
        }
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(5);
    TreeNode* node13 = new TreeNode(3);
    TreeNode* node14 = new TreeNode(4);
    TreeNode* node15 = new TreeNode(6);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node11->right = node14;
    node12->right = node15;

    TreeNode* root2 = new TreeNode;

    TreeNode* root3 = new TreeNode(0);

    Solution solution;

    solution.flatten(root1);
    solution.flatten(root2);
    solution.flatten(root3);
    
    return 0;
}