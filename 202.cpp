#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while(true) {
            if(n == 1 || n == 7) {
                return true;
            }
            if(n > 1 && n < 10) {
                return false;
            }
            int sum = 0;
            while(n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;            
            }
            n = sum;
        }
        return true;
    }
};

int main() {
    int n1 {19};
    int n2 {2};

    Solution solution;

    bool solution1 = solution.isHappy(n1);
    bool solution2 = solution.isHappy(n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}