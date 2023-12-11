#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    int getNumber(char letter) {
        return (letter - 'A' + 1);
    }
public:
    int titleToNumber(string columnTitle) {
        int power = 0;
        int result = 0;
        for(int i = columnTitle.size() - 1; i >= 0; i--) {
            int number = getNumber(columnTitle[i]);
            result += number * pow(26, power);
            power++;
        }
        return result;
    }
};

int main() {
    string columnTitle1 = "A";
    string columnTitle2 = "AB";
    string columnTitle3 = "ZY";

    Solution solution;

    int solution1 = solution.titleToNumber(columnTitle1);
    int solution2 = solution.titleToNumber(columnTitle2);
    int solution3 = solution.titleToNumber(columnTitle3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}