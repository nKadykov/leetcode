#include <iostream>
#include <cstring>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        int length = s.size();
        for(int i = 0; i < length; ++i) {
            s += s[i];
            std::string substring = s.substr(i + 1, length + 1);
            if(substring == goal) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::string s1 = "abcde";
    std::string goal1 = "cdeab";
    std::string s2 = "abcde";
    std::string goal2 = "abced";

    Solution solution;

    bool solution1 = solution.rotateString(s1, goal1);
    bool solution2 = solution.rotateString(s2, goal2);

    std::cout << std::boolalpha << solution1 << std::endl;
    std::cout << std::boolalpha << solution2 << std::endl;

    return 0;
}