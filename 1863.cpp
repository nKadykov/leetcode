#include <iostream>
#include <vector>

class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < (1 << n); ++i) {
            int sub_xor = 0;
            for(int j = 0; j < n; ++j) {
                if(i & (1 << j)) {
                    sub_xor ^= nums[j];
                }
            }
            result += sub_xor;
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1, 3};
    std::vector<int> nums2 {5, 1, 6};
    std::vector<int> nums3 {3, 4, 5, 6, 7, 8};

    Solution solution;

    int solution1 = solution.subsetXORSum(nums1);
    int solution2 = solution.subsetXORSum(nums2);
    int solution3 = solution.subsetXORSum(nums3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}