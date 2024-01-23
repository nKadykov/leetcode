#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int result = false;
        
        for(int i = 0; i < matrix.size(); i++) {
            int left = 0;
            int right = matrix[0].size() - 1;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(matrix[i][mid] == target) {
                    return true;
                }
                else if(matrix[i][mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }

        return result;
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