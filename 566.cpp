#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
        if(mat[0].size() * mat.size() != r * c) {
            return mat;
        }
        std::vector<std::vector<int>> result;
        std::vector<int> aux(c, 0);
        int i, j, rows = mat.size(), columns = mat[0].size(), row = 0, column = 0;
        for(i = 0; i < r; ++i) {
            result.push_back(aux);
        }
        for(i = 0; i < rows; ++i) {
            for(j = 0; j < columns; ++j) {
                result[row][column] = mat[i][j];
                ++column;
                if(column == c) {
                    column = 0;
                    ++row;
                }
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> mat1 {{1, 2}, {3, 4}};
    int r1 = 1;
    int c1 = 4;
    std::vector<std::vector<int>> mat2 {{1, 2}, {3, 4}};
    int r2 = 2;
    int c2 = 4;

    Solution solution;

    std::vector<std::vector<int>> solution1 = solution.matrixReshape(mat1, r1, c1);
    std::vector<std::vector<int>> solution2 = solution.matrixReshape(mat2, r2, c2);

    for(auto x : solution1) {
        for(auto i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        for(auto i : x) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}