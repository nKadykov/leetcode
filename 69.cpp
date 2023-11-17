#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) {
            return x;
        }
        int begin = 0;
        int end = x;
        long int mid = 0;
        while(begin <= end) {
            mid = (begin + end) / 2;
            if((mid * mid <= x) && ((mid + 1) * (mid + 1) > x)) {
                return mid;
            }
            if(mid * mid > x) {
                end = mid;
            }
            else {
                begin = mid;
            }
        }
        return mid;
    }
};

int main() {
    int x1 = 4;
    int x2 = 8;

    Solution solution;

    int solution1 = solution.mySqrt(x1);
    int solution2 = solution.mySqrt(x2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}