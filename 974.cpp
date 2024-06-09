#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(const std::vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        int prefix_sum = 0;
        std::unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;
        for(int num : nums) {
            prefix_sum += num;
            int mod = prefix_sum % k;
            if(mod < 0) {
                mod += k;
            }
            if(prefix_map.find(mod) != prefix_map.end()) {
                result += prefix_map[mod];
                prefix_map[mod] += 1;
            } else {
                prefix_map[mod] = 1;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {4, 5, 0, -2, -3, 1};
    std::vector<int> nums2 {5};
    int k1 = 5;
    int k2 = 9;

    Solution solution;

    int solution1 = solution.subarraysDivByK(nums1, k1);
    int solution2 = solution.subarraysDivByK(nums2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}