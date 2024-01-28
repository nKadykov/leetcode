#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i1 = 0;
        int i2 = 0;
        while(i1 < s.size() && i2 < t.size()) {
            if(s[i1] == t[i2]) {
                i1++;
                i2++;
            }
            else {
                i2++;
            }
        }
        if(i1 == s.size()) {
            return true;
        }
        return false;
    }
};

int main() {
    string s1 = "abc";
    string t1 = "ahbgdc";
    string s2 = "axc";
    string t2 = "ahbgdc";

    Solution solution;

    bool solution1 = solution.isSubsequence(s1, t1);
    bool solution2 = solution.isSubsequence(s2, t2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}