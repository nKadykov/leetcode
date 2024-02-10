#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for(int i = index; i < n; i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    vector<int> nums1 {0,1,0,3,12};
    vector<int> nums2 {0};

    Solution solution;

    solution.moveZeroes(nums1);
    solution.moveZeroes(nums2);

    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}