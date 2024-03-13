#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    int solve(std::string& s1, std::string& s2) {
        int n = s1.size();
        int m = s2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(std::string word1, std::string word2) {
        return word1.size() + word2.size() - 2 * solve(word1, word2);
    }
};

int main() {
    std::string word11 = "sea";
    std::string word12 = "eat";
    std::string word21 = "leetcode";
    std::string word22 = "etco";

    Solution solution;

    int solution1 = solution.minDistance(word11, word12);
    int solution2 = solution.minDistance(word21, word22);

    std::cout << solution1 << std::endl;
    std::cout << solution2;

    return 0;
}