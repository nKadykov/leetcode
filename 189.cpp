#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

int main() {
    vector<int> nums1 {1,2,3,4,5,6,7};
    int k1 = 3;
    vector<int> nums2 {-1,-100,3,99};
    int k2 = 2;

    Solution solution;

    solution.rotate(nums1, k1);
    solution.rotate(nums2, k2);

    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}