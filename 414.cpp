#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(s.size() < 3) {
            return *s.rbegin();
        }
        auto it = s.rbegin();
        advance(it, 2);
        return *it;
    }
};

int main() {
    vector<int> nums1 {3,2,1};
    vector<int> nums2 {1,2};
    vector<int> nums3 {2,2,3,1};

    Solution solution;

    int solution1 = solution.thirdMax(nums1);
    int solution2 = solution.thirdMax(nums2);
    int solution3 = solution.thirdMax(nums3);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}