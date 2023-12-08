#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> resultSet;
        vector<vector<int>> result;
        solve(nums, 0, resultSet);
        for(auto& x : resultSet) {
            result.push_back(x);
        }
        return result;
    }
    void solve(vector<int>& nums, int index, set<vector<int>>& resultSet) {
        if(index >= nums.size() - 1) {
            resultSet.insert(nums);
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, index + 1, resultSet);
            swap(nums[i], nums[index]);
        }
    }
};

int main() {
    vector<int> nums1 {1, 1, 2};
    vector<int> nums2 {1, 2, 3};

    Solution solution;

    vector<vector<int>> solution1 = solution.permuteUnique(nums1);
    vector<vector<int>> solution2 = solution.permuteUnique(nums2);

    
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
