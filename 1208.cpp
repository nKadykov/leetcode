#include <iostream>

class Solution {
public:
    int equalSubstring(std::string s, std::string t, int maxCost) {
        int start = 0, current_cost = 0, max_length = 0;
        int n = s.size();
        for(int end = 0; end < n; ++end) {
            current_cost += abs(s[end] - t[end]);
            while(current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                ++start;
            }
            max_length = std::max(max_length, end - start + 1);
        }
        return max_length;
    }
};

int main() {
    std::string s1 = "abcd";
    std::string t1 = "bcdf";
    int max_cost_1 = 3;
    std::string s2 = "abcd";
    std::string t2 = "cdef";
    int max_cost_2 = 3;
    std::string s3 = "abcd";
    std::string t3 = "acde";
    int max_cost_3 = 0;

    Solution solution;

    int solution1 = solution.equalSubstring(s1, t1, max_cost_1);
    int solution2 = solution.equalSubstring(s2, t2, max_cost_2);
    int solution3 = solution.equalSubstring(s3, t3, max_cost_3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}