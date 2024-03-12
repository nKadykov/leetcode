#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};

int main() {
    vector<int> cost1 {10, 15, 20};
    vector<int> cost2 {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    Solution solution;

    int solution1 = solution.minCostClimbingStairs(cost1);
    int solution2 = solution.minCostClimbingStairs(cost2);

    cout << solution1 << endl;
    cout << solution2;

    return 0;
}