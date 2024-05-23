#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
    int count;
    std::unordered_map<int, int> visited;
    void solve(std::vector<int>& nums, int k, int index) {
        if(index == nums.size()) {
            count++;
            return;
        }
        int num = nums[index];
        if(visited.find(num - k) == visited.end() && visited.find(num + k) == visited.end()) {
            visited[num]++;
            solve(nums, k, index + 1);
            visited[num]--;
            if(visited[num] == 0) {
                visited.erase(num);
            }
        }
        solve(nums, k, index + 1);
    }
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        count = 0;
        solve(nums, k, 0);
        return count - 1;
    }
};

int main() {
    std::vector<int> nums1 {2, 4, 6};
    std::vector<int> nums2 {1};
    int k1 = 2;
    int k2 = 1;

    Solution solution;

    int solution1 = solution.beautifulSubsets(nums1, k1);
    int solution2 = solution.beautifulSubsets(nums2, k2);

    std::cout << solution1 << std::endl;
    std::cout << solution2 << std::endl;

    return 0;
}