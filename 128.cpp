#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) {
            return 0;
        }
        int max = 1;
        int cons = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == (nums[i - 1] + 1)) {
                cons++;
                if(cons > max) {
                    max = cons;
                }
            }
            else {
                if(nums[i] != nums[i - 1]) {
                    cons = 1;
                }
            }
        }
        return max;
    }
};

int main() {
    vector<int> nums1 {100,4,200,1,3,2};
    vector<int> nums2 {0,3,7,2,5,8,4,6,0,1};

    Solution solution;

    int solution1 = solution.longestConsecutive(nums1);
    int solution2 = solution.longestConsecutive(nums2);

    cout << solution1 << '\n';
    cout << solution2 << '\n';

    return 0;
}