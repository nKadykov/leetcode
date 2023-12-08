#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int left = 0;
        int right = N - 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < N; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix1 {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> matrix2 {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };

    Solution solution;

    solution.rotate(matrix1);
    solution.rotate(matrix2);

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