#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <algorithm>

class Solution {
private:
    std::array<int, 2> findMin(std::vector<int>& row) {
        int x0 = INT_MAX;
        int x1 = INT_MAX;
        for(int x : row) {
            if(x < x0) {
                x1 = std::exchange(x0, x);
            }
            else if(x < x1) {
                x1 = x;
            }
        }
        return {x0, x1};
    }
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        for(int i = 1; i < n; ++i) {
            auto min = findMin(grid[i - 1]);
            for(int j = 0; j < n; ++j) {
                if(grid[i - 1][j] == min[0]) {
                    grid[i][j] += min[1];
                }
                else {
                    grid[i][j] += min[0];
                }
            }
        }
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};

int main() {

    std::vector<std::vector<int>> vector1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> vector2 {
        {7}
    };

    Solution solution;

    auto solution1 = solution.minFallingPathSum(vector1);
    auto solution2 = solution.minFallingPathSum(vector2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}