#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    uint32_t n1 = 00000010100101000001111010011100;
    uint32_t n2 = 11111111111111111111111111111101;

    Solution solution;

    uint32_t solution1 = solution.reverseBits(n1);
    bitset<32> solution21(solution1);
    uint32_t solution2 = solution.reverseBits(n2);
    bitset<32> solution22(solution2);

    cout << solution21 <<  '\n';
    cout << solution22;

    return 0;
}