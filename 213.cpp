#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = nums[0];
        dp1[1] = max (nums[0], nums[1]);
        for(int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return max(dp1[n - 2], dp2[n - 1]);
    }
};

int main() {
    vector<int> nums1 {2,3,2};
    vector<int> nums2 {1,2,3,1};
    vector<int> nums3 {1,2,3};

    Solution solution;

    int solution1 = solution.rob(nums1);
    int solution2 = solution.rob(nums2);
    int solution3 = solution.rob(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}