#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int function(int x, int y, int oper) {
        if(oper == '+') {
            return x + y;
        }
        if(oper == '-') {
            return x - y;
        }
        if(oper == '*') {
            return x * y;
        }
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string e) {
        vector<int> result;
        bool isNumber = 1;
        for(int i = 0; i < e.size(); i++) {
            if(!isdigit(e[i])) {
                isNumber = 0;
                vector<int> left = diffWaysToCompute(e.substr(0, i));
                vector<int> right = diffWaysToCompute(e.substr(i + 1));
                for(int x : left) {
                    for(int y : right) {
                        int val = function(x, y, e[i]);
                        result.push_back(val);
                    }
                }
            }
        }
        if(isNumber == 1) {
            result.push_back(stoi(e));
        }
        return result;
    }
};

int main() {
    string expression1 = "2-1-1";
    string expression2 = "2*3-4*5";

    Solution solution;

    vector<int> solution1 = solution.diffWaysToCompute(expression1);
    vector<int> solution2 = solution.diffWaysToCompute(expression2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(int x : solution2) {
        cout << x << ' ';
    }

    return 0;
}