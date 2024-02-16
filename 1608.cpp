#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= n; i++) {
            auto p = lower_bound(nums.begin(), nums.end(), i);
            if(nums.end() - p == i) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {3,5};
    vector<int> nums2 {0,0};
    vector<int> nums3 {0,4,3,0,4};

    Solution solution;

    int solution1 = solution.specialArray(nums1);
    int solution2 = solution.specialArray(nums2);
    int solution3 = solution.specialArray(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}