#include <iostream>
#include <vector>
#include <cstring>

class Solution {
    void solve(const std::string& s, int start, std::vector<std::string>& sub, std::vector<std::vector<std::string>>& result) {
        if(start == s.size()) {
            result.push_back(sub);
            return;
        }
        for(int end = start + 1; end <= s.size(); ++end) {
            if(isPalindrome(s, start, end - 1)) {
                sub.push_back(s.substr(start, end - start));
                solve(s, end, sub, result);
                sub.pop_back();
            }
        }
    }
    bool isPalindrome(const std::string&s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> sub;
        solve(s, 0, sub, result);
        return result;
    }
};


int main() {
    std::string s1 = "aab";
    std::string s2 = "a";

    Solution solution;

    std::vector<std::vector<std::string>> solution1 = solution.partition(s1);
    std::vector<std::vector<std::string>> solution2 = solution.partition(s2);

    for(auto x : solution1) {
        for(auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        for(auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}