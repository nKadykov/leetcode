#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        long long result = 0;
        int i = 0;
        for(num; num > 0; num >>= 1) {
            int first = (num & 1) ^ 1;
            result += first * pow(2, i);
            i++;

        }
        return result;
    }
};

int main() {
    int num1 = 5;
    int num2 = 1;

    Solution solution;

    int solution1 = solution.findComplement(num1);
    int solution2 = solution.findComplement(num2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}