#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) {
            return false;
        }
        while(n % 2 == 0) {
            n /= 2;
        }
        while(n % 3 == 0) {
            n /= 3;
        }
        while(n % 5 == 0) {
            n /= 5;
        }
        if(abs(n) != 1) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    int n1 = 6;
    int n2 = 1;
    int n3 = 14;

    Solution solution;

    bool solution1 = solution.isUgly(n1);
    bool solution2 = solution.isUgly(n2);
    bool solution3 = solution.isUgly(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}