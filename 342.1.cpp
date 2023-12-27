#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
    }
};

int main() {
    int n1 = 16;
    int n2 = 5;
    int n3 = 1;

    Solution solution;

    bool solution1 = solution.isPowerOfFour(n1);
    bool solution2 = solution.isPowerOfFour(n2);
    bool solution3 = solution.isPowerOfFour(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}