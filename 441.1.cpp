#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return floor((-1 + sqrt(1 + 8LL * n)) / 2);
    }
};

int main() {
    int n1 = 5;
    int n2 = 8;

    Solution solution;

    int solution1 = solution.arrangeCoins(n1);
    int solution2 = solution.arrangeCoins(n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}