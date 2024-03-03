#include <iostream>
using namespace std;

class Solution {
    bool solve(string s, int i, int j) {
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return solve(s, i + 1, j) || solve(s, i, j - 1);
            }
        }
        return true;
    }
};

int main() {
    string s1 = "aba";
    string s2 = "abca";
    string s3 = "abc";

    Solution solution;

    bool solution1 = solution.validPalindrome(s1);
    bool solution2 = solution.validPalindrome(s2);
    bool solution3 = solution.validPalindrome(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}