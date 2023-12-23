#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        long long result = 1;
        set<long long> set;
        set.insert(result);
        for(int i = 0; i < n; i++) {
            result = *set.begin();
            set.erase(result);
            set.insert(result * 2);
            set.insert(result * 3);
            set.insert(result * 5);
        }
        return result;
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