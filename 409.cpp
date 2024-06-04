#include <iostream>
#include <unordered_set>

class Solution {
public:
    int longestPalindrome(const std::string& s) {
        std::unordered_set<char> char_set;
        int length = 0;
        for(auto c : s) {
            if(char_set.find(c) != char_set.end()) {
                char_set.erase(c);
                length += 2;
            }
            else {
                char_set.insert(c);
            }
        }
        if(!char_set.empty()) {
            length += 1;
        }
        return length;
    }
};

int main() {
    std::string s1 = "abccccdd";
    std::string s2 = "a";

    Solution solution;

    int solution1 = solution.longestPalindrome(s1);
    int solution2 = solution.longestPalindrome(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}