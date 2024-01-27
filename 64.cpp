#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid1 {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    vector<vector<int>> grid2 {
        {1,2,3},
        {4,5,6}
    };

    Solution solution;

    int solution1 = solution.minPathSum(grid1);
    int solution2 = solution.minPathSum(grid2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}