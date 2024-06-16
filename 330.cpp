#include <iostream>
#include <vector>

class Solution {
public:
    int minPatches(std::vector<int>& nums, int n) {
        long long sum = 1;
        int result = 0;
        int i = 0;
        int number = nums.size();
        while(sum <= n) {
            if(i < number && nums[i] <= sum) {
                sum += nums[i];
                i++;
            } else {
                sum += sum;
                result++;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1, 3};
    int n1 = 6;
    std::vector<int> nums2 {1, 5, 10};
    int n2 = 20;
    std::vector<int> nums3 {1, 2, 2};
    int n3 = 5;

    Solution solution;

    int solution1 = solution.minPatches(nums1, n1);
    int solution2 = solution.minPatches(nums2, n2);
    int solution3 = solution.minPatches(nums3, n3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}