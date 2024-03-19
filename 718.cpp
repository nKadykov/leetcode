#include <iostream>
#include <vector>

class Solution {
    int solve(std::vector<int>& v1, std::vector<int>& v2, int n, int m) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1));
        int result = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if(v1[i - 1] == v2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    result = std::max(result, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        return solve(nums1, nums2, n, m);
    }
};

int main() {
    std::vector<int> nums11 {1, 2, 3, 2, 1};
    std::vector<int> nums12 {3, 2, 1, 4, 7};
    std::vector<int> nums21 {0, 0, 0, 0, 0};
    std::vector<int> nums22 {0, 0, 0, 0, 0};

    Solution solution;

    int solution1 = solution.findLength(nums11, nums12);
    int solution2 = solution.findLength(nums21, nums22);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}