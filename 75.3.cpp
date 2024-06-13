#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                std::swap(nums[index], nums[i]);
                index++;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 1) {
                std::swap(nums[index], nums[i]);
                index++;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 2) {
                std::swap(nums[index], nums[i]);
                index++;
            }
        }
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