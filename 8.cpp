#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int number = s.size();
        int i = 0;
        int i1;
        int result = 0;
        int sign = 1;
        int left = '0';
        int right = '9';
        int digits = 0;
        bool flag = true;
        while(s[i] == ' ') {
            i++;
        }
        if((s[i] < left || s[i] > right) && s[i] != '-' && s[i] != '+') {
            return 0;
        }
        if(s[i] == '-' && s[i + 1] >= left && s[i + 1] <= right) {
            sign = -1;
            i++;
        }
        if(s[i] == '+' && s[i + 1] >= left && s[i + 1] <= right) {
            sign = 1;
            i++;
        }
        i1 = i;
        while(s[i1] >= left && s[i1] <= right) {
            digits++;
            i1++;
        }
        while(s[i] >= left && s[i] <= right) {
            if(result + (s[i] - '0') * pow(10, (digits - 1)) > INT_MAX)
                return INT_MAX * sign + (-1 + sign) / 2;
            result += (s[i] - '0') * pow(10, (digits - 1));
            digits--;
            i++;
            flag = false;
        }
        return sign * result;
    }
};

int main() {
    string string1 = "42";
    string string2 = "   -42";
    string string3 = "4193 with words";
    string string4 = "words and 987";

    Solution solution;

    int solution1 = solution.myAtoi(string1);
    int solution2 = solution.myAtoi(string2);
    int solution3 = solution.myAtoi(string3);
    int solution4 = solution.myAtoi(string4);

    cout << solution1 << ' ';
    cout << solution2 << ' ';
    cout << solution3 << ' ';
    cout << solution4 << ' ';

    return 0;
}