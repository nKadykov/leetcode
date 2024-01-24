#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> sub(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    sub[i] = max(sub[i], sub[j] + 1);
                }
            }
        }
        return *max_element(sub.begin(), sub.end());
    }
};

int main() {
    vector<int> nums1 {10,9,2,5,3,7,101,18};
    vector<int> nums2 {0,1,0,3,2,3};
    vector<int> nums3 {7,7,7,7,7,7,7};

    Solution solution;

    int solution1 = solution.lengthOfLIS(nums1);
    int solution2 = solution.lengthOfLIS(nums2);
    int solution3 = solution.lengthOfLIS(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}
