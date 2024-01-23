#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int begin = 0;
        int end = n - 1;

        while(begin < m && end >= 0) {
            if(matrix[begin][end] == target) {
                return true;
            }
            if(matrix[begin][end] < target) {
                begin++;
            }
            else {
                end--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix1 = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target1 = 5;
    vector<vector<int>> matrix2 {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target2 = 20;

    Solution solution;

    bool solution1 = solution.searchMatrix(matrix1, target1);
    bool solution2 = solution.searchMatrix(matrix2, target2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}