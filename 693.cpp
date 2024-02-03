#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0) {
            int digit1 = n & 1;
            n >>= 1;
            int digit2 = n & 1;
            if(!digit1 ^ digit2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n1 = 5;
    int n2 = 7;
    int n3 = 11;

    Solution solution;

    bool solution1 = solution.hasAlternatingBits(n1);
    bool solution2 = solution.hasAlternatingBits(n2);
    bool solution3 = solution.hasAlternatingBits(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}