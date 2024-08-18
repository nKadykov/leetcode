#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) 
    {
        int n = nums.size();
        std::vector<bool> result(n);
        int remainder = 0;
        for(int i = 0; i < n; ++i)
        {
            remainder = (remainder << 1 | nums[i]) % 5;
            result[i] = !static_cast<bool>(remainder); 
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums1 {0,1,1};
    std::vector<int> nums2 {1,1,1};

    Solution solution;

    std::vector<bool> solution1 = solution.prefixesDivBy5(nums1);
    std::vector<bool> solution2 = solution.prefixesDivBy5(nums2);

    std::cout << std::boolalpha;
    for(bool x : solution1)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(bool x : solution2)
    {
        std::cout << x << ' ';
    }
    
    return 0;
}