#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> result(n);
        std::vector<std::vector<int>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; ++i) {
            std::vector<bool> visit(n, false);
            dfs(graph, i, i, result, visit);
        }
        for(int i = 0; i < n; ++i) {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }
private:
    void dfs(std::vector<std::vector<int>>& graph, int parent, int curr, std::vector<std::vector<int>>& result, std::vector<bool>& visit) {
        visit[curr] = true;
        for(int dest : graph[curr]) {
            if(!visit[dest]) {
                result[dest].push_back(parent);
                dfs(graph, parent, dest, result, visit);
            }
        }
    }
};

int main() {
    int n1 = 8;
    std::vector<std::vector<int>> edge_list1 {{0,3}, {0,4}, {1,3}, {2,4}, {2,7}, {3,5}, {3,6}, {3,7}, {4,6}};
    int n2 = 5;
    std::vector<std::vector<int>> edge_list2 {{0,1}, {0,2}, {0,3}, {0, 4}, {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}};

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.getAncestors(n1, edge_list1);
    std::vector<std::vector<int>> solution2 = solution.getAncestors(n2, edge_list2);

    for(auto& x : solution1) {
        for(auto& i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(auto& x : solution2) {
        for(auto& i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}