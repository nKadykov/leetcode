#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<int> curr(2, 0);
        std::vector<int> after(2, 0);
        std::vector<int> next(2, 0);
        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= 1; ++j) {
                int profit = 0;
                if(j == 0) {
                    int bgt = -prices[i] + after[1];
                    int skip = after[0];
                    profit = std::max(bgt, skip);
                } else {
                    int sell = 0;
                    if(i + 2 <= n)
                        sell = prices[i] + next[0];
                    else
                        sell = prices[i];
                    int skip = after[1];
                    profit = std::max(sell, skip);
                }
                curr[j] = profit;
            }
            next = after;
            after = curr;
        }
        return curr[0];
    }
};

int main() {
    std::vector<int> prices1 {1,2,3,0,2};
    std::vector<int> prices2 {1};

    Solution solution;

    int solution1 = solution.maxProfit(prices1);
    int solution2 = solution.maxProfit(prices2);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';

    return 0;
}