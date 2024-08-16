#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> result(n);
        for(int i = 0; i < n; ++i)
        {
            int length = 1;
            for(int j = 0; j < m; ++j)
            {
                if(grid[j][i] < 0)
                    length = std::max(length, int(std::log10(-grid[j][i]) + 1) + 1);
                else if(grid[j][i] > 9)
                    length = std::max(length, int(std::log10(grid[j][i]) + 1));
            }
            result[i] = length;
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> grid1 = {{1}, {22}, {333}};
    std::vector<std::vector<int>> grid2 = {{-15,1,3}, {15,7,12}, {5,6,-2}};
    
    Solution solution;

    std::vector<int> solution1 = solution.findColumnWidth(grid1);
    std::vector<int> solution2 = solution.findColumnWidth(grid2);

    for(auto x : solution1)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution2)
    {
        std::cout << x << ' ';
    }

    return 0;
}