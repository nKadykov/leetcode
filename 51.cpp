#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> result;
    bool check(vector<string> &board, int row, int col) {
        for(int i = 0; i < row; ++i) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        for(int i = 0; i < row; ++i) {
            int left = col - (row - i);
            if(left >= 0 && board[i][left] == 'Q') {
                return false;
            }
        }
        for(int i = 0; i < row; ++i) {
            int right = col + (row - i);
            if(right < board.size() && board[i][right] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board, int n, int row) {
        if(row == n) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(check(board, row, i)) {
                board[row][i] = 'Q';
                solve(board, n , row + 1);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, n, 0);
        return result;
    }
};

int main() {
    int n1 = 1;
    int n2 = 4;

    Solution solution;

    vector<vector<string>> solution1 = solution.solveNQueens(n1);
    vector<vector<string>> solution2 = solution.solveNQueens(n2);

    for(auto s : solution1) {
        for(auto x : s) {
            cout << x << '\n';
        }
    }
    cout << endl;
    for(auto s : solution2) {
        for(auto x : s) {
            cout << x << '\n';
        }
    }

    return 0;
}