#include <iostream>
#include <vector>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums1 {2,4,6};
    int k1 = 1;
    std::vector<int> nums2 {2,2,2,1,2,2,1,2,2,2};
    int k2 = 2;

    Solution solution;
    
    int solution1 = solution.numberOfSubarrays(nums1, k1);
    int solution2 = solution.numberOfSubarrays(nums2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}