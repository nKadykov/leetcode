#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int m = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] < m) {
                return true;
            }
            while(!s.empty() && s.top() < nums[i]) {
                m = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums1 {1,2,3,4};
    vector<int> nums2 {3,1,4,2};
    vector<int> nums3 {-1,3,2,0};

    Solution solution;

    bool solution1 = solution.find132pattern(nums1);
    bool solution2 = solution.find132pattern(nums2);
    bool solution3 = solution.find132pattern(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}