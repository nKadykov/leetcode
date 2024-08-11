#include <iostream>
#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        int five_count = 0;
        int ten_count = 0;
        for(int bill : bills) {
            if(bill == 5)
                five_count++;
            else if(bill == 10) {
                if(five_count >= 1) {
                    ten_count++;
                    five_count--;
                } else
                    return false;
            }
            else {
                if(ten_count >= 1 && five_count >= 1) {
                    ten_count--;
                    five_count--;
                } else if(five_count >= 3) {
                    five_count -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> bills1 {5,5,5,10,20};
    std::vector<int> bills2 {5,5,10,10,20};

    Solution solution;

    bool solution1 = solution.lemonadeChange(bills1);
    bool solution2 = solution.lemonadeChange(bills2);

    std::cout << std::boolalpha;
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}