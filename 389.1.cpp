#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sums = 0;
        int sumt = 0;
        for(int i = 0; i < s.size(); i++) {
            sums += int(s[i]);
            sumt += int(t[i]);
        }
        sumt += int(t[t.size() - 1]);
        return char(sumt - sums);
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