#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ind;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                ind.push_back(i);
            }
        }
        return ind;
    }
};

int main() {
    vector<int> nums1 {1,2,5,2,3};
    vector<int> nums2 {1,2,5,2,3};
    vector<int> nums3 {1,2,5,2,3};
    int target1 = 2;
    int target2 = 3;
    int target3 = 5;

    Solution solution;

    vector<int> solution1 = solution.targetIndices(nums1, target1);
    vector<int> solution2 = solution.targetIndices(nums2, target2);
    vector<int> solution3 = solution.targetIndices(nums3, target3);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution3) {
        cout << x << ' ';
    }

    return 0;
}