#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> luckyNumbers (std::vector<std::vector<int>>& matrix) {
        int row_number = matrix.size();
        int col_number = matrix[0].size();
        std::vector<int> row_min_vector(row_number, INT_MAX);
        std::vector<int> col_max_vector(col_number, 0);
        for(int row_index = 0; row_index < row_number; ++row_index) {
            for(int col_index = 0; col_index < col_number; ++col_index) {
                int element = matrix[row_index][col_index];
                row_min_vector[row_index] = std::min(row_min_vector[row_index], element);
                col_max_vector[col_index] = std::max(col_max_vector[col_index], element);
            }
        }
        for(int row_index = 0; row_index < row_number; ++row_index) {
            for(int col_index = 0; col_index < col_number; ++col_index) {
                int element = matrix[row_index][col_index];
                if(element == row_min_vector[row_index] && element == col_max_vector[col_index]) {
                    return {element};
                }
            }
        }
        return {};
    }
};

int main() {
    std::vector<std::vector<int>> matrix1 {
        {3,7,8},
        {9,11,13},
        {15,16,17}
    };
    std::vector<std::vector<int>> matrix2 {
        {1,10,4,2},
        {9,3,8,7},
        {15,16,17,12}
    };
    std::vector<std::vector<int>> matrix3 {
        {7,8},
        {1,2}
    };

    Solution solution;

    std::vector<int> solution1 = solution.luckyNumbers(matrix1);
    std::vector<int> solution2 = solution.luckyNumbers(matrix2);
    std::vector<int> solution3 = solution.luckyNumbers(matrix3);

    std::cout << solution1[0] << '\n';
    std::cout << solution2[0] << '\n';
    std::cout << solution3[0] << '\n';

    return 0;
}