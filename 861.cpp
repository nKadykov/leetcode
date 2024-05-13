#include <iostream>
#include <vector>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        auto flipRow = [&](int row) {
            for(int col = 0; col < m; ++col) {
                grid[row][col] = 1 - grid[row][col];
            }
        };
        auto flipCol = [&](int col) {
            for(int row = 0; row < n; ++row) {
                grid[row][col] = 1 - grid[row][col];
            }
        };

        auto checkRow = [&](const std::vector<int>& nums) {
            int result = 0;
            for(int num : nums) {
                result = result * 2 + num;
            }
            return result;
        };

        for(int row = 0; row < n; ++row) {
            if(grid[row][0] == 0) {
                flipRow(row);
            }
        }
        for(int col = 1; col < m; ++col) {
            int count = 0;
            for(int row = 0; row < n; ++row) {
                if(grid[row][col] == 1) {
                    count++;
                }
            }
            if(count * 2 < n) {
                flipCol(col);
            }
        }

        int result = 0;
        for(const auto& row : grid) {
            result += checkRow(row);
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<int>> grid1 {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };
    std::vector<std::vector<int>> grid2 {
        {0}
    };

    Solution solution;

    int solution1 = solution.matrixScore(grid1);
    int solution2 = solution.matrixScore(grid2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}