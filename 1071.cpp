#include <iostream>
#include <numeric>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, std::gcd(size(str1), size(str2))) : "";
    }
};

int main() {
    std::string str11 = "ABCABC";
    std::string str12 = "ABC";
    std::string str21 = "ABABAB";
    std::string str22 = "ABAB";
    std::string str31 = "LEET";
    std::string str32 = "CODE";

    Solution solution;

    std::string solution1 = solution.gcdOfStrings(str11, str12);
    std::string solution2 = solution.gcdOfStrings(str21, str22);
    std::string solution3 = solution.gcdOfStrings(str31, str32);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}