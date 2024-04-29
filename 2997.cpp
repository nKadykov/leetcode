#include <iostream>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        int count = 0;
        while(k || result) {
            int r1 = k & 1;
            int r2 = result & 1;
            if(r1 != r2) {
                count++;
            }
            k /= 2;
            result /= 2;
        }
        return count;
    }
};

int main() {
    std::vector<int> nums1 {2, 1, 3, 4};
    std::vector<int> nums2 {2, 0, 2, 0};
    int k1 = 1;
    int k2 = 0;

    Solution solution;

    int solution1 = solution.minOperations(nums1, k1);
    int solution2 = solution.minOperations(nums2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}