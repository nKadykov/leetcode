#include <iostream>

class Solution {
public:
    int minimumDeletions(std::string s) {
        int result = 0;
        int count = 0;
        for(char c : s) {
            if(c == 'b')
                count++;
            else if(count) {
                result++;
                count--;
            }
        }
        return result;
    }
};

int main() {
    std::string s1 = "aababbab";
    std::string s2 = "bbaaaaabb";

    Solution solution;

    int solution1 = solution.minimumDeletions(s1);
    int solution2 = solution.minimumDeletions(s2);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';

    return 0;
}