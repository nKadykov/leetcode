#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& row_sum, std::vector<int>& col_sum) {
        int row_number = row_sum.size();
        int col_number = col_sum.size();
        std::vector<std::vector<int>> result(row_number, std::vector<int>(col_number, 0));
        int i = 0;
        int j = 0;
        while(i < row_number && j < col_number) {
            int val = std::min(row_sum[i], col_sum[j]);
            result[i][j] = val;
            row_sum[i] -= val;
            col_sum[j] -= val;
            if(row_sum[i] == 0) {
                i++;
            }
            if(col_sum[j] == 0) {
                j++;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> row_sum1 = {3, 8};
    std::vector<int> col_sum1 = {4, 7};
    std::vector<int> row_sum2 = {5, 7, 10};
    std::vector<int> col_sum2 = {8, 6, 8};

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.restoreMatrix(row_sum1, col_sum1);
    std::vector<std::vector<int>> solution2 = solution.restoreMatrix(row_sum2, col_sum2);

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