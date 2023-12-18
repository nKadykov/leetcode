#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int number = n * m;
        int x = 0;
        int y = 0;
        vector<int> result(number, 1);
        for(int i = n - 1; i >= 1; i--) {
            for(int j = m - 1; j >= 1; j--) {
                x = j - 1;
                y = i - 1;
                result[y * m + x] = result[(y + 1) * m + x] + result[y * m + x + 1]; 
            }
        }
        return result[0];
    }
};

int main() {
    int m1 = 3;
    int n1 = 7;
    int m2 = 3;
    int n2 = 2;

    Solution solution;

    int solution1 = solution.uniquePaths(m1, n1);
    int solution2 = solution.uniquePaths(m2, n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}