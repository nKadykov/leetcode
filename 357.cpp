#include <iostream>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        for(int i = 1; i <= n; i++) {
            int mult = 9;
            for(int j = 1; j < i; j++) {
                mult = mult * (10 - j);
            }
            result += mult;
        }
        return result;
    }
};

int main() {
    int n1 = 2;
    int n2 = 0;
    int n3 = 8;

    Solution solution;

    int solution1 = solution.countNumbersWithUniqueDigits(n1);
    int solution2 = solution.countNumbersWithUniqueDigits(n2);
    int solution3 = solution.countNumbersWithUniqueDigits(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}