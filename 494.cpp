#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto s : nums) {
            sum += s;
        }
        if(target > sum || target < -sum) {
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));
        int tr = sum;
        int ntarget = target + tr;
        dp[0][tr - nums[0]] += 1;
        dp[0][tr + nums[0]] += 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= 2 * sum; j++) {
                if(j - nums[i] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
                if(j + nums[i] <= 2 * sum) {
                    dp[i][j] += dp[i - 1][j + nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][ntarget];
    }
};

int main() {
    vector<int> nums1 {1, 1, 1, 1, 1};
    vector<int> nums2 {1};
    int target1 = 3;
    int target2 = 1;

    Solution solution;

    int solution1 = solution.findTargetSumWays(nums1, target1);
    int solution2 = solution.findTargetSumWays(nums2, target2);

    cout << solution1 << endl;
    cout << solution2;

    return 0;
}