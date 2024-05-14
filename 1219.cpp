#include <iostream>
#include <vector>

class Solution {
    std::vector<int> row_w = {1, -1, 0, 0};
    std::vector<int> col_l = {0, 0, -1, 1};
    int max_gold = 0;

    int dfs(std::vector<std::vector<int>>& grid, int x, int y, int n, int m) {
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 0;
        }
        int curr = grid[x][y];
        grid[x][y] = 0;
        int local_max = curr;
        for(int i = 0; i < 4; ++i) {
            int new_x = x + row_w[i];
            int new_y = y + col_l[i];
            local_max = std::max(local_max, curr + dfs(grid, new_x, new_y, n, m));
        }
        grid[x][y] = curr;
            
        return local_max;
    }
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] != 0) {
                    max_gold = std::max(max_gold, dfs(grid, i, j, n, m));
                }
            }
        }
        return max_gold;
    }
};

int main() {
    std::vector<std::vector<int>> grid1 {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };
    std::vector<std::vector<int>> grid2 {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };

    Solution solution;

    int solution1 = solution.getMaximumGold(grid1);
    int solution2 = solution.getMaximumGold(grid2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}