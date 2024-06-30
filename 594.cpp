#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        int result = 0;
        int left = 0;
        int right = 1;
        int current_index = 0;
        sort(nums.begin(), nums.end());
        while (right < nums.size()) {
            if (nums[right] - nums[left] == 1) {
                result = std::max(result, right - left + 1);
            }
            while(nums[right] - nums[left] > 1){
                ++left;
            }
            ++right;
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1,3,2,2,5,2,3,7};
    std::vector<int> nums2 {1,2,3,4};
    std::vector<int> nums3 {1,1,1,1};

    Solution solution;

    int solution1 = solution.findLHS(nums1);
    int solution2 = solution.findLHS(nums2);
    int solution3 = solution.findLHS(nums3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}