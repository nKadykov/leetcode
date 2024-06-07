#include <iostream>
#include <vector>
#include <set>
#include <sstream>

class Solution {
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        std::set<std::string> letter_set(begin(dictionary), end(dictionary));
        std::istringstream iss(sentence);
        std::vector<std::string> temp;
        std::string word;
        std::string result;

        while(iss >> word) {
            temp.push_back(word);
        }
        for(std::string x : temp) {
            int i = 0;
            while(i <= x.size()) {
                std::string current_string = x.substr(0, i);
                if(letter_set.find(current_string) != letter_set.end()) {
                    result += current_string + " ";
                    break;
                }
                if(i == x.size()) {
                    result += current_string + " ";
                }
                i++;
            }
        }
        result.erase(result.size() - 1);
        return result;
    }
};

int main() {
    std::vector<std::string> dictionary1 = {
        "cat",
        "bat",
        "rat"
    };
    std::vector<std::string> dictionary2 = {
        "a",
        "b",
        "c"
    };
    std::string sentence1 = "the cattle was rattled by the battery";
    std::string sentence2 = "aadsfasf absbs bbab cadsfafs";

    Solution solution;

    std::string solution1 = solution.replaceWords(dictionary1, sentence1);
    std::string solution2 = solution.replaceWords(dictionary2, sentence2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}