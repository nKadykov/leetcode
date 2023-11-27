#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int number = digits.size();
        if(number == 0) {
            return {};
        }
        string array[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answer;
        for(auto& a : array[digits[0] - '0']) {
            answer.push_back(string(1, a));
        }
        for(int i = 1; i < number; i++) {
            vector<string> comb;
            for(auto& a : array[digits[i] - '0']) {
                for(auto& b : answer) {
                    comb.push_back(b + a);
                }
            }
            answer = comb;
        }
        return answer;
    }
};

int main() {
    string digits1 {"23"};
    string digits2 {""};
    string digits3 {"2"};

    Solution solution;

    vector<string> solution1 = solution.letterCombinations(digits1);
    vector<string> solution2 = solution.letterCombinations(digits2);
    vector<string> solution3 = solution.letterCombinations(digits3);

    for(auto& x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution2) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto& x : solution3) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}