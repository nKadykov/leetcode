#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numbers;
        for (int x : nums) {
            if (numbers.count(x) > 0)
                return true;
            numbers.insert(x);
        }
        return false;
    }
};

int main() {
    vector<int> nums1 {1,2,3,1};
    vector<int> nums2 {1,2,3,4};
    vector<int> nums3 {1,1,1,3,3,4,3,2,4,2};

    Solution solution;

    bool solution1 = solution.containsDuplicate(nums1);
    bool solution2 = solution.containsDuplicate(nums2);
    bool solution3 = solution.containsDuplicate(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}