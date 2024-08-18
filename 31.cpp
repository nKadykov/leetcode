#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) 
    {
        int number = nums.size();
        int index = -1;
        for(int i = 0; i < number - 1; i++) 
        {
            if(nums[i] < nums[i + 1]) 
            {
                index = i;
            }
        }
        if(index == -1) 
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int left = index + 1;
        for(int i = index + 1; i < number; i++) 
        {
            if(nums[i] > nums[index]) 
            {
                left = i;
            }
        }
        std::swap(nums[index], nums[left]);
        reverse(nums.begin() + 1 + index, nums.end());
        return;
    }
};

int main() 
{
    std::vector<int> nums1 {1, 2, 3};
    std::vector<int> nums2 {3, 2, 1};
    std::vector<int> nums3 {1, 1, 5};

    Solution solution;

    solution.nextPermutation(nums1);
    solution.nextPermutation(nums2);
    solution.nextPermutation(nums3);

    for(auto& x : nums1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto& x : nums2) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto& x : nums3) {
        std::cout << x << ' ';
    }
}