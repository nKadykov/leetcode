#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        int result = n + 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            while(index < n && sum >=  target) {
                result = min(result, i - index + 1);
                sum -= nums[index];
                index++;
            }
        }
        return result == n + 1 ? 0 : result;
    }
};

int main() {
    int target1 = 7;
    vector<int> nums1 {2,3,1,2,4,3};
    int target2 = 4;
    vector<int> nums2 {1,4,4};

    Solution solution;

    int solution1 = solution.minSubArrayLen(target1, nums1);
    int solution2 = solution.minSubArrayLen(target2, nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}