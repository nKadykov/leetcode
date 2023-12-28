#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return a + b;
    }
};

int main() {
    int a1 = 1;
    int b1 = 2;
    int a2 = 2;
    int b2 = 3;

    Solution solution;

    int solution1 = solution.getSum(a1, b1);
    int solution2 = solution.getSum(a2, b2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}