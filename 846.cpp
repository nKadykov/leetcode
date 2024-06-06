#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int group_size) {
        int n = hand.size();
        if(n % group_size) {
            return false;
        }
        std::sort(hand.begin(), hand.end());
        std::vector<int> index(group_size, -1);
        int j = 1;
        for(int i = 0; i < n; ++i) {
            if(hand[i] == -1) {
                continue;
            }
            if(index[0] == -1) {
                index[0] = i;
            }
            else {
                if(j < group_size) {
                    if(hand[i] == (hand[index[j - 1]] + 1)) {
                        index[j] = i;
                        j++;
                    }
                }
                if(j == group_size) {
                    for(int k = 0; k < group_size; ++k) {
                        hand[index[k]] = -1;
                        index[k] = -1;
                    }
                    j = 1;
                    i = 0;
                }
            }
        }
        for(int k = 0; k < group_size; ++k) {
            if(index[k] != -1) {
                hand[index[k]] = -1;
                index[k] = -1;
            }
        }
        for(auto x : hand) {
            if(x != -1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> hand1 {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int group_size1 = 3;
    std::vector<int> hand2 {1, 2, 3, 4, 5};
    int group_size2 = 4;

    Solution solution;

    bool solution1 = solution.isNStraightHand(hand1, group_size1);
    bool solution2 = solution.isNStraightHand(hand2, group_size2);

    std::cout << std::boolalpha << solution1 << std::endl;
    std::cout << std::boolalpha << solution2 << std::endl;

    return 0;
}