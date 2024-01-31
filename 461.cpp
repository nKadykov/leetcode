#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int m = max(x, y);
        int ones = x ^ y;
        int result = 0;
        for(int i = m; i > 0; i /= 2) {
            result += (ones & 1);
            ones >>= 1;
        }
        return result;
    }
};

int main() {
    int x1 = 1;
    int y1 = 4;
    int x2 = 3;
    int y2 = 1;

    Solution solution;

    int solution1 = solution.hammingDistance(x1, y1);
    int solution2 = solution.hammingDistance(x2, y2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}