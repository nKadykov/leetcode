#include <iostream>
#include <vector>
#include <queue>

class Solution {
    std::vector<int> row_w = {0, 0, -1, 1};
    std::vector<int> col_l = {-1, 1, 0, 0};
    void bfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& score, int n) {
        std::queue<std::pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            int s = score[x][y];
            for(int i = 0; i < 4; i++) {
                int new_x = x + row_w[i];
                int new_y = y + col_l[i];
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && score[new_x][new_y] > 1 + s) {
                    score[new_x][new_y] = 1 + s;
                    q.push({new_x, new_y});
                }
            }
        }
    }
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) {
            return 0;
        }
        std::vector<std::vector<int>> score(n, std::vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(n, false));
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});
        while(!pq.empty()) {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();
            if(temp.first == n - 1 && temp.second == n - 1) {
                return safe;
            }
            vis[temp.first][temp.second] = true;
            for(int i = 0; i < 4; ++i) {
                int new_x = temp.first + row_w[i];
                int new_y = temp.second + col_l[i];
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !vis[new_x][new_y]) {
                    int s = std::min(safe, score[new_x][new_y]);
                    pq.push({s, {new_x, new_y}});
                    vis[new_x][new_y] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    std::vector<std::vector<int>> grid1 {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> grid2 {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}
    };

    Solution solution;

    int solution1 = solution.maximumSafenessFactor(grid1);
    int solution2 = solution.maximumSafenessFactor(grid2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}