#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> numbers {2, 3, 5, 7, 11, 13, 17, 19};
        int result = 0;
        for(int i = left; i <= right; i++) {
            int temp = i;
            int ones = 0;
            while(temp) {
                ones++;
                temp = temp & temp - 1;
            }
            if(numbers.count(ones)) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    int left1 = 6;
    int right1 = 10;
    int left2 = 10;
    int right2 = 15;

    Solution solution;

    int solution1 = solution.countPrimeSetBits(left1, right1);
    int solution2 = solution.countPrimeSetBits(left2, right2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}