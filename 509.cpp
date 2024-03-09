#include <iostream>
#include <vector>

class Solution {
public:
    int fib(int n) {
        std::vector<int> dp(n + 1, 0);
        if(n == 0) {
            return dp[0];
        }
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    int n1 = 2;
    int n2 = 3;
    int n3 = 4;

    Solution solution;

    int solution1 = solution.fib(n1);
    int solution2 = solution.fib(n2);
    int solution3 = solution.fib(n3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3;

    return 0;
}