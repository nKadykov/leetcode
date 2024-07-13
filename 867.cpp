#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> result(matrix[0].size(), std::vector<int>(matrix.size(), 0));
        for(size_t i = 0; i < matrix.size(); ++i) {
            for(size_t j = 0; j < matrix[0].size(); ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> matrix1 {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<std::vector<int>> matrix2 {
        {1,2,3},
        {4,5,6},
    };

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.transpose(matrix1);
    std::vector<std::vector<int>> solution2 = solution.transpose(matrix2);

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