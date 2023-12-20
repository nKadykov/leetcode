#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n == 0)
            return "0";
        if(d == 1)
            return to_string(n);
        if(d == -1)
            return to_string((long)abs(n));
        string result = "";
        if((n < 0 && d > 0) || (n > 0 && d < 0))
            result += "-";
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        long long right = n % d;
        if(!right)
            return result;
        else
            result += ".";
        unordered_map<int, int> number;
        while(right != 0) {
            if(number.find(right) != number.end()) {
                result.insert(number[right], "(");
                result += ")";
                return result;
            }
            number[right] = result.length();
            right *= 10;
            result += to_string(right / d);
            right %= d;
        }
        return result;
    }
};

int main() {
    int numerator1 = 1;
    int denominator1 = 2;
    int numerator2 = 2;
    int denominator2 = 1;
    int numerator3 = 4;
    int denominator3 = 333;

    Solution solution;

    string solution1 = solution.fractionToDecimal(numerator1, denominator1);
    string solution2 = solution.fractionToDecimal(numerator2, denominator2);
    string solution3 = solution.fractionToDecimal(numerator3, denominator3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}