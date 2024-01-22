#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max = nums[0];
        int index = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(max <= nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {1,2,1,3,5,6,4};

    Solution solution;

    int solution1 = solution.findPeakElement(nums1);
    int solution2 = solution.findPeakElement(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}