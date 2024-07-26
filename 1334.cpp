#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

class Solution {
public:
    int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], distance = edge[2];
            graph[node1].emplace_back(node2, distance);
            graph[node2].emplace_back(node1, distance);
        }

        auto get_number_of_neighbors_in_distance = [&](int source) -> int {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
            queue.emplace(0, source);
            std::set<int> visited;

            while (!queue.empty()) {
                auto [distance_to_this_node, cur_node] = queue.top();
                queue.pop();
                if (!visited.count(cur_node)) {
                    visited.insert(cur_node);
                    for (const auto& [neighbor, distance] : graph[cur_node]) {
                        int distance_from_source = distance_to_this_node + distance;
                        if (distance_from_source <= distanceThreshold) {
                            queue.emplace(distance_from_source, neighbor);
                        }
                    }
                }
            }
            return visited.size() - 1;
        };

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int neighbors = get_number_of_neighbors_in_distance(source);
            if (neighbors <= minimum_number) {
                minimum_number = neighbors;
                res = source;
            }
        }

        return res;
    }
};

int main() {
    int n1 = 4;
    std::vector<std::vector<int>> edges1 {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int distance_threshold1 = 4;
    int n2 = 5;
    std::vector<std::vector<int>> edges2 {
        {0,1,2},
        {0,4,8},
        {1,2,3},
        {1,4,2},
        {2,3,1},
        {3,4,1}
    };
    int distance_threshold2 = 2;

    Solution solution;

    int solution1 = solution.findTheCity(n1, edges1, distance_threshold1);
    int solution2 = solution.findTheCity(n2, edges2, distance_threshold2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}