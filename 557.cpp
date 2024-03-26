#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string sub;
        std::string result;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reverse(sub.begin(), sub.end());
                result += sub;
                sub = "";
                result += ' ';
            }
            if(s[i] != ' ') {
                sub += s[i];
            }
            if(i == s.size() - 1) {
                reverse(sub.begin(), sub.end());
                result += sub;
            }
        }
        return result;
    }
};

int main() {
    std::string s1 = "Let's take LeetCode contest";
    std::string s2 = "Mr Ding";

    Solution solution;

    std::string solution1 = solution.reverseWords(s1);
    std::string solution2 = solution.reverseWords(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}