#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1 / x;
        }
        long num = abs(n);
        double pow = 1;
        while(num) {
            if(num & 1) {
                pow *= x;
            }
            x *= x;
            num >>= 1;
        }
        return pow;
    }
};

int main() {
    double x1 = 2;
    int n1 = 10;
    double x2 = 2.1;
    int n2 = 3;
    double x3 = 2;
    int n3 = -2;

    Solution solution;

    double solution1 = solution.myPow(x1, n1);
    double solution2 = solution.myPow(x2, n2);
    double solution3 = solution.myPow(x3, n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}