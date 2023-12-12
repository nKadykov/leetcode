#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            if(num < 10) {
                break;
            }
            int sum = 0;
            while(num != 0) {
                sum += (num % 10);
                num /= 10;
            }
            num = sum;
        }   
        return num;
    }
};

int main() {
    int num1 = 38;
    int num2 = 0;

    Solution solution;

    int solution1 = solution.addDigits(num1);
    int solution2 = solution.addDigits(num2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}