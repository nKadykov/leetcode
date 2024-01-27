#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        else {
            dp[0][0] = 1;
        }
        for(int l = 1; l < m; l++) {
            if(obstacleGrid[l][0] == 1) {
                dp[l][0] = 0;
            }
            else {
                dp[l][0] = dp[l - 1][0];
            }
        }
        for(int k = 1; k < n; k++) {
            if(obstacleGrid[0][k] == 1) {
                dp[0][k] = 0;
            }
            else {
                dp[0][k] = dp[0][k - 1];
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else 
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> obstacleGrid1 {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    vector<vector<int>> obstacleGrid2 {
        {0,1},
        {0,0}
    };

    Solution solution;

    int solution1 = solution.uniquePathsWithObstacles(obstacleGrid1);
    int solution2 = solution.uniquePathsWithObstacles(obstacleGrid2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}