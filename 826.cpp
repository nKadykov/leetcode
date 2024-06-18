#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        std::vector<std::pair<int, int>> info;
        for(int i = 0; i < difficulty.size(); i++) {
            info.emplace_back(difficulty[i], profit[i]);
        }
        std::sort(info.begin(), info.end());
        std::vector<std::pair<int, int>> max_profit_for_difficulty;
        int max_profit = 0;
        for(auto& i : info) {
            int d = i.first;
            int p = i.second;
            max_profit = std::max(max_profit, p);
            max_profit_for_difficulty.emplace_back(d, max_profit);
        }
        int total_profit = 0;
        for(int w : worker) {
            int index = binarySearch(max_profit_for_difficulty, w);
            if(index >= 0 && w >= max_profit_for_difficulty[index].first) {
                total_profit += max_profit_for_difficulty[index].second;
            }
        }
        return total_profit;
    }
private:
    int binarySearch(std::vector<std::pair<int, int>>& list, int target) {
        int left = 0, right = list.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list[mid].first <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    std::vector<int> difficulty1 = {2,4,6,8,10};
    std::vector<int> profit1 = {10,20,30,40,50};
    std::vector<int> worker1 = {4,5,6,7};
    std::vector<int> difficulty2 = {85,47,57};
    std::vector<int> profit2 = {24,66,99};
    std::vector<int> worker2 = {40,25,25};

    Solution solution;

    int solution1 = solution.maxProfitAssignment(difficulty1, profit1, worker1);
    int solution2 = solution.maxProfitAssignment(difficulty2, profit2, worker2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}