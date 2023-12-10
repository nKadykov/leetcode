#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int number = rowIndex + 1;
        vector<int> result (rowIndex + 1, 1);
        vector<int> result1 (rowIndex + 1, 1);
        if(rowIndex == 0) {
            return {1};
        }
        for(int i = 2; i < rowIndex + 1; i++) {
            for(int j = 1; j < i; j++) {
                result[j] = result1[j - 1] + result1[j];
            }
            for(int k = 1; k < rowIndex; k++) {
                result1[k] = result[k];
            }
        }
        return result;
    }
};

int main() {
    int rowIndex1 = 3;
    int rowIndex2 = 0;
    int rowIndex3 = 1;

    Solution solution;

    vector<int> solution1 = solution.getRow(rowIndex1);
    vector<int> solution2 = solution.getRow(rowIndex2);
    vector<int> solution3 = solution.getRow(rowIndex3);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution3) {
        cout << x << ' ';
    }

    return 0;
}