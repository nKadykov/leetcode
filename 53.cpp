#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> m(2, vector<int>(nums.size()));
        m[0][0] = m[1][0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            m[1][i] = max(nums[i], nums[i] + m[1][i - 1]);
            m[0][i] = max(m[0][i - 1], m[1][i]);
        }
        return m[0].back();
    }
};

int main() {
    vector<int> nums1 {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 {1};
    vector<int> nums3 {5,4,-1,7,8};

    Solution solution;

    int solution1 = solution.maxSubArray(nums1);
    int solution2 = solution.maxSubArray(nums2);
    int solution3 = solution.maxSubArray(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}