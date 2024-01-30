#include <iostream>
using namespace std;

class Solution {
    char hexNumber(int digit) {
        switch(digit) {
            case 10:
                return 'a';
            case 11:
                return 'b';
            case 12:
                return 'c';
            case 13:
                return 'd';
            case 14:
                return 'e';
            case 15:
                return 'f';
        }
        return digit + '0';
    }
public:
    string toHex(int num) {
        string result;
        if(num == 0) {
            return "0";
        }
        if(num > 0) {
            while(num >= 1) {
                int a = num % 16;
                result = hexNumber(a) + result;
                num /= 16;
            }
        }
        else {
            int n = abs(num) - 1;
            int a = n % 16;
            result = hexNumber(15 - a) + result;
            n /= 16;
            for(int i = 0; i < 6; i++) {
                int a = n % 16;
                result = hexNumber(15 - a) + result;
                n /= 16;
            }
            result = hexNumber(15 - n) + result;

        }
        return result;
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