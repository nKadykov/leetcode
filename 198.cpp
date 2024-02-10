#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0;
        int norob = 0;
        for(int i = 0; i < nums.size(); i++) {
            int newRob = norob + nums[i];
            int newNoRob = max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }
        return max(rob, norob);
    }
};

int main() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {2,7,9,3,1};

    Solution solution;

    int solution1 = solution.rob(nums1);
    int solution2 = solution.rob(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}