#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};

int main() {
    string s1 = "babad";
    string s2 = "cbbd";
    
    Solution solution;

    string solution1;
    string solution2;

    solution1 = solution.longestPalindrome(s1);
    solution2 = solution.longestPalindrome(s2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}