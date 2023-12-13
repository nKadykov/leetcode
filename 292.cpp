#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main() {
    int n1 = 4;
    int n2 = 1;
    int n3 = 2;

    Solution solution;

    bool solution1 = solution.canWinNim(n1);
    bool solution2 = solution.canWinNim(n2);
    bool solution3 = solution.canWinNim(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}