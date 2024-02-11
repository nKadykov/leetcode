#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minimum(0, 0, triangle, n, dp);
    }
    int minimum(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == n - 1) {
            return triangle[i][j];
        }
        int down = triangle[i][j] + minimum(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + minimum(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = min(down, diagonal);
    }
};

int main() {
    vector<vector<int>> triangle1 {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    vector<vector<int>> triangle2 {
        {-10}
    };

    Solution solution;

    int solution1 = solution.minimumTotal(triangle1);
    int solution2 = solution.minimumTotal(triangle2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}