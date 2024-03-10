#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    int solve(const std::string& s, int i, int j, std::vector<std::vector<int>>& dp) {
        if(i >= s.size() || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int result = 0;
        if(s[i] == s[j]) {
            result = solve(s, i + 1, j - 1, dp) + 1;
        }
        else {
            result = std::max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
        }
        return dp[i][j] = result;
    }
public:
    int longestPalindromeSubseq(std::string s) {
        std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(s.size() + 1, -1));
        return solve(s, 0, s.size() - 1, dp);
    }
};

int main() {
    std::string s1 = "bbbab";
    std::string s2 = "cddb";

    Solution solution;

    int solution1 = solution.longestPalindromeSubseq(s1);
    int solution2 = solution.longestPalindromeSubseq(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2;

    return 0;
}