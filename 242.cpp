#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() == s.size()) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == t[i]) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        else {
            return false;
        }
        return true;
    }
};

int main() {
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    Solution solution;

    bool solution1 = solution.isAnagram(s1, t1);
    bool solution2 = solution.isAnagram(s2, t2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}