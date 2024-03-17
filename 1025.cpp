#include <iostream>

class Solution {
public:
    bool divisorGame(int n) {
        if(n % 2) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    int n1 = 2;
    int n2 = 3;

    Solution solution;

    bool solution1 = solution.divisorGame(n1);
    bool solution2 = solution.divisorGame(n2);

    return 0;
}