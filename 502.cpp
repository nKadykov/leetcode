#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects;
        for(int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        std::sort(projects.begin(), projects.end());
        std::priority_queue<int> max_heap;
        int i = 0;
        for(int j = 0; j < k; ++j) {
            while(i < n && projects[i].first <= w) {
                max_heap.push(projects[i].second);
                i++;
            }
            if(max_heap.empty()) {
                break;
            }
            w += max_heap.top();
            max_heap.pop();
        }
        return w;
    }
};

int main() {
    int k1 = 2;
    int w1 = 0;
    std::vector<int> profits1 {1, 2, 3};
    std::vector<int> capital1 {0, 1, 1};
    int k2 = 3;
    int w2 = 0;
    std::vector<int> profits2 {1, 2, 3};
    std::vector<int> capital2 {0, 1, 2};

    Solution solution;

    int solution1 = solution.findMaximizedCapital(k1, w1, profits1, capital1);
    int solution2 = solution.findMaximizedCapital(k2, w2, profits2, capital2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}