#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = 0;
        for(int i = 1; i < nums.size(); i++) {
            int gap = nums[i] - nums[i - 1];
            m = max(m, gap);
        }
        return m;
    }
};

int main() {
    vector<int> nums1 {3,6,9,1};
    vector<int> nums2 {10};

    Solution solution;

    int solution1 = solution.maximumGap(nums1);
    int solution2 = solution.maximumGap(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}