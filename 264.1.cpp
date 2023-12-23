#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(n);
        result[0] = 1;
        int x = 0;
        int y = 0;
        int z = 0;
        for(int i = 1; i < n; i++) {
            result[i] = min(result[x] * 2, min(result[y] * 3, result[z] * 5));
            if(result[i] == 2 * result[x]) {
                x++;
            }
            if(result[i] == 3 * result[y]) {
                y++;
            }
            if(result[i] == 5 * result[z]) {
                z++;
            }
        }
        return result[n - 1];
    }
};

int main() {
    int n1 = 10;
    int n2 = 1;

    Solution solution;

    int solution1 = solution.nthUglyNumber(n1);
    int solution2 = solution.nthUglyNumber(n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}