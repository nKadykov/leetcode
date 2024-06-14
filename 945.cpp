#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] <= nums[i - 1]) {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1, 2, 2};
    std::vector<int> nums2 {3, 2, 1, 2, 1, 7};

    Solution solution;

    int solution1 = solution.minIncrementForUnique(nums1);
    int solution2 = solution.minIncrementForUnique(nums2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}