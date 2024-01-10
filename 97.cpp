#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n1 + n2 != n3) {
            return false;
        }
        if (n1 < n2) {
            return isInterleave(s2, s1, s3);
        }
        vector<bool> dp(n2 + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n2; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= n1; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n2; j++) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n2];
    }
};

int main() {
    string s11 = "aabcc";
    string s12 = "dbbca";
    string s13 = "aadbbcbcac";
    string s21 = "aabcc";
    string s22 = "dbbca";
    string s23 = "aadbbbaccc";
    string s31 = "";
    string s32 = "";
    string s33 = "";

    Solution solution;

    bool solution1 = solution.isInterleave(s11, s12, s13);
    bool solution2 = solution.isInterleave(s21, s22, s23);
    bool solution3 = solution.isInterleave(s31, s32, s33);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}