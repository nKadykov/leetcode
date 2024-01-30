#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        unsigned int number = num;
        string str;
        char arrayNumber[17] = "0123456789abcdef";
        do {
            str += arrayNumber[number % 16];
            number /= 16;
        }
        while(number);

        return {str.rbegin(), str.rend()};
    }
};

int main() {
    int num1 = 26;
    int num2 = -1;

    Solution solution;

    string solution1 = solution.toHex(num1);
    string solution2 = solution.toHex(num2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}