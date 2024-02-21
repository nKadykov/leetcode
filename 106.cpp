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
    TreeNode* solve(vector<int>& inorder, vector<int> postorder, unordered_map<int, int>& mp, int i, int j, int k) {
        if(i == j) {
            return new TreeNode(inorder[i]);
        }
        for(int l = k; l >= 0; l--) {
            if(mp[postorder[l]] >= i && mp[postorder[l]] <= j) {
                TreeNode* root = new TreeNode(postorder[l]);
                root->left = solve(inorder, postorder, mp, i, mp[postorder[l]] - 1, l - 1);
                root->right = solve(inorder, postorder, mp, mp[postorder[l]] + 1, j, l - 1);
                return root;
            }
        }
        return NULL;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, mp, 0, inorder.size() - 1, inorder.size() - 1);
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
    vector<int> inorder1 {9,3,15,20,7};
    vector<int> postorder1 {9,15,7,20,3};
    vector<int> inorder2 {-1};
    vector<int> postorder2 {-1};

    Solution solution;

    TreeNode* solution1 = solution.buildTree(inorder1, postorder1);
    TreeNode* solution2 = solution.buildTree(inorder2, postorder2);

    print(solution1);
    cout << endl;
    print(solution2);

    return 0;
}