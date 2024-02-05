#include <iostream>
#include <vector>
using namespace std;

class Solution {
    void setRowColumn(vector<vector<int>>& result, int i, int j) {
        int m = result.size();
        int n = result[0].size();
        for(int k = 0; k < m; k++) {
            result[k][j] = 0;
        }
        for(int l = 0; l < n; l++) {
            result[i][l] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != 0) {
                    result[i][j] = mat[i][j];
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    setRowColumn(result, i, j);
                }
            }
        }
        mat = result;
    }
};

int main() {
    vector<vector<int>> matrix1 {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    vector<vector<int>> matrix2 {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    Solution solution;

    solution.setZeroes(matrix1);
    solution.setZeroes(matrix2);

    for(auto x : matrix1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(auto x : matrix2) {
        for(auto y : x) {
            cout << y << ' '; 
        }
        cout << '\n';
    }

    return 0;
}