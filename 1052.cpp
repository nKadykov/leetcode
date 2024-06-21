#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        int initialSatisfaction = 0;
        int maxExtraSatisfaction = 0;
        int currentWindowSatisfaction = 0;
        
        for (int i = 0; i < customers.size(); ++i) {
            if (grumpy[i] == 0) {
                initialSatisfaction += customers[i];
            } else if (i < minutes) {
                currentWindowSatisfaction += customers[i];
            }
        }
        
        maxExtraSatisfaction = currentWindowSatisfaction;
        
        for (int i = minutes; i < customers.size(); ++i) {
            currentWindowSatisfaction += customers[i] * grumpy[i];
            currentWindowSatisfaction -= customers[i - minutes] * grumpy[i - minutes];
            maxExtraSatisfaction = std::max(maxExtraSatisfaction, currentWindowSatisfaction);
        }
        
        return initialSatisfaction + maxExtraSatisfaction;   
    }
};

int main() {
    std::vector<int> customers1 {1,0,1,2,1,1,7,5};
    std::vector<int> grumpy1 {0,1,0,1,0,1,0,1};
    int minutes1 = 3;
    std::vector<int> customers2 {1};
    std::vector<int> grumpy2 {0};
    int minutes2 = 1;

    Solution solution;

    int solution1 = solution.maxSatisfied(customers1, grumpy1, minutes1);
    int solution2 = solution.maxSatisfied(customers2, grumpy2, minutes2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}