#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end) {
            if(!isalnum(s[start])) {
                start++;
                continue;
            }
            if(!isalnum(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            else {
                start++;
                end--;
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