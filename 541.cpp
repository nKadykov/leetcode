#include <iostream>
#include <cstring>
#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        std::string result = "";
        int count = 1;
        for(int i = 0; i < s.size(); i+=k) {
            std::string t = s.substr(i, k);
            if(count == 1) {
                reverse(t.begin(), t.end());
                result += t;
                count = 0;
            } else {
                result += t;
                count = 1;
            }
        }
        return result;
    }
};

int main() {
    std::string s1 = "abcdefg";
    int k1 = 2;
    std::string s2 = "abcd";
    int k2 = 2;

    Solution solution;

    std::string solution1 = solution.reverseStr(s1, k1);
    std::string solution2 = solution.reverseStr(s2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}