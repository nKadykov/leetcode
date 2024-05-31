#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::vector<int> result;
        std::map<int, int> count_map;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            count_map[nums[i]]++;
        }
        for(auto &x : count_map) {
            if(x.second == 1) {
                result.push_back(x.first);
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1, 2, 1, 3, 2, 5};
    std::vector<int> nums2 {-1, 0};
    std::vector<int> nums3 {0, 1};

    Solution solution;

    std::vector<int> solution1 = solution.singleNumber(nums1);
    std::vector<int> solution2 = solution.singleNumber(nums2);
    std::vector<int> solution3 = solution.singleNumber(nums3);

    for(auto &x : solution1)
        std::cout << x << ' ';
    std::cout << std::endl;
    for(auto &x : solution2)
        std::cout << x << ' ';
    std::cout << std::endl;
    for(auto &x : solution3)
        std::cout << x << ' ';

    return 0;
}