#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int begin = 1;
        int end = num;
        long long mid = begin + (end - begin) / 2;
        while(begin <= end) {
            if(num == mid * mid) {
                return true;
            }
            if(num > mid * mid) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = begin + (end - begin) / 2;
        }
        return false;
    }
};

int main() {
    int num1 = 16;
    int num2 = 14;

    Solution solution;

    bool solution1 = solution.isPerfectSquare(num1);
    bool solution2 = solution.isPerfectSquare(num2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}