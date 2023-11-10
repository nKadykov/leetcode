#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int N = 0;
        int der = 0;
        vector<int> v;
        if(x < 0)
            return false;
        int i = 0;
        do {
            der = x % 10;
            v.push_back(der);
            x /= 10;
            i++;
        } while(x);
        N = i;
        for(int i = 0; i < N / 2; i++) {
            if(v[i] != v[N - 1 - i])
                return false;
        }
        return true;
    }
};

int main() {
    int v1 = 121 , v2 = -121, v3 = 10;
    Solution sol;
    bool solution;
    solution = sol.isPalindrome(v1);
    cout << solution << '\n';
    solution = sol.isPalindrome(v2);
    cout << solution << '\n';
    solution = sol.isPalindrome(v3);
    cout << solution << '\n';
    return 0;
}