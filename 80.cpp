#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            if(count > 2) {
                n--;
                for(int j = i; j < n; j++) {
                    nums[j] = nums[j + 1];
                }
                i--;
            }
        }
        return n;
    }
};

int main() {
    vector<int> nums1 {1,1,1,2,2,3};
    vector<int> nums2 {0,0,1,1,1,1,2,3,3};

    Solution solution;

    int solution1 = solution.removeDuplicates(nums1);
    int solution2 = solution.removeDuplicates(nums2);

    cout << solution1 << '\n';
    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << solution2 << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}