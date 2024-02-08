#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(m.count(nums[i])) {
                if(abs(i - m[nums[i]]) <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    vector<int> nums1 {1,2,3,1};
    int k1 = 3;
    vector<int> nums2 {1,0,1,1};
    int k2 = 1;
    vector<int> nums3 {1,2,3,1,2,3};
    int k3 = 2;

    Solution solution;

    bool solution1 = solution.containsNearbyDuplicate(nums1, k1);
    bool solution2 = solution.containsNearbyDuplicate(nums2, k2);
    bool solution3 = solution.containsNearbyDuplicate(nums3, k3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}