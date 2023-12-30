#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v0;
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                v0.push_back(nums[i]);
            }
            if(nums[i] == 1) {
                v1.push_back(nums[i]);
            }
            if(nums[i] == 2) {
                v2.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i = 0; i < v0.size(); i++) {
            nums.push_back(v0[i]);
        }  
        for(int i = 0; i < v1.size(); i++) {
            nums.push_back(v1[i]);
        }       
        for(int i = 0; i < v2.size(); i++) {
            nums.push_back(v2[i]);
        }
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