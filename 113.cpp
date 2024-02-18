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
    void addition(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int> temp, int sum) {
        if(!root) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                result.push_back(temp);
            }
            else {
                return;
            }
        }
        addition(root->left, targetSum, result, temp, sum);
        addition(root->right, targetSum, result, temp, sum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        int sum = 0;
        addition(root, targetSum, result, temp, sum);
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(5);
    TreeNode* node11 = new TreeNode(4);
    TreeNode* node12 = new TreeNode(8);
    TreeNode* node13 = new TreeNode(11);
    TreeNode* node14 = new TreeNode(13);
    TreeNode* node15 = new TreeNode(4);
    TreeNode* node16 = new TreeNode(7);
    TreeNode* node17 = new TreeNode(2);
    TreeNode* node18 = new TreeNode(5);
    TreeNode* node19 = new TreeNode(1);
    root1->left = node11;
    root1->right = node12;
    node11->left = node13;
    node12->left = node14;
    node12->right = node15;
    node13->left = node16;
    node13->right = node17;
    node15->left = node18;
    node15->right = node19;
    int targetSum1 = 22;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* node21 = new TreeNode(2);
    TreeNode* node22 = new TreeNode(3);
    root2->left = node21;
    root2->right = node22;
    int targetSum2 = 5;

    TreeNode* root3 = new TreeNode(1);
    TreeNode* node31 = new TreeNode(2);
    root3->left = node31;
    int targetSum3 = 0;

    Solution solution;

    vector<vector<int>> solution1 = solution.pathSum(root1, targetSum1);
    vector<vector<int>> solution2 = solution.pathSum(root2, targetSum2);
    vector<vector<int>> solution3 = solution.pathSum(root3, targetSum3);

    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : solution3) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}