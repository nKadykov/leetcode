#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    int solve(int start, int end, std::vector<std::vector<int>>& dp) {
        if(start >= end) {
            return 0;
        }
        if(dp[start][end] != -1) {
            return dp[start][end];
        }
        int result = INT_MAX;
        for(int i = start; i < end; i++) {
            result = std::min(result, i + std::max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
        }
        dp[start][end] = result;
        return dp[start][end];
    }
public:
    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, -1));
        return solve(1, n, dp);
    }
};

int main() {
    int n1 = 10;
    int n2 = 1;
    int n3 = 2;

    Solution solution;

    int solution1 = solution.getMoneyAmount(n1);
    int solution2 = solution.getMoneyAmount(n2);
    int solution3 = solution.getMoneyAmount(n3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}