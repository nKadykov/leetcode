#include <iostream>
#include <vector>
#include <cfloat>
#include <queue>
#include <algorithm>

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;
        double current_quality = 0;
        std::vector<std::pair<double, int>> ratio;
        std::priority_queue<int> high_quality;

        for(int i = 0; i < n; ++i) {
            ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
        }

        sort(ratio.begin(), ratio.end());

        for(int i = 0; i < n; ++i) {
            double r = ratio[i].first;
            int q = ratio[i].second;
            current_quality += q;
            high_quality.push(q);
            if(high_quality.size() > k) {
                current_quality -= high_quality.top();
                high_quality.pop();
            }
            if(high_quality.size() == k) {
                result = std::min(result, current_quality * r);
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> quality1 {10, 20, 5};
    std::vector<int> quality2 {3, 1, 10, 10, 1};
    std::vector<int> wage1 {70, 50, 30};
    std::vector<int> wage2 {4, 8, 2, 2, 7};
    int k1 = 2;
    int k2 = 3;

    Solution solution;

    double solution1 = solution.mincostToHireWorkers(quality1, wage1, k1);
    double solution2 = solution.mincostToHireWorkers(quality2, wage2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}