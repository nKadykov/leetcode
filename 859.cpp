#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool buddyStrings(std::string s, std::string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        if(s == goal) {
            std::sort(s.begin(), s.end());
            for(int i = 0; i < s.size() - 1; ++i) {
                if(s[i] == s[i + 1]) {
                    return true;
                }
            }
            return false;
        }
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while(i < j && s[i] == goal[i]) {
            i++;
        }
        while(j >= 0 && s[j] == goal[j]) {
            j--;
        }
        if(i < j) {
            std::swap(s[i], s[j]);
        }
        return s == goal;
    }
};

int main() {
    std::string s1 = "ab";
    std::string s2 = "ab";
    std::string s3 = "aa";

    std::string goal1 = "ba";
    std::string goal2 = "ab";
    std::string goal3 = "aa";

    Solution solution;

    bool solution1 = solution.buddyStrings(s1, goal1);
    bool solution2 = solution.buddyStrings(s2, goal2);
    bool solution3 = solution.buddyStrings(s3, goal3);

    std::cout.setf(std::ios::boolalpha);
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}