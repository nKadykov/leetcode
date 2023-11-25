#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        if(num / 1000 != 0) {
            for(int i = 0; i < (num / 1000); i++) {
                result.append("M");
            }
        }
        num = num % 1000;
        if(num / 500 != 0) {
            if(num / 100 == 9) {
                result.append("CM");
            }
            else {
                result.append("D");
                for(int i = 0; i < ((num - 500) / 100); i++) {
                    result.append("C");
                }
            }
        }
        else {
            if(num / 100 == 4) {
                result.append("CD");
            }
            else {
                for(int i = 0; i < (num / 100); i++) {
                    result.append("C");
                }
            }
        }
        num = num % 100;
        if(num / 50 != 0) {
            if(num / 10 == 9) {
                result.append("XC");
            }
            else {
                result.append("L");
                for(int i = 0; i < ((num - 50) / 10); i++) {
                    result.append("X");
                }
            }
        }
        else if (num >= 10) {
            if(num / 10 == 4) {
                result.append("XL");
            }
            else {
                for(int i = 0; i < (num / 10); i++) {
                    result.append("X");
                }
            }
        }
        num = num % 10;
        if(num / 5 != 0) {
            if(num == 9) {
                result.append("IX");
            }
            else {
                result.append("V");
                for(int i = 0; i < num - 5; i++) {
                    result.append("I");
                }
            }
        }
        else {
            if(num == 4) {
                result.append("IV");
            }
            else {
                for(int i = 0; i < num; i++) {
                    result.append("I");
                }
            }
        }
        return result;
    }
};

int main() {
    int num1 = 3;
    int num2 = 58;
    int num3 = 1994;

    Solution solution;

    string solution1 = solution.intToRoman(num1);
    string solution2 = solution.intToRoman(num2);
    string solution3 = solution.intToRoman(num3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}