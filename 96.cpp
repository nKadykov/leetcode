#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> v;
    int function(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        if(n == 2) {
            return 2;
        }
        if(v[n] != -1) {
            return v[n];
        }
        int result = 0;
        for(int i = 1; i <= n; i++) {
            result += function(i - 1) * function(n - i);
        }
        return v[n] = result;
    }
    int numTrees(int n) {
        v.resize(20, -1);
        return function(n);
    }
};

int main() {
    int n1 = 3;
    int n2 = 1;

    Solution solution;

    int solution1 = solution.numTrees(n1);
    int solution2 = solution.numTrees(n2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}