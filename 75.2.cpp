#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return;
    }
};

int main() {
    std::vector<int> nums1 {2,0,2,1,1,0};
    std::vector<int> nums2 {2,0,1};

    Solution solution;

    solution.sortColors(nums1);
    solution.sortColors(nums2);

    for(auto x : nums1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : nums2) {
        std::cout << x << ' ';
    }

    return 0;
}