#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) {
                return (char)t[i];
            }
        }
        return (char)t[t.size() - 1];
    }
};

int main() {
    string s1 = "abcd";
    string s2 = "";
    string t1 = "abcde";
    string t2 = "y";

    Solution solution;

    char solution1 = solution.findTheDifference(s1, t1);
    char solution2 = solution.findTheDifference(s2, t2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}