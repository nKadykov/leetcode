#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp) {
        if(preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;
        root->left = solve(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
        root->right = solve(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int n = preorder.size();
        int m = inorder.size();
        TreeNode* root = solve(preorder, 0, n - 1, inorder, 0, m - 1, mp);
        return root;
    }
};

void print(TreeNode* root) {
    cout << root->val << ' ';
    if(root->left) {
        print(root->left);
    }
    if(root->right) {
        print(root->right);
    }
}

int main() {
    vector<int> preorder1 {3,9,20,15,7};
    vector<int> inorder1 {9,3,15,20,7};
    vector<int> preorder2 {-1};
    vector<int> inorder2 {-1};

    Solution solution;

    TreeNode* solution1 = solution.buildTree(preorder1, inorder1);
    TreeNode* solution2 = solution.buildTree(preorder2, inorder2);

    print(solution1);
    cout << endl;
    print(solution2);

    return 0;
}