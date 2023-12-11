#include <iostream>
#include <cstring>
using namespace std;

class Solution {
    char choose(int mod) {
        char character = 'A' + mod;
        return character;
    }
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber != 0) {
            columnNumber -= 1;
            int mod = columnNumber % 26;
            result = choose(mod) + result;
            columnNumber /= 26;
        }
        return result;
    }
};

int main() {
    int columnNumber1 {1};
    int columnNumber2 {28};
    int columnNumber3 {701};

    Solution solution;

    string solution1 = solution.convertToTitle(columnNumber1);
    string solution2 = solution.convertToTitle(columnNumber2);
    string solution3 = solution.convertToTitle(columnNumber3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';
    
    return 0;
}