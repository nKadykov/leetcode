#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl;

class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) {
            return n ? 1 : 0;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

int main() {
    int n1 = 4;
    int n2 = 25;

    Solution solution;

    int solution1 = solution.tribonacci(n1);
    int solution2 = solution.tribonacci(n2);

    cout << solution1 << endl;
    cout << solution2;

    return 0;
}
