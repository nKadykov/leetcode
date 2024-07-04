#include <iostream>
#include <vector>

class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int num : nums) {
            if(num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if(num > max2) {
                max3 = max2;
                max2 = num;
            } else if(num > max3) {
                max3 = num;
            }
            if(num < min1) {
                min2 = min1;
                min1 = num;
            } else if(num < min2) {
                min2 = num;
            }
        }
        return std::max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main() {
    std::vector<int> nums1 {1, 2, 3};
    std::vector<int> nums2 {1, 2, 3, 4};
    std::vector<int> nums3 {-1, -2, -3};

    Solution solution;

    int solution1 = solution.maximumProduct(nums1);
    int solution2 = solution.maximumProduct(nums2);
    int solution3 = solution.maximumProduct(nums3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}