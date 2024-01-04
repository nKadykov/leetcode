#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        sort(nums.begin(), nums.end(), greater<int>());
        int low = 0;
        int high = nums.size() / 2;
        while(low < nums.size() / 2 && high < nums.size()) {
            result.push_back(nums[high++]);
            result.push_back(nums[low++]);
        }
        while(high < nums.size()) {
            result.push_back(nums[high++]);
        }
        nums = result;
    }
};

int main() {
    vector<int> nums1 {1,5,1,1,6,4};
    vector<int> nums2 {1,3,2,2,3,1};

    Solution solution;

    solution.wiggleSort(nums1);
    solution.wiggleSort(nums2);

    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}