#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i < amount + 1; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if(dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins1 {1,2,5};
    int amount1 = 11;
    vector<int> coins2 {2};
    int amount2 = 3;
    vector<int> coins3 {1};
    int amount3 = 0;

    Solution solution;

    int solution1 = solution.coinChange(coins1, amount1);
    int solution2 = solution.coinChange(coins2, amount2);
    int solution3 = solution.coinChange(coins3, amount3);

    cout << solution1 << endl;
    cout << solution2 << endl;
    cout << solution3;

    return 0;
}