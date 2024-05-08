#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<int> sorted_score = score;
        sort(sorted_score.begin(), sorted_score.end(), std::greater<int>());
        std::vector<std::string> medal = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        std::unordered_map<int, std::string> mapping;
        for(int i = 0; i < sorted_score.size(); ++i) {
            if(i < 3) {
                mapping[sorted_score[i]] = medal[i];
            }
            else {
                mapping[sorted_score[i]] = std::to_string(i + 1);
            }
        }
        std::vector<std::string> result;
        for(int s : score) {
            result.push_back(mapping[s]);
        }
        return result;
    }
};

int main() {
    std::vector<int> score1 {5, 4, 3, 2, 1};
    std::vector<int> score2 {10, 3, 8, 9, 4};

    Solution solution;

    std::vector<std::string> solution1 = solution.findRelativeRanks(score1);
    std::vector<std::string> solution2 = solution.findRelativeRanks(score2);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for(auto x : solution2) {
        std::cout << x << ' ';
    }

    return 0;
}