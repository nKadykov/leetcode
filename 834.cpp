#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> result;
    void dfs(int node, int parent) {
        for(int child : graph[node]) {
            if(child != parent) {
                dfs(child, node);
                count[node] += count[child];
                result[node] += result[child] + count[child];
            }
        }
    }
    void dfs2(int node, int parent) {
        for(int child : graph[node]) {
            if(child != parent) {
                result[child] = result[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        count = vector<int>(n, 1);
        result = vector<int>(n, 0);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);

        return result;
    }
};

int main() {

    int n1 = 6;
    int n2 = 1;
    int n3 = 2;

    vector<vector<int>> edges1 {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5}
    };
    vector<vector<int>> edges2 {};
    vector<vector<int>> edges3 {
        {1, 0}
    };

    Solution solution;

    vector<int> solution1 = solution.sumOfDistancesInTree(n1, edges1);
    vector<int> solution2 = solution.sumOfDistancesInTree(n2, edges2);
    vector<int> solution3 = solution.sumOfDistancesInTree(n3, edges3);

    for(auto &x : solution1) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution2) {
        cout << x << ' ';
    }
    cout << endl;
    for(auto &x : solution3) {
        cout << x << ' ';
    }

    return 0;
}