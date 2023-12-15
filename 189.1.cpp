#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k != 0) {
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end() - k);
            reverse(nums.begin(), nums.end());
        }
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