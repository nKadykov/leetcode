#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int function(vector<int>& nums, int ind, vector<int>& m) {
        if(ind >= nums.size() - 1) {
            return 0;
        }
        if(m[ind] != 0) {
            return m[ind];
        }
        int answer = 10000;
        for(int i = ind + 1; i <= ind + nums[ind]; i++) {
            int number = 1 + function(nums, i, m);
            answer = min(answer, number);
        }
        return m[ind] = answer;
    }
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 2) {
            return 1;
        }
        vector<int> m(nums.size(), 0);
        int result = function(nums, 0, m);
        return result;
    }
};

int main() {
    vector<int> nums1 {2,3,1,1,4};
    vector<int> nums2 {2,3,0,1,4};

    Solution solution;

    int solution1 = solution.jump(nums1);
    int solution2 = solution.jump(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}