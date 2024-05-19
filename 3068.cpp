#include <iostream>
#include <vector>

class Solution {
public:
    long long maximumValueSum(std::vector<int>& nums, int k, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<long long>> temp(n, std::vector<long long>(2, -1));

        return maximum(nums, n, k, 0, 1, temp);
    }
private:
    long long maximum(std::vector<int>& nums, int n, int k, int cur_index, int is_even, std::vector<std::vector<long long>>& temp) {
        if(cur_index == n) {
            return is_even == 1 ? 0 : LLONG_MIN;
        }
        if(temp[cur_index][is_even] != -1) {
            return temp[cur_index][is_even];
        } 

        long long no_xor = nums[cur_index] + maximum(nums, n, k, cur_index + 1, is_even, temp);
        long long xorr = (nums[cur_index] ^ k) + maximum(nums, n, k, cur_index + 1, !is_even, temp);

        long long result = std::max(no_xor, xorr);
        temp[cur_index][is_even] = result;
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1, 2, 1};
    std::vector<int> nums2 {2, 3};
    std::vector<int> nums3 {7, 7, 7, 7, 7, 7};

    int k1 = 3;
    int k2 = 7;
    int k3 = 3;

    std::vector<std::vector<int>> edges1 {
        {0, 1},
        {0, 2}
    };
    std::vector<std::vector<int>> edges2 {
        {0, 1}
    };
    std::vector<std::vector<int>> edges3 {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5}
    };

    Solution solution;

    int solution1 = solution.maximumValueSum(nums1, k1, edges1);
    int solution2 = solution.maximumValueSum(nums2, k2, edges2);
    int solution3 = solution.maximumValueSum(nums3, k3, edges3);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;
    std::cout << solution3 << std::endl;

    return 0;
}