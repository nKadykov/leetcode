#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for(int i = 0; i < magazine.size(); i++) {
            m[magazine[i]]++;
        }
        for(int i = 0; i < ransomNote.size(); i++) {
            m[ransomNote[i]]--;
        }
        for(auto x : m) {
            if(x.second < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote1 = "a";
    string magazine1 = "b";
    string ransomNote2 = "a";
    string magazine2 = "b";
    string ransomNote3 = "a";
    string magazine3 = "b";

    Solution solution;

    bool solution1 = solution.canConstruct(ransomNote1, magazine1);
    bool solution2 = solution.canConstruct(ransomNote2, magazine2);
    bool solution3 = solution.canConstruct(ransomNote3, magazine3);

    return 0;
}