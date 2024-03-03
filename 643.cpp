#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double result = sum / k;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            result = max(result, sum / k);
        }

        return result;
    }
};

int main() {
    vector<int> nums1 {1,12,-5,-6,50,3};
    int k1 = 4;
    vector<int> nums2 {5};
    int k2 = 1;

    Solution solution;

    double solution1 = solution.findMaxAverage(nums1, k1);
    double solution2 = solution.findMaxAverage(nums2, k2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}