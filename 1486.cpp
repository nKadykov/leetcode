#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = start;
        for(int i = 1; i < n; i ++) {
            result ^= (start + 2 * i); 
        }
        return result;
    }
};

int main() {
    int n1 = 5;
    int start1 = 0;
    int n2 = 4;
    int start2 = 3;

    Solution solution;

    int solution1 = solution.xorOperation(n1, start1);
    int solution2 = solution.xorOperation(n2, start2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}