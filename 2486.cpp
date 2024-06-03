#include <iostream>
#include <cstring>

class Solution {
public:
    int appendCharacters(std::string s, std::string t) {
        int s_index = 0;
        int t_index = 0;
        int s_length = s.length();
        int t_length = t.length();

        while(s_index < s_length && t_index < t_length) {
            if(s[s_index] == t[t_index]) {
                t_index++;
            }
            s_index++;
        }
        
        return t_length - t_index;
    }
};

int main() {
    std::string s1 = "coaching";
    std::string t1 = "coding";
    std::string s2 = "abcde";
    std::string t2 = "a";
    std::string s3 = "z";
    std::string t3 = "abcde";

    Solution solution;

    int solution1 = solution.appendCharacters(s1, t1);
    int solution2 = solution.appendCharacters(s2, t2);
    int solution3 = solution.appendCharacters(s3, t3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}