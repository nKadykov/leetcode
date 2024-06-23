#include <iostream>
#include <deque>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> increase;
        std::deque<int> decrease;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(nums[right]);

            while (!decrease.empty() && nums[right] > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(nums[right]);

            while (decrease.front() - increase.front() > limit) {
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    std::vector<int> nums1 {8,2,4,7};
    int limit1 = 4;
    std::vector<int> nums2 {10,1,2,4,7,2};
    int limit2 = 5;
    std::vector<int> nums3 {4,2,2,2,4,4,2,2};
    int limit3 = 0;

    Solution solution;

    int solution1 = solution.longestSubarray(nums1, limit1);
    int solution2 = solution.longestSubarray(nums2, limit2);
    int solution3 = solution.longestSubarray(nums3, limit3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}