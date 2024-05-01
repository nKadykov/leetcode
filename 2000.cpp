#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        if(!word.find(ch)) {
            return word;
        }
        int index = 0;
        for(int i = 0; i < word.size(); ++i) {
            if(word[i] == ch) {
                index = i;
                break;
            }
        }
        for(int i = 0; i <= index / 2; ++i) {
            std::swap(word[i], word[index - i]);
        } 
        return word;
    }
};

int main() {
    std::string word1 = "abcdefd";
    std::string word2 = "xyxzxe";
    std::string word3 = "abcd";

    char ch1 = 'd';
    char ch2 = 'z';
    char ch3 = 'z';

    Solution solution;

    std::string solution1 = solution.reversePrefix(word1, ch1);
    std::string solution2 = solution.reversePrefix(word2, ch2);
    std::string solution3 = solution.reversePrefix(word3, ch3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}