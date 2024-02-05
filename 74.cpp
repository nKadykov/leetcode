#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size();
        int column = mat[0].size();
        int first = 0;
        int last = (row * column) - 1;
        while(first <= last) {
            int mid = (first + last) / 2;
            int r = mid / column;
            int c = mid % column;
            if(mat[r][c] == target) {
                return true;
            }
            else if(mat[r][c] < target) {
                first = mid + 1;
            }
            else {
                last = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix1 {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    vector<vector<int>> matrix2 {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target1 = 3;
    int target2 = 13;

    Solution solution;

    bool solution1 = solution.searchMatrix(matrix1, target1);
    bool solution2 = solution.searchMatrix(matrix2, target2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}