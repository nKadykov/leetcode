#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <numeric>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        vector<int> nums;
        if(!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                q.pop();
                nums.push_back(curr->val);
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            double f = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
            nums.clear();
            result.push_back(f);
        }
        return result;
    }
};

int main() {
    TreeNode* root1 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(9);
    TreeNode* node12 = new TreeNode(20);
    TreeNode* node13 = new TreeNode(15);
    TreeNode* node14 = new TreeNode(7);
    root1->left = node11;
    root1->right = node12;
    node12->left = node13;
    node12->right = node14;

    TreeNode* root2 = new TreeNode(3);
    TreeNode* node21 = new TreeNode(9);
    TreeNode* node22 = new TreeNode(20);
    TreeNode* node23 = new TreeNode(15);
    TreeNode* node24 = new TreeNode(7);
    root2->left = node21;
    root2->right = node22;
    node21->left = node23;
    node21->right = node24;

    Solution solution;

    vector<double> solution1 = solution.averageOfLevels(root1);
    vector<double> solution2 = solution.averageOfLevels(root2);

    for(auto x : solution1) {
        cout << setprecision(5) << fixed << x << ' ' ;
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << setprecision(5) << fixed << x << ' ';
    }

    return 0;
}