#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;

        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int rem = sum % k;
            
            if(map.find(rem) != map.end()) {
                if(i - map[rem] > 1) {
                    return true;
                }
            } else {
                map[rem] = i;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> nums1 = {23, 2, 4, 6, 7};
    std::vector<int> nums2 = {23, 2, 6, 4, 7};
    std::vector<int> nums3 = {23, 2, 6, 4, 7};

    int k1 = 6;
    int k2 = 6;
    int k3 = 13;

    Solution solution;

    bool solution1 = solution.checkSubarraySum(nums1, k1);
    bool solution2 = solution.checkSubarraySum(nums3, k2);
    bool solution3 = solution.checkSubarraySum(nums3, k3);

    std::cout << std::boolalpha << solution1 << std::endl; 
    std::cout << std::boolalpha << solution2 << std::endl; 
    std::cout << std::boolalpha << solution3 << std::endl; 

    return 0;
}