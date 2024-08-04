#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        std::vector<int> arr(n * (n + 1) / 2);
        for(int i = 0, k = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum += nums[j];
                arr[k++] = sum;
            }
        }
        std::sort(arr.begin(), arr.end());
        int result = 0;
        const int mod = 1e9 + 7;
        for(int i = left - 1; i < right; ++i) {
            result = (result + arr[i]) % mod;
        }
        return result;
    }
};

int main() {
    std::vector<int> nums1 {1,2,3,4};
    int n1 = 4;
    int left1 = 1;
    int right1 = 5;
    std::vector<int> nums2 {1,2,3,4};
    int n2 = 4;
    int left2 = 3;
    int right2 = 4;
    std::vector<int> nums3 {1,2,3,4};
    int n3 = 4;
    int left3 = 1;
    int right3 = 10;

    Solution solution;

    int solution1 = solution.rangeSum(nums1, n1, left1, right1);
    int solution2 = solution.rangeSum(nums2, n2, left2, right2);
    int solution3 = solution.rangeSum(nums3, n3, left3, right3);

    std::cout << solution1 << '\n';
    std::cout << solution2 << '\n';
    std::cout << solution3 << '\n';

    return 0;
}