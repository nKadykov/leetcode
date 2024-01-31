#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    result += 4;
                    if(i > 0 && grid[i - 1][j] == 1) {
                        result -= 2;
                    }
                    if(j > 0 && grid[i][j - 1] == 1) {
                        result -= 2;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> grid1 {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    vector<vector<int>> grid2 {
        {1}
    };
    vector<vector<int>> grid3 {
        {1,0}
    };

    Solution solution;

    int solution1 = solution.islandPerimeter(grid1);
    int solution2 = solution.islandPerimeter(grid2);
    int solution3 = solution.islandPerimeter(grid3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}