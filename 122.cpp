#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        if(n <= 1) {
            return 0;
        }
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};

int main() {
    vector<int> prices1 {7,1,5,3,6,4};
    vector<int> prices2 {1,2,3,4,5};
    vector<int> prices3 {7,6,4,3,1};

    Solution solution;

    int solution1 = solution.maxProfit(prices1);
    int solution2 = solution.maxProfit(prices2);
    int solution3 = solution.maxProfit(prices3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}