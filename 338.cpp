#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int countOnes(int i) {
        int count = 0;
        while(i >= 1) {
            count += i % 2;
            i /= 2;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        for(int i = 1; i <= n; i++) {
            result[i] = countOnes(i);
        }
        return result;
    }
};

int main() {
    int n1 = 2;
    int n2 = 5;

    Solution solution;

    vector<int> solution1 = solution.countBits(n1);
    vector<int> solution2 = solution.countBits(n2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}