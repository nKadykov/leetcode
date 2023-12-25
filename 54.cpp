#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int up = 0;
        int down = matrix.size() - 1;
        vector<int> result;
        while(left <= right || up <= down) {
            if(up <= down) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[up][i]);
                }
                up++;
            } 
            if(left <= right) {
                for(int i = up; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(up <= down) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            if(left <= right) {
                for(int i = down; i >= up; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> matrix1 {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrix2 {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    Solution solution;

    vector<int> solution1 = solution.spiralOrder(matrix1);
    vector<int> solution2 = solution.spiralOrder(matrix2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}