#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = grid[0].size() - 1; j >= 0; j--) {
                if(grid[i][j] < 0) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> grid1 {
        {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3}
    };
    vector<vector<int>> grid2 {
        {3,2},
        {1,0},
    };

    Solution solution;

    int solution1 = solution.countNegatives(grid1);
    int solution2 = solution.countNegatives(grid2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}