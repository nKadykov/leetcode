#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int solve(int amount, vector<int>& coins, vector<vector<int>>& dp, int index) {
        if(index >= coins.size()) {
            return 0;
        }
        if(amount == 0) {
            return 1;
        }
        if(dp[amount][index] != -1) {
            return dp[amount][index];
        }
        int result = 0;
        for(int i = index; i < coins.size(); i++) {
            if(amount >= coins[i]) {
                result += solve(amount - coins[i], coins, dp, i);
            }
        }
        return dp[amount][index] = result;

    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.rbegin(), coins.rend());
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, -1));
        return solve(amount, coins, dp, 0);
    }
};

int main() {
    int amount1 = 5;
    vector<int> coins1 {1, 2, 5};
    int amount2 = 3;
    vector<int> coins2 {2};
    int amount3 = 10;
    vector<int> coins3 {10};

    Solution solution;

    int solution1 = solution.change(amount1, coins1);
    int solution2 = solution.change(amount2, coins2);
    int solution3 = solution.change(amount3, coins3);

    cout << solution1 << endl;
    cout << solution2 << endl;
    cout << solution3;

    return 0;
}