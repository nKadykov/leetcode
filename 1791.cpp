#include <iostream>
#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& e) {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};

int main() {
    std::vector<std::vector<int>> a1 {
        {1, 2},
        {2, 3},
        {4, 2}
    };
    std::vector<std::vector<int>> a2 {
        {1, 2},
        {5, 1},
        {1, 3},
        {1, 4}
    };

    Solution solution;

    int solution1 = solution.findCenter(a1);
    int solution2 = solution.findCenter(a2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}