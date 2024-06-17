#include <iostream>
#include <vector>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int divisor = 2; divisor * divisor <= c; divisor++) {
            if(c % divisor == 0) {
                int count = 0;
                while(c % divisor == 0) {
                    count++;
                    c /= divisor;
                }
                if(divisor % 4 == 3 && count % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};

int main() {
    int c1 = 5;
    int c2 = 3;

    Solution solution;

    bool solution1 = solution.judgeSquareSum(c1);
    bool solution2 = solution.judgeSquareSum(c2);

    std::cout << std::boolalpha << solution1 << std::endl;
    std::cout << std::boolalpha << solution2 << std::endl;

    return 0;
}