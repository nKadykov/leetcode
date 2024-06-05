#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<int> min_frequency(26, INT_MAX);
        for(auto& word : words) {
            std::vector<int> frequency(26, 0);
            for(char c : word) {
                frequency[c - 'a']++;
            }
            for(int i = 0; i < 26; ++i) {
                min_frequency[i] = std::min(min_frequency[i], frequency[i]);
            }
        }
        std::vector<std::string> result;
        for(int i = 0; i < 26; ++i) {
            while(min_frequency[i]-- > 0) {
                result.push_back(std::string(1, i + 'a'));
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::string> words1 {
        "bella",
        "label",
        "roller"
    };
    std::vector<std::string> words2 {
        "cool",
        "lock",
        "cook"
    };

    Solution solution;

    std::vector<std::string> result1 = solution.commonChars(words1);
    std::vector<std::string> result2 = solution.commonChars(words2);

    for(int i = 0; i < result1.size(); ++i) {
        std::cout << result1[i] << ' ';
    }
    std::cout << std::endl;
    for(int i = 0; i < result2.size(); ++i) {
        std::cout << result2[i] << ' ';
    }

    return 0;
}