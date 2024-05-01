#include <iostream>
#include <vector>

class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        std::vector<long long> count(1024, 0);
        long long result = 0;
        int prefixXOR = 0;
        count[prefixXOR] = 1;
        for(char ch : word) {
            int charIndex = ch - 'a';
            prefixXOR ^= 1 << charIndex;
            result += count[prefixXOR];
            for(int i = 0; i < 10; i++) {
                result += count[prefixXOR ^ (1 << i)];
            }
            count[prefixXOR]++;
        }
        return result;
    }
};

int main() {

    std::string word1 = "aba";
    std::string word2 = "aabb";
    std::string word3 = "he";

    Solution solution;

    int solution1 = solution.wonderfulSubstrings(word1);
    int solution2 = solution.wonderfulSubstrings(word2);
    int solution3 = solution.wonderfulSubstrings(word3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}