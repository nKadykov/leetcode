#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int count = accumulate(nums.begin(), nums.begin() + k, 0);
        int max_swap = count;
        for(int i = k; i < n + k; ++i) {
            count += nums[i % n] - nums[(i - k + n) % n];
            max_swap = std::max(max_swap, count);
        }
        return k - max_swap;
    }
};

int main() {
    std::vector<int> nums1 {0,1,0,1,1,0,0};
    std::vector<int> nums2 {0,1,1,1,0,0,1,1,0};
    std::vector<int> nums3 {1,1,0,0,1};

    Solution solution;

    int solution1 = solution.minSwaps(nums1);
    int solution2 = solution.minSwaps(nums2);
    int solution3 = solution.minSwaps(nums3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;
    
    return 0;
}