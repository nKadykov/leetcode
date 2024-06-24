#include <iostream>
#include <vector>

class Solution {
public:
    int minKBitFlips(std::vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int result = 0;
        std::vector<int> is_flipped(n, 0);

        for(int i = 0; i < n; ++i) {
            if(i >= k) {
                flipped ^= is_flipped[i - k];
            }
            if(flipped == nums[i]) {
                if(i + k > n) {
                    return -1;
                }
                is_flipped[i] = 1;
                flipped ^= 1;
                result++;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {0,1,0};
    int k1 = 1;
    std::vector<int> nums2 {1,1,0};
    int k2 = 2;
    std::vector<int> nums3 {0,0,0,1,0,1,1,0};
    int k3 = 3;

    Solution solution;

    int solution1 = solution.minKBitFlips(nums1, k1);
    int solution2 = solution.minKBitFlips(nums2, k2);
    int solution3 = solution.minKBitFlips(nums3, k3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}