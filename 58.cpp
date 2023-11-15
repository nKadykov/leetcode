#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0, index = s.size() - 1;
        while(s[index] == ' ') {
            index--;
        }
        while(s[index] != ' ') {
            length++;
            if(index == 0) {
                return length;
            }
            index--;
        }
        return length;
    }
};

int main() {
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";

    Solution solution;

    int solution1 = solution.lengthOfLastWord(s1);
    int solution2 = solution.lengthOfLastWord(s2);
    int solution3 = solution.lengthOfLastWord(s3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';

    return 0;
}