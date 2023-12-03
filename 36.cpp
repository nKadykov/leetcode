#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        multiset<int> numbers; 
        for(int i = 0; i < 9; i++) {
            multiset<int> numbers2;
            int j = 0;
            while(j < 9) {
                numbers2.insert(board[i][j]);
                j++;
            }
            for(int i = 1; i < 10; i++) {
                if(numbers2.count(i + '0') > 1) {
                    result = false;
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            multiset<int> numbers2;
            int j = 0;
            while(j < 9) {
                numbers2.insert(board[j][i]);
                j++;
            }
            for(int i = 1; i < 10; i++) {
                if(numbers2.count(i + '0') > 1) {
                    result = false;
                }
            }
        }
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                multiset<int> numbers;
                for(int k = i; k < (i + 3); k++) {
                    for(int l = j; l < (j + 3); l++) {
                        numbers.insert(board[k][l]);
                    }
                }
                for(int p = 1; p < 10; p++) {
                    if(numbers.count(p + '0') > 1) {
                        result = false;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<char>> board1 {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> board2 {
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'},
        {'5','3','.','.','7','.','.','.','.'}};

    Solution solution;

    bool solution1 = solution.isValidSudoku(board1);
    bool solution2 = solution.isValidSudoku(board2);

    cout << solution1 << '\n';
    cout << solution2 << '\n'; 

    return 0;
}