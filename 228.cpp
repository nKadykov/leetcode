#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        if(nums.size() == 1) {
            return {to_string(nums[0])};
        }
        vector<string> result;
        int prev = nums[0];
        int next = nums[0];
        string elem;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == (nums[i - 1] + 1)) {
                next = nums[i];
            }
            else {
                if(prev == next) {
                    elem = to_string(prev);
                }
                else {
                    elem = to_string(prev) + "->" + to_string(next);
                }
                result.push_back(elem);
                prev = nums[i];
                next = nums[i];
            }
        }
        if(prev == next) {
            elem = to_string(prev);
            result.push_back(elem);
        }
        else {
            elem = to_string(prev) + "->" + to_string(next);
            result.push_back(elem);
        }
        return result;
    }
};

int main() {
    vector<int> nums1 {0,1,2,4,5,7};
    vector<int> nums2 {0,2,3,4,6,8,9};

    Solution solution;

    vector<string> solution1 = solution.summaryRanges(nums1);
    vector<string> solution2 = solution.summaryRanges(nums2);

    for(auto x : solution1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : solution2) {
        cout << x << ' ';
    }

    return 0;
}