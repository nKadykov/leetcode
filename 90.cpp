#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void sub(vector<vector<int>>& result, vector<int>& s, int ind, vector<int> nums) {
        result.push_back(s);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i - 1]) {
                continue;
            }
            s.push_back(nums[i]);
            sub(result, s, i + 1, nums);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> s;
        sort(nums.begin(), nums.end());
        sub(result, s, 0, nums);
        return result;
    }
};

int main() {
    vector<int> nums1 {1,2,2};
    vector<int> nums2 {0};

    Solution solution;

    vector<vector<int>> solution1 = solution.subsetsWithDup(nums1);
    vector<vector<int>> solution2 = solution.subsetsWithDup(nums2);

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