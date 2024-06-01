#include <iostream>

class Solution {
public:
    int scoreOfString(std::string s) {
        int result = 0;
        for(int i = 1; i < s.size(); ++i) {
            result += abs(s[i] - s[i - 1]);
        }
        return result;
    }
};

int main() {
    std::string s1 = "hello";
    std::string s2 = "zaz";

    Solution solution;

    int solution1 = solution.scoreOfString(s1);
    int solution2 = solution.scoreOfString(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}