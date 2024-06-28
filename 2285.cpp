#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> degree(n, 0);
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        std::vector<int> cities(n);
        for (int i = 0; i < n; i++) {
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        long long totalImportance = 0;
        for (int i = 0; i < n; i++) {
            totalImportance += (long long)(n - i) * degree[cities[i]];
        }
        
        return totalImportance;
    }
};

int main() {
    int n1 = 5;
    std::vector<std::vector<int>> roads1 {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    int n2 = 5;
    std::vector<std::vector<int>> roads2 {{0, 3}, {2, 4}, {1, 3}};

    Solution solution;

    int solution1 = solution.maximumImportance(n1, roads1);
    int solution2 = solution.maximumImportance(n2, roads2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}