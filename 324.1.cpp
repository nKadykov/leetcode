#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> result;
        for(auto x : nums) {
            result.push(x);
        }
        for(int i = 1; i < n; i += 2) {
            nums[i] = result.top();
            result.pop();
        }
        for(int i = 0; i < n; i += 2) {
            nums[i] = result.top();
            result.pop();
        }
    }
};

int main() {
    vector<int> nums1 {1,5,1,1,6,4};
    vector<int> nums2 {1,3,2,2,3,1};

    Solution solution;

    solution.wiggleSort(nums1);
    solution.wiggleSort(nums2);

    for(auto x : nums1) {
        cout << x << ' ';
    }
    cout << '\n';
    for(auto x : nums2) {
        cout << x << ' ';
    }

    return 0;
}