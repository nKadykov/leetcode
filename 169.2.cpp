#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int e = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(c == 0) {
                e = nums[i];
            }
            c += e == nums[i] ? 1 : -1;
        }
        return e;
    }
};

int main() {
    vector<int> nums1 {3,2,3};
    vector<int> nums2 {2,2,1,1,1,2,2};

    Solution solution;

    int solution1 = solution.majorityElement(nums1);
    int solution2 = solution.majorityElement(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}