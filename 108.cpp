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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1) {
            TreeNode* tree = new TreeNode(nums[0]);
        }
        int middle = nums.size() / 2;
        TreeNode *tree = new TreeNode(nums[middle]);
        vector<int> leftvector(nums.begin(), nums.begin() + middle);
        vector<int> rightvector(nums.begin() + middle + 1, nums.end());
        tree->left = sortedArrayToBST(leftvector);
        tree->right = sortedArrayToBST(rightvector);
        return tree;
    }
};

int main() {
    vector<int> nums1 {-10,-3,0,5,9};
    vector<int> nums2 {1,3};

    Solution solution;

    TreeNode* solution1 = solution.sortedArrayToBST(nums1);
    TreeNode* solution2 = solution.sortedArrayToBST(nums2);

    return 0;
}