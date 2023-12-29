#include <iostream>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int result = 0;
        for(int k = 2; k <= n; k++) {
            int priv = n / k;
            int remain = n % k;
            int power = 1;
            for(int i = 0; i < k; i++) {
                if(remain) {
                    power *= (priv + 1);
                    remain--;
                }
                else {
                    power *= priv;
                }
            }
            result = max(result, power);
        }
        return result;
    }
};

int main() {
    int n1 = 2;
    int n2 = 10;

    Solution solution;

    int solution1 = solution.integerBreak(n1);
    int solution2 = solution.integerBreak(n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}