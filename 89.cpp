#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n);
        for(int i = 0; i < (1 << n); i++) {
            result[i] = i ^ (i >> 1);
        }
        return result;
    }
};

int main() {
    int n1 = 2;
    int n2 = 1;

    Solution solution;

    vector<int> solution1 = solution.grayCode(n1);
    vector<int> solution2 = solution.grayCode(n2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}