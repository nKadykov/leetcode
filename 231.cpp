#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }
        while(n != 1) {
            if(n % 2) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

int main() {
    int n1 = 1;
    int n2 = 16;
    int n3 = 3;

    Solution solution;

    bool solution1 = solution.isPowerOfTwo(n1);
    bool solution2 = solution.isPowerOfTwo(n2);
    bool solution3 = solution.isPowerOfTwo(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}