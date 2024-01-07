#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string a = "";
        for(int i = 0; i < s.size(); i++) {
            if((s[i] < 123 && s[i] > 96) || (s[i] < 58 && s[i] > 47)) {
                a += s[i];
            }
            else if(s[i] < 91 && s[i] > 64) {
                a += (s[i] + 32);
            }
        }
        int n = a.size();
        for(int i = 0; i < a.size() / 2; i++) {
            if(a[i] != a[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    Solution solution;

    bool solution1 = solution.isPalindrome(s1);
    bool solution2 = solution.isPalindrome(s2);
    bool solution3 = solution.isPalindrome(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}