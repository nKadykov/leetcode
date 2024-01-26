#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid;
        while(begin <= end) {
            mid = (begin + end) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                begin = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {-1,0,3,5,9,12};
    int target1 = 9;
    vector<int> nums2 {-1,0,3,5,9,12};
    int target2 = 2;

    Solution solution;

    int solution1 = solution.search(nums1, target1);
    int solution2 = solution.search(nums2, target2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}