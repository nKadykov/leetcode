#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i;
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