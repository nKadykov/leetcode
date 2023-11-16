#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sum;
        int first = 0;
        int number1 = a.size() - 1;
        int number2 = b.size() - 1;
        while(number1 >= 0 || number2 >= 0 || first) {
            if(number1 >= 0) {
                first += a[number1--] - '0';
            }
            if(number2 >= 0) {
                first += b[number2--] - '0';
            }
            sum += first % 2 + '0';
            first /= 2;
        }
        reverse(begin(sum), end(sum));
        return sum;
    }
};

int main() {
    string a1 = "11";
    string b1 = "1";
    string a2 = "1010";
    string b2 = "1011";

    Solution solution;

    string solution1 = solution.addBinary(a1, b1);
    string solution2 = solution.addBinary(a2, b2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}