#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int result = 0;
        int last = -1;
        for(int i = 0; i < 32; ++i) {
            if((n >> i) & 1) {
                if(last != -1) {
                    result = max(result, i - last);
                }
                last = i;
            }
        }
        return result;
    }
};

int main() {
    int n1 = 22;
    int n2 = 8;
    int n3 = 5;

    Solution solution;

    int solution1 = solution.binaryGap(n1);
    int solution2 = solution.binaryGap(n2);
    int solution3 = solution.binaryGap(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}