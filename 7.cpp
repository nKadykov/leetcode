#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int beginNumber) {
        long resultNumber = 0;
        while(beginNumber) {
            resultNumber *= 10;
            resultNumber += beginNumber % 10;
            beginNumber /= 10;
        }
        if(resultNumber > INT_MAX || resultNumber < INT_MIN) {
            return 0;
        }
        return int(resultNumber);
    }
};

int main() {
    int number1 = 123;
    long long int number2 = 2147483;

    Solution solution;

    int solution1 = solution.reverse(number1);
    int solution2 = solution.reverse(number2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}