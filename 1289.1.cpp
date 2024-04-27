#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        int result = INT_MAX;
        for(int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; j++) {
                int temp = INT_MAX;
                for(int k = 0; k < n; ++k) {
                    if(k != j) {
                        temp = std::min(temp, grid[i][j] + dp[i - 1][k]); 
                    }
                    dp[i][j] = temp;
                }
            }
        }
        for(int j = 0; j < n; ++j) {
            result = std::min(result, dp[n - 1][j]);
        }
        return result;
    }
};

int main() {

    std::vector<std::vector<int>> vector1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> vector2 {
        {7}
    };

    Solution solution;

    auto solution1 = solution.minFallingPathSum(vector1);
    auto solution2 = solution.minFallingPathSum(vector2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}