#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool makeEqual(std::vector<std::string>& words) {
        std::unordered_map<char, int> letter_map;
        int min_number = INT_MAX;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words[i].size(); ++j) {
                letter_map[words[i][j]]++;
            }
        }
        if(words.size() == 1) {
            return true;
        }
        for(auto x : letter_map) {
            if(x.second % words.size() != 0)
                return false;
        }
        return true;
    }
};

int main() {
    std::vector<std::string> words1 {
        "abc",
        "aabc",
        "bc"
    };
    std::vector<std::string> words2 {
        "ab",
        "a"
    };

    Solution solution;

    bool solution1 = solution.makeEqual(words1);
    bool solution2 = solution.makeEqual(words2);

    std::cout.setf(std::ios::boolalpha);
    std::cout << solution1 << "\n";
    std::cout << solution2 << "\n";

    return 0;
}