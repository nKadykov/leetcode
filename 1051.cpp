#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> expected = heights;
        std::sort(expected.begin(), expected.end());
        int result = 0;
        for(int i = 0; i < heights.size(); ++i) {
            if(heights[i] != expected[i]) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> heights1 = {1, 1, 4, 2, 1, 3};
    std::vector<int> heights2 = {5, 1, 2, 3, 4};
    std::vector<int> heights3 = {1, 2, 3, 4, 5};

    Solution solution;

    int solution1 = solution.heightChecker(heights1);
    int solution2 = solution.heightChecker(heights2);
    int solution3 = solution.heightChecker(heights3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}