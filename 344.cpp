#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n / 2; ++i) {
            std::swap(s[i], s[n - 1 - i]);
        }
    }
};

int main() {
    std::vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};

    Solution solution;

    solution.reverseString(s1);
    solution.reverseString(s2);

    for(int i = 0; i < s1.size(); ++i) {
        std::cout << s1[i];
    }
    std::cout << '\n';
    for(int i = 0; i < s2.size(); ++i) {
        std::cout << s2[i];
    }

    return 0;
}