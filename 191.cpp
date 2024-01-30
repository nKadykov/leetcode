#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for(int i = 0; i < 32; i++) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    uint32_t n1 = 00000000000000000000000000001011;
    uint32_t n2 = 00000000000000000000000010000000;
    uint32_t n3 = 11111111111111111111111111111101;

    Solution solution;

    int solution1 = solution.hammingWeight(n1);
    int solution2 = solution.hammingWeight(n2);
    int solution3 = solution.hammingWeight(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}