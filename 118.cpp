#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) {
            return {};
        }
        if(numRows == 1) {
            return {{1}};
        }
        vector<vector<int>> result = generate(numRows - 1);
        vector<int> numbers(numRows, 1);
        for(int i = 1; i < numRows - 1; i++) {
            numbers[i] = result.back()[i - 1] + result.back()[i];
        }
        result.push_back(numbers);
        return result;
    }
};

int main() {
    int numRows1 = 5;
    int numRows2 = 1;

    Solution solution;

    vector<vector<int>> solution1 = solution.generate(numRows1);
    vector<vector<int>> solution2 = solution.generate(numRows2);


    for(auto x : solution1) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for(auto x : solution2) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    return 0;
}