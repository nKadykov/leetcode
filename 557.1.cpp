#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string result;
        std::stringstream str(s);
        std::string l;
        while(str >> l) {
            reverse(l.begin(), l.end());
            result += l + " ";
        }
        result.pop_back();
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