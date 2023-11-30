#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int number = nums.size();
        for(int i = 0; i < number; i++) {
            if(nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums1 {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    vector<int> nums2 {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;

    Solution solution;

    bool solution1 = solution.search(nums1, target1);
    bool solution2 = solution.search(nums2, target2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}