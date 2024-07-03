#include <iostream>
#include <cstring>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        std::string result = "";
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        int j = 0;
        int c = 0;
        while(i < num1.size() && j < num2.size()) {
            int sum = int(num1[i++] - '0') + int(num2[j++] - '0') + carry;
            carry = sum / 10;
            result.push_back(static_cast<char>(sum % 10 + '0'));
        }
        while(i < num1.size()) {
            int sum = int(num1[i++] - '0') + carry;
            carry = sum / 10;
            result.push_back(static_cast<char>(sum % 10 + '0'));
        }
        while(j < num2.size()) {
            int sum = static_cast<int>(num2[j++] - '0') + carry;
            carry = sum / 10;
            result.push_back(static_cast<char>(sum % 10 + '0'));
        }
        while(carry) {
            result.push_back(static_cast<char>((carry % 10) + '0'));
            carry = carry / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    std::string num11 = "11";
    std::string num12 = "123";
    std::string num21 = "456";
    std::string num22 = "77";
    std::string num31 = "0";
    std::string num32 = "0";

    Solution solution;

    std::string solution1 = solution.addStrings(num11, num12);
    std::string solution2 = solution.addStrings(num21, num22);
    std::string solution3 = solution.addStrings(num31, num32);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}