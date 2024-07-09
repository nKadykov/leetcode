#include <iostream>
#include <set>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        int pointer_1 = 0;
        int pointer_2 = s.size() - 1;
        std::set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vowels.insert('A');
        vowels.insert('E');
        vowels.insert('I');
        vowels.insert('O');
        vowels.insert('U');
        while(pointer_1 < pointer_2) {
            if(vowels.find(s[pointer_1]) == vowels.end()) {
                pointer_1++;
                continue;
            }
            if(vowels.find(s[pointer_2]) == vowels.end()) {
                pointer_2--;
                continue;
            }
            if(vowels.find(s[pointer_1]) != vowels.end() && vowels.find(s[pointer_2])  != vowels.end()) {
                std::swap(s[pointer_1], s[pointer_2]);
                pointer_1++;
                pointer_2--;
            }
        }
        return s;
    }
};

int main() {
    std::string s1 = "hello";
    std::string s2 = "leetcode";

    Solution solution;

    std::string solution1 = solution.reverseVowels(s1);
    std::string solution2 = solution.reverseVowels(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}