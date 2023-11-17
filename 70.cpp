#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vector;
        vector.push_back(1);
        vector.push_back(1);
        for(int i = 2; i <= n; i++) {
            vector.push_back(vector[i - 1] + vector[i - 2]);
        }
        int sum = vector.back();
        return sum;
    }
};

int main() {
    int n1 = 2;
    int n2 = 3;
    int n3 = 10;

    Solution solution;

    int solution1 = solution.climbStairs(n1);
    int solution2 = solution.climbStairs(n2);
    int solution3 = solution.climbStairs(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}