#include <iostream>
#include <vector>
using namespace std;

class Solution {
    long long function(vector<long long>& v, int n, int i, vector<int>& primes, vector<long long>& numbers) {
        if(i == n) {
            return v[n - 1];
        }
        long long next = INT_MAX;
        for(int j = 0; j < primes.size(); j++) {
            next = min(next, v[numbers[j]] * primes[j]);
        }
        v[i] = next;
        for(int i = 0; i < primes.size(); i++) {
            if(v[numbers[i]] * primes[i] == next) {
                numbers[i]++;
            }
        }

        return function(v, n, i + 1, primes, numbers);
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> v(n, -1);
        v[0] = 1;
        vector<long long> numbers(primes.size(), 0);

        return function(v, n, 1, primes, numbers);
    }
};

int main() {
    int n1 = 12;
    vector<int> primes1 {2,7,13,19};
    int n2 = 1;
    vector<int> primes2 {2,3,5};

    Solution solution;

    int solution1 = solution.nthSuperUglyNumber(n1, primes1);
    int solution2 = solution.nthSuperUglyNumber(n2, primes2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}