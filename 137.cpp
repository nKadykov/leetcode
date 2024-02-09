#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<int> nums1 {2,2,3,2};
    vector<int> nums2 {0,1,0,1,0,1,99};

    Solution solution;

    int solution1 = solution.singleNumber(nums1);
    int solution2 = solution.singleNumber(nums2);

    cout << solution1 << '\n';
    cout << solution2;

    return 0;
}