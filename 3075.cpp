#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), std::greater<int>());
        long long result = 0;
        int index = 0;
        for(int i = index; i < k; ++i) {
            result += std::max(happiness[i] - i, 0);
        }
        return result;
    }
};

int main() {
    std::vector<int> happiness1 {1, 2, 3};
    std::vector<int> happiness2 {1, 1, 1, 1};
    std::vector<int> happiness3 {2, 3, 4, 5};
    int k1 = 2;
    int k2 = 2;
    int k3 = 1;

    Solution solution;

    int solution1 = solution.maximumHappinessSum(happiness1, k1);
    int solution2 = solution.maximumHappinessSum(happiness2, k2);
    int solution3 = solution.maximumHappinessSum(happiness3, k3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}