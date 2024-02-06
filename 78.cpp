#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void pushSub(vector<int> nums, vector<int> sub, int index, vector<vector<int>>& result) {
        if(index >= nums.size()) {
            result.push_back(sub);
            return;
        }
        pushSub(nums, sub, index + 1, result);
        int number = nums[index];
        sub.push_back(number);
        pushSub(nums, sub, index + 1, result);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        int index = 0;
        pushSub(nums, sub, index, result);
        return result;
    }
};

int main() {
    vector<int> nums1 {1,2,3};
    vector<int> nums2 {0};

    Solution solution;

    vector<vector<int>> solution1 = solution.subsets(nums1);
    vector<vector<int>> solution2 = solution.subsets(nums2);

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

    return 0;
}