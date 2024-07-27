#include <iostream>

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        int n = s.size();
        int counter = 0;
        for(auto x : s) {
            if(x == '1')
                counter++;
        }
        s = std::string(n, '0');
        if(counter == 0)
            return s;
        else {
            s[n - 1] = '1';
            counter--;
            for(int i = 0; i < counter; ++i)
                s[i] = '1';
        }
        return s;
    }
};

int main() {
    std::string s1 = "010";
    std::string s2 = "0101";

    Solution solution;

    std::string solution1 = solution.maximumOddBinaryNumber(s1);
    std::string solution2 = solution.maximumOddBinaryNumber(s2);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';

    return 0;
}