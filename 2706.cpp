#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        std::sort(prices.begin(), prices.end());
        if(prices[0] + prices[1] <= money) {
            return money - (prices[1] + prices[0]);
        }
        return money;
    }
};

int main() {
    std::vector<int> prices1 {1,2,2};
    int money1 = 3;
    std::vector<int> prices2 {3,2,3};
    int money2 = 3;

    Solution solution;

    int solution1 = solution.buyChoco(prices1, money1);
    int solution2 = solution.buyChoco(prices2, money2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}