#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = INT_MIN;
        int p = 1;
        for(int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            m = max(p, m);
            if(p == 0) {
                p = 1;
            }
        }
        p = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            p *= nums[i];
            m = max(p, m);
            if(p == 0) {
                p = 1;
            }
        }
        return m;
    }
};

int main() {
    vector<int> nums1 {2,3,-2,4};
    vector<int> nums2 {-2,0,-1};

    Solution solution;

    int solution1 = solution.maxProduct(nums1);
    int solution2 = solution.maxProduct(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}