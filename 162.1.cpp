#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        if(nums[0] > nums[1]) {
            return 0;
        }
        if(nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int begin = 0;
        int end = nums.size();

        while(begin <= end) {
            int mid = (begin + end) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid + 1]) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        return 0;
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