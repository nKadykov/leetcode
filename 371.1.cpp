#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int c = a & b;
            a = a ^ b;
            b = c << 1;
            cout << a << ' ';
        }
        return a;
    }
};

int main() {
    int a1 = 1;
    int b1 = 2;
    int a2 = 2;
    int b2 = 3;

    Solution solution;

    int solution1 = solution.getSum(a1, b1);
    int solution2 = solution.getSum(a2, b2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}