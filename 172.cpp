#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int i = 5;
        int result = 0;

        while(n / i) {
            result += n / i;
            i *= 5;
        }
        return result;
    }
};

int main() {
    int n1 = 3;
    int n2 = 5;
    int n3 = 0;

    Solution solution;

    int solution1 = solution.trailingZeroes(n1);
    int solution2 = solution.trailingZeroes(n2);
    int solution3 = solution.trailingZeroes(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}