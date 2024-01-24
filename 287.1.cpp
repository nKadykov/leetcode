#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {1,3,4,2,2};
    vector<int> nums2 {3,1,3,4,2};

    Solution solution;

    int solution1 = solution.findDuplicate(nums1);
    int solution2 = solution.findDuplicate(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}