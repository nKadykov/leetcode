#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int number = nums.size();
        int index = 0;
        int left = 0;
        int flag = false;
        int right = number - 1;
        for(int i = 0; i < number - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                index = i;
                flag = true;
                break;
            }
        }
        if(target == nums[0]) {
            return 0;
        }
        if(target < nums[0] && flag) {
            left = index + 1;
            right = number - 1;
        }
        if(target > nums[0] && flag){
            left = 0;
            right = index;
        }
        int mid = (left + right) / 2;
        while(left <= right) {
            if(target > nums[mid]) {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else if(target < nums[mid]){
                right = mid - 1;
                mid = (left + right) / 2;
            }
            else {
                return mid;
            }

        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    vector<int> nums2 {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    vector<int> nums3 {1};
    int target3 = 0;

    Solution solution;

    int solution1 = solution.search(nums1, target1);
    int solution2 = solution.search(nums2, target2);
    int solution3 = solution.search(nums3, target3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3 << '\n';
}