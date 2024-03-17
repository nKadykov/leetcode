#include <iostream>

class Solution {
    bool good(int n) {
        bool result = false;
        int y;
        while(n > 0) {
            y = n % 10;
            switch(y) {
                case 0:
                case 1:
                case 8:
                    break;
                case 2:
                case 5:
                case 6:
                case 9:
                    result = true;
                    break;
                default:
                    return false;
            }
            n /= 10;
        }
        return result;
    }
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(good(i)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n1 = 10;
    int n2 = 1;
    int n3 = 2;

    Solution solution;

    int solution1 = solution.rotatedDigits(n1);
    int solution2 = solution.rotatedDigits(n2);
    int solution3 = solution.rotatedDigits(n3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3;

    return 0;
}