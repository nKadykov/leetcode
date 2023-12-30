#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[n]);
                n++;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[n]);
                n++;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2) {
                swap(nums[i], nums[n]);
                n++;
            }
        }
        return;
    }
};

int main() {
    vector<int> nums1 {2,0,2,1,1,0};
    vector<int> nums2 {2,0,1};

    Solution solution;

    solution.sortColors(nums1);
    solution.sortColors(nums2);

    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}