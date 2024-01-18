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
    int val = INT_MIN;
    int freq = 0;
    int max = 0;
    void mode(TreeNode* root, vector<int>& result) {
        if(root == nullptr) {
            return;
        }
        mode(root->left, result);
        if(val == root->val) {
            freq++;
        }
        else {
            val = root->val;
            freq = 1;
        }
        if(freq > max) {
            max = freq;
            result = {root->val};
        }
        else if(freq == max) {
            result.push_back(root->val);
        }
        mode(root->right, result);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        mode(root, result);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node11 = new TreeNode(2);
    TreeNode* node12 = new TreeNode(2);
    root1->right = node11;
    node11->left = node12;

    TreeNode* root2 = new TreeNode(1);

    Solution solution;

    vector<int> solution1 = solution.findMode(root1);
    vector<int> solution2 = solution.findMode(root2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}