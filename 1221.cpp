#include <iostream>

class Solution {
public:
    int balancedStringSplit(std::string s) {
        int result = 0;
        int count_R = 0;
        int count_L = 0;
        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == 'R') {
                count_R++;
            } else if (s[i] == 'L') {
                count_L++;
            }
            if(count_R == count_L) {
                result++;
                count_R = 0;
                count_L = 0;
            }
        }
        return result;
    }
};

int main() {
    std::string s1 = "RLRRLLRLRL";
    std::string s2 = "RLRRRLLRLL";
    std::string s3 = "LLLLRRRR";

    Solution solution;

    int solution1 = solution.balancedStringSplit(s1);
    int solution2 = solution.balancedStringSplit(s2);
    int solution3 = solution.balancedStringSplit(s3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}