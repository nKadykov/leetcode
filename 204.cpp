#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        for(long long i = 2; i * i <= n; i++) {
            if(prime[i]) {
                for(long long j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(prime[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n1 = 10;
    int n2 = 0;
    int n3 = 1;

    Solution solution;

    int solution1 = solution.countPrimes(n1);
    int solution2 = solution.countPrimes(n2);
    int solution3 = solution.countPrimes(n3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}