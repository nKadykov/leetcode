#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;
                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = std::max(temp, grid[k][l]);
                    }
                }
                grid[i - 1][j - 1] = temp;
            }
        }
        grid.resize(n - 2);
        for(int i = 0; i < n; ++i) {
            grid[i].resize(n - 2);
        }
        return grid;
    }
};

int main() {
    std::vector<std::vector<int>> grid1 {
        {9,9,8,1},
        {5,6,2,6},
        {8,2,6,4},
        {6,2,2,2}
    };
    std::vector<std::vector<int>> grid2 {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,2,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1}
    };

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.largestLocal(grid1);
    std::vector<std::vector<int>> solution2 = solution.largestLocal(grid2);

    for(auto x : solution1) {
        for(auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(auto x : solution2) {
        for(auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}