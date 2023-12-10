#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return profit;
    }
};

int main() {
    vector<int> prices1 {7,1,5,3,6,4};
    vector<int> prices2 {7,6,4,3,1};

    Solution solution;

    int solution1 = solution.maxProfit(prices1);
    int solution2 = solution.maxProfit(prices2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}