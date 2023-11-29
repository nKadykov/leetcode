#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long divide = abs(dividend);
        long divise = abs(divisor);
        long result = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while(divide >= divise) {
            long temp = divise;
            long plus = 1;
            while(temp << 1 <= divide) {
                temp <<= 1;
                plus <<= 1;
            }
            divide -= temp;
            result += plus;
        }
        return sign * result;
    }
};

int main() {
    int dividend1 = 10;
    int divisor1 = 3;
    int dividend2 = 7;
    int divisor2 = -3;

    Solution solution;

    int solution1 = solution.divide(dividend1, divisor1);
    int solution2 = solution.divide(dividend2, divisor2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}