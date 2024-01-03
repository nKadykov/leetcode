#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int map[26] = {0};
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        for(int i = 0; i < s.size(); i++) {
            int number = s[i] - 'a';
            map[number]++;
        }
        for(int i = 0; i < t.size(); i++) {
            int number = t[i] - 'a';
            map[number]--;
        }
        for(int i = 0; i < 26; i++) {
            if(map[i] != 0) {
                return false;
            }
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