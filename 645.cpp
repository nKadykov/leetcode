#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int sum = nums[0];
        int dif = nums.size();
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            dif += i;
            if(nums[i] == nums[i - 1]) {
                result.push_back(nums[i]);
            }
        }
        dif = result[0] + (dif - sum);
        result.push_back(dif);
        return result;
    }
};

int main() {
    vector<int> nums1 {1,2,2,4};
    vector<int> nums2 {1,1};

    Solution solution;

    vector<int> solution1 = solution.findErrorNums(nums1);
    vector<int> solution2 = solution.findErrorNums(nums2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}
