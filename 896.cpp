#include <iostream>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool result = false;
        result = solve(nums);
        if(result)
        {
            return true;
        }
        std::reverse(nums.begin(), nums.end());
        result = solve(nums);
        return result;
    }
private:
    bool solve(std::vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 1; i < n; ++i)
        {
            if(nums[i - 1] > nums[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    std::vector<int> nums1 {1,2,2,3};
    std::vector<int> nums2 {6,5,4,4};
    std::vector<int> nums3 {1,3,2};

    Solution solution;

    bool solution1 = solution.isMonotonic(nums1);
    bool solution2 = solution.isMonotonic(nums2);
    bool solution3 = solution.isMonotonic(nums3);

    std::cout << std::boolalpha;
    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}