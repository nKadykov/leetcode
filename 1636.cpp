#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        std::sort(nums.begin(), nums.end(), [&](int n1, int n2) {
            if(freq[n1] != freq[n2]) {
                return freq[n1] < freq[n2];
            } else {
                return n2 < n1;
            }
        });
        return nums;
    }
};

int main() {
    std::vector<int> nums1 {1,1,2,2,2,3};
    std::vector<int> nums2 {2,3,1,3,2};
    std::vector<int> nums3 {-1,1,-6,4,5,-6,1,4,1};

    Solution solution;

    std::vector<int> solution1 = solution.frequencySort(nums1);
    std::vector<int> solution2 = solution.frequencySort(nums2);
    std::vector<int> solution3 = solution.frequencySort(nums3);

    for(auto x : solution1) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution2) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(auto x : solution3) {
        std::cout << x << ' ';
    }

    return 0;
}