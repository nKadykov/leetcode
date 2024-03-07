#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for(int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        for(int i = 1; i <= n; i++) {
            if(dp[i] == 1) {
                continue;
            }
            int root = sqrt(i);
            int mn = INT_MAX;
            for(int j = 1; j <= root; j++) {
                mn = min(mn, dp[j * j] + dp[i - j * j]);
            }
            dp[i] = mn;
        }
        return dp[n];
    }
};

int main() {
    int n1 = 12;
    int n2 = 13;

    Solution solution;

    int solution1 = solution.numSquares(n1);
    int solution2 = solution.numSquares(n2);

    cout << solution1 << endl;
    cout << solution2;

    return 0;
}