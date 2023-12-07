#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(nums, result, 0);
        return result;
    }
    void solve(vector<int>& nums, vector<vector<int>>& result, int index) {
        if(index >= nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};

int main() {
    vector<int> nums1 {1, 2, 3};
    vector<int> nums2 {0, 1};
    vector<int> nums3 {1};

    Solution solution;

    vector<vector<int>> solution1 = solution.permute(nums1);
    vector<vector<int>> solution2 = solution.permute(nums2);
    vector<vector<int>> solution3 = solution.permute(nums3);

    
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
    cout << '\n';
    return 0;
}
