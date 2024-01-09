#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] != '0') {
                dp[i] = dp[i + 1];
                if(i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};

int main() {
    string s1 = "12";
    string s2 = "226";
    string s3 = "06";

    Solution solution;

    int solution1 = solution.numDecodings(s1);
    int solution2 = solution.numDecodings(s2);
    int solution3 = solution.numDecodings(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}