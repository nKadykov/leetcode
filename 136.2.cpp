#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x : nums) {
            m[x]++;
        }
        for(auto x : m) {
            if(x.second == 1) {
                return x.first;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 {2,2,1};
    vector<int> nums2 {4,1,2,1,2};
    vector<int> nums3 {1};

    Solution solution;

    int solution1 = solution.singleNumber(nums1);
    int solution2 = solution.singleNumber(nums2);
    int solution3 = solution.singleNumber(nums3);

    cout << solution1 << '\n';
    cout << solution2 << '\n';
    cout << solution3;

    return 0;
}