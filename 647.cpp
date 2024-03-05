#include <iostream>

class Solution {
    std::string t;
    int check(int l, int r) {
        int result = 0;
        while(l >= 0 && r <= t.size()) {
            if(t[l--] == t[r++]) {
                result++;
            }
            else {
                break;
            }
        }
        return result;
    }
public:
    int countSubstrings(std::string s) {
        int n = s.size();
        int result = 0;
        t = s;
        for(int i = 0; i < n; i++) {
            result += check(i, i);
            result += check(i, i + 1);
        }
        return result;
    }
};

int main() {
    std::string s1 = "abc";
    std::string s2 = "aaa";

    Solution solution;

    int solution1 = solution.countSubstrings(s1);
    int solution2 = solution.countSubstrings(s2);

    std::cout << solution1 << std::endl;
    std::cout << solution2;

    return 0;
}