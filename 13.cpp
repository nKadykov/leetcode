#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        for(int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'M':
                    number += 1000;
                    break;
                case 'D':
                    number += 500;
                    break;
                case 'C':
                    if(s[i + 1] == 'M') {
                        number += 900;
                        i++;
                    }
                    else if(s[i + 1] == 'D') {
                        number += 400;
                        i++;
                    }
                    else
                        number += 100;
                    break;
                case 'L':
                    number += 50;
                    break;
                case 'X':
                    if(s[i + 1] == 'C') {
                        number += 90;
                        i++;
                    }
                    else if(s[i + 1] == 'L') {
                        number += 40;
                        i++;
                    } else
                        number += 10;
                    break;
                case 'V':
                    number += 5;
                    break;
                case 'I':
                    if(s[i + 1] == 'X') {
                        number += 9;
                        i++;
                    }
                    else if(s[i + 1] == 'V') {
                        number += 4;
                        i++;
                    } else
                        number += 1;
            }
        }
        return number;
    }
};

int main() {
    string s1 = "III", s2 = "LVIII", s3 = "MCMXCIV";
    Solution sol;
    int number;
    number = sol.romanToInt(s1);
    cout << number << '\n';
    number = sol.romanToInt(s2);
    cout << number << '\n';
    number = sol.romanToInt(s3);
    cout << number << '\n';
    return 0;
}