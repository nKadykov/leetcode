#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }
        return totalSum - sum;
    }
};

int main() {
    vector<int> nums1 {3,0,1};
    vector<int> nums2 {0,1};
    vector<int> nums3 {9,6,4,2,3,5,7,0,1};

    Solution solution;

    int solution1 = solution.missingNumber(nums1);
    int solution2 = solution.missingNumber(nums2);
    int solution3 = solution.missingNumber(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}