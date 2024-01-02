#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

int main() {
    vector<int> nums1 {3,2,1,5,6,4};
    vector<int> nums2 {3,2,3,1,2,4,5,5,6};
    int k1 = 2;
    int k2 = 4;

    Solution solution;

    int solution1 = solution.findKthLargest(nums1, k1);
    int solution2 = solution.findKthLargest(nums2, k2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}