#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};

int main() {
    vector<int> nums1 {3,2,3};
    vector<int> nums2 {2,2,1,1,1,2,2};

    Solution solution;

    int solution1 = solution.majorityElement(nums1);
    int solution2 = solution.majorityElement(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}