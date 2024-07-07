#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        int carry = 0;
        for(int i = num.size() - 1; i >= 0; --i) {
            int digit = k % 10;
            int val = num[i];
            num[i] = (num[i] + digit + carry) % 10;
            carry = (val + digit + carry) / 10;
            k = k / 10;
        }
        while(k || carry) {
            int digit = k % 10;
            int val = (digit + carry) % 10;
            num.insert(num.begin(), val);
            carry = (digit + carry) / 10;
            k /= 10;
        }
        return num;
    }
};

int main() {
    std::vector<int> num1 = {1,2,0,0};
    int k1 = 34;
    std::vector<int> num2 = {2,7,4};
    int k2 = 181;
    std::vector<int> num3 = {2,1,5};
    int k3 = 806;

    Solution solution;

    std::vector<int> solution1 = solution.addToArrayForm(num1, k1);
    std::vector<int> solution2 = solution.addToArrayForm(num2, k2);
    std::vector<int> solution3 = solution.addToArrayForm(num3, k3);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for(auto x : solution2) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    for(auto x : solution3) {
        std::cout << x << ' ';
    }


    return 0;
}