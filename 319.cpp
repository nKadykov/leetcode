#include <iostream>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int result = 0;
        for(int i = 1; i <= n; i++) {
            if(i * i <= n) {
                result++;
            }
            else {
                break;
            }
        }
        return result;
    }
};

int main() {
    int n1 = 3;
    int n2 = 0;
    int n3 = 1;

    Solution solution;

    int solution1 = solution.bulbSwitch(n1);
    int solution2 = solution.bulbSwitch(n2);
    int solution3 = solution.bulbSwitch(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}