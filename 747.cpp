#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int dominantIndex(std::vector<int>& nums) {
        int max = 0;
        int max_index = 0;
        int second_max = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > max) {
                second_max = max;
                max = nums[i];
                max_index = i;
            }
            if(nums[i] > second_max && nums[i] < max) {
                second_max = nums[i];
            }
        }
        if(max < (2 * second_max)) {
            return -1;
        }
        return max_index;
    }
};

int main() {
    std::vector<int> nums1 = {3,6,1,0};
    std::vector<int> nums2 = {1,2,3,4};

    Solution solution;

    int solution1 = solution.dominantIndex(nums1);
    int solution2 = solution.dominantIndex(nums2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}