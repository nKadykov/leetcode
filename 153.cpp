#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin < end) {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] > nums[end]) {
                begin = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[begin];
    }
};

int main() {
    vector<int> nums1 {3,4,5,1,2};
    vector<int> nums2 {4,5,6,7,0,1,2};
    vector<int> nums3 {11,13,15,17};

    Solution solution;

    int solution1 = solution.findMin(nums1);
    int solution2 = solution.findMin(nums2);
    int solution3 = solution.findMin(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}