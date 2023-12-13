#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) {
            return true;
        }
        while(n != 0) {
            if(n % 3 != 0) {
                break;
            }
            n /= 3;
            if(n == 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n1 = 27;
    int n2 = 0;
    int n3 = -1;

    Solution solution;

    bool solution1 = solution.isPowerOfThree(n1);
    bool solution2 = solution.isPowerOfThree(n2);
    bool solution3 = solution.isPowerOfThree(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}