#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {  
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int max_number = std::numeric_limits<int>::min();
        while(left < right) {
            int sum = nums[left] + nums[right];

            if(sum == 0) {
                max_number = std::max(max_number, nums[right]);
                left++;
                right--;
            }
            
            if(sum < 0) {
                left++;
            }

            if(sum > 0) {
                right--;
            }
        }

        return max_number != std::numeric_limits<int>::min() ? max_number : -1;
    }
};

int main() {
    std::vector<int> nums1 {-1, 2, -3, 3};
    std::vector<int> nums2 {-1, 10, 6, 7, -7, 1};
    std::vector<int> nums3 {-10, 8, 6, 7, -2, -3};

    Solution solution;

    int solution1 = solution.findMaxK(nums1);
    int solution2 = solution.findMaxK(nums2);
    int solution3 = solution.findMaxK(nums3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}